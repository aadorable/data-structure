#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "seqstack.h"

/////////////////////////////////////////////
//冒泡排序
//时间复杂度：O(N^2)
//空间复杂度：O(1)
///////////////////////////////////////////
//[0,bound]是有序区间
//[bound,size]是待排序区间
//
void Swap(int* a,int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int array[],size_t size){
	if(size <= 1){
		return;
	}
	size_t bound = 0;
	for(;bound < size; ++bound){
		size_t cur = size - 1;
		for(; cur > bound; --cur){
			if(array[cur] < array[cur -1]){
				Swap(&array[cur],&array[cur-1]);
			}
		}
	}
	return;
}

/////////////////////////////////////////////////
//选择排序
//时间复杂度：O(N^2)
//空间复杂度：O(1)
////////////////////////////////////////////////
//
void SelectSort(int array[],size_t size){
	if(size <= 1){
		return;
	}
	size_t bound = 0;
	for(;bound < size;++bound){
		size_t i = bound;
		for(;i < size;++i){
			if(array[bound] > array [i]){
				Swap(&array[bound],&array[i]);
			}
		}
	}
	return;
}

//////////////////////////////////////////////////
//堆排序
//时间复杂度：O(N*logN)
//空间复杂度：O(1)
/////////////////////////////////////////////////
//要求从小到大排序，所以应该建立一个大堆
void AdjustDown(int array[],size_t size ,size_t index){
	size_t parent = index;
	size_t child = 2 * parent + 1;
	while(child < size){
		//1.比较左右子树
		if(child+1 < size && array[child+1] > array[child]){
			child = child + 1;
		}
		//2.比较child 和 parent
		if(array[child] > array[parent]){
			Swap(&array[child],&array[parent]);
		}
		else{
			break;
		}
		parent = child;
		child = 2*parent + 1;
	}
	return;
}
void HeapCreate(int array[],size_t size){
	//算出最后一个元素的父节点
	size_t i = (size - 1 - 1) / 2;
	for(;i > 0;--i){
		AdjustDown(array,size,i);
	}
	AdjustDown(array,size,0);
}

void HeapSort(int array[],size_t size){
	if(size <= 1){
		return;
	}
	//1.先建立一个堆
	HeapCreate(array,size);
	//2.依次删除栈顶元素
	size_t heap_size = size;
	while(heap_size > 0){
		Swap(&array[0],&array[heap_size - 1]);
		--heap_size;
		AdjustDown(array,heap_size,0);
	}
	return;
}

////////////////////////////////////////////////////////
//插入排序
//时间复杂度：O(N^2)
//空间复杂度：O(1)
///////////////////////////////////////////////////////
void InsertSort(int array[],size_t size){
	if(size <= 1){
		return;
	}
	size_t bound = 1;
	for(;bound < size; ++bound){
		int value = array[bound];
		size_t i = bound;
		for(;i > 0;--i){
			if(array[i - 1] > value){
				//进行搬运
				array[i] = array[i - 1];
			}
			else{
				break;
			}
		}
		//无论上面循环是通过i == 0方式退出的
		//还是找到一个合适的位置退出的，下面逻辑都合法
		array[i] = value;
	}
	return;
}

//////////////////////////////////////////////////
//希尔排序
//时间复杂度：O(N^1.3)
//空间复杂度：O(1)
/////////////////////////////////////////////////

void ShellSort(int array[], int64_t size){
	if(size <= 1){
		return;
	}
  //1.先生成步长序列，此处直接按照希尔序列生成
  //N/2 N/4 N/8 ... 1
	int64_t gap = size / 2;
	for(; gap > 0; gap /= 2){
		//生成步长序列
		int64_t bound = gap;
  	    //完成所有组的所有元素的插入排序
		for(; bound < size; ++bound){
  		    //先处理第一组第一个元素
  		    //再处理第二组第一个元素
  		    //。。。。
  		    //再处理第一组第二个元素
  		    //。。。。
            int value = array[bound];
            int64_t i = bound;
            for(; i >= gap; i -= gap){
                //第三重循环
                //进行当前元素的插入动作
                if(array[i - gap] > value){
                    array[i] = array[i - gap];
                }else{
                    break;
                }
            }
            array[i] = value;
		}
	}
    return;
}

