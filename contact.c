#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include "contact.h"
#include <memory.h>
#include <string.h>
#include <stdlib.h>


//��ʼ��ͨѸ¼
void init(struct Contact* ps) {
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
//�����ϵ��
void add(struct Contact* ps) {
	if (ps->size >= MAX) {
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������>:");
	scanf("%s", ps->data[ps->size].name);
	printf("����������>:");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�>:");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰>:");
	scanf("%s", ps->data[ps->size].tel);
	printf("�������ַ>:");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	
}
//��ʾ��ϵ��
void show(const struct Contact* ps) {
	printf("%s\t%s\t%s\t%s\t%s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ��ѯ������>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}
	printf("%s\t%s\t%s\t%s\t%s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
//ɾ��ָ����ϵ��
void del(struct Contact* ps) {
	printf("������Ҫɾ��������>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}
	int i = 0;
	for (i = pos; i < ps->size - 1; i++) {
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("ɾ���ɹ�\n");


}
//�޸�
void modify(struct Contact* ps) {
	printf("������Ҫ�޸ĵ�����>:\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int pos = findByName(ps, name);
	if (pos == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}

	printf("����������>:");
	scanf("%s", ps->data[pos].name);
	printf("����������>:");
	scanf("%d", &(ps->data[pos].age));
	printf("�������Ա�>:");
	scanf("%s", ps->data[pos].sex);
	printf("������绰>:");
	scanf("%s", ps->data[pos].tel);
	printf("�������ַ>:");
	scanf("%s", ps->data[pos].addr);

	printf("�޸ĳɹ�");

}
//����
void sort(struct Contact* ps) {
	int i = 0; 
	for (i = 0; i < ps->size; i++) {
		int k = 0;
		for (k = i; k < ps->size - 1; k++) {
			
			int ret = strcmp(ps->data[k].name, ps->data[k + 1].name);
			if (ret > 0) {
				struct PInfo temp;
				temp = ps->data[k];
				ps->data[k] = ps->data[k + 1];
				ps->data[k + 1] = temp;
			}
		}
	}

	printf("�������.\n");

}