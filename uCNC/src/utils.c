/*
	Name: util.c
	Description: Some useful constants and macros.

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 29/11/2023

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#include "cnc.h"

#ifndef CRC_WITHOUT_LOOKUP_TABLE
const uint8_t __rom__ crc7_table[256] =
	{
		0x00, 0x09, 0x12, 0x1b, 0x24, 0x2d, 0x36, 0x3f,
		0x48, 0x41, 0x5a, 0x53, 0x6c, 0x65, 0x7e, 0x77,
		0x19, 0x10, 0x0b, 0x02, 0x3d, 0x34, 0x2f, 0x26,
		0x51, 0x58, 0x43, 0x4a, 0x75, 0x7c, 0x67, 0x6e,
		0x32, 0x3b, 0x20, 0x29, 0x16, 0x1f, 0x04, 0x0d,
		0x7a, 0x73, 0x68, 0x61, 0x5e, 0x57, 0x4c, 0x45,
		0x2b, 0x22, 0x39, 0x30, 0x0f, 0x06, 0x1d, 0x14,
		0x63, 0x6a, 0x71, 0x78, 0x47, 0x4e, 0x55, 0x5c,
		0x64, 0x6d, 0x76, 0x7f, 0x40, 0x49, 0x52, 0x5b,
		0x2c, 0x25, 0x3e, 0x37, 0x08, 0x01, 0x1a, 0x13,
		0x7d, 0x74, 0x6f, 0x66, 0x59, 0x50, 0x4b, 0x42,
		0x35, 0x3c, 0x27, 0x2e, 0x11, 0x18, 0x03, 0x0a,
		0x56, 0x5f, 0x44, 0x4d, 0x72, 0x7b, 0x60, 0x69,
		0x1e, 0x17, 0x0c, 0x05, 0x3a, 0x33, 0x28, 0x21,
		0x4f, 0x46, 0x5d, 0x54, 0x6b, 0x62, 0x79, 0x70,
		0x07, 0x0e, 0x15, 0x1c, 0x23, 0x2a, 0x31, 0x38,
		0x41, 0x48, 0x53, 0x5a, 0x65, 0x6c, 0x77, 0x7e,
		0x09, 0x00, 0x1b, 0x12, 0x2d, 0x24, 0x3f, 0x36,
		0x58, 0x51, 0x4a, 0x43, 0x7c, 0x75, 0x6e, 0x67,
		0x10, 0x19, 0x02, 0x0b, 0x34, 0x3d, 0x26, 0x2f,
		0x73, 0x7a, 0x61, 0x68, 0x57, 0x5e, 0x45, 0x4c,
		0x3b, 0x32, 0x29, 0x20, 0x1f, 0x16, 0x0d, 0x04,
		0x6a, 0x63, 0x78, 0x71, 0x4e, 0x47, 0x5c, 0x55,
		0x22, 0x2b, 0x30, 0x39, 0x06, 0x0f, 0x14, 0x1d,
		0x25, 0x2c, 0x37, 0x3e, 0x01, 0x08, 0x13, 0x1a,
		0x6d, 0x64, 0x7f, 0x76, 0x49, 0x40, 0x5b, 0x52,
		0x3c, 0x35, 0x2e, 0x27, 0x18, 0x11, 0x0a, 0x03,
		0x74, 0x7d, 0x66, 0x6f, 0x50, 0x59, 0x42, 0x4b,
		0x17, 0x1e, 0x05, 0x0c, 0x33, 0x3a, 0x21, 0x28,
		0x5f, 0x56, 0x4d, 0x44, 0x7b, 0x72, 0x69, 0x60,
		0x0e, 0x07, 0x1c, 0x15, 0x2a, 0x23, 0x38, 0x31,
		0x46, 0x4f, 0x54, 0x5d, 0x62, 0x6b, 0x70, 0x79};
#else
uint8_t crc7(uint8_t c, uint8_t crc)
{
	uint8_t i = 8;
	crc ^= c;
	for (;;)
	{
		if (crc & 0x80)
		{
			crc ^= 0x89;
		}
		if (!--i)
		{
			return crc;
		}
		crc <<= 1;
	}
}
#endif

uint8_t buffer_write_available(ring_buffer_t *buffer)
{
	return (buffer->size - buffer->count);
}

uint8_t buffer_read_available(ring_buffer_t *buffer)
{
	return buffer->count;
}

bool buffer_empty(ring_buffer_t *buffer)
{
	return !buffer->count;
}

bool buffer_full(ring_buffer_t *buffer)
{
	return (buffer->size == buffer->count);
}

void buffer_peek(ring_buffer_t *buffer, void *ptr)
{
	memcpy(ptr, &buffer->data[buffer->tail * buffer->elem_size], buffer->elem_size);
}

void buffer_remove(ring_buffer_t *buffer)
{
	uint8_t tail;
	__ATOMIC__
	{
		tail = buffer->tail;

		if (!buffer_empty(buffer))
		{
			tail++;
			if (tail >= buffer->size)
			{
				tail = 0;
			}

			buffer->tail = tail;
			buffer->count--;
		}
	}
}

void buffer_dequeue(ring_buffer_t *buffer, void *ptr)
{
	if (!buffer_empty(buffer))
	{
		uint8_t tail;
		__ATOMIC__
		{
			tail = buffer->tail;
			memcpy(ptr, &buffer->data[tail * buffer->elem_size], buffer->elem_size);
			tail++;
			if (tail >= buffer->size)
			{
				tail = 0;
			}

			buffer->tail = tail;
			buffer->count--;
		}
	}
}

void buffer_store(ring_buffer_t *buffer)
{
	if (!buffer_full(buffer))
	{
		uint8_t head;
		__ATOMIC__
		{
			head = buffer->head;

			head++;
			if (head >= buffer->size)
			{
				head = 0;
			}

			buffer->head = head;
			buffer->count++;
		}
	}
}

void buffer_enqueue(ring_buffer_t *buffer, void *ptr)
{
	if (!buffer_full(buffer))
	{
		uint8_t head;
		__ATOMIC__
		{
			head = buffer->head;
			memcpy(&buffer->data[head * buffer->elem_size], ptr, buffer->elem_size);
			head++;
			if (head >= buffer->size)
			{
				head = 0;
			}
			buffer->head = head;
			buffer->count++;
		}
	}
}

void *buffer_next_free(ring_buffer_t *buffer)
{
	__ATOMIC__
	{
		return &buffer->data[buffer->head * buffer->elem_size];
	}

	return NULL;
}

void buffer_write(ring_buffer_t *buffer, void *ptr, uint8_t len, uint8_t *written)
{
	uint8_t count, head, *p = (uint8_t *)ptr;
	__ATOMIC__
	{
		head = buffer->head;
		count = buffer->count;
		count = MIN(buffer->size - count, len);
		*written = 0;
		if (count)
		{
			uint8_t avail = (buffer->size - head);
			if (avail < count && avail)
			{
				memcpy(&buffer->data[head * buffer->elem_size], ptr, avail * buffer->elem_size);
				*written = avail;
				count -= avail;
				head = 0;
			}
			else
			{
				avail = 0;
			}
			if (count)
			{
				memcpy(&buffer->data[head * buffer->elem_size], &p[avail * buffer->elem_size], count * buffer->elem_size);
				*written += count;
				head += count;
				if (head == buffer->size)
				{
					head = 0;
				}
				buffer->head = head;
				buffer->count += *written;
			}
		}
	}
}

void buffer_read(ring_buffer_t *buffer, void *ptr, uint8_t len, uint8_t *read)
{
	uint8_t count, tail, *p = (uint8_t *)ptr;
	__ATOMIC__
	{
		tail = buffer->tail;
		count = buffer->count;
		if (count > len)
		{
			count = len;
		}
		*read = 0;
		if (count)
		{
			uint8_t avail = buffer->size - tail;
			if (avail < count && avail)
			{
				memcpy(ptr, &buffer->data[tail * buffer->elem_size], avail * buffer->elem_size);
				*read = avail;
				count -= avail;
				tail = 0;
			}
			else
			{
				avail = 0;
			}
			if (count)
			{
				memcpy(&p[avail * buffer->elem_size], &buffer->data[tail * buffer->elem_size], count * buffer->elem_size);
				*read += count;
				tail += count;
				if (tail == buffer->size)
				{
					tail = 0;
				}
				buffer->tail = tail;
				buffer->count -= *read;
			}
		}
	}
}

void buffer_clear(ring_buffer_t *buffer)
{
	__ATOMIC__
	{
		memset(buffer->data, 0, buffer->elem_size * buffer->size);
		buffer->tail = 0;
		buffer->head = 0;
		buffer->count = 0;
	}
}