#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void merge(int numbers[], int left, int mid, int right);

void print_array(int arr[], int len) {
    int i;

    for (i=0; i < len; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void merge_sort(int numbers[], int left, int right) {
    int mid;

    if (right > left)
    {
        mid = (right + left) / 2;
        merge_sort(numbers, left, mid);
        merge_sort(numbers, mid+1, right);

        merge(numbers, left, mid+1, right);
    }
}

void merge(int numbers[], const int left, const int mid, const int right)
{
    int left1 = left;
    int mid1 = mid;

    int left_end, num_elements, tmp_pos;

    left_end = mid - 1;
    tmp_pos = 0;
    num_elements = right - left + 1;
    int temp[num_elements];

    while ((left1 <= left_end) && (mid1 <= right))
    {
        if (numbers[left1] <= numbers[mid1])
        {
            temp[tmp_pos++] = numbers[left1++];
        }
        else
        {
            temp[tmp_pos++] = numbers[mid1++];
        }
    }

    while (left1 <= left_end)
    {
        temp[tmp_pos++] = numbers[left1++];
    }
    while (mid1 <= right)
    {
        temp[tmp_pos++] = numbers[mid1++];
    }

    int i;
    left1 = left;
    for (i=0; i < num_elements; i++, left1++)
    {
        numbers[left1] = temp[i];
    }
}


int main(int argc, const char * argv[]) {
    int len = 7;
    int arr[] = {23,12,6,5,4,2,21};
    int arrPadre[len/2];
    int arrHijo[1+(len/2)];
    int arrPipe[len];
    int i = 0;
    for(i = 0; i<(len/2); i++){
        arrPadre[i] = arr[i];
    }
    int j=0;
    for(j=0;j<(len/2)+1; j++){
        arrHijo[j] = arr[j+len/2];
    }
    pid_t pid;
    int p[2];
    pipe(p);
    if(pid = fork()){
        merge_sort(arrPadre, 0, len/2);
        close(p[1]);
        dup2(p[0], 0);
        execlp("bin/cat", "cat", "-", NULL);
        //print_array(arrPadre, len/2);
    } else{
        merge_sort(arrHijo, 0, 1+len/2);
        //print_array(arrHijo, 1+len/2);
    }
    close(p[0]);
    pid_t pidd;
    int pp[2];
    pipe(pp);
    if(pidd = fork()){
        i = 0;
        for(i = 0; i<(len/2); i++){
            arrPipe[i] = arrPadre[i];
        }
    } else{
        j=0;
        for(j = 0; j<(len/2)+1; j++){
            arrPipe[j+len/2] = arr[j];
        }
    }
    merge_sort(arrPipe, 0, len);
    print_array(arrPipe, len);
	exit(0);
    return 0;
}
