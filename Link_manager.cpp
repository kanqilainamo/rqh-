#include<iostream>
#include<string>
using namespace std;

//BUGS
// 输入是字符数会出现cin流错误


template<typename T>
struct node
{
	T data;
	node* next;
	node(T data = 0, node<T>* next = nullptr) { this->data = data; this->next = next; }
};

template<typename T>
class Mylink
{
public:
	Mylink();					//构造函数

	void print_link();			//0显示函数
	void creat();				//1创建函数
	void clear_link();			//2删除函数
	void find_link();			//3查找指定位置元素
	void insert_link();			//4指定位子插入元素
	void delet_link();			//5删除指定位子元素
	void count_link();			//6统计长度

private:
	int length;
	node<T>* head;
};
void show_menu();


int main()
{
	Mylink<int> l;
	char choice[1];
	while (true)
	{
		show_menu();
		cin >> choice;
		switch (choice[0])
		{
		case '0':l.print_link(); break;
		case '1':l.creat(); break;
		case '2':l.clear_link(); break;
		case '3':l.find_link(); break;
		case '4':l.insert_link(); break;
		case '5':l.delet_link(); break;
		case '6':l.count_link(); break;
		case '9':exit(1);
		default:
			printf("输入错误！请输入正确的选项\n");
			break;
		}
		system("pause");
		system("cls");

	}
	return 0;
}




template<typename T>
Mylink<T>::Mylink()
{
	head = new node<int>(0);
	length = 0;
}

template<typename T>
void Mylink<T>::creat()
{
	system("cls");
	int clength;
	cout << "输入添加个数: ";
	cin >> clength;
	node<T>* p, * temp;
	p = head;
	if (clength <= 0)
	{
		cout << "错误！输入值应大于1" << endl;
		return;
	}
	else
	{
		int i = 1;
		while (i <= clength)
		{
			temp = new node<T>;
			cout << "NO." << i << " 的值为 :";
			cin >> temp->data;
			p->next = temp;
			p = temp;
			this->length++;
			i++;
		}
	}
}
template<typename T>
void Mylink<T>::print_link()
{
	node<T>* temp = head->next;
	int i = 1;
	if (this->length == 0)
	{
		cout << "链表为空" << endl;
		return;
	}
	while (temp)
	{
		cout << "NO." << i << "的值为" << temp->data << endl;
		i++;
		temp = temp->next;
	}

}
//2 清空链表
template<typename T>
void Mylink<T>::clear_link()
{
	node<T>* p, * temp;
	p = head->next;
	temp = head->next;
	while (p)
	{
		temp = temp->next;
		delete p;
		p = temp;
		this->length--;
	}
	head->next = nullptr;
	if (length == 0)
	{
		cout << "链表删除完毕" << endl;
	}
}
//菜单显示
void show_menu()
{
	cout << "输入你要做的操作：" << endl;
	printf("********************\n");
	printf("0.显示链表\n");
	printf("1.创建链表\n");
	printf("2.删除链表\n");
	printf("3.查询节点\n");
	printf("4.插入节点\n");
	printf("5.删除节点\n");
	printf("6.查询链表长度\n");
	printf("9.退出程序\n");
	printf("********************\n");
}

//3查找指定位置元素
template<typename T>
void Mylink<T>::find_link()
{

	int i, c = 0;
	printf("查找第几个节点？ ");
	cin >> i;
	node<T>* p;
	p = this->head->next;
	if (i < 0)
	{
		printf("输入有误");
		return;
	}
	while (p)
	{
		c++;
		if (c == i)
		{
			cout << "NO." << i << "的值为：" << p->data << endl;
			return;
		}
		p = p->next;
	}
	printf("超出范围！\n");
}

//4指定位子插入元素
template<typename T>
void Mylink<T>::insert_link()
{
	int i, index = 0;
	T value;
	node<T>* p, * temp_new;
	p = head;
	printf("请输入你要插入的位子:");
	cin >> i;
	if (i<0 || i>this->length)
	{
		printf("输入错误！");
		return;
	}
	printf("请输入你要插入的值:");
	cin >> value;
	while (index < i - 1)
	{
		p = p->next;
		index++;
	};
	temp_new = new node<T>(value); //1 新建节点
	temp_new->next = p->next;	// 2 存右节点地址
	p->next = temp_new;			//3 存新节点地址
	this->length++;
	printf("插入成功！\n");
}
//5指定位子删除元素
template<typename T>
void Mylink<T>::delet_link()
{
	if (length == 0)
	{
		printf("链表为空！\n");
		return;
	}
	int i, index = 0;
	node<T>* p, * temp;
	p = head;
	printf("请输入你要删除的位子：");
	cin >> i;
	if (i<0 || i>this->length)
	{
		printf("输入错误！");
		return;
	}
	while (index < i - 1) // p 指向删除节点的前一个
	{
		p = p->next;
		index++;
	}
	temp = p;				// 1 记录 i-1节点位子
	p = p->next;			// 2 p指向下一个节点
	temp->next = p->next;   // 3 i-1 指向i+1
	delete p;				// 4 删除节点i 
	length--;
	printf("删除成功\n");
}
//6 统计长度
template<typename T>
void Mylink<T>::count_link()
{
	cout << "链表长度为：" << length << endl;
}