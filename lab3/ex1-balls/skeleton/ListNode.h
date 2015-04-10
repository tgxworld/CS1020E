class ListNode {
private:
  int _value;
  ListNode* _next;
  ListNode* _prev;
public:
  ListNode(int value);
  ListNode* getNext();
  ListNode* getPrev();
  void setNext(ListNode* ptr);
  void setPrev(ListNode* ptr);
  void setValue(int value);
  int getValue();
};
