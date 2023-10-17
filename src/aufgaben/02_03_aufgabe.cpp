#include <iostream>
#include <vector>

// Node Klasse für single linked list
class Node
{
public:
    int daten_;
    Node *next_;

    // Default Konstruktor
    Node()
    {
        daten_ = 0;
        next_ = NULL;
    }

    // Daten Konstruktor
    Node(int daten)
    {
        daten_ = daten;
        next_ = NULL;
    }
    int TailElements(){
        int count = 0;
        for (Node *AktuellesElement = this; AktuellesElement != NULL; AktuellesElement = AktuellesElement->next_)
        {
            count++;
        }
        return count;
    }
};

void ausgabeSingleLinkedList(Node *head)
{
    // todo implentieren der Ausgabefunktion
    std::cout << "Ausgabe Single Linked List" << std::endl;
    for (Node *AktuellesElement = head; AktuellesElement != NULL; AktuellesElement = AktuellesElement->next_)
    {
        std::cout << AktuellesElement->daten_ << "->";
    }
    std::cout << "NULL" << std::endl;
}

Node *loescheNLetztesElement(Node *head, int index)
{
    // todo implentieren der Loeschfunktion
    int count = head->TailElements();
    int NLetzeselement = count - index;
    count = 1;
    Node *AktuellesElement;

    for(AktuellesElement = head; AktuellesElement != NULL && count < NLetzeselement; AktuellesElement = AktuellesElement->next_)
        count++;
    
    if(AktuellesElement==NULL) return head;
    if(AktuellesElement->next_==NULL) return head;
    
    Node *NaechstesElement = AktuellesElement->next_->next_;
    delete AktuellesElement->next_;
    AktuellesElement->next_ = NaechstesElement;

    return head;
}

int main()
{
    int element_offset = 3;

    Node *head = new Node(0);
    Node *aktuelles_element = head;

    // anlegen von single linked list mit 10 Elementen
    for (int i = 1; i < 10; i++)
    {
        Node *new_node = new Node(i);
        aktuelles_element->next_ = new_node;
        aktuelles_element = new_node;
    }
    ausgabeSingleLinkedList(head); // Daten von 0 bis 9 werden ausgegeben

    loescheNLetztesElement(head, element_offset);

    ausgabeSingleLinkedList(head); // Daten ohne element offset werden ausgegeben

    // aufraumen single linked list
    aktuelles_element = head;
    while (aktuelles_element != NULL)
    {
        Node *naechstes_element = aktuelles_element->next_;
        delete aktuelles_element;
        aktuelles_element = naechstes_element;
    }

    return 0;
}