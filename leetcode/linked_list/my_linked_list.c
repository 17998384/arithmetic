//
// Created by 我叫城北徐公° on 2021/5/17.
//

//  707. 设计链表

//  设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
//
//  在链表类中实现这些功能：
//
//  get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
//  addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//  addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//  addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//  deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
//
//
//  示例：
//
//  MyLinkedList linkedList = new MyLinkedList();
//  linkedList.addAtHead(1);
//  linkedList.addAtTail(3);
//  linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
//  linkedList.get(1);            //返回2
//  linkedList.deleteAtIndex(1);  //现在链表是1-> 3
//  linkedList.get(1);            //返回3
//
//
//
//  提示：
//
//  所有val值都在 [1, 1000] 之内。
//  操作次数将在  [1, 1000] 之内。
//  请不要使用内置的 LinkedList 库。


#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int val;
    Node* next;
    Node* prev;
};

typedef struct
{
    Node* head;
    Node* tail;
    int size;
} MyLinkedList;

static Node* new_node(int val)
{
    Node* node = calloc(1, sizeof(Node));
    node->val = val;
    return node;
}

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate()
{
    return calloc(1, sizeof(MyLinkedList));
}

static Node* find_node(MyLinkedList* obj, int index)
{
    if (index < 0 || index >= obj->size) return NULL;
    int size;
    //如果大于一半，则从后半部分找
    if (index > (size = (obj->size >> 1)))
    {
        Node* tail = obj->tail;
        for (int i = obj->size - 1; i > size; --i, tail = tail->prev)
        {
            if (i == index) return tail;
        }
    }
        //否则从前半部分找
    else
    {
        Node* head = obj->head;
        for (int i = 0; i <= size; ++i, head = head->next)
        {
            if (i == index) return head;
        }
    }
    return NULL;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
    Node* tmp = obj->head;
    Node* findNode;
    int res = (findNode = find_node(obj, index)) ? findNode->val : -1;
    return res;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    Node* node = new_node(val);
    obj->size++;
    if (obj->head)
    {
        node->next = obj->head;
        obj->head->prev = node;
        obj->head = node;
        return;
    }
    obj->head = obj->tail = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    Node* node = new_node(val);
    obj->size++;
    if (obj->tail)
    {
        obj->tail->next = node;
        node->prev = obj->tail;
        obj->tail = node;
        return;
    }
    obj->head = obj->tail = node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if (index > obj->size) return;
    else if (index == obj->size) myLinkedListAddAtTail(obj, val);
    else if (index < 0 || !obj->size || !index) myLinkedListAddAtHead(obj, val);
    else
    {
        Node* newNode = new_node(val);
        Node* findNode = find_node(obj, index);
        findNode->prev->next = newNode;
        newNode->prev = findNode->prev;
        newNode->next = findNode;
        findNode->prev = newNode;
        obj->size++;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (index >= obj->size || index < 0) return;
    Node* findNode = find_node(obj, index);
    if (!findNode) return;
    Node* prev = findNode->prev;
    Node* next = findNode->next;
    if (!prev) obj->head = next;
    else
    {
        prev->next = next;
        if (next) next->prev = prev;
    }
    if (!next) obj->tail = prev;
    else
    {
        next->prev = prev;
        if (prev) prev->next = next;
    }
    free(findNode);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj)
{
    Node* next = NULL;
    while (obj->head)
    {
        next = obj->head->next;
        free(obj->head);
        obj->head = next;
    }
    free(obj);
}
