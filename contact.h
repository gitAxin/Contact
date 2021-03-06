

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

//通迅录
struct Contact {
	struct PInfo data[MAX];//通迅录所有数据
	int size;//通迅录条数
};

//初始化通迅录
void init(struct Contact* ps);
//添加联系人
void add(struct Contact* ps);
//显示联系人
void show(const struct Contact* ps);

void search(const struct Contact* ps);
//删除指定联系人
void del(struct Contact* ps);
//修改
void modify(struct Contact* ps);
//排序
void sort(struct Contact* ps);