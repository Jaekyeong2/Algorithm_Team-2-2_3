/*
���α׷�����: ������ �̿��� ������ ����
������: �ҿ���(202010754)
�ǽ���: 2023-05-05
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
	fp = fopen("data.txt", "r"); //�б�� ���� ���� 

	if (fp == NULL)
		printf("���Ͽ��� ����");

	for (i = 0; i < size; i++)
	{
		if (fscanf(fp, "%d", &num) == 1) // ���Ͽ��� ���� �б�
		{
			array[i] = num;
		}
		else
		{
			printf("�б� ����\n");
			break;
		}
	}

	printf("�����б� ����!\n");

	fclose(fp);
}
void Copy_File(int array[], int size)
{
	int i;
	FILE* fp = NULL;
	fp = fopen("result.txt", "w"); //����� ���Ͽ��� 

	if (fp == NULL)
		printf("���Ͽ��� ����");

	for (i = 0; i < size; i++) 	// �迭�� ���� ���Ͽ� ����
		fprintf(fp, "%d ", array[i]);

	printf("���Ϻ��� ����!\n");

	fclose(fp);
}
int Quick_Sort(int array[], int left, int right)
{
	if (left < right) {
		int pivot = array[left]; //ó�� �ε����� �Ǻ����� ���� 
		int i = left;
		int j = right + 1;		//do while�� ���� ���ۺ��� 1���ҽ�Ű�Ƿ� 1�� �����ش�. 

		print(array, left, right + 1);

		while (1)
		{
			do {
				i++;
			} while (array[i] < pivot && i <= right);	//�Ǻ����� ū ���� ������ �ش� �ε������� ���� 

			do {
				j--;
			} while (array[j] > pivot && j >= left + 1);	//�Ǻ����� ���� ���� ������ �ش� �ε������� ���� 

			if (i >= j)		//�迭�� ��Ž���� ��Ž���� ��������� ���� 
				break;

			swap(&array[i], &array[j]);	//���� ���� ������, ū���� �ڷ� ��ȯ
			print(array, left, right + 1);
		}

		swap(&array[left], &array[j]);	//�������� �Ǻ��� ��ġ ��ȯ 
		print(array, left, right + 1);

		Quick_Sort(array, left, j - 1);		//�������� �Ǻ� �� ������ 
		Quick_Sort(array, j + 1, right);	//�Ǻ� ���� �ε������� �迭�� �������� 
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