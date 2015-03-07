/* 
 * File:   driect_access_table.c
 * Author: Beck
 *
 * Created on 2015年3月5日, 下午1:45
 */
/**
 * 直接寻址表
 * 可以看做是一种删除和查找都是O(n)的数组
 * 是哈希表的最基础形态
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket
{
	int index;
	char *value;
}bucket;

bucket *_table[10];//指向_bucket的指针

bucket* search(bucket **_table, int i)
{
	return _table[i];
}

void insert(bucket **_table, bucket *_bucket)
{
	_table[_bucket->index] = _bucket;
}

void delete(bucket **_table, bucket *_bucket)
{
	_table[_bucket->index] = NULL;
}

/**
int main(int argc, char** argv) {
	int i;
	bucket *_bucket = (bucket *)malloc(sizeof(bucket));
	_bucket->index = 5;
	_bucket->value = "abc";
	
	bucket *_bucket1 = (bucket *)malloc(sizeof(bucket));
	_bucket1->index = 3;
	_bucket1->value = "cba";
	
	//初始化table
	for(i = 0; i < 10; i++) {
       _table[i] = (bucket *)malloc(sizeof(bucket *));
		_table[i] = NULL;
	}
	insert(_table, _bucket);
	insert(_table, _bucket1);
	printf("test");
	bucket *b = search(_table, 3);
	printf("test %s %d", b->value, b->index);
	
	return (EXIT_SUCCESS);
}
*/