#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {
  string numStr1, numStr2;
  cin >> numStr1;
  cin >> numStr2;

  int max = numStr1.size() > numStr2.size() ? numStr1.size() : numStr2.size();

  int *pnum1 = new int[numStr1.size()];
  int *pnum2 = new int[numStr2.size()];
  int *presult = new int[max + 1];

  memset(pnum1, 0, sizeof(pnum1));
  memset(pnum2, 0, sizeof(pnum2));
  memset(presult, 0, sizeof(presult));

  int j = 0;

  for (int i = numStr1.size() - 1; i >= 0; i--) {
    if (!isdigit(numStr1[i])) {
      cout << "Input error!" << endl;
      exit(1);
    } else {
      pnum1[j++] = numStr1[i] - '0';
    }
  }

  j = 0;

  for (int i = numStr2.size() - 1; i >= 0; i--) {
    if (!isdigit(numStr2[i])) {
      cout << "Input error!" << endl;
      exit(1);
    } else {
      pnum2[j++] = numStr2[i] - '0';
    }
  }

  for (int i = 0; i < max; i++) {
    if (i < numStr1.size() && i < numStr2.size()) {
      presult[i] = presult[i] + pnum1[i] + pnum2[i];
    } else if (i >= numStr2.size() ) {
      presult[i] = presult[i] + pnum1[i];
    } else {
      presult[i] = presult[i] + pnum2[i];
    }

    if (presult[i] > 9) {
      presult[i] -= 10;
      presult[i+1]++;
    }
  }

  bool flag = false;
  for (int i = max; i >= 0; i--) {
    if (flag) {
      cout << presult[i];
    } else if (presult[i]) {
      cout << presult[i];
      flag = true;
    }
  }

  cout << endl;
  return 0;
}
