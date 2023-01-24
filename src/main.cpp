#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace std::chrono;

void checkExist(string expression, vector<string>& solutions) {
  // Prosedur untuk mengecek apakah solusi sudah pernah muncul sebelumnya
  // Jika sudah pernah muncul maka solusi tidak akan dianggap

  for (int i=0; i<solutions.size(); i++) {
    if (solutions[i] == expression) {
      return;
    }
  }

  solutions.push_back(expression);
  return;
}

void checkSolution(int num, string expression,vector<string>& solutions) {
  // Prosedur untuk mengetahui apakah hasil kombinasi 4 kartu merupakan solusi atau bukan
  // Dan menentukan apakah solusi sudah pernah muncul atau belum

  if (num == 24)
    checkExist(expression, solutions);
} 

void printSolution(vector<string> solutions) {
  // Prosedur untuk mencetak solusi ke layar

  if (solutions.size() == 0) {
    cout << "Tidak ada solusi\n";
  } else {
    cout << "Jumlah solusi: " << solutions.size() << "\n";
    for (int i=0; i < solutions.size(); i++) {
      cout << solutions[i] << "\n";
    }
  }
}

int operation (int x, int y, char opr) {
  // Fungsi untuk melakukan operasi aritmetika berdasarkan dua input angka dan satu karakter sebagai operator

  if (opr == '+') {
    return  x+y;
  } else if (opr == '-') {
    return  x-y;
  } else if (opr == '/') {
    return  x/y;
  } else if (opr == '*') {
    return  x*y;
  } else return 0;
}

string convertToString(char* buffer) {
  // Fungsi untuk mengonversi array of character ke string

  string str = buffer;
  return str;
}

void saveToFile(vector<string> solutions) {
  // Prosedur untuk menyimpan solusi ke dalam file berdasarkan masukan pengguna

  // Kamus lokal
  string filename;

  // Algoritma
  cout << "Masukkan nama file output: ";
  cin >> filename;
  ofstream fout("../test/" + filename + ".txt");

  fout << "Jumlah solusi: " << solutions.size() << "\n";
  for (int i=0; i < solutions.size(); i++) {
    fout << solutions[i] << "\n";
  }

  fout.close();
  cout << "Output berhasil disimpan\n";
}

void charSplit(string input,  vector<int>& cards, bool &isRight) {
  int count = 0;

  for (int i=0; i < input.size(); i++) {
    if (input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || 
    input[i] == '7' || input[i] == '8' || input[i] == '9') {
      cards.push_back((int)input[i]-48);
      count++;

    } else if (input[i] == '1') {
      if (input[i+1] == '0') {
        cards.push_back(10);
        count++;
        i++;
      } else if (input[i+1] == ' ') {
        cout << "Untuk angka satu, masukkan huruf A!\n";
        cards.clear();
        return;
      } else {
        cout << "Masukkan angka dalam rentang 2-9\n";
      }
    } else if (input[i] == 'A') {
      cards.push_back(1);
      count++;
    } else if (input[i] == 'J') {
      cards.push_back(11);
      count++;
    } else if (input[i] == 'Q') {
      cards.push_back(12);
      count++;
    } else if (input[i] == 'K') {
      cards.push_back(13);
      count++;
    } else if (input[i] == ' ') {
    } else {
      cout << "Karakter masukan tidak benar, masukkan input dengan benar!\n";
      cards.clear();
      return;
    }

    if (count > 4) {
      cout << "Masukan terlalu banyak, masukkan 4 kartu\n";
      cards.clear();
      return;
    }
  }

  if (count < 4) {
    cout << "Masukan terlalu sedikit, masukkan 4 kartu\n";
    cards.clear();
    return;
  } else {
    isRight = true;
    cout << "Kartu anda adalah: ";
    for (int i=0; i<4; i++) {
      cout << cards[i] << " ";
    }
    return;
  }
}

