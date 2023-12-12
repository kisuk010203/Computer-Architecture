#include "matmul.h"
#include <immintrin.h>
#include <stdlib.h>

#pragma GCC target("avx,avx2")
#define BLOCK_SIZE 512

void matmul(const int M, const int N, const int K, const int *inputA,
            const int *inputB, int *output) {
    for (int i = 0; i < M; i += BLOCK_SIZE) {
        for (int k = 0; k < K; k += BLOCK_SIZE) {
            for (int j = 0; j < N; j += BLOCK_SIZE) {
                for (int blocked_i = i; blocked_i < i + BLOCK_SIZE; blocked_i++) {
                    for (int blocked_k = k; blocked_k < k + BLOCK_SIZE; blocked_k++) {
                        __m256i a = _mm256_set1_epi32(inputA[blocked_i * K + blocked_k]); // load and broadcast from inputA
                        for (int blocked_j = j; blocked_j < j + BLOCK_SIZE; blocked_j += 8) {
                            __m256i c = _mm256_loadu_si256(
                                (__m256i *)&output[blocked_i * N + blocked_j]); // load output
                            __m256i b = _mm256_loadu_si256(
                                (__m256i *)&inputB[blocked_k * N + blocked_j]); // load inputB
                            c =
                                _mm256_add_epi32(c, _mm256_mullo_epi32(a, b));
                            _mm256_storeu_si256((__m256i *)&output[blocked_i * N + blocked_j],
                                                c); // store
                        }
                    }
                }
            }
        }
    }
}
