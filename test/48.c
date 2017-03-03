#include <stdio.h>

typedef struct map
{
	int freq;
	int cnt;
} hash;

int dup_cnt;
hash dup[100];

int check_dup(int num)
{
	int i;

	for (i = 0; i < dup_cnt; i++)
		if (dup[i].freq == num)
			return i;

	return -1;
}

int find_kinds_freq(int *arr, int size)
{
	int i;

	/*
	1. 값을 넣고 
	2. 다음에 들어오는 값이 이전 값중 같은게 있다면
	3. cnt 를 증가시킨다.
	*/
	for (i = 0; i <= size; i++)
	{
		int dup_loc;
		if ((dup_loc = check_dup(arr[i])) != -1)
		{
			if (arr[i] == 1)
				printf("Here\n");
			dup[dup_loc].cnt++;
		}
		else
		{
			dup[dup_cnt].freq = arr[i];
			dup[dup_cnt].cnt++;
			dup_cnt++;
		}
	}
#if 0
	for (i = 1; arr[i]; i++)
	{
		for (j = 0; j < dup_cnt; j++)
		{
			if (dup[dup_cnt - 1].freq == arr[i])
			{
				dup[dup_cnt - 1].cnt++;
				break;
			}
			else
			{
				dup[dup_cnt].freq = arr[i];
				dup[dup_cnt].cnt = 1;
				dup_cnt++;
			}
		}		
	}
#endif

	return dup_cnt;
}

void print_arr(hash *arr)
{
	int i;

	for (i = 0; i < dup_cnt - 1; i++)
		printf("freq = %d, cnt = %d\n", arr[i].freq, arr[i].cnt);
	puts("");
}

void sort(hash *arr, int len)
{
	int i, j, key1, key2;

	for (i = 1; i < len - 1; i++)
	{
		key1 = arr[i].freq;
		key2 = arr[i].cnt;

		for (j = i - 1; arr[j].freq > key2 && j > -1; j--)
		{
			arr[j + 1].freq = arr[j].freq;
			arr[j + 1].cnt = arr[j].cnt;
		}

		arr[j + 1].freq = key1;
		arr[j + 1].cnt = key2;
	}
}

void print_many_freq(void)
{
	int i;

	for(i = dup_cnt - 2; i > dup_cnt - 5; i--)
		printf("dup[%d].freq = %d\n", i, dup[i].freq);
}

int main(void)
{
	int arr[] = {
		2400, 2400,   2400, 2400, 2400, 2400, 2400, 2400, 2400,  2400,
		2400, 2400,   2400, 2400, 2400, 2400, 2400, 2400, 2400,  2400,
		2400, 2400,   2400, 2400, 2400, 2400, 2400, 2400, 5000,  5000,
		5000, 5000,   5000, 5000, 5000, 5000, 5000, 5000, 5000,  5000,
		5000, 5000,   5000, 5000, 5000, 5000, 5000, 5000, 5000,  5000,
		5000, 5000,   5000, 5000, 5000, 5000, 5000, 5000, 5000,  5000,
		5000, 5000,   5000, 5000, 500,  500,  500,  500,  500,   500,
		500,  500,    500,  500,  500,  500,  500,  500,  500,   500,
		500,  500,    500,  500,  500,  500,  500,  500,  1,     2,
		3,    4,      5,    6,    7,    8,    9,    10,   11,    12,
		13,   14,     15,   16,   17,   18,   234,  345,  26023, 346,
		345,  234,    457,  3,    1224, 34,   646,  732,  5,     4467,
		45,   623,    4,    356,  45,   6,    123,  3245, 6567,  234,
		567,  6789,   123,  2334, 345,  4576, 678,  789,  1000,  978,
		456,  234756, 234,  4564, 3243, 876,  645,  534,  423,   312,
		756,  235 ,   75678
	};

	int size = sizeof(arr) / sizeof(int);
	printf("size = %d\n", size);

	hash *map_arr = NULL;

	size = find_kinds_freq(arr, size);
	printf("dup_cnt = %u\n", dup_cnt);
	print_arr(dup);

	sort(dup, size);
	print_arr(dup);

	print_many_freq();

	return 0;
}
