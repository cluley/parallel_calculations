#include <iostream>
#include <thread>
#include <random>
#include <execution>

#include "v_sum.h"

int main() {
	std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << '\n' << std::endl;
	std::cout << "\t\t" << 1000 << '\t' << 10'000 << '\t' << 100'000 << '\t' << 1'000'000;
	
	for (int i = 1; i < 6; ++i) {
		switch (i)
		{
		case 1:
			std::cout << '\n' << i << " поток:\t";
			break;
		case 2:
			std::cout << '\n' << i << " потокa:\t";
			break;
		case 3:
			std::cout << '\n' << (i + 1) << " потока:\t";
			break;
		case 4:
			std::cout << '\n' << (i * 2) << " потоков:\t";
			break;
		case 5:
			std::cout << '\n' << (i + 11) << " потоков:\t";
			break;
		default:
			break;
		}
		
		size_t size = 100;

		while (size != 1'000'000) {
			size *= 10;

			std::vector<int> v1(size), v2(size);
			std::mt19937 gen;
			std::uniform_int_distribution<int> dist(0, 100);
			std::generate(v1.begin(), v1.end(), [&]() {
				return dist(gen);
				});
			std::generate(v2.begin(), v2.end(), [&]() {
				return dist(gen);
				});

			switch (i)
			{
			case 1:
				v_sum1th(v1, v2);
				break;
			case 2:
				v_sum2th(v1, v2);
				break;
			case 3:
				v_sum4th(v1, v2);
				break;
			case 4:
				v_sum8th(v1, v2);
				break;
			case 5:
				v_sum16th(v1, v2);
				break;
			default:
				break;
			}
		}
	}

	return 0;
}