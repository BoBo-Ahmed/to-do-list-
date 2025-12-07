#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void addTask(int id, string title, string description, string status)
    {
        Node *newNode = new Node(id, title, description, status);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Task added successfully: " << title << endl;
    }

    void editTask(int id, string newTitle, string newDescription, string newStatus)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to edit." << endl;
            return;
        }

        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->title = newTitle;
                temp->description = newDescription;
                temp->status = newStatus;
                found = true;
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }

    void displayAllTasks()
    {
        Node *temp = head;
        cout << "\n--- To-Do List ---" << endl;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << " | Title: " << temp->title
                 << " | Status: " << temp->status << endl;
            temp = temp->next;
        }
        cout << "\n-----------------------------------------------\n"
             << endl;
    }
int countTasks()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
void deleteTask(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        
        if (head->id == id)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Task with ID " << id << " has been deleted." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                prev->next = temp->next;
                delete temp;
                found = true;
                cout << "Task with ID " << id << " has been deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }
void deleteAllTasks()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
        cout << "All tasks have been deleted." << endl;
    }
void markAsDone(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to mark as done." << endl;
            return;
        }

        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->status = "done";
                found = true;
                cout << "Task ID " << id << " has been marked as done." << endl;
                return;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task ID " << id << " not found." << endl;
        }
    }
    // Masry
    void searchTaskID(int id)
    {
        if (head == NULL)
        {
            cout << "\n The List is Empty, Nothing to Search for!" << endl;
            return;
        }
        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "ID: " << temp->id << " | Title: " << temp->title
                     << " | Status: " << temp->status << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }
};
#endif
