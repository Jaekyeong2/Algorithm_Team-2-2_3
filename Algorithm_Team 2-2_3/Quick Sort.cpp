/*
프로그램설명: 파일을 이용한 퀵정렬 구현
개발자: 소예찬(202010754)
실습일: 2023-05-05
*/
#include <stdio.h>
#define MAX_SIZE_ARRAY 10
void swap(int* px, int* py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}
void print(int arr[], int start, int end)
{
	int i;
	for (i = start; i < end; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void Read_File(int array[], int size)
{
	int i, num;
	FILE* fp = NULL;
	fp = fopen("data.txt", "r"); //읽기용 파일 열기 

	if (fp == NULL)
		printf("파일열기 실패");

	for (i = 0; i < size; i++)
	{
		if (fscanf(fp, "%d", &num) == 1) // 파일에서 정수 읽기
		{
			array[i] = num;
		}
		else
		{
			printf("읽기 실패\n");
			break;
		}
	}

	printf("파일읽기 성공!\n");

	fclose(fp);
}
void Copy_File(int array[], int size)
{
	int i;
	FILE* fp = NULL;
	fp = fopen("result.txt", "w"); //쓰기용 파일열기 

	if (fp == NULL)
		printf("파일열기 실패");

	for (i = 0; i < size; i++) 	// 배열의 값을 파일에 저장
		fprintf(fp, "%d ", array[i]);

	printf("파일복사 성공!\n");

	fclose(fp);
}
int Quick_Sort(int array[], int left, int right)
{
	if (left < right) {
		int pivot = array[left]; //처음 인덱스를 피봇으로 설정 
		int i = left;
		int j = right + 1;		//do while을 통해 시작부터 1감소시키므로 1을 더해준다. 

		print(array, left, right + 1);

		while (1)
		{
			do {
				i++;
			} while (array[i] < pivot && i <= right);	//피봇보다 큰 수를 만나면 해당 인덱스에서 정지 

			do {
				j--;
			} while (array[j] > pivot && j >= left + 1);	//피봇보다 작은 수를 만나면 해당 인덱스에서 정지 

			if (i >= j)		//배열의 앞탐색과 뒷탐색이 엇갈릴경우 중지 
				break;

			swap(&array[i], &array[j]);	//작은 값은 앞으로, 큰수는 뒤로 교환
			print(array, left, right + 1);
		}

		swap(&array[left], &array[j]);	//작은수와 피봇의 위치 교환 
		print(array, left, right + 1);

		Quick_Sort(array, left, j - 1);		//좌측부터 피봇 전 값까지 
		Quick_Sort(array, j + 1, right);	//피봇 다음 인덱스부터 배열의 우측까지 
	}
}


int main(void)
{
	int array[MAX_SIZE_ARRAY] = { 0 };

	Read_File(array, MAX_SIZE_ARRAY);
	Quick_Sort(array, 0, MAX_SIZE_ARRAY - 1);
	Copy_File(array, MAX_SIZE_ARRAY);
	print(array, 0, MAX_SIZE_ARRAY);

	return 0;
}