////////////////////////////////////////////////////////////
//归并排序
//时间复杂度：O(N * logN)
//空间复杂度：O(N)
//稳定性：稳定排序
////////////////////////////////////////////////////////////

//第一个区间：[beg, mid)
//第二个区间：[mid, end)
void _MergeArray(int array[], int64_t beg, int64_t mid, int64_t end, int* tmp){
    int64_t cur1 = beg;
    int64_t cur2 = mid;
    int64_t tmp_index = beg;
    while(cur1 < mid && cur2 < end){
        if(array[cur1] < array[cur2]){
            tmp[tmp_index++] = array[cur1++];
        }else{
            tmp[tmp_index++] = array[cur2++];
        }
    }
    if(cur1 < mid){
        while(cur1 < mid){
            tmp[tmp_index++] = array[cur1++];
        }
    }else{
        while(cur2 < end){
            tmp[tmp_index++] = array[cur2++];
        }
    }
    while(cur1 < mid){
        tmp[tmp_index++] = array[cur1++];
    }
    while(cur2 < end){
        tmp[tmp_index++] = array[cur2++];
    }
    memcpy(array + beg, tmp + beg, sizeof(int) * (end - beg));
}

void _MergeSort(int array[], int64_t beg, int64_t end, int* tmp){
    if(end - beg <= 1){
        return;
    }
    int64_t mid = beg + (end - beg) / 2;
    _MergeSort(array, beg, mid, tmp);
    _MergeSort(array, mid, end, tmp);
    //先保证左右区间均为有序区间后，才能进行合并
    _MergeArray(array, beg, mid, end, tmp);
}

void MergeSort(int array[], int64_t size){
    int* tmp = (int*)malloc(sizeof(int) * size);
    //[0, size)
    _MergeSort(array, 0, size, tmp);
    free(tmp);
}

//归并排序的非递归版本
void MergeSortByLoop(int array[], int64_t size){
    if(size <= 1){
        return;
    }
    int* tmp = (int*)malloc(sizeof(int) * size);
    int64_t gap = 1;
    for(; gap < size; gap *= 2){
        int64_t i = 0;
        for(; i < size; i += gap * 2){
            //每次循环其实就是在处理两个相邻的区间
            int64_t beg = i;
            int64_t mid = i + gap;
            int64_t end = i + 2 * gap;
            if(mid > size){
                mid = size;
            }
            if(end > size){
                end = size;
            }
            //[beg, mid),[mid, end)
            _MergeArray(array, beg, mid, end, tmp);
        }
    }
    free(tmp);
}

///////////////////////////////////////////////////////////
//快速排序
//时间复杂度：最坏O(N^2)，序列是完全逆序的
//            平均O(N*logN)
//空间复杂度：O(logN)
//////////////////////////////////////////////////////////
//


//交换法
int64_t Partion1(int array[], int64_t beg, int64_t end){
    //1.先定义好区间的边界
    int64_t left = beg;
    int64_t right = end - 1;
    //2.取最后一个元素作为基准值
    int key = array[right];
    while(left < right){
        //3.从左到右找到一个大于基准值的元素
        while(left < right && array[left] <= key){
            ++left;
        }
        //4.从右到左找到一个小于基准值的元素
        while(left < right && array[right] >= key){
            --right;
        }
        //5.进行交换
        if(left < right){
            Swap(&array[left], &array[right]);
        }
    }
    //6.此时是将left指向的值和最后一个元素(基准值)进行交换
    //此时的left指向的值一定大于等于基准值
    //  a)如果是因为 ++left 导致的循环推出，由于 right 在上一次循环的交换中已经指向一个大于等于基准值的元素
    //  b)如果是因为 --right 导致的循环推出，由于在刚刚的 left 查找过程中 left 已经找到了一个大于等于基准值的元素
    //  因此，最终的结论就是 left 指向的值一定大于等于基准值
    Swap(&array[left], &array[end - 1]);
    return left;
}

