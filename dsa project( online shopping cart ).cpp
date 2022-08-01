#include<iostream>
#include<stdlib.h> 


using namespace std; 


struct node
{
int itemID;
string itemName;
double price;
double purchaseQuanitity;
double totalPrice;
node *next;
};




class Cart
{
private:
node *head,*tail;
public: 


Cart()
{
head=NULL;
tail=NULL;
} 

int itemID;
string itemName;
double price;
double purchaseQuanitity;
double totalPrice;




void addToCart(int ID,string name,double pri,double purQuantity,double totalprice)
{
node *tmp=new node;
int p=0; 

if(head!=NULL)
{


node *t=new node;
t=head;


while(t!=NULL)
{
if(ID==t->itemID)
{
p=1;
}

t=t->next;
}



}



if(p==0)
{
tmp->itemID=ID;
tmp->itemName=name;
tmp->price=pri;
tmp->purchaseQuanitity=purQuantity;
tmp->totalPrice=tmp->totalPrice+totalprice;

tmp->next=NULL;

if(head==NULL)
{
head=tmp;
tail=tmp;
}

else
{
tail->next=tmp;
tail=tail->next;
}

}


else
{
cout<<"\t\t<<Already exites Item>>\n";
}

}

void removeFromCart(int m)
{
node *tmp,*pre;

tmp=head;


if(m==tmp->itemID)
{
head=head->next;
return;
}
else
{

while(tmp->itemID!=m)
{
pre=tmp;
tmp=tmp->next;
}
pre->next=tmp->next;
delete tmp;
}

}

void changeQuantity()
{
int y;


if(head==NULL)
{
cout<<"Cart is empty\n";
}
else
{

cout<<"Enter item ID to change Quantity\n";
cin>>y;

node *tmp=new node;
tmp=head;

while(tmp!=NULL)
{
if(y==tmp->itemID)
{
cout<<"Enter new Quantity amount\n";
cin>>tmp->purchaseQuanitity;
cout<<"\n new Quaitity is set to "<<tmp->purchaseQuanitity<<endl;
break;
}
tmp=tmp->next;
}
}

}


void viewCart()
{
node *tmp=new node;
tmp=head;
cout<<"\nItems ( Quantity )\n\n";
while(tmp!=NULL)
{
cout<<" "<<tmp->itemID<<" "<<tmp->itemName<<" ( "<<tmp->purchaseQuanitity<<" ) "<<"\n";
//cout<<" "<<tmp->itemID<<" ( "<<tmp->purchaseQuanitity<<" ) "<<"\n";
tmp=tmp->next;
}
}








void printBill()
{
int total=0,u=0;
node *tmp=new node;
tmp=head;
cout<<"\n\tItems ( Quantity ) ( Price per piece )\n\n";
while(tmp!=NULL)
{
cout<<" "<<tmp->itemName<<" ( "<<tmp->purchaseQuanitity<<" ) "<<"("<<tmp->price<<")"<<"\n";

u=tmp->price*tmp->purchaseQuanitity;
total=total+u;

tmp=tmp->next;
}
cout<<"\n\t Total Price: "<<total<<endl<<endl;

}

};

int menu()
{
int option;
cout<<"\n\nChose desire action by number:\n\n";
cout<<"1: Add item\n";
cout<<"2:Change Quantity\n";
cout<<"3:Delete Item\n";
cout<<"4:Display Complete Cart\n";
cout<<"5:Bill\n";
cout<<"6:Exit\n\n";
cin>>option;
return option;
}


int main()
{


int itemID;
string itemName;
double price;
double purchaseQuanitity;
double totalPrice=0;
int end=0;
string a=" ";
int option;


Cart s1;



while(option!=7)
{

option=menu();

system("cls");


if(option==1)
{

a=" ";
while(a!="yes")
{

cout<<"\nEnter item ID\n";
cin>>itemID;
cout<<"\nEnter item Name\n";
cin>>itemName;
cout<<"\nEnter Price\n";
cin>>price;
cout<<"\nEnter Purchase Quanitity\n";
cin>>purchaseQuanitity;


s1.addToCart(itemID,itemName,price,purchaseQuanitity,totalPrice); 

cout<<"\n\nExit (yes or no)\n";
cin>>a;
system("cls");
}

system("cls");

}

else if(option==2)
{

s1.changeQuantity();

}
else if (option==3)
{
int k;
cout<<"Enter ID to Delete that Item\n";
cin>>k;
s1.removeFromCart(k);
cout<<"Item Deleted from the list\n";
}
else if(option==4)
{
s1.viewCart();
cout<<endl;
system("pause");
system("cls");
}
else if(option==5)
{
s1.printBill();
cout<<endl;
system("pause");
system("cls");
}
else if(option==6)
{
	system("cls");
cout<<"\n\n\t\3\3 Thank u for using our servis \3\3\n\n";
break;
}

}



}
