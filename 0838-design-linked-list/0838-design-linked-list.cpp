class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head;
        for (int sample = 0; sample < index; sample++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
       Node* newNode = new Node(val);
       newNode->next = head;
       head = newNode;
       size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
        head = newNode;
        }
        else{ 
        Node* temp = head;   
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next= newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
         Node* newNode = new Node(val);
        if (index == 0) {
        newNode->next = head;
        head = newNode;
         }
        else{
        Node* temp1 = head;
        for (int i = 0; i < index - 1; i++) {
            temp1 = temp1->next;
        }
        newNode->next = temp1->next;
        temp1->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* temp=head;
        if (index == 0) {
        head = head->next;
        delete temp;
        }
        else{
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
         Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */