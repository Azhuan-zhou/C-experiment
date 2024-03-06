#include <iostream>
#define defaultSize 100
using namespace std;

template <typename E> 
class Link
{
public:
    E element; // ����������
    Link *next; // ����ָ����
    // ������������
    Link(const E& elemval, Link* nextval =NULL)
    { 
        element = elemval; 
        next = nextval; 
    }
    Link(Link* nextval =NULL) 
    { 
        next = nextval; 
    }
};

template <typename E> 
class LList
{
private:
    Link<E>* head; // ͷ�ڵ�
    Link<E>* tail; // β���
    Link<E>* curr; // ��ǰָ��Ľ��
    int cnt; // �����ĳ���
    // ������ʼ��
    void init() 
    { 
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    // �������
    void removeall() 
    { 
        while(head != NULL) 
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    // �������캯��
    LList() 
    { 
        init(); 
    }
    // ������������
    ~LList() { removeall(); } 
    // �������
    void clear() 
    { 
        removeall(); 
        init(); 
    }
    // ��curλ�ò���Ԫ��it
    void insert(const E& it) 
    {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) //���curr��β����λ��
        {
            tail = curr->next; 
        }
        cnt++;
    }
    // ��β�������Ԫ��
    void append(const E& it)
    { 
        tail = tail->next = new Link<E>(it, NULL); // �ȴ���һ���µĽ�㣬����β���ָ���µĽ�㣬�ٰ�β�������ƶ�һλ
        cnt++;
    }
    // ɾ��������currָ�����һ�����
    E remove() 
    {
        if(curr->next == NULL)
        {
            cout<<"No element";
            exit(-1);
        }
        E it = curr->next->element; 
        Link<E>* ltemp = curr->next; 
        if (tail == curr->next) tail = curr; // ���ɾ���Ľ��ʱβ���
        curr->next = curr->next->next; // �ñ�currָ����
        delete ltemp; // �ͷſռ�
        cnt--; 
        return it;
    }
    // ��curr��ָ���ƶ�ͷ���
    void moveToStart() 
    { 
        curr = head; 
    }
    // ��curr��ָ���ƶ�β���
    void moveToEnd() 
    { 
        curr = tail; 
    }
    // ��curr��ǰ�ƶ�
    void prev() {
        if (curr == head) return; // curr��ͷ�ڵ�
        Link<E>* temp = head;
        // ��ͷ��ʼ�����
        while (temp->next!=curr)
        {
            temp=temp->next;
        } 
        curr = temp;
    }
    // ��curr����ƶ�
    void next()
    { 
        if (curr != tail)  // curr����β��㣬������ƶ�
            curr = curr->next;
    }
    // ������������
    int length() const 
    { 
        return cnt; 
    } 
    // ����curr���position
    int currPos() const {
        Link<E>* temp = head;
        int i;
        // ��ͷ�ڵ㿪ʼ����
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    // ��cur�ƶ���ָ����positionλ��
    void moveToPos(int pos) 
    {
        if(pos<0&&pos>cnt)
        {
            cout<<"Position out of range";
            exit(-1);
        }
        curr = head;
        for(int i=0; i<pos; i++) 
            curr = curr->next;
    }
    // ����currָ����һ������������
    const E& getValue() const 
    {
        if(curr->next==NULL)
        {
            cout<<"No Value";
            exit(-1);
        }
        return curr->next->element;
    }
};


