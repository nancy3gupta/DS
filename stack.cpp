#include <iostream>
using namespace std;

template <typename T>
class mystack{
	T *s;
	int top;
	int capacity;

	public:
		mystack(int N=10){
			capacity=N;
			top=-1;
			s=new T[capacity];
		}

		void push(T ele);
		T pop();
		void disp();
		bool isempty(){return (top ==-1);}
		bool isfull(){return ((top+1)==capacity);}
		int size(){return(top+1);}
		int topele(){return (s[top]);}


};
template <typename T> void mystack<T>::push(T ele){
	if(top ==(capacity-1)){
		cout<<"STACK OVERFLOW: stack is full";
	}
	else{
		top=top+1;
		s[top]=ele;
	}
}
template <typename T> T mystack<T>::pop(){
	if(top==-1){
		cout<<"STACK UNDERFLOW: stack is empty";
		return 1;
	}
	else{
		T temp=s[top];
		top=top-1;
		return temp;
	}
}
template <typename T> void mystack<T>::disp(){
	for(int x=top;x>-1;x--){
		cout<<s[x]<<" ";
	}
}
void menu(){
	cout<<"\t INDEX \n";
	cout<<"1. push an object in stack "<<endl;
	cout<<"2. pop an object in stack "<<endl;
	cout<<"3. check if stack is empty "<<endl;
	cout<<"4. check if stack is full "<<endl;
	cout<<"5. size of stack "<<endl;
	cout<<"6. top element of stack "<<endl;
	cout<<"7. display the stack "<<endl;
	cout<<"8. exit "<<endl;
	cout<<"\n \n \n";
}

int main(){
	int choice;
	int mem,p;
	cout<<"enter the size of stack: ";
	cin>>mem;
	mystack <int> s(mem);
	menu();
	do{
		cout<<"enter your choice = ";
		cin>>choice;
		switch(choice){
		case 1:{
			cout<<"enter the element you want to enter: ";
			cin>>p;
			s.push(p);
			cout<<"\n\n";
			break;
		}
		case 2:{
			cout<<"the last element is popped out\n\n";
			s.pop();
			break;
		}
		case 3:{
			if(s.isempty()==1){
				cout<<"stack is empty\n \n";
			}
			else{
				cout<<"stack is not empty\n \n";
			}
			break;
		}
		case 4:{
			if(s.isfull()==1){
				cout<<"stack is full\n \n";
			}
			else{
				cout<<"stack is not full\n \n";
			}
			break;
		}
		case 5:{
			cout<<"size of the stack = "<<s.size()<<endl<<endl;
			break;
		}
		case 6:{
			cout<<"top element of the stack is = "<<s.topele()<<endl<<endl;
			break;
		}
		case 7:{
			cout<<"stack is ";
			s.disp();
			cout<<endl<<endl;
			break;
		}
		default:{
			cout<<"end";
			break;
		}
	}
	}
	while(choice!=8);

	return 0;
}
