#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

};
void addWord (Node*& head, string word){
    Node* newNode = new Node();
    newNode->data = word;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


}
void undo(Node*& head){
    if (head == NULL) {
        cout<<"There are no words to delete!"<<endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    cout << "Last word deleted." << endl;

}
void display (Node* head){
    Node* temp = head;
    cout << "\nEditor: ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    string input;

    cout<<"---Single Linked List---"<< endl;
    cout<<"Enter a word..."<< endl;
    cout<<"To undo, type UNDO; to exit, type EXIT.\n"<< endl;

    while (true) {
        cout << "Enter a word: ";
        cin >> input;

        if (input == "EXIT") {
            cout << "Exiting to program..." << endl;
            break;
        }
        else if (input == "UNDO") {
            undo(head);
        }
        else {
            addWord(head, input);
        }
        display(head);
    }



    return 0;
}
