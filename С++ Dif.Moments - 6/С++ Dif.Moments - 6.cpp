#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
using namespace std;


mutex mtx_cout;

mutex m;

class pcout
{
private:
    lock_guard<mutex> lk;
public:
    pcout() : lk(lock_guard<mutex>(mtx_cout))
    {
    }

    template<typename T>
    pcout& operator<<(const T& data)
    {
        cout << data;
        return *this;
    }

    pcout& operator<<(ostream& (*fp)(ostream&))                
    {                                                                    
        cout << fp;                                                 
        return *this;                                                    
    }                                                                    
};

void doSomething(int number)
{
    pcout() << "start thread " << number << endl;
    pcout() << "stop thread " << number << endl;
}

bool isPrime(size_t num)
{
    size_t limit = num / 2;

    if (num > 2)
    {
        for (size_t i = 2; i <= limit; ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void task2()
{
    size_t maxValue = 500000;
    size_t counThreads = 30;
    vector<size_t> answers;
    
    mutex m;

    for (size_t i = 0; i < maxValue;)
    {
        vector<thread> v;

        for (size_t j = i + counThreads; i <= j; ++i)
        {
            v.push_back(thread([=, &m, &answers]()
                {
                    if (isPrime(i))
                    {
                        lock_guard lg(m);
                        answers.push_back(i);
                    }
                }));
        }
        for (auto& t : v)
            t.join();
    }

    for (const auto &a : answers)
    {
      cout << "Число " << a << " простое" << endl;
    }
}

void addDig(vector<int>& v)
{
    this_thread::sleep_for(1000ms);
    lock_guard lg(m);
    int dig = rand();
    v.push_back(dig);      
}


void deleteDig(vector<int>& v)
{
    this_thread::sleep_for(500ms);
    lock_guard lg(m);
    sort(v.begin(), v.end());
    v.pop_back();
}

template<typename Print>
void printV(vector<Print>& v)
{
    ostream_iterator<Print> it_o = { cout, " | " };
    copy(v.begin(), v.end(), it_o);
    cout << endl;
}

int main()
{
    thread th1(doSomething, 1);
    thread th2(doSomething, 2);
    thread th3(doSomething, 3);
    th1.join();
    th2.join();
    th3.join();
	//---------------------------
    
    task2();
    
    //----------------------
    
    vector<int> vec = { 1 , 14 , 22 , 33 ,24 ,15};
    
    while (vec.empty() == false)
    {
        thread owner([&]()
            {
                addDig(vec);
            });
        thread thief([&]()
            {
                deleteDig(vec);
            });
        owner.join();
        thief.join();
        printV(vec); 
    }

	return 0;
}


