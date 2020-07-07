#include <stdlib.h>
using namespace std;
#ifndef ex3
#define ex3

template <class T>
class node
{
    public:
    T key;
    node* next;
    node* previous;
    node(T key); 
    node();
    ~node(); 
};
template <class T>
node<T>::node()
{
    
}
template <class T>
node<T>::node(T data)
{
    this->key=data;
    
}
template <class T>
node<T>::~node()
{

}
template <class T>
class list
{
    private:
    T* head;
    T* tail;
    int listSize;
    public:
    list();                                                  //Done
    ~list();                                                 //Done
    T* begin();                                              //Done, tested
    T* end();                                                //Done, tested
    T& front();                                              //Done, tested
    T& back();                                               //Done, tested
    bool empty();                                            //Done, tested
    int size();                                              //Done, tested
    void clear();                                            //Done, tested
    void insert(T* headNode, int position);                  //Done, tested. position start on number 0, which is 1 right of head
    void erase(int position);                                //Done, tested
    void push_back(T* newNode);                              //Done, tested
    void push_front(T* newNode);                             //Done, tested
    void pop_back();                                         //Done, tested
    void pop_front();                                        //Done, tested
    void print();                                            //Testing purposes
};
template <class T>
list<T>::list()
{
    this->head=NULL;
    this->tail=NULL;
    
}

template <class T>
list<T>::~list()
{
    while(this->head!=nullptr)
    {
        T* next = this->head->next;
        delete this->head;
        this->head=next;
    }
    
}
template <class T>
void list<T>::print() {
	cout << "Current List: ";
	T* temp = this->head;
	while(temp) {
		cout << " -> "<< temp->key;
		temp = temp->next;
	}
	cout <<endl;
}

template <class T>
T* list<T>::begin()
{
    return this->head;
}
template <class T>
T* list<T>::end()
{
    return this->tail;
}
template <class T>
T& list<T>::front()
{
    return *(this->head);
}
template <class T>
T& list<T>::back()
{
    return *(this->tail);
}
template <class T>
bool list<T>::empty()
{
    if(this->head==nullptr)
    {
        return true;
    }
    return false;
}
template <class T>
int list<T>::size()
{
    int tempSize=0;
    T* temp = this->head;
    while(temp!=nullptr)
    {
        tempSize++;
        temp=temp->next;
    }
    this->listSize=tempSize;
    return this->listSize;
}
template <class T>
void list<T>::clear()
{
    T* current = this->head;
    T* next;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
        
    }
    this->head=NULL;
    
}
template <class T>
void list<T>::insert(T* newNode, int position)
{
    
    T* current = this->head;
    int iter=0;
    while(iter!=position&&current!=NULL)
    {
        current=current->next;
        iter++;
    }
    
    if(iter==0)
    {
        push_front(newNode);
        return;
    }
    if(current==NULL)
    {
        push_back(newNode);
        return;
    }
    T* temp = newNode;
    T* prev = this->head;
    T* next = this->head->next;

    for (int i = 0; i < position; i++)
    {
        prev = prev->next;
        next = next->next;
    }
    prev->next = temp;
    next->previous = temp;
    temp->previous = prev;
    temp->next = next;
    
    
    
}
template <class T>
void list<T>::erase(int position)
{
    int iter=0;
    T* current = this->head;
    
    while(iter!=position&&current!=NULL)
    {
        current=current->next;
        iter++;
    }
    if(current!=NULL)
    {
        //std::cout<<"At position "<<position<<" key is: "<<current->key<<endl;
        if(current==this->head) //node to delete is head
        {
            this->head=current->next;
        }
        if(current->next!=NULL)
        {
            current->next->previous=current->previous;
        }
        if(current->previous!=NULL)
        {
            current->previous->next=current->next;
        }
        free(current);
    }
    else
    {
        std::cout<<"Key not found"<<endl;
    }
}
template <class T>
void list<T>::push_back(T* newNode)
{
    newNode->next=nullptr;
    newNode->previous=nullptr;
    if(this->head==nullptr)
    {
        this->head=newNode;
        this->tail=this->head;
    }
    else
    {
        this->tail->next=newNode;
        newNode->previous=this->tail;
        this->tail=newNode;
    }
}
template <class T>
void list<T>::push_front(T* newNode)
{
    newNode->next=nullptr;
    newNode->previous=nullptr;
    if(this->head==nullptr)
    {
        this->head=newNode;
        this->tail=this->head;
    }
    else
    {
        this->head->previous=newNode;
        newNode->next=this->head;
        this->head=newNode;
    }
}
template <class T>
void list<T>::pop_back()
{
    T* temp = this->tail;
    this->tail=this->tail->previous;
    this->tail->next=nullptr;
}
template <class T>
void list<T>::pop_front()
{
    T* temp = this->head;
    this->head=this->head->next;
    this->head->previous=nullptr;
}
#endif