#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "EngineInitializer.h"
#include "Point2D.h"
#include "test.cpp"
void PlayerStart(char* playername);
void MonsterLogic();
int i;
GritEngine::Point2D playerposition;
int monsternumber = 0;
class Node{
    public:
        char* MonsterName  ;
        Node* Next ;
        GritEngine::Point2D monsterposition;
        ~Node() {
            delete[] (MonsterName);
        }
};
Node* mainhead = NULL;
Node* head = NULL;
void deleteallmonsters(Node* mainhead);
void MonsterStart(Node* mainhead);
Node* pushh(Node* head, char* monstername);
int main()
{
    {
        GritEngine::initialize();
        GritEngine::Point2DUnitTest();
        //_CrtSetBreakAlloc(300);
        std::cout << "Enter the number of monsters you want \n";
        std::cin >> monsternumber;
        for (int k = 0; k < monsternumber; k++)
        {
            char* MN = new char[10];
            std::cout << "Enter the name of monster you want \n";
            std::cin >> MN;
            if (mainhead == NULL) {
                mainhead = new Node();
                mainhead->MonsterName = MN;
                head = mainhead;
            }
            else {
                head = pushh(head, MN);
            }

        }
        char* Playername = new char[10];
        std::cout << "Enter your name: \t";
        std::cin >> Playername;
        PlayerStart(Playername);
        MonsterLogic();
        delete[] Playername;
        char a = 'a';
        while (a != 'q')
        {
            GritEngine::Point2D x(1, 0);
            GritEngine::Point2D y(0, 1);
            std::cout << "Select WASD to move your player or Q to quit \n";
            std::cin >> a;
            switch (a) {
            case 'W':
            case 'w':
                std::cout << "New Player Position is:" << std::endl;
                playerposition += y;
                std::cout << playerposition.x() << "\t";
                std::cout << playerposition.y() << std::endl;
                MonsterLogic();
                break;

            case 'S':
            case 's':
                std::cout << "New Player Position is:" << std::endl;
                playerposition -= y;
                std::cout << playerposition.x() << "\t";
                std::cout << playerposition.y() << std::endl;
                MonsterLogic();
                break;
            case 'D':
            case 'd':
                std::cout << "New Player Position is:" << std::endl;
                playerposition += x;
                std::cout << playerposition.x() << "\t";
                std::cout << playerposition.y() << std::endl;
                MonsterLogic();
                break;
            case 'A':
            case 'a':
                std::cout << "New Player Position is:" << std::endl;
                playerposition -= x;
                std::cout << playerposition.x() << "\t";
                std::cout << playerposition.y() << std::endl;
                MonsterLogic();
                break;
            case 'Q':
            case 'q':
                a = 'q'; deleteallmonsters(mainhead);
                break;
            }
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
void deleteallmonsters(Node* mainhead)
{

    Node* temp = mainhead;
    while (mainhead != NULL)
    {
        std::cout << mainhead->MonsterName << std::endl;
        mainhead = mainhead->Next;
        delete temp;
        temp = mainhead;
    }
}

void PlayerStart(char* playername)
{
    playerposition.setposition(playerposition.generatex(), playerposition.generatey());
    std::cout << " Position of " << playername << ": " << playerposition.x() << "\t" << playerposition.y() << "\n";
}


Node* pushh(Node* tail, char* monstername)
{
    Node* newnode = new Node();
    newnode->MonsterName = monstername;
    tail->Next = newnode;
    return newnode;
}

void MonsterStart(Node* mainhead)
{
    Node* temp = mainhead;
    temp->monsterposition.setposition(temp->monsterposition.generatex(), temp->monsterposition.generatey());
    std::cout << "Monster " << temp->MonsterName << " is at:" << "\n" << temp->monsterposition.x() << "\t" << temp->monsterposition.y() << "\n"; 
}

void MonsterLogic()
{
    int randomint;
    Node* temporary; 
    temporary = mainhead;
    
    for (i = 1; i <= monsternumber; i++)
    {
        if (playerposition.x() == temporary->monsterposition.x() && playerposition.y() == temporary->monsterposition.y())
        {
            std::cout << "GAME OVER\n";
            break;
        }
        else
        {
            MonsterStart(temporary);
            temporary = temporary->Next;
        }
    }
    randomint = rand();
    if (randomint % 100 <= 5 && monsternumber>1)
    {
        std::cout << "A monster was killed\n";
        Node* tempp = mainhead; 
        mainhead = mainhead->Next;
        monsternumber--;
        delete tempp;
    }
    else if (randomint % 100 >= 95)
    {
        char* bots = new char[10]{ "vader" };
        if (monsternumber < 10)
        {
            std::cout << "A monster was added\n";
            Node* newnode = new Node();
            head->Next = newnode;
            newnode->MonsterName = bots;
            head = newnode;
            monsternumber++;
        }
        else
        {
            delete[] bots;
        }

    }
}