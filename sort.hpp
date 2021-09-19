#ifndef VE281P1_SORT_HPP
#define VE281P1_SORT_HPP

#include <vector>
#include <functional>

template<typename T>
static void swap(std::vector<T> &vector, int i, int j){
    T temp = vector[i];
    vector[i] = vector[j];
    vector[j] = temp;
}

template<typename T, typename Compare = std::less<T> >
void bubble_sort(std::vector<T> &vector, Compare comp = Compare()) {
    bool swapped = false;
    int last_unsorted = vector.size() - 1;;
    int swap_index = -1;
    while(!swapped){
        swapped = true;
        for (int i = 0; i < last_unsorted; i++){
            if (!comp(vector[i], vector[i + 1])){
                swap(vector, i, i + 1);
                swapped = false;
                swap_index = i;
            }
        }
        last_unsorted = swap_index;
    }

}

template<typename T, typename Compare = std::less<T> >
void insertion_sort(std::vector<T> &vector, Compare comp = Compare()) {
    int len = vector.size();
    for (int i = len - 2; i >= 0; i--){
        T tmp = vector[i];
        int k = i + 1;
        while (k < len && comp(vector[k], tmp))
        {
            vector[k - 1] = vector[k];
            k++;
        }
        vector[k - 1] = tmp;
    }
    // for (int i = 1; i < vector.size(); i++){
    //     T tmp = vector[i];
    //     // std::cout << "here" << tmp;
    //     int k = i - 1;
    //     while (k >= 0 && comp(tmp, vector[k])){
    //         vector[k + 1] = vector[k];
    //         k--;
    //     }
    //     vector[k + 1] = tmp;
    // }
}

template<typename T, typename Compare = std::less<T> >
void selection_sort(std::vector<T> &vector, Compare comp = Compare()) {
    int max, min;
    int len = vector.size();
    for (int i = 0; i < len / 2 ; i++){
        max = i;
        min = i;
        for (int k = i + 1; k < len - i; k++){
            if (comp(vector[max], vector[k]))
                max = k;
            if (comp(vector[k], vector[min]))
                min = k;
        }
        if (max == min) break;
        swap(vector, max, len - i - 1);
        if (min == len - i - 1) min = max;
        swap(vector, min, i);
    }
}

template<typename T, typename Compare = std::less<T>>
static void merge_Sorted(std::vector<T> &vector, int begin, int end, std::vector<T> &ret, Compare comp = Compare()){
    int left_index = begin;
    int mid = (begin + end) / 2;
    int right_inedex = mid + 1;
    int ret_index = begin;
    while (left_index <= mid && right_inedex <= end)
    {
        if (comp(vector[left_index], vector[right_inedex])){
            ret[ret_index++] = vector[left_index++];
        }
        else{
            ret[ret_index++] = vector[right_inedex++];
        }
    }
    if (left_index > mid){
        for (int k = right_inedex; k <= end; k++)
            ret[ret_index++] = vector[k];
    }
    else{
        for (int k = left_index; k <= mid; k++)
            ret[ret_index++] = vector[k];
    }
    for (int j = begin; j <= end; j++){
        vector[j] = ret[j];
    }
}

template<typename T, typename Compare = std::less<T> >
static void merge_divide(std::vector<T> &vector, int begin, int end, std::vector<T> &ret, Compare comp = Compare()){
    if (begin == end) return;
    int mid = (begin + end) / 2;
    merge_divide(vector, begin, mid, ret);
    merge_divide(vector, mid + 1, end, ret);
    merge_Sorted(vector, begin, end, ret, comp);
}

template<typename T, typename Compare = std::less<T> >
void merge_sort(std::vector<T> &vector, Compare comp = Compare()) {
    int len = vector.size();
    if (len < 2) return;
    std::vector<T> ret(len);
    merge_divide(vector, 0, len - 1, ret, comp);
}














template<typename T, typename Compare = std::less<T> >
static int partition(std::vector<T> &vector, int begin, int end, std::vector<T> &ret, Compare comp = Compare()){
    int pivot = vector[begin];
    int left = begin;
    int right = end;
    int index = begin + 1;
    while (index <= end && left < right){
        if (comp(vector[index], pivot))
            ret[left++] = vector[index++];
        else
            ret[right--] = vector[index++];
    }
    ret[left] = pivot;
    for (int j = begin; j <= end; j++){
        vector[j] = ret[j];
    }
    return left;
}

template<typename T, typename Compare = std::less<T> >
static void q_sorter(std::vector<T> &vector, int begin, int end, std::vector<T> &ret, Compare comp = Compare()){
    if (begin >= end) return;
    int mid = partition(vector, begin, end, ret, comp);
    q_sorter(vector, begin, mid, ret, comp);
    q_sorter(vector, mid + 1, end, ret, comp);
}


template<typename T, typename Compare = std::less<T> >
void quick_sort_extra(std::vector<T> &vector, Compare comp = Compare()) {
    // std::cout << "begin";
    int len = vector.size();
    if (len < 2) return;
    std::vector<T> ret(len);
    q_sorter(vector, 0, len - 1, ret, comp);
}
























template<typename T, typename Compare = std::less<T> >
static int inplace_partition(std::vector<T> &vector, int begin, int end, Compare comp = Compare()){
    int pivot = vector[begin];
    int left = begin + 1;
    int right = end;
    while (left < right){
        while (left < right && comp(vector[left], pivot)) left++;
        while (left < right && comp(pivot, vector[right])) right--;
        if (left < right) swap(vector, left++, right--);
    }
    // if (left > right || (left == right) && (vector[left] > pivot)) left--;
    if (left > right || (left == right && (vector[left] > pivot))) left--;
    swap(vector, begin, left);
    return left;
}
template<typename T, typename Compare = std::less<T> >
static void inplace_q_sorter(std::vector<T> &vector, int begin, int end, Compare comp = Compare()){
    if (begin >= end) return;
    int mid = inplace_partition(vector, begin, end);
    inplace_q_sorter(vector, begin, mid - 1);
    inplace_q_sorter(vector, mid + 1, end);
}

template<typename T, typename Compare = std::less<T> >
void quick_sort_inplace(std::vector<T> &vector, Compare comp = Compare()) {
    int len = vector.size();
    if (len < 2) return;
    inplace_q_sorter(vector, 0, len - 1);
}


#endif //VE281P1_SORT_HPP
