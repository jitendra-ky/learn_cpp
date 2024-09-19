#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void print_list()
    {
        Node *cur_node = head;
        while (cur_node)
        {
            cout << cur_node->data << " ";
            cur_node = cur_node->next;
        }
        cout << endl;
    }

    void append(int data)
    {
        Node *new_node = new Node(data);

        if (!head)
        {
            head = new_node;
            return;
        }

        Node *last_node = head;
        while (last_node->next)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    void prepend(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insert_after_node(Node *prev_node, int data)
    {
        if (!prev_node)
        {
            cout << "Previous node does not exist." << endl;
            return;
        }

        Node *new_node = new Node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    void delete_node(int key)
    {
        Node *cur_node = head;
        Node *prev = nullptr;

        if (cur_node && cur_node->data == key)
        {
            head = cur_node->next;
            delete cur_node;
            return;
        }

        while (cur_node && cur_node->data != key)
        {
            prev = cur_node;
            cur_node = cur_node->next;
        }

        if (!cur_node)
            return;

        prev->next = cur_node->next;
        delete cur_node;
    }

    void delete_node_at_pos(int pos)
    {
        if (!head)
            return;

        Node *cur_node = head;

        if (pos == 0)
        {
            head = cur_node->next;
            delete cur_node;
            return;
        }

        Node *prev = nullptr;
        int count = 1;
        while (cur_node && count != pos)
        {
            prev = cur_node;
            cur_node = cur_node->next;
            count++;
        }

        if (!cur_node)
            return;

        prev->next = cur_node->next;
        delete cur_node;
    }

    int len_iterative()
    {
        int count = 0;
        Node *cur_node = head;
        while (cur_node)
        {
            count++;
            cur_node = cur_node->next;
        }
        return count;
    }

    int len_recursive(Node *node)
    {
        if (!node)
            return 0;
        return 1 + len_recursive(node->next);
    }

    void reverse_iterative()
    {
        Node *prev = nullptr;
        Node *cur = head;
        Node *next = nullptr;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    Node *reverse_recursive(Node *cur, Node *prev = nullptr)
    {
        if (!cur)
            return prev;

        Node *next = cur->next;
        cur->next = prev;
        return reverse_recursive(next, cur);
    }

    void reverse_recursive_helper()
    {
        head = reverse_recursive(head);
    }

    LinkedList *merge_sorted(LinkedList *llist)
    {
        Node *p = head;
        Node *q = llist->head;
        Node *s = nullptr;

        LinkedList *merged_list = new LinkedList();

        if (!p)
            return llist;
        if (!q)
            return this;

        if (p->data <= q->data)
        {
            s = p;
            p = p->next;
        }
        else
        {
            s = q;
            q = q->next;
        }
        merged_list->head = s;

        while (p && q)
        {
            if (p->data <= q->data)
            {
                s->next = p;
                s = p;
                p = s->next;
            }
            else
            {
                s->next = q;
                s = q;
                q = s->next;
            }
        }

        if (!p)
            s->next = q;
        if (!q)
            s->next = p;

        return merged_list;
    }

    void remove_duplicates()
    {
        Node *cur = head;
        Node *prev = nullptr;
        unordered_map<int, int> dup_values;

        while (cur)
        {
            if (dup_values.count(cur->data))
            {
                prev->next = cur->next;
                delete cur;
            }
            else
            {
                dup_values[cur->data] = 1;
                prev = cur;
            }
            cur = prev->next;
        }
    }

    int print_nth_from_last(int n)
    {
        int total_len = len_iterative();
        Node *cur = head;

        while (cur)
        {
            if (total_len == n)
                return cur->data;
            total_len--;
            cur = cur->next;
        }
        return -1; // In case the node is not found
    }

    void rotate(int k)
    {
        if (!head || !head->next)
            return;

        Node *p = head;
        Node *q = head;
        Node *prev = nullptr;
        int count = 0;

        while (p && count < k)
        {
            prev = p;
            p = p->next;
            q = q->next;
            count++;
        }

        p = prev;
        while (q)
        {
            prev = q;
            q = q->next;
        }
        q = prev;

        q->next = head;
        head = p->next;
        p->next = nullptr;
    }

    int count_occurences_iterative(int data)
    {
        int count = 0;
        Node *cur = head;
        while (cur)
        {
            if (cur->data == data)
                count++;
            cur = cur->next;
        }
        return count;
    }

    int count_occurences_recursive(Node *node, int data)
    {
        if (!node)
            return 0;
        if (node->data == data)
            return 1 + count_occurences_recursive(node->next, data);
        else
            return count_occurences_recursive(node->next, data);
    }

    bool is_palindrome()
    {
        string s = "";
        Node *p = head;
        while (p)
        {
            s += to_string(p->data);
            p = p->next;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    void move_tail_to_head()
    {
        if (!head || !head->next)
            return;

        Node *last = head;
        Node *second_to_last = nullptr;

        while (last->next)
        {
            second_to_last = last;
            last = last->next;
        }

        last->next = head;
        second_to_last->next = nullptr;
        head = last;
    }

    void sum_two_lists(LinkedList *llist)
    {
        Node *p = head;
        Node *q = llist->head;

        LinkedList *sum_llist = new LinkedList();
        int carry = 0;

        while (p || q)
        {
            int i = (p) ? p->data : 0;
            int j = (q) ? q->data : 0;

            int s = i + j + carry;
            carry = s / 10;
            int remainder = s % 10;
            sum_llist->append(remainder);

            if (p)
                p = p->next;
            if (q)
                q = q->next;
        }
        sum_llist->print_list();
    }
};

int main()
{
    LinkedList llist1, llist2;

    llist1.append(5);
    llist1.append(6);
    llist1.append(3);

    llist2.append(8);
    llist2.append(4);
    llist2.append(2);

    cout << 365 + 248 << endl; // Expected sum: 613
    llist1.sum_two_lists(&llist2);

    return 0;
}