//挖坑法
int64_t Partion2(int array[], int64_t beg, int64_t end){
    //1.定义好区间边界
    int64_t left = beg;
    int64_t right = end - 1;
    //2.取最后一个元素作为基准值
    int key = array[right];     //right指向的位置，就可以被覆盖了
    while(left < right){
        //从左到右找到一个大于基准值的元素
        while(left < right && array[left] <= key){
            ++left;
        }
        if(left < right){
            //将找到的这个大于基准值的元素，填到right指向的坑里
            //随着填坑动作的完成，left指向的位置也就可以被别人覆盖
            //left也就成了一个坑
            array[right--] = array[left];
        }
        //4.从右到左找到一个小于基准值的元素
        while(left < right && array[right] >= key){
            --right;
        }
        if(left < right){
            array[left++] = array[right];
        }
    }
    array[left] = key;
    return left;
}

//双指针前移法
int64_t Partion3(int array[], int64_t beg, int64_t end){
    int64_t cur = beg;
    int64_t pre = beg - 1;
    int key = array[end - 1];
    while(cur < end){
        if(array[cur] < key && ++pre != cur){
            Swap(&array[cur], &array[pre]);
        }
        ++cur;
    }
    if(++pre != end){
        Swap(&array[pre], &array[end - 1]);
    }
    return pre;
}

void _QuickSort(int array[], int64_t beg, int64_t end){
    if(end - beg <= 1){
        return;
    }
    //Partion 函数的作用，是对当前[beg, end)区间进行调整
    //整理成以某个基准值为中心，左侧元素小于等于基准值，右侧元素大于等于基准值
    //返回值表示的含义是基准值所在的下标
    int64_t mid = Partion3(array, beg, end);
    _QuickSort(array, beg, mid);
    _QuickSort(array, mid + 1, end);
}

void QuickSort(int array[], int64_t size){
    _QuickSort(array, 0, size);
}

void QuickSortByLoop(int array[], int64_t size){
    if(size <= 1){
        return;
    }
    SeqStack stack;
    SeqStackInit(&stack);
    int64_t beg = 0;
    int64_t end = size;
    SeqStackPush(&stack, beg);
    SeqStackPush(&stack, end);
    while(stack.size > 0){
        SeqStackTop(&stack, &end);
        SeqStackPop(&stack);
        SeqStackTop(&stack, &beg);
        SeqStackPop(&stack);
        if(end - beg <= 1){
            continue;
        }
        int64_t mid = Partion1(array, beg, end);
        SeqStackPush(&stack, beg);
        SeqStackPush(&stack, mid);
        SeqStackPush(&stack, mid + 1);
        SeqStackPush(&stack, beg);
    }
}

/////////////////////////////////////////////////////////////
//计数排序
/////////////////////////////////////////////////////////////
void CountSort(int array[], size_t size){

}

void Print(int array[], size_t size){
	size_t i = 0;
	for(;i < size;++i){
		printf("%d ",array[i]);
	}
}

int main(){
	int array[] = {1,3,12,45,13,65,23,19,34};
	size_t len = sizeof(array)/sizeof(array[0]);

	BubbleSort(array,len);
	printf("[冒泡排序后]：");
	Print(array,len);
	printf("\n");
	
	SelectSort(array,len);
	printf("[选择排序后]：");
	Print(array,len);
	printf("\n");
	
	HeapSort(array,len);
	printf("[ 堆排序后 ]：");
	Print(array,len);
	printf("\n");

	InsertSort(array,len);
	printf("[插入排序后]：");
	Print(array,len);
	printf("\n");

	ShellSort(array,len);
	printf("[希尔排序后]：");
	Print(array,len);
	printf("\n");

    MergeSort(array, len);
	printf("[归并排序后]：");
	Print(array,len);
	printf("\n");

    MergeSortByLoop(array, len);
	printf("[归并排序后]：");
	Print(array,len);
	printf("\n");

    QuickSort(array, len);
	printf("[快速排序后]：");
	Print(array,len);
	printf("\n");

    QuickSortByLoop(array, len);
	printf("[快速排序后]：");
	Print(array,len);
	printf("\n");
	return 0;
}
	
