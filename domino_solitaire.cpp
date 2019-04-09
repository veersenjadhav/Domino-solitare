#include <iostream>
#include <stdio.h>

using namespace std;

class domino_solitaire
{
private:
    int size, *arr1 = new int[2<<10], *arr2 = new int[2<<10], prev, res, vert, hor;
public:
    domino_solitaire(int t_size, int t_arr1[], int t_arr2[]);
    void calculate_tiles();
};

domino_solitaire::domino_solitaire(int t_size, int t_arr1[], int t_arr2[])
{
    size = t_size;
    
    for(int i = 0; i < size; i++)
    {
        arr1[i] = t_arr1[i];
    }

    for(int i = 0; i < size; i++)
    {
        arr2[i] = t_arr2[i];
    }
}

void domino_solitaire::calculate_tiles()
{
    prev = 0;
    res = abs(arr1[0] - arr2[0]);

    for(int i = 1; i < size; i++)
    {
        vert = res + abs(arr1[i] - arr2[i]);
        hor = prev + abs(arr1[i] - arr1[i-1]) + abs(arr2[i] - arr2[i-1]);
        prev = res;
        res = max(vert, hor);
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "\n Enter Size of arrays : ";
    cin >> size;

    int arr1[size], arr2[size];
    cout << "\n Enter " << size << "elements of array 1 :";
    for(int i = 0; i < size; i++)
        cin >> arr1[i];

    cout << "\n Enter " << size << "elements of array 2 :";
    for(int i = 0; i < size; i++)
        cin >> arr2[i];

    domino_solitaire ds(size, arr1, arr2);

    ds.calculate_tiles();

    return 0;
}

