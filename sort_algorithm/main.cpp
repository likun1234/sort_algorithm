#include <iostream>
#include <string.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void merge(int arr[], int left, int mid, int right)
{
	int len = right - left + 1;
	int *temp = new int[len];
	int i = left;
	int j = mid + 1;
	int index = 0;
	while(i<=mid && j<=right)//paixu
	{
		temp[index++] = arr[i]<=arr[j]?arr[i++]:arr[j++];
	}
	while (i<=mid)
	{
		temp[index++] = arr[i++];
	}
	while (j<=right)
	{
		temp[index++] = arr[j++];
	}
	for (int k=0;k<len;k++)
	{
		arr[left++] = temp[k];
	}
        delete[] temp;
}


void guibingpaixu(int arr[], int left, int right)//guibingpaixu
{
	if (left==right) 
		return;
	int mid = (left+right)/2;
	guibingpaixu(arr, left, mid);
	guibingpaixu(arr, mid+1, right);
	merge(arr, left, mid, right);
        
}

void heaptify(int arr[], int i, int n)
{
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	int max = i;
	if(left_child<n&&arr[left_child]>arr[max])
		max = left_child;
	if(right_child<n&&arr[right_child]>arr[max])
		max = right_child;
	if (max!=i)
	{
		swap(arr[i], arr[max]);
		heaptify(arr, max,n);
	}
}



int buildheap(int arr[], int n)
{
	int size = n;
	for(int i=size/2-1;i>=0;i--)
	{
            heaptify(arr, i,n);
	} 
        return size;
}

void heapsort(int arr[], int n)//duipaixu
{
	int heap_size = buildheap(arr,n);
	while(heap_size>1)
	{
		swap(arr[0], arr[--heap_size]);
		heaptify(arr, 0, heap_size);
	}
}

void qiuck_sort(int arr[], int left, int right)//kuaisupaixu
{
	int i,j;
	if (left> right)
	{
		return;
	}
	i = left;
	j = right;
	int temp = arr[left];//standard
	while(i!=j)
	{
		while(i<j && arr[j]>=temp) j--;
		while(i<j && arr[i]<=temp) i++;
		if (i<j)
			swap(arr[i], arr[j]);
	}
	arr[left] = arr[i];
	arr[i] = temp;
	qiuck_sort(arr, left, i-1);
	qiuck_sort(arr, i+1, right);
}


void bubblesort(int arr[], int n)
{
	for (int i=0;i<n-1;i++)
	{
		bool flag = false;
		for (int j=0;j<n-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}


void selectsort(int arr[], int n)
{
	for (int i=0;i<n-1;i++)
	{
		int min = i;
		for (int j=i+1;j<n;j++)
		{
			if (arr[j]<arr[min])
				min = j;
		}
		if (min != i)
			swap(arr[min], arr[i]);
	}
}


void insertsort(int arr[], int n)
{
	for (int i=1;i<n;i++)
	{
		int j = i-1;
                int get = arr[i];
		while(j>=0&&arr[j]>get)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = get;

	}
}

void cocksort(int arr[], int n)//cock paixu
{
	int left = 0;
	int right = n-1;
	while(left<right)
	{
		for (int i=left;i<right;i++)
		{
			if (arr[i]>arr[i+1])
			{
                            swap(arr[i],arr[i+1]);
			}
		}
		right--;
		for (int i=right;i>left;i--)
		{
			if (arr[i]<arr[i-1])
				swap(arr[i],arr[i-1]);
		}
		left++;
	}
}

void tongpaixu(int arr[], int n)//tongpaixu
{
	int temp[1000] = {0};
	//temp = (int*)memset(temp,0,sizeof(int)*1000);
	for (int i=0;i<n;i++)
	{
		temp[arr[i]]++;
	}

	for (int i=0;i<1000;i++)
	{
		while(temp[i]>0)
		{
			cout<<i<<"\t";
			temp[i]--;
		}
	}
}

//计算逆序对，利用归并排序

//int findlistlen(ListNode* head)
//{
//	int len = 0;
//	while(head)
//	{
//		len++;
//		head = head->next;
//	}
//        return len;
//}
//
//ListNode* walk(ListNode* head, int n)
//{
//	while(n--)
//	{
//		head = head->next;
//	}
//        return head;
//}
//
//ListNode* findfirstnode(ListNode* head1, ListNode* head2)
//{
//    int len1 = findlistlen(head1);
//    int len2 = findlistlen(head2);
//    if (len1>len2)
//        head1 = walk(head1, len1-len2);
//    if (len2>len1)
//        head2 = walk(head2, len2-len1);
//     
//}
//


int main()
{
	int arr[] = {100, 34,2,10,5,3,7,45,8,3};
	int n = sizeof(arr)/sizeof(int);
	guibingpaixu(arr, 0, n-1);
        //qiuck_sort(arr,0, n-1);
        //heapsort(arr, n);        
        //bubblesort(arr, n);
        //selectsort(arr, n);
        //insertsort(arr, n);
        //cocksort(arr, n);
         //tongpaixu(arr, n);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	return 0;    
}
