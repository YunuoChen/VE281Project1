#include <iostream>
#include <vector>
#include <algorithm> 
#include "sort.hpp"
using namespace std;
void print_v(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// template<typename T, typename Compare = std::less<T> >
// typedef void (*PMF[]) (std::vector<T> &vector, Compare comp);

int main()
{
    int len;
    cin >> len;
    int tmp;
    vector<int> unsorted;
    for (int i = 0; i < len; i++){
        cin >> tmp;
        unsorted.push_back(tmp);
    }
    // for (int i = 0; i < 6; i++){
    vector<int> sort(unsorted.begin(), unsorted.end());
    bubble_sort(sort);
    print_v(sort);

    vector<int> sort2(unsorted.begin(), unsorted.end());
    insertion_sort(sort2);
    print_v(sort2);
    
    vector<int> sort3(unsorted.begin(), unsorted.end());
    selection_sort(sort3);
    print_v(sort3);

    vector<int> sort4(unsorted.begin(), unsorted.end());
    merge_sort(sort4);
    print_v(sort4);


    vector<int> sort5(unsorted.begin(), unsorted.end());
    quick_sort_extra(sort5);
    print_v(sort5);

    vector<int> sort6(unsorted.begin(), unsorted.end());
    quick_sort_inplace(sort6);
    print_v(sort6);
    // }
    

}
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include "sort.hpp"
// #include <string>
// #include <vector>
// #include <chrono>
// #include <fstream>
// #include <sstream>

// enum SortType{
//     BubbleSort,
//     InsertionSort,
//     SelectionSort,
//     MergeSort,
//     QuickSort,
//     QuickSortExtra,
//     Last
// };



// template <typename T>
// void readFromFile(std::vector<std::vector<T>> &lists){
//     std::ifstream iFile("rand.txt");
//     std::string tmp_string = "";
//     while (std::getline(iFile, tmp_string)){
//         std::cout << "string: " << tmp_string << std::endl;
//         lists.push_back({});
//         std::istringstream iStream;
//         iStream.str(tmp_string);
//         T tmp_variable;
//         while (iStream >> tmp_variable){
//             // std::cout << tmp_variable << std::endl;
//             lists[lists.size() - 1].push_back(tmp_variable);
//         }
//     }
// }

// template <typename T, typename Compare = std::less<T>>
// void calTime(std::vector<T> vector, void(*sort_func)(std::vector<int>&, Compare), int index, Compare comp = Compare()){
//     // std::vector<void (*)(std::vector<T>, std::less<T>)> func_vec = {bubble_sort};
//     // typedef void sort_fun(std::vector<T>&, Compare);
//     // typedef sort_fun* sort_fun_p;
//     // std::vector<sort_fun_p> fun_vec = {bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort_inplace, quick_sort_extra};
//     // store how much time each algorithm costs
//     std::ofstream ofstream_time("./time/sort_time_" + std::to_string(index), std::ios::app);
//     std::ofstream ofstream_result("./result/sort_result_" + std::to_string(index), std::ios::app);
//     ofstream_result << "Original: ";
//     for (int i = 0; i < vector.size(); i++){
//         ofstream_result << vector[i] <<  " ";
//     }
//     ofstream_result << std::endl;
//     auto t1 = std::chrono::steady_clock::now();
//     sort_func(vector, std::less<T>());
//     auto t2 = std::chrono::steady_clock::now();
//     double duration = std::chrono::duration<double, std::micro>(t2 - t1).count();
//     ofstream_time << duration << " ";
//     ofstream_result << "Sorted: ";
//     for (int i = 0; i < vector.size(); i++){
//         ofstream_result << vector[i] <<  " ";
//     }
//     ofstream_result << std::endl;
// }

// // template<typename T>
// // void outputSortedLists(std::vector<T> &vector){
// //     for(int i = 0; i < )
// // }

// int main(){
//     std::vector<int>vec = {3, 4, 1, 2, 0};
//     std::vector<std::vector<int>> unsorted_lists;
//     readFromFile<int>(unsorted_lists);
//     typedef void sort_fun(std::vector<int>&, std::less<int>);
//     typedef sort_fun* sort_fun_p;
//     std::vector<sort_fun_p> fun_vec = {bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort_inplace, quick_sort_extra};
//     for (int i = 0; i < unsorted_lists.size(); i++){
//         for (int j = 0; j < fun_vec.size(); j++){
//             calTime<int>(unsorted_lists[i], fun_vec[j], j);
//         }
//     }
//     // std::vector<void (*)(std::vector<int>)> func_vec;
//     // // void (*)(std::vector<int>) ptr = bubble_sort<int, std::less<int> >;
//     // func_vec.push_back(bubble_sort);
//     // quick_sort_extra(vec, std::less<int>());
//     // std::cout << unsorted_lists.size() << std::endl;
//     return 0;
// }