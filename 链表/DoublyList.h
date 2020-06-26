#include "SingleList.h"

// 写个内部类，SingleList<T>::first指针就可以用了

// 双链表
template <typename T>
class DoublyList : public SingleList<T>{
    
    public:

  
    public:

      DoublyList() {
        SingleList<T>::first = new   Node<T>();
    }

    // 尾插法初始化
    DoublyList(T data[] ,int n){
        
     SingleList<T>::first = new Node<T>();
    
          Node<T> *s ;

          Node<T> *p = SingleList<T>::first;

     for (int i = 0; i < n; i++){

         s = new  Node<T>();

         s->data = data[i];

         s->next = NULL;

         s->pre = p;

         p->next = s;

         p = s;

        }
        
    }

     T erase (int n){

             if(n <= 0 ){

             throw "删除位置出错";
         }

              Node<T> *p = SingleList<T>::first ;

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

                 p->next->pre = NULL;

                 p->next = s;

                 s->pre = p;

                 return data;
            }

            p = p->next;
        }

        throw "删除位置出错";
     }

     bool insert(int n , T data){

                  if(n <= 0 || n > this->len() + 1 ){

             throw "插入位置出错";
         }

              Node<T> *p = SingleList<T>::first ;

         int index = 0;

         while (p->next != NULL)
         {

             // 此时p是待删除节点的前节点

             index++;

             if (index == n)
             {
                      Node<T> *s = p->next;

                 p->next = new      Node<T>();

                  p->next->data = data;

                  p->next->pre = p;

                  p->next->next = s;

                  s->pre = p->next;

                  return true;
            }

            p = p->next;
        }

        p->next = new  Node<T>();

        p->next->pre = p;

        p->next->data = data;

        return true;

     }

};