#include"SDLL.h"
Hangman::Hangman() {
	answer_render = new Text("zh-cn.ttf", 30);
	badGuessCount = 0;
	just_started = false;
	indicator = 0;
}
void Hangman::nhaptudien(const char* file) { // ham truyen file tu can doan vao vector tu dien
	tudien.clear();
	ifstream motep;
	motep.open(file);
	string a;
	while (!motep.eof()) {
		motep >> a;
		tudien.push_back(a);
	}
	motep.close();
}
void Hangman::khoitaotu() { // ham random mot tu trong danh sach tudien

	srand(static_cast<unsigned int>(time(0))); // random mot tu khac moi lan compile
	int random_number = 0;
	if (this->diff == 1) {
		random_number = rand() % 10;
	}
	if (this->diff == 2) {
		random_number = (rand() % 20) + 10;
	}
	if (this->diff == 3) {
		random_number = (rand() % 19) + 30;
	}
	string tucantim(tudien[random_number].size(), '-'); // khoi tao tu can tim gom nhung ki tu '-'
	chosedWord = tudien[random_number];  // dap an
	for (int i = 0; i < chosedWord.size(); i++) {
		if (chosedWord[i] == '_') {
			tucantim[i] = '_';
		}
	}
	answer = tucantim;
	cout << chosedWord << endl;
}
void Hangman::hint() {
	if (!find_hint) {
		cout << "hello" << endl;
		int dem = 0;
		vector<int> unknown;
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == '-') {
				dem++;
				unknown.push_back(i);
			}
		}
		cout << dem << endl;
		srand(static_cast<unsigned int>(time(0)));
		if (badGuessCount == 5 && dem > 1) {
			int random = rand() % unknown.size();
			//cout << random;
			Hin = chosedWord[unknown[random]];
		}
		cout << Hin;
		find_hint = true;
	}
}
void Hangman::draw(const string& file, int font_size,int x, int y , int z) {
	answer_render->draw(file, font_size,x,y,z);
}
void Hangman::update(char e) {
	if (chosedWord.find(e) != string::npos) {
		for (int i = 0; i < answer.size(); i++) {
			if (chosedWord[i] == e) {
				answer[i] = e; // thay doi nhung ki tu - thanh ki tu vua nhap
			}
		}
	}
	else {
		badGuessCount++;
	}
	cout << badGuessCount << endl;
	cout << answer;
	if (answer.find('-') == string::npos) {
		fully_answered = true;
		if (fully_answered) {
			cout << "cc" << endl;
		}
	}
	if (badGuessCount == 7) {
		fully_answered = true;
		cout << "cc" << endl;
	}
}
void Hangman::set_high_score() {
	ofstream link;
	link.open("Highsore.txt", ios::app);
	link << player_name << endl;
	link.close();
	ofstream file;
	file.open("time.txt", ios::app);
	file << time_wasted << endl;
	file.close();
}
void Hangman::sort_high_score() {
	time_played_list.clear();
	player_name_list.clear();
	ifstream link_1, link_2;
	link_1.open("Highsore.txt");
	while (!link_1.eof()) {
		string x;
		link_1 >> x;
		player_name_list.push_back(x);
	}
	link_2.open("time.txt");
	while (!link_2.eof()) {
		int y;
		link_2 >> y;
		time_played_list.push_back(y);
	}
	for (int i = 0; i < player_name_list.size(); i++) {
		for (int j = i + 1; j < player_name_list.size(); j++) {
			if (time_played_list[i] >= time_played_list[j]) {
				swap(time_played_list[i], time_played_list[j]);
				swap(player_name_list[i], player_name_list[j]);
			}
		}
	}
	/*for (int i = 0; i < player_name_list.size(); i++) {
		cout << player_name_list[i] << " " << time_played_list[i] << endl;
	}*/
}
void Hangman::reset() {
	badGuessCount = 0;
	just_started = false;
	khoitaotu();
	answer_render->name = answer;
	fully_answered = false;
	find_hint = false;
	indicator = 0;
	Hin.clear();
}