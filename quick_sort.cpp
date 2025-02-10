#include <iostream>
using namespace std;

// 分区函数，返回枢轴的最终位置
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为枢轴
    int i = low - 1; // i 指向小于枢轴的区域

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // 交换，使小于枢轴的元素移到左侧
        }
    }
    swap(arr[i + 1], arr[high]); // 将枢轴放到最终位置
    return i + 1;
}

// 快速排序主函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 分区
        quickSort(arr, low, pi - 1); // 递归排序左半部分
        quickSort(arr, pi + 1, high); // 递归排序右半部分
    }
}

// 测试代码
int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
