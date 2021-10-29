#include<iostream>
#include<string>
using namespace std;

//BUGS
// �������ַ��������cin������


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
	Mylink();					//���캯��

	void print_link();			//0��ʾ����
	void creat();				//1��������
	void clear_link();			//2ɾ������
	void find_link();			//3����ָ��λ��Ԫ��
	void insert_link();			//4ָ��λ�Ӳ���Ԫ��
	void delet_link();			//5ɾ��ָ��λ��Ԫ��
	void count_link();			//6ͳ�Ƴ���

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
			printf("���������������ȷ��ѡ��\n");
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
	cout << "������Ӹ���: ";
	cin >> clength;
	node<T>* p, * temp;
	p = head;
	if (clength <= 0)
	{
		cout << "��������ֵӦ����1" << endl;
		return;
	}
	else
	{
		int i = 1;
		while (i <= clength)
		{
			temp = new node<T>;
			cout << "NO." << i << " ��ֵΪ :";
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
		cout << "����Ϊ��" << endl;
		return;
	}
	while (temp)
	{
		cout << "NO." << i << "��ֵΪ" << temp->data << endl;
		i++;
		temp = temp->next;
	}

}
//2 �������
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
		cout << "����ɾ�����" << endl;
	}
}
//�˵���ʾ
void show_menu()
{
	cout << "������Ҫ���Ĳ�����" << endl;
	printf("********************\n");
	printf("0.��ʾ����\n");
	printf("1.��������\n");
	printf("2.ɾ������\n");
	printf("3.��ѯ�ڵ�\n");
	printf("4.����ڵ�\n");
	printf("5.ɾ���ڵ�\n");
	printf("6.��ѯ������\n");
	printf("9.�˳�����\n");
	printf("********************\n");
}

//3����ָ��λ��Ԫ��
template<typename T>
void Mylink<T>::find_link()
{

	int i, c = 0;
	printf("���ҵڼ����ڵ㣿 ");
	cin >> i;
	node<T>* p;
	p = this->head->next;
	if (i < 0)
	{
		printf("��������");
		return;
	}
	while (p)
	{
		c++;
		if (c == i)
		{
			cout << "NO." << i << "��ֵΪ��" << p->data << endl;
			return;
		}
		p = p->next;
	}
	printf("������Χ��\n");
}

//4ָ��λ�Ӳ���Ԫ��
template<typename T>
void Mylink<T>::insert_link()
{
	int i, index = 0;
	T value;
	node<T>* p, * temp_new;
	p = head;
	printf("��������Ҫ�����λ��:");
	cin >> i;
	if (i<0 || i>this->length)
	{
		printf("�������");
		return;
	}
	printf("��������Ҫ�����ֵ:");
	cin >> value;
	while (index < i - 1)
	{
		p = p->next;
		index++;
	};
	temp_new = new node<T>(value); //1 �½��ڵ�
	temp_new->next = p->next;	// 2 ���ҽڵ��ַ
	p->next = temp_new;			//3 ���½ڵ��ַ
	this->length++;
	printf("����ɹ���\n");
}
//5ָ��λ��ɾ��Ԫ��
template<typename T>
void Mylink<T>::delet_link()
{
	if (length == 0)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	int i, index = 0;
	node<T>* p, * temp;
	p = head;
	printf("��������Ҫɾ����λ�ӣ�");
	cin >> i;
	if (i<0 || i>this->length)
	{
		printf("�������");
		return;
	}
	while (index < i - 1) // p ָ��ɾ���ڵ��ǰһ��
	{
		p = p->next;
		index++;
	}
	temp = p;				// 1 ��¼ i-1�ڵ�λ��
	p = p->next;			// 2 pָ����һ���ڵ�
	temp->next = p->next;   // 3 i-1 ָ��i+1
	delete p;				// 4 ɾ���ڵ�i 
	length--;
	printf("ɾ���ɹ�\n");
}
//6 ͳ�Ƴ���
template<typename T>
void Mylink<T>::count_link()
{
	cout << "������Ϊ��" << length << endl;
}