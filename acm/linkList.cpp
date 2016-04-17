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
