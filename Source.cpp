#include <iostream>

using namespace std;

typedef int dataT;
typedef struct node* Po;
struct node {
    dataT data;
    Po left;
    Po right;
};

void treeBuilder(dataT);
void print(Po, int);
void Infix(Po);
Po DeleteNode(Po father, int x);
Po root = nullptr;

int main() {
    int number;

    cout << "Vuvedete chislo (ili -1 za da prikluchite): ";
    cin >> number;
    while (number != -1)
    {
        treeBuilder(number);

        cout << "Vuvedete oshte edno chislo (ili -1 za da prikluchite): ";
        cin >> number;
    }


    print(root, 5);
    Infix(root);
    
    cout << "Vuvedete chislo koeto da bude premahnato (ili -1 za da prikluchite): ";
    cin >> number;
    while (number != -1)
    {
        DeleteNode(root,number);

        cout << "Taka izglejda durvoto sled premahvaneto";
        print(root, 5);
        Infix(root);

        cout << "Vuvedete oshte edno chislo (ili -1 za da prikluchite): ";
        cin >> number;
    }

    return 0;
}

void treeBuilder(dataT x) {
    Po loc = root;
    Po insert = loc;

    if (root == nullptr)
    {
        loc = new node;
        loc->left = nullptr;
        loc->right = nullptr;
        loc->data = x;
        root = loc;
    }
    else {
        /*
        loc trqbva da spre kogato found == true
        ILI
        loc == nullptr
        */

        while (loc != nullptr && loc->data != x)
        {
            insert = loc;
            if (loc->data > x)
            {
                loc = loc->left;
            }

            else
            {
                loc = loc->right;
            }

        }
        if (loc != nullptr)
        {
            cout << "Elementyt be nameren!" << endl;
        }
        else {
            loc = new node;
            loc->data = x;
            loc->left = nullptr;
            loc->right = nullptr;

            if (loc->data > insert->data)
            {
                insert->right = loc;

            }
            else {
                insert->left = loc;
            }

        }
    }

}

void print(Po root, int space) {
    int COUNT = 10;
    if (root == nullptr)
        return;

    space += COUNT;
    print(root->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";
    print(root->left, space);
}

void Infix(Po help)
{
    if (help)
    {
        Infix(help->left);
        cout << help->data << " ";
        Infix(help->right);
    }
}

Po DeleteNode (Po father, int x)
{
    if (father == nullptr) {
        cout << " darvoto e prazno! " << endl;
        return father;
    }
    else
    {
        if (x < father->data)
        {
            father->left = DeleteNode(father->left, x);

        }
        else if (x > father->data)
        {
            father->right = DeleteNode(father->right, x);
        }
        else if (father->left == nullptr && father->right == nullptr)
        {
            delete father;
            father = nullptr;
            return father;
        }
        else if (father->left == nullptr)
        {
            Po temp = father;
            father = father->right;
            delete temp;
            return father;
        }
        else if (father->right == NULL)
        {
            Po temp = father;
            father = father->left;
            delete temp;
            return father;
        }

        else {

            Po temp = father;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            father->data = temp->data;
            father->left = DeleteNode(father->left, temp->data);



        }
        return father;
    }
}