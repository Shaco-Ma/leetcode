/*
        kmp算法是匹配字符串的,这里不适用
        假设最大长度是1000
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

/*template <typename T>
const T& get_min(const T &t1, const T &t2)
{
        return t1<t2?t1:t2;
}*/

class Solution {
 public:
  ~Solution();
  string Longest(string s);

 private:
  int get_string_array(int[], const string &, int);
  int *get_array = nullptr;
  string ret_s;
  string *s_add = nullptr;
};

Solution::~Solution() {
  if (s_add != nullptr) {
    delete s_add;
  }
  if (get_array != nullptr) {
    delete[] get_array;
  }
}

//长度和 base_s 一样,最后的是base_s的长度
//返回最长回文的pos
int Solution::get_string_array(int array_in[], const string &base_s,
                               int string_len) {
  // int max_len = 0;
  int i = 0;
  //指向最大回文的最右端
  int max = 0;
  //最大回文的中间点
  int pos = 0;
  cout << "string_len: " << string_len << endl;

  for (i = 1; i < string_len; i++) {
    //得到改为的基础值,最少为1,因为有#
    if (i < max) {
      array_in[i] = min(array_in[2 * pos - 1], max - i);
    } else
      array_in[i] = 1;

    //开始从此位开始,往两边扩展,查找回文
    while (base_s.at(i - array_in[i]) == base_s.at(i + array_in[i])) {
      array_in[i]++;
    }
	cout << "array_in["<<i<<"] = " << array_in[i] << endl;

    //更新max和pos
    if (array_in[i] > max) {
      //得到最大回文的最右边
      max = array_in[i];
      pos = i;
    }
	cout << endl;
    // max_len = std::max(max_len, array_in[i] - 1);
  }

  // return max_len;
  return pos;
}

string Solution::Longest(string s) {
  int i = 0;
  int len_s_add = 2;
  int len_s = s.size();
  int pos = 0;
  if (s_add != nullptr) {
    delete s_add;
  }
  if (len_s < 2) {
    return s;
  }
  for (i = 0; i < len_s; ++i) {
    len_s_add += 2;
  }
  s_add = new string;
  get_array = new int[len_s_add]();

  s_add->push_back('$');
  s_add->push_back('#');
  for (i = 0; i < len_s; i++) {
    s_add->push_back(s.at(i));
    s_add->push_back('#');
  }
  s_add->push_back('\0');
  cout << *s_add << endl;

  pos = get_string_array(get_array, *s_add, len_s_add);

  for (i = 0; i < len_s_add; i++) {
    cout << get_array[i] << "  ";
  }
  cout << endl;

  //真实长度
  len_s = get_array[pos] - 1;
  cout << "len_s = " << len_s << endl;
  cout << "pos = " << pos << endl;
  //真实位置
  pos = pos / 2 - 1;
  //真实开始位置
  pos = pos - (len_s - 1) / 2;
  cout << "pos = " << pos << endl;

  for (i = 0; i < len_s; i++) {
    ret_s.push_back(s.at(pos + i));
  }
  cout << ret_s << endl;

  return ret_s;
}

int main(void) {
  //			 $#b#a#b#d#a#
  //string base_s("ac");
  string base_s("babda");
  Solution Long_substring;
  Long_substring.Longest(base_s);
  return EXIT_SUCCESS;
}
