#include<iostream>
using namespace std;

template<typename T>void b_sort(T a[],int n)
{
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				T temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	

}

template<typename T>void i_sort(T a[],int n)
{
	int i,j,x;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		x=a[i];
		while(j>=0 && a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}


template<typename T1>void print(T1 a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
		
int main()
{

	int ch,n,m;
	do
	{
		cout<<"\nEnter the size of array: ";
		cin>>n;
		if(n<0)
			cout<<"\nsize cannot be 0..please re-enter";
	}while(n<0);
	char y;
	int a[n];
	float b[n];
	char c[n];
	do
	{
		cout<<"\n1.Enter 1 for integer"<<"\n2.Enter 2 for float"<<"\n3.Enter 3 For character ";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
		       	for(int i=0;i<n;i++)
		       	{	 
			    cout<<"Enter the array element: ";
			    cin>>a[i];   
		       	}
		       	cout<<"\nArray before sorting: \n";
		       	print<int>(a,n);
		       	do
			{
				cout<<"\nEnter 1 to sort array by insertion sort and \n2 to sort array by bubble sort: ";
		       		cin>>m;
				if(m!=1 && m!=2)
					cout<<"\nEnter only 1 or 2";
			}while(m!=1 && m!=2);

		      	if(m==2){ 
		      		b_sort<int>(a,n);
		       		cout<<"\nArray after sorting by bubble sort: ";
				print<int>(a,n);
		      	}	
		      	else
		      	{	
			      i_sort<int>(a,n);
			      cout<<"\nArray after sorting by insertion sort: ";
				print<int>(a,n);
		      	}	
		      	break;

			case 2: 
		       	for(int i=0;i<n;i++)
		       	{	 
			    cout<<"Enter the array element: ";
			    cin>>b[i];   
		       	}
		       	cout<<"\nArray before sorting: \n";
		       	print<float>(b,n);
		       	do
			{
				cout<<"\nEnter 1 to sort array by insertion sort and 2 to sort array by bubble sort: ";
		       		cin>>m;
				if(m!=1 && m!=2)
					cout<<"\nEnter only 1 or 2";
			}while(m!=1 && m!=2);

		      	if(m==2){ 
		      	b_sort<float>(b,n);
		       	cout<<"\nArray after sorting by bubble sort: ";
			print<float>(b,n);
		      	}	
		      	else
		      	{	
		      		i_sort<float>(b,n);
		      		cout<<"\nArray after sorting by insertion sort: ";
				print<float>(b,n);
	      		}
	     		break;
		 
		 	case 3:
		        
			for(int i=0;i<n;i++)
		       	{ 
			    cout<<"Enter the array element: ";
			    cin>>c[i];   
		      	 }
		       	cout<<"\nArray before sorting: \n";
		       	print<char>(c,n);
		       	do
			{
				cout<<"\nEnter 1 to sort array by insertion sort and 2 to sort array by bubble sort: ";
		       		cin>>m;
				if(m!=1 && m!=2)
					cout<<"\nEnter only 1 or 2";
			}while(m!=1 && m!=2);

		      	if(m==2){ 
		      		 b_sort<char>(c,n);
		       		cout<<"\nArray after sorting by bubble sort: ";
				print<char>(c,n);
		     	 }
		      	else
		      	{
			      i_sort<char>(c,n);
			      cout<<"\nArray after sorting by insertion sort: ";
				print<char>(c,n);
		      	}
		}
		cout<<"\ndo you want to continue if yes enter Y or else n: ";
		cin>>y;
	
	}while(y=='y'||y=='Y');
}

			
