#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
	if (argc < 3)
		std::cout << "usage: xor <infile> <outfile> <integer(0-255)>" << std::endl;
	std::ifstream infile (argv[1], std::ios::binary);
	std::ofstream outfile (argv[2], std::ios::binary);
	char *memblock = new char;
	if (infile.is_open() && outfile.is_open()) {
		while (!infile.eof()) {
			infile.read(memblock, 1);
			*memblock ^= std::atoi(argv[3]);
			outfile.write(memblock, 1);
		}
		infile.close();
		outfile.close();
	}
	return 0;
}
