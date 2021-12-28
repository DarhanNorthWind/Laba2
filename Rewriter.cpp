#include "Rewriter.h"

#define D " ,:;"
#define E ".!?"
Rewriter::Rewriter()
{
	string path = "Text.txt", line = "",str = "";
	ifstream f;
	f.open(path);

	if (f.is_open()) {


		while (getline(f, line, '\0'))
		{
			 str+= chek(line);
			 
		}
		f.close();
		cout << str;
	}
	else
		cout << "file not oped\n";


}

string Rewriter::chek(string line)
{
	bool flag = false;
	int i = 0, pos1 = 0, pos2 = 0, pos1w = 0, pos2w = 0, cntNum = 0;
	char c, prev;
	string wrd = "", out = "",num = "0123456789";
	while (line[i] != '\0') {
		c = line[i];
		if (c == D[0] || c == D[1] || c == D[2] || c == D[3]
			|| c == D[4] || c == E[0]
			|| c == E[1] || c == E[2]) {
			prev = line[i - 1];
			//найден разделитель


			if (prev != D[0] && prev != D[1] && prev != D[2] && prev != D[3]
				&& prev != D[4]
				&& prev != E[0] && prev != E[1] && prev != E[2]) {
				//предыдущий символ не разделитель


				if (c == D[0] || c == D[1] || c == D[2] || c == D[3]
					|| c == D[4] || c == E[0] || c == E[1] || c == E[2]) {
					pos2w = i;
					wrd = line.substr(pos1w, pos2w - pos1w);
					if ("1" == wrd|| "2" == wrd || "3" == wrd || "4" == wrd || "5" == wrd || "6" == wrd || "7" == wrd 
						||"9"==wrd||"8"==wrd||"0"==wrd)
						flag = true;

				}
				if (c == E[0] || c == E[1] || c == E[2]) {
					pos2 = i;
					if (flag) {//тут прозведём замену цифр на текст
						string buffer = line.substr(pos1, pos2 - pos1 + 1) + "\n";
						//произвести подсчёт цифр в строке и заменить их в на слова
						int j = 0;
						while (buffer[j] != '\n') {
							if ('1' == buffer[j] || '2' == buffer[j] || '3' == buffer[j] || '4' == buffer[j] || '5' == buffer[j] || '6' == buffer[j] || '7' == buffer[j]
								|| '8' == buffer[j] || '9' == buffer[j] || '0' == buffer[j])
								cntNum++;
							j++;
						}
						for (int i = 0; i < cntNum; i++) {
							if (buffer.find("1") != -1) { buffer.replace(buffer.find("1"), 1, "один"); }
							else if (buffer.find("2") != -1) { buffer.replace(buffer.find("2"), 1, "два"); }
							else if (buffer.find("3") != -1) { buffer.replace(buffer.find("3"), 1, "три"); }
							else if (buffer.find("4") != -1) { buffer.replace(buffer.find("4"), 1, "четыре"); }
							else if (buffer.find("5") != -1) { buffer.replace(buffer.find("5"), 1, "пять"); }
							else if (buffer.find("6") != -1) { buffer.replace(buffer.find("6"), 1, "шесть"); }
							else if (buffer.find("7") != -1) { buffer.replace(buffer.find("7"), 1, "семь"); }
							else if (buffer.find("8") != -1) { buffer.replace(buffer.find("8"), 1, "восемь"); }
							else if (buffer.find("9") != -1) { buffer.replace(buffer.find("9"), 1, "девять"); }
							else if (buffer.find("0") != -1) { buffer.replace(buffer.find("0"), 1, "ноль"); }
						}
						out += buffer;
						flag = false;
					}
					else {
						out += line.substr(pos1, pos2 - pos1 + 1) + "\n";
					}
				}

			}

		}
		else {

			if (i != 0) {
				if (line[i - 1] == D[0] || line[i - 1] == D[1] || line[i - 1] == D[2] || line[i - 1] == D[3]
					|| line[i - 1] == D[4] || line[i - 1] == E[0] || line[i - 1] == E[1] || line[i - 1] == E[2]) {
					pos2w = i;
					pos1w = i;
				}
				if (i >= 2) {
					if ((line[i - 1] == D[0] || line[i - 1] == D[1] || line[i - 1] == D[2] || line[i - 1] == D[3]
						|| line[i - 1] == D[4] || line[i - 1] == '\n' || line[i - 1] == E[0] || line[i - 1] == E[1] || line[i - 1] == E[2]) && (line[i - 2] == E[0]
							|| line[i - 2] == E[1] || line[i - 2] == E[2])) {

						pos2 = i;
						pos1 = i;
						pos2w = i;
						pos1w = i;

					}
				}
			}

		}
		i++;
	}
	
	return string(out);
}
