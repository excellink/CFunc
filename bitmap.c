/*
 * 程序功能：创建一个Bitmap用于存储信息
 * 运行环境：64位系统
 * 1. 传入一个数n，在对应bitmap位上置位
 * 2. 最大存储数据量 BITMAP_SIZE * UNIT_SIZE
 * 3. bitmap下表范围 [0, BITMAP_SIZE * UNIT_SIZE - 1]
 * 4. 2 ^ n = UNIT_SIZE, MASK = 2 ^ n - 1, SHIFT = n 
 */

#include <stdio.h>
#include <stdbool.h>

#define N 1024
#define SHIFT 3
#define MASK 0x07
#define UNIT_SIZE 8
#define BITMAP_SIZE N/UNIT_SIZE

typedef unsigned char uint8;
typedef unsigned int uint32;

uint8 bitmap[BITMAP_SIZE + 1]={0};

void bitmap_set(int n)
{
	bitmap[n >> SHIFT] |= (1 << (n & MASK));
	printf("bitmap[%u] = 0x%x\n", n >> SHIFT, bitmap[n >> SHIFT]);
	return;
}

void bitmap_clear(int n)
{
	bitmap[n >> SHIFT] &= ~ (1 << (n & MASK));
	printf("bitmap[%u] = 0x%x\n", n >> SHIFT, bitmap[n >> SHIFT]);
	return;
}

bool bitmap_check(int n)
{
	return bitmap[n >> SHIFT] & (1 << (n & MASK));
}

void main()
{
	int x;
	printf("set bitmap:\n");
	while(scanf("%d",&x))
	{
		bitmap_set(x);
		printf("check %d\n", bitmap_check(x));
		bitmap_clear(x);
		printf("check %d\n", bitmap_check(x));
		printf("set bitmap:\n");
	}
	return;
}