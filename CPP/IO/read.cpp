#include <iostream>
#include <fstream>
using namespace std;

#define RBuffSize 1024
#define RKey 38

void encode(char* body,size_t size)
{
  for (size_t i = 0; i < size; i++) {

#if RKey
    *body++ ^= RKey;
#else
    ++*body++;
#endif
  }
}

void decode(char* body,size_t size)
{
  for (size_t i = 0; i < size; i++) {

#if RKey
    // *body = *body ^ RKey;
    // body++;
    *body++ ^= RKey;
#else
  --*body++;
#endif
  }
}

void print_encoded_file(const char* file_name)
{
  ifstream input_file(file_name);
  if (input_file.is_open())
  {
    char buff[RBuffSize];
    while (!input_file.eof()) {
      input_file.read(buff,sizeof(buff));
      decode(buff,input_file.gcount());
      cout<<buff;
    }
    cout<<endl;
    input_file.close();
  }else
  {
    cout<<"Open file failed."<<endl;
  }
}


int main(int argc, char const *argv[]) {
  //获取命令行中的参数
  if (argc != 3) {
    for (size_t i = 0; i < argc; i++) {
      cout<<*(argv++);
    }
    cout<<endl;
  }


  ifstream input_file(argv[1],ios::binary|ios::in);
  ofstream output_file(argv[2],ios::binary|ios::out);

  if (input_file.is_open()&&output_file.is_open())
  {
    char buff[RBuffSize];
    while (!input_file.eof()) {
      input_file.read(buff,sizeof(buff));
      encode(buff,input_file.gcount());
      output_file.write(buff,input_file.gcount());
    }

    input_file.close();
    output_file.close();

    print_encoded_file(argv[2]);
  }else
  {
      cout<<"Open file error!"<<endl;
  }

  return 0;
}
