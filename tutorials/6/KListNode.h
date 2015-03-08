#ifndef k_list_node_h
#define k_list_node_h

class KListNode {
  private:
    int _item;
    int _k;
    KListNode* _kNext;
    KListNode* _next;
  public:
    KListNode(int item, int k);
    int getItem();
    KListNode* getKNext();
    KListNode* getNext();
    void setKNext(KListNode* listNode);
    void setNext(KListNode* listNode);
};

#endif
