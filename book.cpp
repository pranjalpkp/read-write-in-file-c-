#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
	int bookid;
	char title[20];
	float price;
	public:
		Book()
		{
			bookid=0;
			strcpy(title,"no title");
			price=0;
		}
		void getBookData()
		{
			cout<<"Enter Book detail:-";
			cout<<"Book id, Title and Price ";
			cin>>bookid;
			cin.ignore();
			cin.getline(title,19);
			cin>>price;
		}
		void showBookData()
		{
			cout<<"\n"<<bookid<<" "<<title<<" "<<price;
		}
		int storeBook();
		void viewAllBooks();
};
void Book::viewAllBooks()
{
	ifstream fin;
	fin.open("file.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\nFile not found !!";
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof()){
		showBookData();	
		fin.read((char*)this,sizeof(*this));
		}
		fin.close();
	
	}

}
int Book::storeBook()
{
	if(bookid==0 && price==0)
	{
		cout<<"Book data not intilialized ";
		return (0);
	}
	else
	{
	ofstream fout;
	fout.open("file.dat",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
	return (1);
    }
}
int main()
{
	Book b1,b2;
//	b1.getBookData();
//	b1.showBookData();
//	b1.storeBook();
	b1.viewAllBooks();
	//b2.showBookData();
	//b2.storeBook();
}
