#define _CRT_SECURE_NO_DEPRECATE 1

/*
1.存放1000个好友的信息
名字
电话
性别
住址
年龄

2.增加
3.删除指定名字
4.查找
5.修改
6.打印
7.排序
*/

#include <stdio.h>
#include "contact.h"

void menu() {
	printf("***************************** ******\n");
	printf("****** 1. add       2. del    ******\n");
	printf("****** 3. search    4. modify ******\n");
	printf("****** 5. show      6. sort	  ******\n");
	printf("****** 0. exit                ******\n");
	printf("************************************\n");
}

int main() {
	int input = 0;
	struct Contact contact;//通迅录,包括数据和联系人个数
	init(&contact);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		//printf("%d", input);
		switch (input)
		{
		case ADD:
			add(&contact);
			show(&contact);
			break;
		case DEL:
			del(&contact);
			break;
		case SEARCH:
			search(&contact);
			break;
		case MODIFY:
			modify(&contact);
			break;
		case SHOW:
			show(&contact);

			break;
		case SORT:
			sort(&contact);
			break;
		case EXIT:
			printf("退出通迅录!\n");
			break;
		default:
			printf("输入错误!\n");
			break;
		}

	} while (input);
	return 0;
}

