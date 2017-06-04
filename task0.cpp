#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void shoba(vector<int> m,vector<int> c,int n,int q);
void kamal( vector<int>  m,vector<int> c,int n,int q);
void jasmine( vector<int> m,vector<int>  c,int n,int q);

int main()
{
	int n,q,i,j;
	
	
	cout<<"Enter the number of curtains \n";
	cin>>n ;
	vector<int> m(n);
	 cout<<"Enter measurements \n";
    for (i=0; i<n; i++)
  cin>>m[i];
    cout<<"Enter the number of queries \n";
    cin>>q;
    vector<int> c(q);
    cout<<"Enter the requirements \n";
    for(j=0;j<q;j++)
    cin>>c[j];
    cout<<"SHOBA \n";shoba(m,c,n,q);
    sort(m.begin(), m.end()); //sorting in ascending order
	cout<<"KAMAL \n";kamal(m,c,n,q);//output according to sorted array
    cout<<"JASMINE \n";jasmine(m,c,n,q);//output according to sorted array

return 0;
}
void kamal( vector<int> m,vector<int> c,int n,int q)
{ int k,mid,l,r,t,p;

for(k=0;k<q;k++)
{ t=0;l=0; r=n-1;
while (l <= r)
  {
    int mid = l + (r-l)/2;

    if (m[mid] >= c[k]  &&  m[mid-1]<c[k]) 
        {t=1;
		m[mid]-= c[k];
		break;
		}
 
    else if (m[mid] > c[k]  &&  m[mid-1] > c[k])
       r=mid-1;
 
       else
         l = mid + 1; 
  }
  
if(t==1)
	{
	for(p=0;p<n;p++)
	cout<<m[p];
	cout<< "\n";} 
	else if(t==0)
	cout<<"-1 \n";
	
}
  	
		
}

void jasmine( vector<int> m,vector<int> c,int n,int q)
{
	int k,r,t,p;
for(k=0;k<q;k++)
{ t=0;
for(r=n-1;r>0;r--)
{
	if(m[r]>=c[k])
	{t=1;
	m[r]-=c[k];
	break;
	}
}
if(t==1)
	{
	for(p=0;p<n;p++)
	cout<<m[p];
	cout<< "\n";} 
	else if(t==0)
	cout<<"-1 \n";
  }
  }
  	
void shoba(vector<int> m,vector<int> c,int n,int q)

{ int k,l,p,t;
	for(l=0;l<q;l++)
	{for(k=n-1;k>0;k--)
	{t=0;
	  if(c[l]==m[k]||c[l]<m[k])
	  {t=1;
	   if(c[l]==m[k]) m[k]=0;
	   else m[k]-=c[l];
	  break;}
}  
   if(t==1)
	{
	for(p=0;p<n;p++)
	cout<<m[p];
	cout<< "\n";} 
	else if(t==0)
	cout<<"-1 \n";
	
	}	
}

