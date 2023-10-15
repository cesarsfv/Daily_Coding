// Dado um array de inteiros, retorne um novo array tal que cada elemento no índice i do novo array seja o produto de todos os números no array original, exceto aquele em i.
// Por exemplo, se nossa entrada fosse [1, 2, 3, 4, 5], a saída esperada seria [120, 60, 40, 30, 24]. Se nossa entrada fosse [3, 2, 1], a saída esperada seria [2, 3, 6].

#include <iostream>
#include <vector>

std::vector<int> produtoExcetoAtual(const std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> resultado(n, 1);

    int produto = 1;

    // Calcula o produto de todos os elementos à esquerda de i e o armazena em resultado[i]
    for (int i = 0; i < n; i++) {
        resultado[i] *= produto;
        produto *= nums[i];
    }

    produto = 1;

    // Calcula o produto de todos os elementos à direita de i e multiplica com resultado[i]
    for (int i = n - 1; i >= 0; i--) {
        resultado[i] *= produto;
        produto *= nums[i];
    }

    return resultado;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> resultado = produtoExcetoAtual(nums);

    for (int num : resultado) {
        std::cout << num << " ";
    }

    return 0;
}