int main() {

  // Kamus Lokal
  bool isRight = false;
  char inputChar;
  int input, card1, card2, card3, i, num;
  string expression;
  string cardString;
  char oprs[4] = {'+', '-', '*', '/'};
  char buffer[50];
  vector<int> cards;
  vector<string> solutions;
  
  // Input
  cout << "Pilih jenis input: (Ketikkan angkanya saja)\n";
  while (!isRight) {
    cout << "1. Manual\n2. Acak\n";
    cin >> input;

    if (input > 0 && input < 3) isRight = true;
    else cout << "Masukan salah, tolong masukkan angka 1 atau 2!\n";
  }

  isRight = false;
  if (input == 1) {
    // Input dari pengguna
    while (!isRight) {
      cout << "Masukkan 4 kartu: \n";
      cout << "<card 1> <card 2> <card 3> <card 4>\n";
      getline(cin >> ws, cardString);
      
      charSplit(cardString, cards, isRight);
      // isRight = true;
      // cout << cardString << "\n";
    }
  } else {
    // Input acak
    srand(time(0));

    cout << "Kartu anda adalah: ";
    for (i=0; i<4; i++) {
      card1 = rand() % 13 + 1;
      cards.push_back(card1);
      if (card1 == 1) {
        cout << "A ";      
      } else if (card1 == 11) {
        cout << "J ";      
      } else if (card1 == 12) {
        cout << "Q ";      
      } else if (card1 == 13) {
        cout << "K ";      
      } else {
        cout << card1 << " ";
      }
    }
    cout << "\n";
  }

  // Memulai perhitungan waktu algoritma bruteforce
  auto start = high_resolution_clock::now();

  for (i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++) {
        for (int l=0; l<4; l++) {
          card1 = cards[l];
          cards.erase(cards.begin()+l);
          
          for (int m=0; m<3; m++) {
          card2 = cards[m];
          cards.erase(cards.begin()+m);

            for (int n=0; n<2; n++) {
              card3 = cards[n];
              cards.erase(cards.begin()+n);

              // ((c0 op0 c1) op1 c2) op2 c3
              num = operation((operation(operation(card1, card2, oprs[i]), card3, oprs[j])), cards[0], oprs[k]);
              sprintf(buffer, "(( %d %c %d ) %c %d) %c %d", card1, oprs[i], card2, oprs[j], card3, oprs[k], cards[0]);
              expression = convertToString(buffer);
              checkSolution(num, expression, solutions);

              // (c0 op0 (c1 op1 c2)) op2 c3
              num = operation((operation(card1, operation(card2, card3, oprs[i]), oprs[j])), cards[0], oprs[k]);
              sprintf(buffer, "( %d %c ( %d %c %d )) %c %d", card1, oprs[i], card2, oprs[j], card3, oprs[k], cards[0]);
              expression = convertToString(buffer);
              checkSolution(num, expression, solutions);
              
              // c0 op0 ((c1 op1 c2) op2 c3)
              num = operation(card1, oprs[i], (operation(operation(card2, card3, oprs[j]), cards[0], oprs[k])));
              sprintf(buffer, "%d %c (( %d %c %d ) %c %d )", card1, oprs[i], card2, oprs[j], card3, oprs[k], cards[0]);
              expression = convertToString(buffer);
              checkSolution(num, expression, solutions);
              
              // c0 op0 (c1 op1 (c2 op2 c3))
              num = operation(card1, oprs[i], (operation(card2, operation(card3, cards[0], oprs[j]), oprs[k])));
              sprintf(buffer, "%d %c ( %d %c ( %d %c %d ))", card1, oprs[i], card2, oprs[j], card3, oprs[k], cards[0]);
              expression = convertToString(buffer);
              checkSolution(num, expression, solutions);
              
              // ((c0 op0 c1) op1 (c2 op2 c3)
              num = operation((operation(card1, card2, oprs[i])), (operation(card3, cards[0], oprs[j])), oprs[j]);
              sprintf(buffer, "( %d %c %d ) %c ( %d %c %d )", card1, oprs[i], card2, oprs[j], card3, oprs[k], cards[0]);
              expression = convertToString(buffer);
              checkSolution(num, expression, solutions);

              cards.insert(cards.begin()+n, card3);
            }
            cards.insert(cards.begin()+m, card2);
          }      
          cards.insert(cards.begin()+l, card1);
        }
      }
    }
  }

  // Mencatat waktu algoritma bruteforce selesai
  auto stop = high_resolution_clock::now();

  // Menghitung durasi yang diperlukan dalam algoritma bruteforce;
  auto duration = duration_cast<microseconds>(stop - start);
  
  printSolution(solutions);
  cout << "Waktu eksekusi bruteforce: "
      << duration.count() << " microseconds" << endl;

  // Output ke file
  cout << "Apakah solusi ingin disimpan dalam file? (y/n)\n";
  while (true) {
    cin >> inputChar;
    if (inputChar == 'y') {
      saveToFile(solutions);
      return 0;
    } else if (inputChar == 'n') {
      return 0;
    } 

    cout << "Masukan salah, masukkan huruf y atau n\n";
  }
  
}