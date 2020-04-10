#include<iostream>
#include<vector>

#include<cstdlib> //genrate random number

using namespace std ;

/*long long MaximumPairwiseProduct_BruteForce(const vector<int>& numbers)
{
	long long result=0;
	int n= numbers.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1 ; j < n; j++)
		{
			if (((long long) numbers[i])*numbers[j] > result)
			{
				result = ((long long) numbers[i])*numbers[j] ;
			}
			
		}
		
	}
	
	return result;
}*/

long long FastMaxPairwiseProduct(const vector<int>& numbers) 
{
    int n = numbers.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;

    int max_index2 = -1;
    for (int j = 0 ; j < n; ++j)
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}


int main ()
{
	/*while (true)
	{
		int n = ((rand() % 10000) +2) ;    //random between 2 ---> 10 (%)  ****** rand() % 100;         //the range 0 to 99
		cout << n << "\n"<< endl ;

		vector<int> a;
		for (int i = 0; i < n; i++)
		{
			a.push_back(rand() % 100000) ;
		}
		for (int i = 0; i < n; i++)
		{
			cout<<a[i]<<' ' ;
		}
		cout<<"\n";

		long long res1 =MaximumPairwiseProduct_BruteForce(a) ;
		long long res2 = FastMaxPairwiseProduct(a) ;

		if ( res1 != res2 )
		{
			cout<<"wrong answer bitch try again : res1 : "  << res1 << "  res2 : " << res2 << "\n" ;
			break ;
		}
		else	
		{
			cout<<"ok \n"<<endl ;
		}
	
	}*/
	


	int n;
	cin>>n;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i] ;
	}

	long long result = FastMaxPairwiseProduct(numbers);
	cout<<result;

	return 0;
}