#include <iostream>
#include <cassert>

using namespace std;

struct output_b
{
    int position, length;
};

int isprime(int x) //legacy code, not used due to method used for prime numbers
{
    if (x <= 1)
        return 0;
    if (x == 2) //checks the only prime even number
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int i = 3; i * i <= x; i += 2) //only checks odd numbers up to (and including) sqrt(x)
        if (x % i == 0)
            return 0;
    return 1;
}

void test_isprime()
{
    //tests for the isprim() function
    assert(isprime(2));
    assert(isprime(3));
    assert(isprime(24077));
    assert(!isprime(1));
    assert(!isprime(0));
    assert(!isprime(-5));
    assert(!isprime(24072));
}

void eratostene(int x)
{
    //for each prime number found marks all multiples (up to x) as non prime
    int s[x + 2];//array used for marking primes
    for (int i = 2; i < x; i++)
        s[i] = 0;//making the entire array 0
    s[0] = 1;
    s[1] = 1;
    //0 and 1 are non-prime, but we cannot use the algorithm with them (0*x is 0 infinite loop, 1*x = all numbers)
    for (int i = 2; i < x; i++)
        if (s[i] == 0)
            for (int j = 2 * i; j < x; j = j + i)
                s[j] = 1;
    for (int i = 0; i < x; i++)
        if (s[i] == 0)
            cout << i << ' ';
}

output_b tuple_compare(int lenc, int &lenmax, int pc, int &pmax)
{
    //compares lenc,pc tuple with lenmax,pmax based on lengths
    if (lenc > lenmax)
    {
        output_b ret = {pc, lenc};
        lenmax = lenc;
        pmax = pc;
        return ret;
    }
    output_b ret = {pmax, lenmax};
    return ret;
}

output_b ascending_sequence(int a[], int x, bool do_print) //int[]: array, int: length, bool: test or console output
{
    int lenc = 1, lenmax = -1, pc = 0, pmax = 0;//TO-DO!: switch lenc,pc and lenmax,pmax to output_b structs
    output_b ret = {pmax, lenmax};
    //lenc = length of current subarray,lenmax = length of longest subarray, pc = position of current subarray, pmax = position of maximum subarray
    for (int i = 0; i < x - 1; i++)
        if (a[i] < a[i + 1])
        {
            lenc++;
        }
        else
        {
            ret = tuple_compare(lenc, lenmax, pc, pmax);
            pc = i + 1;
            lenc = 1;
        }
    ret = tuple_compare(lenc, lenmax, pc, pmax);
    if (do_print) //console output, doesn't get called during tests
        for (int i = 0; i < ret.length; i++)
            cout << a[i + ret.position] << ' ';
    return ret;
}

void test_ascending_sequence()
{
    //runs the test for the sequence function
    int x[20] = {1, 2, 3, 4, 5}, x1[20] = {1, 2, 1, 2, 5}, x2[20] = {5, 2, 4, 1, 8, 1, 2, 1, 2, 5}, x3[20] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2}, x4[20] = {1, 2, 1, 2, 1, 2, 1, 2, 3, 4};
    //no longer stingy on memory
    output_b res = ascending_sequence(x, 5, 0); //x={1,2,3,4,5}
    assert(res.position == 0 && res.length == 5);
    res = ascending_sequence(x1, 5, 0); //x={1,2,1,2,5}
    assert(res.position == 2 && res.length == 3);
    res = ascending_sequence(x2, 10, 0); //x={5,2,4,1,8,1,2,1,2,5}
    assert(res.position == 7 && res.length == 3);
    res = ascending_sequence(x3, 10, 0); //x={1,2,1,2,1,2,1,2,1,2}
    assert(res.position == 0 && res.length == 2);
    res = ascending_sequence(x4, 10, 0); //x={1,2,1,2,1,2,1,2,3,4}
    assert(res.position == 6 && res.length == 4);
    res = ascending_sequence(x4, 9, 0); //x={1,2,1,2,1,2,1,2,3}
    assert(res.position == 6 && res.length == 3);
}

int input_a()
{
    //function generates input for a)
    int x;
    cout << "a)\nn=";
    cin >> x;
    return x;
}

void input_b(int &n, int *a)
{
    //function generates input for b)
    cout << "\nb)\nNumber of elements (n<1000):";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void a_solve()
{
    //function takes input and calls the solving function for a)
    int n;
    n = input_a();
    eratostene(n);
}

void b_solve()
{
    //function takes input and calls the solving function for b)
    int n, a[1000];
    input_b(n, a);
    ascending_sequence(a, n, 1);
}

void run_tests()
{
    //function runs all assertion tests - to be called at start of program
    test_isprime();
    test_ascending_sequence();
}

void a_solve_check()
{
    //runs the console input for wether or not to run the solution for a)
    char run_validate;
    cout << "\nDo you want to run a)?: Y/N\n";
    cin >> run_validate;
    if (run_validate == 'Y' || run_validate == 'y')
        a_solve();
}

void b_solve_check()
{
    //runs the console input for wether or not to run the solution for b)
    char run_validate;
    cout << "\nDo you want to run b)?: Y/N\n";
    cin >> run_validate;
    if (run_validate == 'Y' || run_validate == 'y')
        b_solve();
}

int main()
{
    run_tests();
    a_solve_check();
    b_solve_check();
}