#include <iostream>
#include <algorithm>
using namespace std;

void PrintNumberSet(int set[], int size) {	// Function for printing out the given Array of data
	for (int i = 0; i < size - 1; i++) {
		cout << set[i] << ", ";
	}
	cout << set[size - 1] << endl;
}

class Word {
private:
	string word;
	int score;
public:
	Word() {
		word = "empty";
		score = rand() % 200;
	}

	Word(string word) : word(word) {
		score = rand() % 200;
	}

	Word(string word, int score) : word(word), score(score) {}

	friend bool operator<(const Word& word1, const Word& word2) {	// Overloaded '<' Operator Funciton used by sort to display Objects in ascending order numerically
		return word1.score < word2.score;
	}

	friend bool WordCompare(const Word& word1, const Word& word2);	// initializes the friend Function
	friend bool ScoreCompare(const Word& word1, const Word& word2);

	string GetWord() {
		return word;
	}

	int GetScore() {
		return score;
	}
};

void PrintSet(Word set[], int size) {
	for (int i = 0; i < size; i++) {
		cout << set[i].GetWord() << "(" << set[i].GetScore() << ") ";
	}
	cout << endl;
}

bool WordCompare(const Word& word1, const Word& word2) {	// Function used by sort to display Objects in ascending order alphabetically
	return word1.word < word2.word;
}

bool ScoreCompare(const Word& word1, const Word& word2) {	// Function used by sort to deal with duplicate Objects
	if (word1.word == word2.word) {
		return word1.score < word2.score;
	}
	else {
		return word1.word < word1.word;
	}
}

class Ant {
private:
	string name;
	int workload;
public:
	Ant(string name, int workload) : name(name), workload(workload) {}	// Default Constructor
	
	friend ostream& operator<<(ostream& out, const Ant ant) {	// Overloaded Insertion Operator for ease of printing Objects
		out << ant.name << " (" << ant.workload << ") ";
		return out;
	}

	friend Ant operator+(const Ant ant1, const Ant ant2) {	// Overloaded Addition Operator for adding Variables using Template
		return Ant(ant1.name + ", " + ant2.name, ant1.workload + ant2.workload);
	}
};

template <typename T> // 'T' is the placeholder Variable similar to 'i' in an Iteration Loop
T add(T a, T b) {	// add Function that works with almost any Object
	return a + b;
}

int main()
{
	const int size = 10;
	int numbers[] = { 6, 2, 4, 3, 10, 1, 7, 9, 8, 5 };
	sort(numbers, numbers + size);	// sorts numbers in decending order
	PrintNumberSet(numbers, size);	// calls print Function

	Word words[] = { Word("Banana"), Word("Apple"), Word("Grape"), Word("Orange"), Word("Cherry"), Word("DragonFruit"), Word("Mango"), Word("Pineapple"), Word("Watermelon"), Word("Strawberry") };
	sort(words, words + size);	// sorts by score
	PrintSet(words, size);
	sort(words, words + size, WordCompare);	// sorts by word
	PrintSet(words, size);

	Word words1[] = { Word("Banana"), Word("Apple"), Word("Banana"), Word("Apple"), Word("Banana"), Word("Apple"), Word("Banana"), Word("Cherry"), Word("Cherry"), Word("Banana") };
	sort(words1, words1 + size, WordCompare);
	sort(words1, words1 + size, ScoreCompare);	// handles duplicates
	PrintSet(words1, size);

	cout << add(2, 3) << endl;
	cout << add(4.5, 8.9) << endl;
	Ant worker("worker", 15);
	Ant soldier("soldier", 10);
	cout << add(worker, soldier) << endl;
	cout << add('a', 'c') << endl;
}
