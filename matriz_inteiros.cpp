/* Dada uma matriz de inteiros, encontre o primeiro inteiro positivo ausente em tempo linear e espaço constante. Em outras palavras, encontre o menor número inteiro positivo que não existe na matriz. A matriz também pode conter duplicatas e números negativos.
Por exemplo, a entrada [3, 4, -1, 1] deve dar 2. A entrada [1, 2, 0] deve dar 3.
Você pode modificar a matriz de entrada no local. */ 



#include <iostream>
#include <vector>

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    std::vector<int> arr1 = {3, 4, -1, 1};
    std::vector<int> arr2 = {1, 2, 0};

    int result1 = firstMissingPositive(arr1);
    int result2 = firstMissingPositive(arr2);

    std::cout << "Resultado 1: " << result1 << std::endl;
    std::cout << "Resultado 2: " << result2 << std::endl;

    return 0;
}
