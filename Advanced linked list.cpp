#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
};

class List{
	private:
		Node* head;
	public:
		List(){
			head=NULL;	
		};
		void basa_eleman_ekle(int x);
		void elemanlari_yazdir();
		void elemanlari_yazdir(int sayi);
		void sona_eleman_ekle(int x);
		void araya_ekle(int x, int index);
		int eleman_sayisi();
		void sirala();
		void bastan_sil();
		void sondan_sil();
		void sil(int x);
		
};

void List::sil(int x)
{
	if(head==NULL)
	{
		cout<<"Eleman olmadigindan silme yapilmadi\n";
	}
	else
	{
		Node*gezici = head;
		Node*gezici2= head;
		while(gezici!=NULL)
		{
			if(gezici->data == x)
			{
				if(gezici==head)
				{
					bastan_sil();
				}
				else
				{
					gezici2->next = gezici->next;
					delete gezici;
				}
				gezici2=head;
				gezici=head;
			}
			else
			{
				gezici2=gezici;
				gezici = gezici->next;
			}
		}
	}
}

void List::sondan_sil()
{
	if(eleman_sayisi()<2)
	{
		bastan_sil();
	}
	else
	{
		Node * gezici = head;
		Node * gezici2 = head;	
		while(gezici->next!= NULL)
		{
			gezici2 = gezici;
			gezici = gezici->next;	
		}
		delete gezici;
		gezici2->next = NULL;
	}
}


void List::bastan_sil()
{
	if(head!=NULL)
	{
		Node * yedek = head;
		head = head->next;
		delete yedek;	
	}
	else
	{
		cout<<"Liste bos, silme islemi yapilmadi\n";
	}
}


void List::araya_ekle(int x,int index)
{
	if(index<1)
	{
		cout<<"Hatali Index!\n";
	}
	else if(index==1)
	{
		basa_eleman_ekle(x);
	}
	else
	{
		Node* gezgin = head;
		int sayac = 1;
		while(gezgin != NULL && sayac<index-1)
		{
			sayac++;
			gezgin = gezgin->next;
		}
		
		if(gezgin==NULL)
		{
			cout<<"Eleman sayisi "<<eleman_sayisi()<<". Oraya ekleyemezsin!\n";
		}
		else
		{
			Node * yeni = new Node();
			yeni->data = x;
			yeni->next = gezgin->next;
			gezgin->next = yeni;
		}
	}
}



int List::eleman_sayisi()
{
	Node* gezgin = head;
	int sayac =0;
	while(gezgin!=NULL)
	{
		sayac++;
		gezgin = gezgin->next;
	}
	return sayac;
}

void List::sona_eleman_ekle(int x)
{
	Node * yeni = new Node();
	yeni->data = x;
	yeni->next = NULL;
	
	if(head==NULL)
		basa_eleman_ekle(x);
	else
	{
		Node* gezgin = head;
		while(gezgin->next != NULL)
		{
			gezgin = gezgin->next;
		}
		gezgin->next = yeni;
	}
}


void List::elemanlari_yazdir(int sayi)
{
	Node * gezgin = head;
	
	while(gezgin!=NULL && sayi!=0)
	{
		sayi--;
		cout<<gezgin->data<<" ";
		gezgin = gezgin->next;
	}	
}



void List::elemanlari_yazdir()
{
	Node * gezgin = head;
	
	while(gezgin!=NULL)
	{
		cout<<gezgin->data<<" ";
		gezgin = gezgin->next;
	}	
}

void List::basa_eleman_ekle(int x)
{
	Node * yeni = new Node();
	yeni->data = x;
	
	if(head==NULL)
	{
		yeni->next = NULL;
		head = yeni;	
	}
	else
	{
		yeni->next = head;
		head = yeni;	
	}
}



int main(int argc, char** argv) 
{
	List l1;
	
	
	
	l1.basa_eleman_ekle(10);
	l1.basa_eleman_ekle(20);
	l1.basa_eleman_ekle(30);
	l1.basa_eleman_ekle(40);
	l1.elemanlari_yazdir(2);
	cout<<endl;
	l1.elemanlari_yazdir();
	
	return 0;
}
