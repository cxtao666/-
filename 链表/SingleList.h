#include <iostream>

using namespace std;

/* 
 线性表从位置1开始的
 */

/* 
有头节点
 建立链表
 清楚链表
 添加节点   头插法  尾插法
 删除节点
 修改对应位置的节点 
 查找对应位置的节点
 返回链表的长度
 链表的初始化
 按值查找
 遍历打印
 判空
 */


  template <typename S>
    class Node{
     public:
     S data;
     Node *next = NULL;
     Node *pre = NULL;
};

//first 指针不能动
template <typename T>
class SingleList{

public:


    SingleList(){
        first = new Node<T>;
    }

    // 尾插法初始化
    SingleList(T data[] ,int n){
        
     first = new Node<T>;
    
     Node<T> *s ;

     Node<T> *p = first;

     for (int i = 0; i < n; i++){

         s = new Node<T>;

         s->data = data[i];

         s->next = NULL;

         p->next = s;

         p = s;

        }
        
    }

    void  printflist(){

        Node<T> *p = first->next;

        while(p != NULL){

            cout << p->data << " ";

            p = p->next;
        }

        cout << endl;
    }

    bool clean(){

        if(first->next != NULL){
            delete first;
            first = new Node<T>;
        }
         return true;
    }

    bool isEmpty(){

        if(first->next == NULL){
            return true;
        }
        return false;
    }

    int len(){

        int lenght = 0;

        Node<T> *p = first->next;

        while(p != NULL){
            lenght++;
            p = p->next;
        }

        return lenght;
    }

    Node<T>* find(T n){

         Node<T> *p = first->next;

        while(p != NULL){
            
            if(p->data == n){
                return p;
            }

            p = p->next;
        }

        return NULL;
    }
     
     T findIndex(int n){

         if(n <= 0 ){

             throw "查找位置出错";
         }

         Node<T> *p = first->next;

         int index = 0;

         while (p != NULL)
         {

             index++;

             if (index == n)
             {
                 return p->data;
            }

            p = p->next;
        }

        throw "查找位置出错";
     }

      bool change(int n , T data){

         if(n <= 0 ){

             throw "修改位置出错";
         }

         Node<T> *p = first->next;

         int index = 0;

         while (p != NULL)
         {

             index++;

             if (index == n)
             {
                 p->data = data;
                 return true;
            }

            p = p->next;
        }

        throw "修改位置出错";
     }  

     T erase (int n){

            if(n <= 0 ){

             throw "删除位置出错";
         }

         Node<T> *p = first ;

         int index = 0;

         while (p->next != NULL)
         {

             // 此时p是待删除节点的前节点

             index++;

             if (index == n)
             {
                 Node<T> *s = p->next->next;

                 T data = p->next->data;

                 p->next->next = NULL;

                 p->next = s;

                 return data;
            }

            p = p->next;
        }

        throw "删除位置出错";
     }

     bool insert(int n , T data){

              if(n <= 0 || n > len() + 1 ){

             throw "插入位置出错";
         }

         Node<T> *p = first ;

         int index = 0;

         while (p->next != NULL)
         {

             // 此时p是待删除节点的前节点

             index++;

             if (index == n)
             {
                 Node<T> *s = p->next;


                 p->next = new Node<T>;

                  p->next->data = data;

                 p->next->next = s;

                 return true;
            }

            p = p->next;
        }

        p->next = new Node<T>;

        p->next->data = data;

        return true;
     }


protected:

    Node<T> *first; // first节点的数据域不存在
};
