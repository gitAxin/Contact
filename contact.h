

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 128

enum Opt {
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
struct PInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];

};

//ͨѸ¼
struct Contact {
	struct PInfo data[MAX];//ͨѸ¼��������
	int size;//ͨѸ¼����
};

//��ʼ��ͨѸ¼
void init(struct Contact* ps);
//�����ϵ��
void add(struct Contact* ps);
//��ʾ��ϵ��
void show(const struct Contact* ps);

void search(const struct Contact* ps);
//ɾ��ָ����ϵ��
void del(struct Contact* ps);
//�޸�
void modify(struct Contact* ps);
//����
void sort(struct Contact* ps);