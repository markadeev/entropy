#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
	// read the file provided in argv[1] into inputfile
	ifstream inputfile(argv[1], ios::binary);
	// check if the file is opened
	if (!inputfile.is_open()){
		cout << "Failed to open file.\nUse ./entropy file.txt or ./entropy /root/Downloads/1.jpg" << endl;
		return 1;
	}
	// fill the vector with bytes from inputfile
	// unsigned char is treated as raw binary data
	vector<unsigned char> buffer(istreambuf_iterator<char>(inputfile), {});
	int bufsize = buffer.size();
	inputfile.close();

	// create hashmap to count byte frequencies
	unordered_map<unsigned char, int> counts;
	for (auto c : buffer){
		counts[c]++;
	}

	double entropy = 0;
	// loop over every value in hashmap counts
	for (auto [key, value] : counts){
		// probability of this byte
		double p = (double)value / bufsize;
		// shannon entropy formula
		entropy -= p * log2(p);
	}

	cout << "Bytes: " << bufsize << endl;
	cout << "Entropy: " << entropy << endl;

	return 0;
}
