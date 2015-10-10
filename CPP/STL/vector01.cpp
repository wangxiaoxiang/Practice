
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  char a[26];
  for (char i = 0; i <26; i++) {
    a[i] = 'a'+i;
  }

  std::vector<char> vChar(a,a+26);

  size_t size = vChar.size();
  for (size_t i = 0; i < size; i++) {
    /* code */
    cout<<vChar[i]<<" ";
  }
  return 0;
}
