// Core of a search system.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <map>


using namespace std;
int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
	string text;
	getline(cin, text);
	return text;
}

int ReadLineWithNumber() {
	int result = 0;
	cin >> result;
	ReadLine();
	return result;
}

vector<string> SplitIntoWords(const string& text) {
	vector<string> words;
	string word;
	for (const char c : text) {
		if (c == ' ') {
			if (!word.empty()) {
				words.push_back(word);
				word.clear();
			}
		}
		else {
			word += c;
		}
	}
	if (!word.empty()) {
		words.push_back(word);
	}
	return words;
}

set<string> ParseStopWords(const string& text) {
	set<string> stop_words;
	for (const string& word : SplitIntoWords(text)) {
		stop_words.insert(word);
	}
	return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
	vector<string> words;
	for (const string& word : SplitIntoWords(text)) {
		if (stop_words.count(word) == 0) {
			words.push_back(word);
		}
	}
	return words;
}

void AddDocument(vector<vector<string>>& documents, const set<string>& stop_words, const string& document) {
	const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
	documents.push_back(words);
}

set<string> ParseQuery(const string& text, const set<string>& stop_words) {
	set<string> query_words;
	for (const string word : SplitIntoWordsNoStop(text, stop_words)) {
			query_words.insert(word);
	}
	return query_words; // для задания
}

bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
	for (const string word : document_words) {
		if (query_words.count(word) != 0) {
			return true;
			break;
		}
	}
	return false;
}

vector<pair<int, int>> FindAllDocuments(const )

int main()
{
	const string stop_words_joined = ReadLine();
	const set<string> stop_words = ParseStopWords(stop_words_joined);

	// Read documents
	vector<vector<string>> documents;
	const int document_count = ReadLineWithNumber();
	for (int document_id = 0; document_id < document_count; ++document_id) {
		AddDocument(documents, stop_words, ReadLine());
	}

	const string query = ReadLine();
	for (const int document_id : FindDocuments(documents, stop_words, query)) {
		cout << "{ document_id = "s << document_id << " }"s << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
