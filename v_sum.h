#pragma once

#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <thread>

void v_sum1th(std::vector<int>& v1, std::vector<int>& v2) {
    auto start = std::chrono::steady_clock::now();
    std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), std::plus<int>());
    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
    std::cout << delta.count() << "μs" << '\t';
}

void v_sum2th(std::vector<int>& v1, std::vector<int>& v2) {
    auto start = std::chrono::steady_clock::now();
    std::transform(std::execution::par, v1.begin(), v1.end(), v2.begin(), v1.begin(), std::plus<int>());
    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << delta.count() << "μs" << '\t';
}

void v_sum4th(std::vector<int>& v1, std::vector<int>& v2) {
#pragma warning(push)
#pragma warning(disable:4552)
#pragma warning(disable:4267)
    auto start = std::chrono::steady_clock::now();

    int quarter = v1.size() / 4;

    std::thread th1([&]() {
        for (int i = 0; i < quarter; ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
    });

    std::thread th2([&]() {
        for (int i = (quarter + 1); i < (quarter * 2); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th3([&]() {
        for (int i = ((quarter * 2) + 1); i < (v1.size() - quarter); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th4([&]() {
        for (int i = ((v1.size() - quarter) + 1); i < v1.size(); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    
    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << delta.count() << "μs" << '\t';
#pragma warning(pop)
}

void v_sum8th(std::vector<int>& v1, std::vector<int>& v2) {
#pragma warning(push)
#pragma warning(disable:4267)

    auto start = std::chrono::steady_clock::now();

    int one_8 = v1.size() / 8;

    std::thread th1([&]() {
        for (int i = 0; i < one_8; ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th2([&]() {
        for (int i = (one_8 + 1); i < (one_8 * 2); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th3([&]() {
        for (int i = ((one_8 * 2) + 1); i < (one_8 * 3); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th4([&]() {
        for (int i = ((one_8 * 3) + 1); i < (one_8 * 4); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th5([&]() {
        for (int i = ((one_8 * 4) + 1); i < (one_8 * 5); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th6([&]() {
        for (int i = ((one_8 * 5) + 1); i < (one_8 * 6); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th7([&]() {
        for (int i = ((one_8 * 6) + 1); i < (one_8 * 7); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th8([&]() {
        for (int i = ((one_8 * 7) + 1); i < v1.size(); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();

    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << delta.count() << "μs" << '\t';

#pragma warning(pop)
}

void v_sum16th(std::vector<int>& v1, std::vector<int>& v2) {
#pragma warning(push)
#pragma warning(disable:4267)

    auto start = std::chrono::steady_clock::now();

    int one_16 = v1.size() / 16;

    std::thread th1([&]() {
        for (int i = 0; i < one_16; ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th2([&]() {
        for (int i = (one_16 + 1); i < (one_16 * 2); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th3([&]() {
        for (int i = ((one_16 * 2) + 1); i < (one_16 * 3); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th4([&]() {
        for (int i = ((one_16 * 3) + 1); i < (one_16 * 4); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th5([&]() {
        for (int i = ((one_16 * 4) + 1); i < (one_16 * 5); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th6([&]() {
        for (int i = ((one_16 * 5) + 1); i < (one_16 * 6); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th7([&]() {
        for (int i = ((one_16 * 6) + 1); i < (one_16 * 7); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th8([&]() {
        for (int i = ((one_16 * 7) + 1); i < (v1.size() / 2); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th9([&]() {
        for (int i = ((v1.size() / 2) + 1); i < (one_16 * 9); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th10([&]() {
        for (int i = ((one_16 * 9) + 1); i < (one_16 * 10); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th11([&]() {
        for (int i = ((one_16 * 10) + 1); i < (one_16 * 11); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th12([&]() {
        for (int i = ((one_16 * 11) + 1); i < (one_16 * 12); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th13([&]() {
        for (int i = ((one_16 * 12) + 1); i < (one_16 * 13); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th14([&]() {
        for (int i = ((one_16 * 13) + 1); i < (one_16 * 14); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th15([&]() {
        for (int i = ((one_16 * 14) + 1); i < (one_16 * 15); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });

    std::thread th16([&]() {
        for (int i = ((one_16 * 15) + 1); i < v1.size(); ++i)
        {
            v1[i] = v1[i] + v2[i];
        }
        });


    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();
    th11.join();
    th12.join();
    th13.join();
    th14.join();
    th15.join();
    th16.join();

    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << delta.count() << "μs" << '\t';

#pragma warning(pop)
}