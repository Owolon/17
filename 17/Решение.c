#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#define XMIN -100
#define XMAX 123
int sort_buble(int* ptrarr, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (ptrarr[j - 1] > ptrarr[j])
			{
				temp = ptrarr[j - 1];
				ptrarr[j - 1] = ptrarr[j];
				ptrarr[j] = temp;
			}
		}
	}
	return ptrarr;
}
int sort_select(int* ptrarr, int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		int imax = i;
		for (int j = i + 1; j < n;)
		{
			if (ptrarr[i] > ptrarr[imax])
			{
				imax = i;
			}
			temp = ptrarr[i];
			ptrarr[i] = ptrarr[imax];
			ptrarr[imax] = temp;
		}
	}
	return ptrarr;
}
int sort_insert(int* ptrarr, int n)
{
	int temp, j;
	for (int i = 1; i < n - 1; i++)
	{
		temp = ptrarr[i];
		j = i;
		if (ptrarr[j-1] > temp && j>0)
		{
			ptrarr[j] = ptrarr[j - 1];
			j = j - 1;
		}
		ptrarr[j] = temp;
	}
	return ptrarr;
}
int sort_fust_shell(int* ptrarr, int n)
{
	int j,temp;
	for (int h = n/2; h > 0; h/=2)
	{
		for (int k = 0; k < h; k++)
		{
			for (int i = 0; i < n/h; i++)
			{
				j = i;
				while ((j > 0) && ptrarr[j * h + k] < ptrarr[(j - 1) * h + k])
				{
					temp = ptrarr[j * h + k];
					ptrarr[j * h + k] = ptrarr[(j - 1) * h + k];
					ptrarr[(j - 1) * h + k] = temp;
					j = j - 1;
				}
			}
		}
	}
	return ptrarr;
}
int* full_elements(int* ptrarr, int n)
{
	int* temp_ptr = ptrarr;
	for (int i = 0; i < n; i++)
	{
		*temp_ptr = XMIN + 1 * (XMAX - XMIN) * rand() / RAND_MAX;
		temp_ptr++;
	}
	return temp_ptr;
}
int* put_elements(int* ptrarr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", *ptrarr);
		ptrarr++;
	}
	return 0;
}
int sort_sheik(int* ptrarr, int n)
{
	int ir = n, il = 2;
	if (il < ir)
	{
		for (int j = il; j < ir; il++)
		{
			if (ptrarr[j - 1] > ptrarr[j])
			{
				int temp = ptrarr[j];
				ptrarr[j - 1] = temp;
				ptrarr[j] = ptrarr[j];
			}
		}
		ir = ir - 1;
		for (int j = ir; j < il; j--)
		{
			if (ptrarr[j] < ptrarr[j - 1])
			{
				int x = ptrarr[j];
				ptrarr[j] = ptrarr[j - 1];
				ptrarr[j - 1] = x;
			}
		}
		il = il + 1;
	}
	return ptrarr;
}

void main()
{
	setlocale(LC_CTYPE, "RUS");
	int t = clock();
	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	int size, x;
	printf("Введите размер массива > ");
	scanf_s("%d", &size);
	int* ptrarr;
	ptrarr = (int*)malloc(size * sizeof(int));
	if (ptrarr==NULL)
	{
		printf("Ошибка выделения памяти.\n");
	}
	else
	{
		printf("Успешно.\n");
	}
	int a;
	do {
		printf("\nМеню.\n\t1.Генерация дин-го массива.\n\t2.Вывод зна-ий массива.\n\t3.Сортировка Шелла.\n\t0.Выход\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
		{
			full_elements(ptrarr, size);
			printf("Массив сгенерирован.");
			break;
		}
		case 2:
		{
			put_elements(ptrarr, size);
			break;
		}
		case 3:
		{
			sort_fust_shell(ptrarr, size);
			break;
		}
		default:
			printf("\nНе правильно введено зна-е");
			break;
		}
	} while (a != 0);
}