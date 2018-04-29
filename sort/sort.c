#include <stdio.h>

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
//
//void ShellSort(int array[],int64_t size){
//	if(size <= 1){
//		return;
//	}
	//1.先生成步长序列，此处直接按照希尔序列生成
//	int64_t gap = size/2;
//	for(;gap > 0;gap/=2){
//		//生成步长序列
//		int64_t bound = gap;
		//完成所有组的所有元素的插入排序
//		for(;bound< size;++bound){
			//先处理第一组第一个元素
			//再处理第二组第一个元素
			//。。。。
			//再处理第一组第二个元素
			//。。。。
//		}
//	}
//}



void Print(int array[],size_t size){
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
	printf("[堆排序后]：");
	Print(array,len);
	printf("\n");

	InsertSort(array,len);
	printf("[插入排序后]：");
	Print(array,len);
	printf("\n");

	return 0;
}
	
