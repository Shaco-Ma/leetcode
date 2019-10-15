/*
    看答案得到的启发,用hashmap,假设是128字符的assii字符,提前设定hashmap大小128
    把s中的每个字符的后一个地址给为当前字符的下一个地址(在s中的位置);
    当在hashmap中找到这个这个字符的时候,自动把字符串的起始位置给到下一个的起始位置;
    这样就找到了第一个无重复字符串的大小;
    然后从第一个重复的字符位置开始往后找,每次对比这个最大的值是否变化;
    看来滑动窗口适合找最大的字符串?
    其实能想到的就是遍历,查找一个无重复字符串,想到了hashmap,但是不知道该怎么存储,有了滑动窗口就明白了很多.
*/

#include <stdio.h>
#include <string.h>

#define MAX_NUM(a,b)        (a<b?b:a)
//假设是128的字符集
#define HASHMAP_SIZE        (128)

typedef struct _hashmap_
{
    char c;
    int addr;
}hashmap, *Phashmap;

void init_hashmap(Phashmap need_init, int map_len)
{
    int i = 0;
    if(need_init)
    {
        for(i=0;i<map_len;i++)
        {
            need_init[i].c = 0;
            need_init[i].addr = -1;
        }
    }
}

int get_hashmap(Phashmap map, unsigned char c)
{
    return map[c].addr;
}

void set_hashmap(Phashmap map, unsigned char c, int addr)
{
    map[c].addr = addr;
}

//>= 0在这里面
int is_inhashmap(Phashmap map, unsigned char c)
{
	//获取k值的方法,直接把c转化为相应的下标值,c一定>=0
	if(map)
	{
		return map[c].addr;
	}
	return 0;
}

int lengthOfLongestSubstring(char * s){
    int i = 0, j = 0;
	int ans = 0;
	int size = strlen(s);
    hashmap map[HASHMAP_SIZE];
    init_hashmap(map, HASHMAP_SIZE);
	for(j=0;j<size;j++)
	{
		if(is_inhashmap(map, s[j]))
		{
			i =	MAX_NUM(get_hashmap(map, s[j]), i);
		}
		ans = MAX_NUM(ans, j-i+1);
		set_hashmap(map, s[j], j+1);
	}

	return ans;
}

int main(void)
{
	//char *test_s = "abcabcbb";
	//char *test_s = "bbbbb";
	char *test_s = "pwwkew";
	int size = lengthOfLongestSubstring(test_s);
	printf("string :%s, size = %d\n", test_s, size);
}



