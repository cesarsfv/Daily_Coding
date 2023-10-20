def max_sum_non_adjacent(nums):
    if not nums:
        return 0

    prev_max = 0  # Maior soma até o elemento anterior
    curr_max = 0  # Maior soma até o elemento atual

    for num in nums:
        # A ideia é calcular a maior soma possível no elemento atual considerando os elementos anteriores
        new_max = max(prev_max, curr_max)
        curr_max = prev_max + num
        prev_max = new_max

    # O resultado final é o máximo entre a soma incluindo o último elemento e a soma excluindo o último elemento
    return max(prev_max, curr_max)

# Exemplos de uso:
print(max_sum_non_adjacent([2, 4, 6, 2, 5]))  # Saída: 13
print(max_sum_non_adjacent([5, 1, 1, 5]))  # Saída: 10
