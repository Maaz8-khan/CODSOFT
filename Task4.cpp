#include <iostream>
#include <string>
using namespace std;

class List
{
public:
    string description;
    string status;

    List() {}
    List(string description, string status)
    {
        this->description = description;
        this->status = status;
    }
};

class Node
{
public:
    List l;
    Node *nxtptr;

    Node() : nxtptr(nullptr) {}
    Node(const List &list) : l(list), nxtptr(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->nxtptr;
            delete current;
            current = next;
        }
    }

    void Insert_Node(const List &l)
    {
        Node *newNode = new Node(l);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->nxtptr != nullptr)
        {
            temp = temp->nxtptr;
        }
        temp->nxtptr = newNode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << endl;
            cout << temp->l.description << " - " << temp->l.status << endl;
            temp = temp->nxtptr;
        }
    }

    void mark_completed(const string &task)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->l.description == task)
            {
                temp->l.status = "completed";
                return;
            }
            temp = temp->nxtptr;
        }
        cout << "Task not found" << endl;
    }

    void remove(const string &task)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->l.description == task)
        {
            Node *temp = head;
            head = head->nxtptr;
            delete temp;
            return;
        }

        Node *prev = nullptr;
        Node *current = head;

        while (current != nullptr && current->l.description != task)
        {
            prev = current;
            current = current->nxtptr;
        }

        if (current == nullptr)
        {
            cout << "Task not found" << endl;
            return;
        }

        prev->nxtptr = current->nxtptr;
        delete current;
    }
};

int main()
{
    LinkedList list;
    int choice;
    string task;
    string status;

    do
    {
        cout << endl;
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, task);
            cout << "Enter task status: ";
            getline(cin, status);
            list.Insert_Node(List(task, status));
            break;

        case 2:
            cout << "Tasks:" << endl
                 << endl;
            list.display();
            break;
        case 3:

            cout << endl << "Enter task description to mark as completed: ";
            cin.ignore();
            getline(cin, task);
            list.mark_completed(task);
            break;
        case 4:
            cout << endl
                 << "Enter task description to remove: ";
            cin.ignore();
            getline(cin, task);
            list.remove(task);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
