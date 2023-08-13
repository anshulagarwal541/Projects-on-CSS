#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct farmer
{
    string name;
    int id;
    string *item;
    int *price;
    float *weight;
    int array_size;
    struct farmer *next;
    struct farmer *previous;
};
class Farmer
{
public:
    struct farmer *head;
    struct farmer *last;
public:int flag,c;
	Farmer()
	{
		flag=0;
		c=0;
		last=NULL;
		head=new farmer;
		head->name="";
		head->id=0;
		head->item=NULL;
		head->price=NULL;
		head->weight=NULL;
		head->array_size=0;
		//Create();
	}
	void  Create()
	{
		int choice,ch_f;
		cout<<"1)Farmers' portal     2)Back to MAIN MENU:"<<endl;
		cin>>ch_f;
		if(ch_f==1){
		cout<<"1)SignUp     2)Login:"<<endl;
		cin>>choice;
		if(choice==1){
		SignUp();}
		else if(choice==2)
		Login();
		else
		{
			cout<<"Wrong input"<<endl;
			Create();
		}}
	}
    void SignUp()
    {
        string n;
        cout << "Enter name:" << endl;
        //getline(cin,n);
        cin>>n;
        cout<<"Your ID is "<<c+1<<endl;
        if (c == 0)
        {
            head->name = n;
            head->id = c+1;
            head->next = NULL;
            head->previous=NULL;
            last = head;
            c++;
        }
        else
        {
            struct farmer *t;
            t = new farmer;
            t->name = n;
            t->id = c+1;
            t->next = NULL;
            t->previous=last;
            last->next = t;
            last = t;
            c++;
        }
        Create();
    }
    void Login()
    {
        int pos;
        flag=1;
        cout<<"Enter your ID:";
        cin>>pos;
        if(pos>=1 && pos<=c)
        {
            struct farmer *t;
            t=head;
            for(int x=1;x<pos;x++)
            {
                t=t->next;
            }
            cout<<"Your name is "<<t->name<<endl;
            int nItems;
            cout<<"Enter the number of items:";
            cin>>nItems;
            t->item=new string[nItems];
            t->price=new int[nItems];
            t->weight=new float[nItems];
            t->array_size=nItems;
            cout<<"Enter items, their prices(in Ruppees/kg) and weight(in kg) of items:"<<endl;
            for(int a=0;a<nItems;a++)
            {
            	cin>>t->item[a]>>t->price[a]>>t->weight[a];
			}
        }
        else
        {
            cout<<"Account doesn't exist'"<<endl;
        }
        Create();
    }
    void Display()
    {
        if (c == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            struct farmer *t;
            t = head;
            do
            {
                cout << t->name << " " << t->id << endl;
                
                for(int a=0;a<(t->array_size);a++)
                {
                	cout<<t->item[a]<<"  "<<t->price[a]<<"  "<<t->weight[a]<<endl;
				}
				cout<<endl;
                t=t->next;
            } while (t!=NULL);
            cout << endl;
        }
    }
    int Buy(float weight, string item, int id)
    {
			struct farmer *t;
			t=head;
			for(int a=1;a<id;a++)
			{
				t=t->next;
			}
			for(int a=0;a<t->array_size;a++)
			{
				if(t->item[a]==item)
				{
					t->weight[a]=t->weight[a]-weight;
					if(t->weight[a]<0)
					{t->weight[a]=t->weight[a]+weight; return 0;}
					else
					return 1;
				}
			}
			/*if(point)
			{
				t->weight[i]=t->weight[i]-weight;
				if(t->weight[i]<0)
				{t->weight[i]=t->weight[i]+weight; return 0;}
				else
				{return 1;}
			}*/
		
   	}
};
class Consumer
{
	private:int id; string item; float weight;
	public:
	Consumer()
	{
		id=0;
		item="";
		weight=0.0f;
	}
	int getID()
	{
		cout<<"Enter the ID of the farmer from whom you want to make a deal:";
		cin>>id;
		return id;
	}
	string getItem()
	{
		cout<<"Enter the item you want to buy:";
		cin>>item;
		return item;
	}
	float getWeight()
	{
		cout<<"Enter how many kgs you want to buy:";
		cin>>weight;
		return weight;
	}
};
int main()
{
    int ch;
    int i=1;
    Farmer f;
    Consumer c;
    do
    {
    	cout<<"Enter choice"<<endl;
		cout<<"1.Farmer     2.Consumer     3.Exit()"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.Create();
				f.Display();
				break;
			case 2:
				if(!(f.flag))
				{
					cout<<"Out of stock"<<endl;
					break;
				}
				else
				{
				
				int id=c.getID();
				if(!(id>=1 && id<=f.c))
				{
					cout<<"Wrong ID inserted"<<endl;
					break;
				}
				string item=c.getItem();
				struct farmer *t;
				t=f.head;
				for(int x=1;x<id;x++)
				{
					t=t->next;
				}
				bool found=false;
				for(int x=0;x<t->array_size;x++)
				{
					if(t->item[x]==item)
					{
						found=true;
						break;
					}
				}
				if(!(found))
				{
					cout<<"Item not found"<<endl;
					break;
				}
				float weight=c.getWeight();
				int res=f.Buy(weight,item,id);
				if(res)
				//if(f.Buy(c.getWeight(),c.getItem(),c.getID()))
				cout<<"Purchase DONE"<<endl;
				else
				cout<<"Purchase not possible"<<endl;
				f.Display();
			}
				break;
			default: 
				cout<<"Exited"<<endl;
				i=0;
			
		}
	}while(i==1);
	return 0;
}