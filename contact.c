#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include "contact.h"
#include <memory.h>
#include <string.h>
#include <stdlib.h>


//初始化通迅录
void init(struct Contact* ps) {
	//memset(ps->data, 0, sizeof(ps->data));
	ps->data = (struct PInfo*)malloc(DEFAULT_CAPACITY * sizeof(struct PInfo));
	if (ps->data == NULL) {
		printf("扩容失败\n");
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;
}

//检查容量
/*
* 如果满了就增加容量,不满则什么都不做
*/
void checkCapacity(struct Contact* ps) {
	if (ps->size < ps->capacity) {
		return;
	}
	struct PInfo* p = (struct PInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PInfo));
	if (p != NULL) {
		ps->data = p;
		ps->capacity += 2;
		//printf("扩容成功\n");
	}
	else {
		printf("扩容失败\n");
	}
}
//添加联系人
void add(struct Contact* ps) {
	/*if (ps->size == ps->capacity) {
		printf("通讯录已满\n");
		return;
	}*/
	//检查容量
	checkCapacity(ps);

	printf("请输入姓名>:");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄>:");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别>:");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话>:");
	scanf("%s", ps->data[ps->size].tel);
	printf("请输入地址>:");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	
}
//显示联系人
void show(const struct Contact* ps) {
	printf("%s\t%s\t%s\t%s\t%s\n", "姓名", "年龄", "性别", "电话", "地址");
	int i = 0;
	for (int i = 0; i < ps->size; i++) {
		printf("%s\t%d\t%s\t%s\t%s\n", ps->data[i].name,
			ps->data[i].age, 
			ps->data[i].sex, 
			ps->data[i].tel, 
			ps->data[i].addr);

	}
}

void search(struct Contact* ps) {
	printf("请输入要查询的名称>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("联系人不存在\n");
		return;
	}
	printf("%s\t%s\t%s\t%s\t%s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%s\t%d\t%s\t%s\t%s\n", ps->data[pos].name,
		ps->data[pos].age,
		ps->data[pos].sex,
		ps->data[pos].tel,
		ps->data[pos].addr);
}
int findByName(struct Contact* ps, char* name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		int ret = strcmp(ps->data[i].name, name);
		if (ret == 0) {
			return i;
		}
	}
	return -1;
}
//删除指定联系人
void del(struct Contact* ps) {
	printf("请输入要删除的名称>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("联系人不存在\n");
		return;
	}
	int i = 0;
	for (i = pos; i < ps->size - 1; i++) {
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("删除成功\n");


}
//修改
void modify(struct Contact* ps) {
	printf("请输入要修改的名称>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("联系人不存在\n");
		return;
	}

	printf("请输入姓名>:");
	scanf("%s", ps->data[pos].name);
	printf("请输入年龄>:");
	scanf("%d", &(ps->data[pos].age));
	printf("请输入性别>:");
	scanf("%s", ps->data[pos].sex);
	printf("请输入电话>:");
	scanf("%s", ps->data[pos].tel);
	printf("请输入地址>:");
	scanf("%s", ps->data[pos].addr);

	printf("修改成功");

}
//排序
void sort(struct Contact* ps) {
	int i = 0; 
	for (i = 0; i < ps->size - 1; i++) {
		int k = 0;
		for (k = 0; k < ps->size - i - 1; k++) {
			
			int ret = strcmp(ps->data[k].name, ps->data[k + 1].name);
			//printf("%d, %s, %s\n", ret, ps->data[k].name, ps->data[k + 1].name);
			if (ret > 0) {
				struct PInfo temp = { 0 };
				temp = ps->data[k];
				ps->data[k] = ps->data[k + 1];
				ps->data[k + 1] = temp;
			}
		}
	}

	printf("排序完成.\n");

}

void destroy(struct Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}