#include <iostream>
using namespace std;

template <typename T>
class myqueue{
	T* Q;
	int capacity,n,f,r;
	
	public:
		myqueue(int c){
			n=0;
			capacity=c;
			Q=new T[capacity];
			f=r=0;
		}
		void Qinsert(T ele);
		T Qdelete();
		bool is_empty(){ return (n==0);
		};
		int size(){ return(n);
		};
		void disp();
};
template <typename T> void myqueue<T>::Qinsert(T ele){
	if(n==capacity){
		cout<<"queue is full\n";
	}
	else{
		Q[r]=ele;
		r=(r+1)%capacity;
		n++;
		cout<<ele<<" has been inserted in queue\n";
	}
}
template <typename T> T myqueue<T>::Qdelete(){
	if(n==0){
		cout<<"queue is empty\n";
	}
	else{
		T temp=Q[f];
		f=(f+1)%capacity;
		n--;
		return temp;
	}
}
template <typename T> void myqueue<T>::disp(){
	for (int i=0;i<capacity-1;i++){
		cout<<Q[i]<<" ";
	}
}
void menu(){
	cout<<"1. insert an element in queue.\n";
	cout<<"2. delete first element from queue.\n";
	cout<<"3. size of queue.\n";
	cout<<"4. check if queue is empty?\n";
 	cout<<"5. display the queue.\n";
	cout<<"6. exit.\n";
}
int main(){
	int choice, mem;
	cout<<"enter the size of queue: ";
	cin>>mem;
	myqueue <int> q(mem);
	menu();
	do{
		cout<<"enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				int p;
				cout<<"enter the ele you want to insert: ";
				cin>>p;
				q.Qinsert(p);
				cout<<endl;
				break;
			}
			case 2:{
				cout<<q.Qdelete()<<"is deleted from queue\n";
				break;
			}
			case 3:{
				cout<<"size of the queue is: "<<q.size()<<endl;
				break;
			}
			case 4:{
				if(q.is_empty()==1){
					cout<<"queue is empty\n";
				}
				else{
					cout<<"queue is not empty\n";
				}
				break;
			}
			case 5:{
				cout<<"QUEUE IS :\n";
				q.disp();
				break;
			}
			default:{
				cout<<"end!!\n";
				break;
			}
		}
	}while(choice!=6);
	return 0;
}
