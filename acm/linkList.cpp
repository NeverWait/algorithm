#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node * create() {
    node *head, *p, *s;
    head = (node *)malloc(sizeof(Node));
    head->next = NULL;
    p = head;
    cout << "请输入任意个整数，用空格间隔开并用0结束：" << endl;
    int temp;
    while(cin>>temp && temp!=0){
        s = (node *) malloc(sizeof(node));
        s->data = temp;
        p->next = s;
        p = s;
    }
    p->next = NULL;
    cout << "链表创建成功";
    return head;
}


int list_len(node *head)
{
    node *p = head->next;
    if(p == NULL){
        return 0;
    }
    int num = 0;
    while(NULL!=p){
        p = p->next;
        num++;
    }
    return num;
}

void insert_link(node *head)
{
    cout << "请输入插入的数据";
    int data;
    cin >> data;
    node *s = (node *) malloc(sizeof(node));
    if(!s){
        cout << "数据" << data << "插入失败，请重新尝试";
        return;
    }
    s->data = data;
    s->next = head->next;
    head->next = s;
    cout << "数据" << data << "插入成功";
}

void dele_data(node *head)
{
    cout << "请输入要删除的数据：";
    int temp = 0;
    cin >> temp;
    node *p = head;
    while (p->next->data!=temp && NULL!=p->next){
        p = p->next;
    }
    if(NULL==p->next){
        cout << "未发现您输入的数据，请重新操作";
    } else {
        node *q = p->next;
        p->next = p->next->next;
        free(q);
        cout << "删除" << temp << "成功";
    }
}

void traversal(node *head)
{
    node *p = head->next;
    while(NULL!=p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}


node * sort_link(node *head)
{
    node *p = head->next;
    if(NULL==p || NULL==p->next){
        cout << "链表为空或者只有一个元素，无需排序";
        return head;
    }
    node *q = p->next;
    bool flag = true;
    while(flag){
        flag = false;
        while(NULL!=q){
            if(p->data>q->data){
                p->data = p->data + q->data;
                q->data = p->data - q->data;
                p->data = p->data - q->data;
                flag = true;
            }
            p = q;
            q = q->next;
        }
        p = head->next;
        q = p->next;
    }
    cout << "排序完毕" << endl;
    return head;
}
node * negtive_link(node *head)
{
    /*
     * 思想：将链表除头节点外的节点依次取下，然后插入到链表中
     */
    node *p = head->next;
    head->next = NULL;
    node *q;
    while(NULL!=p){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
    cout << "逆序完毕" << endl;
    return head;

}
int main(void)
{
    node *head = create();
    int counts = 0;
    traversal(head);
    cout << "输入一下数字继续操作：\n" << "0:退出  1：插入数据  2：删除数据  3：对链表排序  4：将链表逆序  5：查看链表个数" << endl;
    int option = 0;
    while(cin >> option && option!=0){
        switch (option){
            case 1:
                insert_link(head);
                break;
            case 2:
                dele_data(head);
                break;
            case 3:
                head = sort_link(head);
                break;
            case 4:
                head = negtive_link(head);
                break;
            case 5:
                counts = list_len(head);
                cout << counts;
                break;
            default:
                break;
        }
        cout << "输入一下数字继续操作：\n" << "0:退出  1：插入数据  2：删除数据  3：对链表排序  4：将链表逆序  5：查看链表个数" << endl;
        traversal(head);
    }
    return 0;
}
//上面是用的struct,下面的方式是使用class方法
#include <iostream>
#include <assert.h>
using namespace std;

class List
{
public:
    int num;
    class List *next;
    void create();
    void print();
    void find();
    void insert();
    void dele();
    void choose();
};
typedef List Node;
typedef Node *Link;
Link top, p, s;
void List::choose() {
    List List1;
    int r;
    bool toD = true;
    while(toD){
        cout << "1, input data create a new table" << endl;
        cout << "2, print the table" << endl;
        cout << "3, find a digital in the table" << endl;
        cout << "4, insert digital in the table" << endl;
        cout << "5, delete the digital in the table" << endl;
        cin >> r;
        switch (r){
            case 1:
                List1.create();
                break;
            case 2:
                List1.print();
                break;
            case 3:
                List1.find();
                break;
            case 4:
                List1.insert();
                break;
            case 5:
                List1.dele();
                break;
            default:
                toD = false;
        }
    }
}
void List::create() {
    int c = 1;
    top = new Node;
    (*top).next = NULL;
    p = top;
    cout << "please enter a num, enter 0 if you want to return" << endl;
    while(c != 0){
        cin >> c;
        if(c == 0){
            break;
        }
        s = new Node;
        s->num = c;
        (*p).next = s;
        (*s).next = NULL;
        p = (*p).next;
    }
    print();
}
void List::print()
{
    if(top == NULL){
        cout << "list is none" << endl;
        return;
    }
    p = (*top).next;
    while(p){
        cout << (*p).num << ' ';
        p = (*p).next;
    }
    cout << endl;
}
void List::find()
{
    int i;
    p = (*top).next;
    cout << "enter the num you want to find" << endl;
    cin >> i;
    while((*p).num != i && p != NULL){
        p = (*p).next;
    }
    if(p == NULL){
        cout << "not such data";
    }
    else
    {
        cout << (*p).num;
    }
    cout << endl;
}
void List::insert()
{
    assert(top != NULL);
    p = new Node;
    cout << "enter the num you want to insert:" << endl;
    cin >> (*p).num;
    (*p).next = (*top).next;
    (*top).next = p;
    print();
}
void List::dele()
{
    assert(top != NULL);
    int i;
    Link q;
    cout << "enter the num you to delete" << endl;
    cin >> i;
    p = top;
    q = (*top).next;
    while(q){
        if((*q).num == i){
            (*p).next = (*q).next;
            free(q);
            cout << "delete successfully" << endl;
            print();
            return;
        }
        else{
            q = (*q).next;
            p = (*p).next;
        }
    }
    print();
    cout << "not such data" << endl;
}
int main(void){
    List List1;
    List1.choose();
    return 0;
}
