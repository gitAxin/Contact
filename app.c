#define _CRT_SECURE_NO_DEPRECATE 1

/*
1.���1000�����ѵ���Ϣ
����
�绰
�Ա�
סַ
����

2.����
3.ɾ��ָ������
4.����
5.�޸�
6.��ӡ
7.����
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
	struct Contact contact;//ͨѸ¼,�������ݺ���ϵ�˸���
	init(&contact);
	do
	{
		menu();
		printf("��ѡ��>:");
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
			printf("�˳�ͨѸ¼!\n");
			break;
		default:
			printf("�������!\n");
			break;
		}

	} while (input);
	return 0;
}

