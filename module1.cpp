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

void bubble_sort(vector<int> a, int n)
{
    bool swapped;
    do
    {
        swapped = false;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i];sp;
    }*/
}


void selection_sort(vector<int> a, int n)
{
    int mini;
    for(int i=0;i<n-2;i++)
    {
        mini = i;
        for(int j=i+1;j<n-1;j++)
        {
            if(a[j]<a[mini])
            {
                mini = j;
            }
        }
        swap(a[i],a[mini]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i];sp;
    }


}

void insertion_sort(vector<int> a, int n)
{
    int val, j;
    for(int i=1;i<=n-1;i++)
    {
        val = a[i];
        j = i-1;
        while(j>=0 && a[j] > val)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = val;
    }
}
int main()
{
    int n, *ptr,t;
    vector<int> li;
    cout<<"hello world";sp;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    ptr = pseudo_random(arr, n);
   /*
    for(int i=0;i<n;i++)
    {
        cout<<*(ptr+i);sp;
    }*/

     /*//rand()
    for(int i=0;i<n;i++)
    {
        arr[i] = rand();
        cout<<arr[i];sp;
    }*/

    //write to a file
    ofstream fout;
    fout.open("sample.txt");
    for(int i=0;i<n;i++)
    {
        fout<<*(ptr+i)<<" ";
    }
    fout.close();

    //Read from file
    ifstream fin;
    fin.open("sample.txt");
    while (fin)
    {
        fin>>t;
        li.push_back(t);
    }

    //for best case analysis
   // sort(li.begin(), li.end());
    //reverse(li.begin(), li.end());
    //the ultimate list
    /* for(int i=0;i<n;i++)
    {
        cout<<li[i];sp;
    }nl;*/

    auto start = high_resolution_clock::now();
    selection_sort(li, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
