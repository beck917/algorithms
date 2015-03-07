/* 
 * File:   bubbleSort.c
 * Author: Beck
 * 两种不同的冒泡思路
 * Created on 2015年3月5日, 下午1:45
 */
#include <stdio.h>
#include <stdlib.h>

void bubbleSort2(int nums[], int len) {
	int i,j,tmp,x=0;
	for(i = 0; i < len; i++) {
		for(j = i+1; j < len; j++) {
			if (nums[j] < nums[i]) {
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
}

void bubbleSort(int nums[], int len) {
	int i,j,tmp;
	for(i = 0; i < len - 1; i++) {
		for(j = 0; j < len - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
}
/*
int main(int argc, char** argv) {
	int nums[] = {6,8,4,5,3,2,10};
	int i;
	bubbleSort2(nums, 7);
	for(i = 0; i < 7; i++) {
		printf("%d \n", nums[i]);
	}
	return (EXIT_SUCCESS);
}
*/