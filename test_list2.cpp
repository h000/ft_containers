#include <list>
#include <iostream>
#include <cmath>

struct is_odd 
{
	bool operator() (const int& value) { return (value%2)==1; }
};

bool single_digit(const int & value)
{
	return (value < 10);
}

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ 
		return (fabs(first-second)<5.0); 
	}
};

bool my_comparison (double first, double second)
{
	return ( int(first) < int(second) );
}


using namespace std;

int main()
{
	list<int> my_list1;

	std::cout << "======== size & empty ===========" << std::endl;

	std::cout << "size : " << my_list1.size() << std::endl;
	std::cout << "empty? : " << std::boolalpha << my_list1.empty() << std::endl;

	std::cout << "========= push_back & push_front ==========" << std::endl;

	for (int i = 1; i <= 5; ++i)
		my_list1.push_back(i);

	my_list1.push_front(0);
	std::cout << "size : " << my_list1.size() << std::endl;
	std::cout << "max_size : " << my_list1.max_size() << std::endl;
	std::cout << "empty? : " << std::boolalpha << my_list1.empty() << std::endl;

	std::cout << "========= List constructor ==========" << std::endl;


	list<int> my_list2(my_list1);
	
	for (list<int>::iterator it = my_list2.begin(); it != my_list2.end(); ++it)
    {
		std::cout << '<' << *it << '>';
	}
  	std::cout << '\n';

	list<int>::reverse_iterator rit = my_list2.rbegin();
	int i = 0;
	while (rit != my_list2.rend())
		std::cout << " " << *rit++;
	std::cout << '\n';

	for (list<int>::reverse_iterator rit = my_list1.rbegin(); rit != my_list1.rend(); ++rit)
		std::cout << " " << *rit;
	std::cout << '\n';
	std::cout << "==================" << std::endl;

	
	list<int> my_list3((unsigned int)3, 5);
	for (list<int>::iterator it = my_list3.begin(); it != my_list3.end(); ++it)
    	std::cout << '<' << *it << '>';
  	std::cout << '\n';

	list<int> my_list4(my_list2.begin(), my_list2.end());
	for (list<int>::iterator it = my_list4.begin(); it != my_list4.end(); ++it)
    	std::cout << '<' << *it << '>';
  	std::cout << '\n';


	std::cout << "========= iter & rev_iter ==========" << std::endl;
	for (list<int>::iterator it = my_list1.begin(); it != my_list1.end(); ++it)
    	std::cout << '<' << *it << '>';
  	std::cout << '\n';

	list<int>::iterator from(my_list1.begin());
	list<int>::iterator until(my_list1.end());
	
	list<int>::reverse_iterator rev_begin(until);
	list<int>::reverse_iterator rev_end(from);

	while (rev_begin != rev_end)
		std::cout << '<' << *(rev_begin++) << '>';
	std::cout << '\n';

	for (list<int>::reverse_iterator rit = my_list1.rbegin(); rit != my_list1.rend(); ++rit)
		std::cout << " " << *rit;
	std::cout << '\n';

	std::cout << "======== front & back ===========" << std::endl;
	std::cout << "my_list1 front is : " << my_list1.front() << std::endl;
	std::cout << "my_list1 back is : " << my_list1.back() << std::endl;

	std::cout << "========pop_front===========" << std::endl;
	
	while (!my_list1.empty())
	{
		std::cout << my_list1.front() << std::endl;
		my_list1.pop_front();
	}

	std::cout << "========pop_back===========" << std::endl;

	while (!my_list2.empty())
	{
		std::cout << my_list2.back() << std::endl;
		my_list2.pop_back();
	}

	std::cout << "========= assign ==========" << std::endl;

	list<int> first;
	list<int> second;
	first.assign((unsigned int)7, 10);
	second.assign(first.begin(), first.end());
	int myints[] = {1776, 7, 4};
  	first.assign (myints, myints + 3);

	std::cout << "Size of first: " << first.size() << std::endl;
	std::cout << "Size of second: " << second.size() << std::endl;

	std::cout << "========= swap ==========" << std::endl;
	
	list<int> a ((unsigned int)3,100);   // three ints with a value of 100
	list<int> b ((unsigned int)5,200);  // five ints with a value of 200

	
	a.swap(b);

	std::cout << "first contains:";

	for (list<int>::iterator it=a.begin(); it!=a.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "by reverse iterator:";

	for (list<int>::reverse_iterator it=a.rbegin(); it!=a.rend(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (list<int>::iterator it=b.begin(); it!=b.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "by reverse iterator:";

	for (list<int>::reverse_iterator it=b.rbegin(); it!=b.rend(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "========= resize ==========" << std::endl;

	list<int> my_list5;
	for (int i = 1; i < 10; ++i)
		my_list5.push_back(i);

	i = 0;
	for (list<int>::iterator it=my_list5.begin(); it!=my_list5.end(); ++it)
    	std::cout << ' ' << *it;	
	std::cout << '\n';

	my_list5.resize(5);
	for (list<int>::iterator it=my_list5.begin(); it!=my_list5.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';

	my_list5.resize(8,100);

	for (list<int>::iterator it=my_list5.begin(); it!=my_list5.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';


	my_list5.resize(12);
	for (list<int>::iterator it=my_list5.begin(); it!=my_list5.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "========= splice ==========" << std::endl;

	list<int> mylist1, mylist2;
	list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
									// mylist2 (empty)
									// "it" still points to 2 (the 5th element)
	std::cout << "mylist1 contains:";
	for (list<int>::iterator iter = mylist1.begin(); iter != mylist1.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';										
	
	std::cout << *it << std::endl;
	
	mylist2.splice(mylist2.begin(), mylist1, it);
									// mylist1: 1 10 20 30 3 4
									// mylist2: 2
	
	std::cout << "mylist1 contains:";
	for (list<int>::iterator iter = mylist1.begin(); iter != mylist1.end(); ++iter)
		std::cout << ' ' << *iter;

	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (list<int>::iterator iter = mylist2.begin(); iter != mylist2.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';
	
	it = mylist1.begin();
	for (int i = 0; i < 3; ++i)
		++it; //it is pointing 30.

	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
									// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	for (list<int>::iterator iter = mylist1.begin(); iter != mylist1.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	std::cout << "========= remove ==========" << std::endl;

	int my_ints[]= {17,89,7,14};
	list<int> mylist3 (my_ints, my_ints + 4);

	std::cout << "mylist contains:";
	for (list<int>::iterator it=mylist3.begin(); it!=mylist3.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist3.remove(89);
	std::cout << "remove 89" << std::endl;

	std::cout << "mylist contains:";
	for (list<int>::iterator it=mylist3.begin(); it!=mylist3.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "========= remove_if ==========" << std::endl;
	

	int my_ints2[]= {15,36,7,17,20,39,4,1};
	list<int> mylist4 (my_ints2 , my_ints2 + 8);   // 15 36 7 17 20 39 4 1

	mylist4.remove_if (single_digit);           // 15 36 17 20 39

	mylist4.remove_if (is_odd());               // 36 20

	std::cout << "mylist contains:";
	for (list<int>::iterator it = mylist4.begin(); it != mylist4.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "========= sort & unique ==========" << std::endl;
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
	list<double> mylist5 (mydoubles,mydoubles+10);
	
	std::cout << "mylist contains:";
	for (list<double>::iterator it=mylist5.begin(); it!=mylist5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	mylist5.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
								// 15.3,  72.25, 72.25, 73.0,  73.35

	std::cout << "SORTED mylist contains:";
	for (list<double>::iterator it=mylist5.begin(); it!=mylist5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "SORTED mylist in reverse:";
	for (list<double>::reverse_iterator it=mylist5.rbegin(); it!=mylist5.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist5.unique();           //  2.72,  3.14, 12.15, 12.77
								// 15.3,  72.25, 73.0,  73.35
	for (list<double>::iterator it=mylist5.begin(); it!=mylist5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist5.unique (same_integral_part);  //  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0

	mylist5.unique (is_near());           //  2.72, 12.15, 72.25

	std::cout << "mylist contains:";
	for (list<double>::iterator it=mylist5.begin(); it!=mylist5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "SORTED mylist in reverse:";
	for (list<double>::reverse_iterator it=mylist5.rbegin(); it!=mylist5.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "========= reverse ==========" << std::endl;
	
	list<int> mylist6;
	for (int i=1; i<10; ++i)
		mylist6.push_back(i);

	mylist6.reverse();
	
	std::cout << "mylist contains:";
	for (list<int>::iterator it = mylist6.begin(); it != mylist6.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "Reverse to reverse:";
	for (list<int>::reverse_iterator it = mylist6.rbegin(); it != mylist6.rend(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';

	std::cout << "========= merge ==========" << std::endl;

	list<double> j;
	list<double> k;

	j.push_back (3.1);
	j.push_back (2.2);
	j.push_back (2.9);

	k.push_back (3.7);
	k.push_back (7.1);
	k.push_back (1.4);
	
	j.sort();
	std::cout << "first list contains:";
	for (list<double>::iterator it = j.begin(); it != j.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	k.sort();
	std::cout << "second list contains:";
	for (list<double>::iterator it = k.begin(); it != k.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	j.merge(k);
	
	std::cout << "after merge, first list contains:";
	for (list<double>::iterator it = j.begin(); it != j.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "=====================" << std::endl;
	
	k.push_back(2.1);

	for (list<double>::iterator it = k.begin(); it != k.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "=====================" << std::endl;
	j.merge(k, my_comparison);

	std::cout << "first contains:";
	for (list<double>::iterator it = j.begin(); it != j.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "==========non_member function overloads===========" << std::endl;
	std::cout << "==========realtional operators===========" << std::endl;

	list<int> p, q, r;
	for (int i = 1; i < 4; ++i)
		p.push_back(i*10);		// 10 20 30
	for (int i = 1; i < 4; ++i)
		q.push_back(i*10);		// 10 20 30
	for (int i = 3; i > 0; --i)
		r.push_back(i*10);		// 30 20 10
	if (p == q) std::cout << "p and q are equal\n";
	if (q != r) std::cout << "q and r are not equal\n";

	if (q < r) std::cout << "q is less than r\n";
	if (r > q) std::cout << "r is greater than q\n";

	if (p <= q) std::cout << "p is less than or equal to q\n";
	if (p >= q) std::cout << "p is greater than or equal to q\n";

	std::cout << "==========realtional operators===========" << std::endl;

	list<int> foo ((unsigned int)3,100);   // three ints with a value of 100
	list<int> bar ((unsigned int)5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "by reverse iterator";
	for (list<int>::reverse_iterator it = foo.rbegin(); it!=foo.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "by reverse iterator";
	for (list<int>::reverse_iterator it = bar.rbegin(); it!=bar.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "=====================" << std::endl;

}