/* 
 * File:   bubbleSort.c
 * Author: Beck
 * 两种不同的冒泡思路
 * Created on 2015年3月5日, 下午1:45
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket
{
	char *key;
	char *value;
	struct bucket *next;
} bucket;

typedef struct hashTable
{
	
} hashTable;
/*
 * 
 */
int main(int argc, char** argv) {
	int nums[] = {6,8,4,5,3,2,10};
	int i;
	bubbleSort2(nums, 7);
	for(i = 0; i < 7; i++) {
		printf("%d \n", nums[i]);
	}
	return (EXIT_SUCCESS);
}