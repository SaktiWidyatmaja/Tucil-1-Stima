/* Kode untuk mengecek solusi yang ada */
int main() {
  for (int a = 0 ; a < 4 ; a++){
    for(int b = 0 ; b <4 ; b++) {
      if (b != a){
        for (int c = 0 ; c < 4 ; c++) {
          if ((c != a) && (c != b)) {
            for (int d = 0 ; d < 4 ; d++) {
              if ((d !=a ) && (d != b) && ( d!= c)){
                ArrNum[n][0] = Num[a]; ArrNum[n][1] = Num[b];
                ArrNum[n][2] = Num[c]; ArrNum[n][3] = Num[d]; IsExist = false;
                for (int f = 0 ; f < n ; f++) {
                  for (int g = 0 ; g < 4 ; g++) {
                    if (g < 3) {
                      if (ArrNum[f][g] != ArrNum[n][g]) break;
                    } else {
                      if (ArrNum[f][g] == ArrNum[n][g]) IsExist = true;
                    }
                  }
                  if (IsExist == true) break;
                }

                if (IsExist == false ) {
                  n++;
                  for (int i = 0 ; i < 4 ; i++) { // Operator pertama
                    for (int j = 0 ; j < 4 ; j++) { // Operator kedua
                      for (int k = 0; k < 4 ; k++) { // Operator ketiga
                      /* Fungsi untuk mengatasi semua kemungkinan bracket (5 kemungkinan) */
                        if (fabs(OpFunc(Op[k], (OpFunc(Op[j], (OpFunc(Op[i],Num[a], Num[b])), Num[c])), Num[d]) -Hasil) <= EPS) { // ((n0 op0 n1) op1 n2) op2 d3
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[k], (OpFunc( Op[i], Num[a], (OpFunc(Op[j],Num[b], Num[c])) ) ) , Num[d])- Hasil) <= EPS) { // (n0 op0 (n1 op1 n2)) op2 d3
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[j],OpFunc(Op[i], Num[a], Num[b]), OpFunc(Op[k], Num[c], Num[d])) - Hasil ) <= EPS) { // (n0 op0 n1) op1 (n2 op2 n3)
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[k],OpFunc(Op[j],Num[b],Num[c]), Num[d])) - Hasil) <= EPS) { // n0 op0 ((n1 op1 n2) op2 n3)
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[j],Num[b],OpFunc(Op[k], Num[c],Num[d]))) - Hasil) <= EPS) { // n0 op0 (n1 op1 (n2 op2 n3))
                          solusiCounter++; 
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

double OpFunc (char op, double a, double b) { 
/* Fungsi empat operator aritmatika aritmatika */
  if (op == '+') return (double)a+b;
  else if (op == '-') return (double)a-b;
  else if (op == '/') { if (b != 0) return (double)a/b;}
  else if (op == '*') return (double)a*b;
}
 