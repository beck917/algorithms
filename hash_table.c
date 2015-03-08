
/* 
 * File:   bubbleSort.c
 * Author: Beck
 * 哈希表
 * 暂时没有做(碰撞)容量扩充
 * Created on 2015年3月8日, 下午1:45
 */
#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101
#define SUCCESS 0
#define FAILED -1

typedef struct bucket
{
	char *key;
	char *value;
	struct bucket *next;
} bucket;

typedef struct hashTable
{
	int size;
	int cur_size;
	bucket **buckets;
} hashTable;

static int hash(char *key)
{
	int num = 0;
	char *tmp_key = key;
	
	while(*tmp_key != '\0') {
		num = *tmp_key + 32 * num;
		tmp_key++;
	}
	return num%HASHSIZE;
}

int insert(hashTable *ht, char *key, char *value)
{
	int index = hash(key);
	bucket *org_bucket = ht->buckets[index];
	bucket *tmp_bucket = org_bucket;
	while (tmp_bucket) {
		if (strcmp(tmp_bucket->key, key) == 0) {
			tmp_bucket->value = value;
			return 1;
		}
		tmp_bucket = tmp_bucket->next;
	}
	bucket *bck = (bucket *)malloc(sizeof(bucket));
	bck->key = key;
	bck->value = value;
	bck->next = NULL;
	ht->cur_size++;
	
	if (org_bucket) {
		bck->next = org_bucket;
	}
	ht->buckets[index] = bck;
	return 1;
}

char* lookup(hashTable *ht, char *key)
{
	int index = hash(key);
	bucket *bck = ht->buckets[index];
	while(bck) {
		if (strcmp(bck->key, key) == 0) {
			return bck->value;
		}
		bck = bck->next;
	}
	return NULL;
}
/*
int main(int argc, char** argv) {
	hashTable *ht = (hashTable *)malloc(sizeof(hashTable));
	ht->size = HASHSIZE;
	ht->cur_size = 0;
	ht->buckets = (bucket **)calloc(HASHSIZE, sizeof(bucket *));
	insert(ht, "key_test", "value_test");
	char *value = lookup(ht, "key_test");
	printf("value: %s", value);
	return (EXIT_SUCCESS);
}
*/