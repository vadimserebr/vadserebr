//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct Node
{
	int number;
	Node *Next, *Prev;
};

struct Node—py
{
	int numberCpy;
	Node—py *Next—py, *Prev—py;
};

class Queue
{
	Node *Head, *Tail;
	Node—py *Head—py, *Tail—py;
public:
	Queue(): Head(NULL), Tail(NULL), Head—py(NULL), Tail—py(NULL) {}//Constructor
	~Queue();//Destructor
	void Show(); //Function of displaying the list on the screen
	void Show—py();//The function of displaying split lists
	void Add(int x); //The function of adding items to the list
	void Devide(); //The function of dividing the list into two
	void delete_unit(Node* temp);//Function of removing an item from the list
};

Queue::~Queue()
{
	while (Head)
	{
	   Tail = Head->Next;
	   delete Head;
	   Head = Tail;
	}
}

void Queue::Add(int number)
{
	Node *temp = new Node;
	temp->Next = NULL;
	temp->number = number;
	if (Head != NULL)
	{
	   temp->Prev = Tail;
	   Tail->Next = temp;
	   Tail = temp;
	}
	else
	{
	   temp->Prev = NULL;
	   Head = Tail = temp;
	}
}

void Queue::Show()
{
	Node *temp = Tail;
	temp = Head;
	while (temp != NULL)
	{
	   Form1->Memo1->Lines->Add(temp->number);
	   temp = temp->Next;
	}
}

void Queue::Devide()
{
	Node *temp = Tail;
	temp = Head;
	while (temp != NULL)
	{
	  if ((temp->number) < 0)
	  {
		 Node—py *temp—py = new Node—py;
		 temp—py->Next—py = NULL;
		 temp—py->number—py = temp->number;
		 if (Head—py != NULL)
		 {
			 temp—py->Prev—py = Tail—py;
			 Tail—py->Next—py = temp—py;
			 Tail—py = temp—py;
		 }
		 else
		 {
			 temp—py->Prev—py = NULL;
			 Head—py = Tail—py = temp—py;
		 }
		delete_unit(temp);
	  }
	  temp = temp->Next;
	}
}

void Queue::Show—py()
{
	Node *temp = Tail;
	Node—py *temp—py = Tail—py;
	temp = Head;
	while (temp != NULL)
	{
	   Form1->Memo1->Lines->Add(temp->number);
	   temp = temp->Next;
	}
	temp—py = Head—py;
	while (temp—py != NULL)
	{
	   Form1->Memo2->Lines->Add(temp—py->number—py);
	   temp—py = temp—py->Next—py;
	}
}

void Queue::delete_unit(Node* temp)
{
	if (temp == Head)
	{
		Head = Head->Next;
		Head->Prev = NULL;
	}
	else if (temp == Tail)
	{
		Tail = Tail->Prev;
		Tail->Next = NULL;
	}
	else
	{
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
	}
}

int n;
Queue ob;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)//When the button is pressed, it fills the list with random numbers
{
	   int amount = StrToInt(Edit1->Text);
	   for (int i = 0; i < amount; i ++)
	   {
		   int number = float (rand() % 20000) / 100 - 100;
		   ob.Add(number);
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//When the button is pressed, it displays the initial list
{
	   Memo1->Clear();
	   ob.Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)//When the button is pressed, it displays a divided list
{
	   Memo1->Clear();
	   Memo2->Clear();
	   ob.Show—py();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)//When you press the button, it splits the original list into two
{
	   ob.Devide();
}
//---------------------------------------------------------------------------

