#include<bits/stdc++.h>
#define nl cout<<"\n"
#define sp cout<<" "

using namespace std;
using namespace std::chrono;

int* pseudo_random(int num[], int n)
{
    int c1(0);
    long long int m,a,c,x0,xn1;
    m = 2147483647;
    a = 16807;
    c = 40025;
    x0 = 3+1458;
    long long int xn = x0;
    while(xn1 != x0)
    {
        xn1 = (a*xn +c)%m;
       // cout<<xn1;sp;
        num[c1] = xn1 % 1000;
        xn = xn1;
        c1++;
        if(n<c1)
        {
            break;
        }
    }
    return num;
}

int linear_search(vector<int> a, int n, int x)
{
    int i = 0;
    while(1)
    {
        if(i>n)
        {
            break;
        }
        else if(a[i] == x)
        {
            break;
        }
        i++;
    }
    return i;
}

int binary_searchh(vector<int> a, int n, int value)
{
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high) / 2;
        if(a[mid]>value)
        {
            high = mid - 1;
        }
        else if(a[mid]<value)
        {
            low = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;//not found

}


int main()
{
    int n, *ptr,t;
    vector<int> li;
    cout<<"module 2";sp;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    ptr = pseudo_random(arr, n);


    //write to a file
    ofstream fout;
    fout.open("sample2.txt");
    for(int i=0;i<n;i++)
    {
        fout<<*(ptr+i)<<" ";
    }
    fout.close();

    //Read from file
    ifstream fin;
    fin.open("sample2.txt");
    while (fin)
    {
        fin>>t;
        li.push_back(t);
    }

/*
    for(int i=0;i<n;i++)
    {
        cout<<li[i];sp;
    }nl;*/

    int x;
    cin>>x;
   // sort(li.begin(), li.end());
    //reverse(li.begin(), li.end());


    auto start = high_resolution_clock::now();
    cout<<linear_search(li, n, x);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() * 1000000000 << " nanoseconds" << endl;

    return 0;
}
