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

struct NodeCpy
{
	int numberCpy;
	NodeCpy *NextCpy, *PrevCpy;
};

class Queue
{
	Node *Head, *Tail;
	NodeCpy *HeadCpy, *TailCpy;
public:
	Queue(): Head(NULL), Tail(NULL), HeadCpy(NULL), TailCpy(NULL) {}//Constructor
	~Queue();//Destructor
	void Show(); //Function of displaying the list on the screen
	void ShowCpy();//The function of displaying split lists
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
		 NodeCpy *tempCpy = new NodeCpy;
		 tempCpy->NextCpy = NULL;
		 tempCpy->numberCpy = temp->number;
		 if (HeadCpy != NULL)
		 {
			 tempCpy->PrevCpy = TailCpy;
			 TailCpy->NextCpy = tempCpy;
			 TailCpy = tempCpy;
		 }
		 else
		 {
			 tempCpy->PrevCpy = NULL;
			 HeadCpy = TailCpy = tempCpy;
		 }
		delete_unit(temp);
	  }
	  temp = temp->Next;
	}
}

void Queue::ShowCpy()
{
	Node *temp = Tail;
	NodeCpy *tempCpy = TailCpy;
	temp = Head;
	while (temp != NULL)
	{
	   Form1->Memo1->Lines->Add(temp->number);
	   temp = temp->Next;
	}
	tempCpy = HeadCpy;
	while (tempCpy != NULL)
	{
	   Form1->Memo2->Lines->Add(tempCpy->numberCpy);
	   tempCpy = tempCpy->NextCpy;
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
	   ob.ShowCpy();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)//When you press the button, it splits the original list into two
{
	   ob.Devide();
}
//---------------------------------------------------------------------------

