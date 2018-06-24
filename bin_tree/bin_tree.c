#include "bin_tree.h"

#include <stdio.h>
#include <assert.h>

#include "seqqueue.h"
#include "seqstack.h"

TreeNode* CreateTreeNode(TreeNodeType value){
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

void DestroyTreeNode(TreeNode* ptr){
    free(ptr);
}

void TreeInit(TreeNode** root){
	if(root == NULL){
		return;
	}
	*root = NULL;
}

void PreOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	printf("%c ",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	InOrder(root->lchild);
	printf("%c ",root->data);
	InOrder(root->rchild);
}

void PostOrder(TreeNode* root){	
	if(root == NULL){
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c ",root->data);
}

void LevelOrder(TreeNode* root){
    if(root == NULL){
        //空树
        return;
    }
    SeqQueue q;
    SeqQueueInit(&q);
    //1.先把根节点插入到队列
    SeqQueuePush(&q, root);
    //2.循环取队首元素
    TreeNode* cur = NULL;
    while(SeqQueueFront(&q, &cur)){
         //3.访问队首元素并出队列
         printf("%c ", cur->data);
         SeqQueuePop(&q);
         //4.将队首元素的左右子树依次入队列
         if(cur->lchild != NULL){
             SeqQueuePush(&q, cur->lchild);
         }
         if(cur->rchild != NULL){
             SeqQueuePush(&q, cur->rchild);
         }
         //5.进入下一次循环，直到队列为空
    }
}

TreeNode* _TreeCreate(TreeNodeType array[], size_t size, size_t* index, TreeNodeType null_node){
    if(index == NULL){
        return NULL;    //非法输入
    }
    if(*index >= size){
        //构建已完成
        return NULL;
    }
    if(array[*index] == null_node){
        return NULL;
    }
    TreeNode* new_node = CreateTreeNode(array[*index]);
    ++(*index);
    new_node->lchild = _TreeCreate(array,size,index,null_node);
    ++(*index);
    new_node->rchild = _TreeCreate(array,size,index,null_node);
    return new_node;
}

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node){
    //当前读到了数组的第几个元素
    size_t index = 0;
    return _TreeCreate(array, size, &index, null_node);
}

void TreeDestroy(TreeNode** root){
    if(root == NULL){
        return;    //非法输入
    }
    if(*root == NULL){
        return;
    }
    TreeNode* to_delete = *root;
    TreeNode* to_delete_lchild = to_delete->lchild;
    TreeNode* to_delete_rchild = to_delete->rchild;
    DestroyTreeNode(to_delete);
    TreeDestroy(&to_delete_lchild);
    TreeDestroy(&to_delete_rchild);
    *root = NULL;
}

TreeNode* TreeClone(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    TreeNode* new_root = CreateTreeNode(root->data);
    new_root->lchild = TreeClone(root->lchild);
    new_root->rchild = TreeClone(root->rchild);
    return new_root;
}

//size_t TreeSize(TreeNode* root){
//    if(root == NULL){
//        return 0;
//    }
//    return 1 + TreeSize(root->lchild) + TreeSize(root->rchild);
//}
//
void _TreeSize(TreeNode* root,size_t* size){
    if(root == NULL || size == NULL){
        return;    //非法输入
    }
    //访问当前元素，每次访问一个就把size++
    ++(*size);
    _TreeSize(root->lchild,size);
    _TreeSize(root->rchild,size);
}

size_t TreeSize(TreeNode* root){
    size_t size = 0;
    _TreeSize(root,&size);
    return size;
}

size_t TreeLeafSize(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }
    return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}

size_t TreeKLevelSize(TreeNode* root, int K){
    if(root == NULL || K < 1){
        return 0;
    }
    if(K == 1){
        return 1;
    }
    return TreeKLevelSize(root->lchild, K - 1) + TreeKLevelSize(root->rchild, K - 1);
}

size_t TreeHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    size_t lheight = TreeHeight(root->lchild);
    size_t rheight = TreeHeight(root->rchild);
    return lheight > rheight ? lheight + 1 : rheight + 1;
}

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find){
    if(root == NULL){
        return NULL;
    }
    if(root->data == to_find){
        return root;
    }
    TreeNode* lresult = TreeFind(root->lchild, to_find);
    TreeNode* rresult = TreeFind(root->rchild, to_find);
    return lresult != NULL ? lresult : rresult;
}

TreeNode* LChild(TreeNode* node){
    if(node == NULL){
        return NULL;
    }
    return node->lchild;
}

TreeNode* RChild(TreeNode* node){
    if(node == NULL){
        return NULL;
    }
    return node->rchild;
}

TreeNode* Parent(TreeNode* root, TreeNode* node){
    if(root == NULL || node == NULL){
        return NULL;
    }
    if(root->lchild == node || root->rchild == node){
        return root;
    }
    TreeNode* lresult = Parent(root->lchild, node);
    TreeNode* rresult = Parent(root->rchild, node);
    return lresult != NULL ? lresult : rresult;
}

void PreOrderByLoop(TreeNode* root){
    if(root == NULL){
        return;
    }
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack, root);
    while(1){
        TreeNode* top = NULL;
        SeqStackTop(&stack, &top);
        if(top == NULL){
            //遍历完
            break;
        }
        //访问当前栈顶元素
        printf("%c ", top->data);
        //将栈顶元素出栈
        SeqStackPop(&stack);

        //把当前元素右子树和左子树分别入栈
        if(top->rchild != NULL){
            SeqStackPush(&stack, top->rchild);
        }
        if(top->lchild != NULL){
            SeqStackPush(&stack, top->lchild);
        }
    }
    printf("\n");
}

void InOrderByLoop(TreeNode* root){
    if(root == NULL){
        return;
    }
    SeqStack stack;
    SeqStackInit(&stack);
    TreeNode* cur = root;
    while(1){
        //1.从根结点出发，尝试找到当前树的最左侧节点 
        //  每次经过一个节点，就把这个节点入栈
        while(cur != NULL){
            SeqStackPush(&stack, cur);
            cur = cur->lchild;
        }
        //2.取栈顶元素，访问，并将该元素出栈
        TreeNode* top = NULL;
        SeqStackTop(&stack, &top);
        if(top == NULL){
            //遍历结束
            break;
        }
        printf("%c ", top->data);
        SeqStackPop(&stack);
        //3.处理当前元素的右子树，回到循环开始，再去找右子树的最左节点
        cur = top->rchild;
    }
    printf("\n");
    return;
}

void PostOrderByLoop(TreeNode* root){
    if(root == NULL){
        return;
    }
    SeqStack stack;
    SeqStackInit(&stack);
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    while(1){
        while(cur != NULL){
            SeqStackPush(&stack, cur);
            cur = cur->lchild;
        }
        TreeNode* top = NULL;
        SeqStackTop(&stack, &top);
        if(top == NULL){
            break;
        }
        //取出栈顶元素后，满足以下两个条件之一，才能访问top
        //1.top 的右子树为空
        //2.top 的右子树被访问过
        //否则就需要处理 top 的右子树
        if(top->rchild == NULL || top->rchild == pre){
            printf("%c ", top->data);
            SeqStackPop(&stack);
            pre = top;
        }
        else{
            cur = top->rchild;
        }
    }
    printf("\n");
}

void TreeMirror(TreeNode* root){
    if(root == NULL){
        return;
    }
    TreeNode* tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tmp;
    TreeMirror(root->lchild);
    TreeMirror(root->rchild);
}

int isCompleteTree(TreeNode* root){
    if(root == NULL){
        return -1;
    }
    SeqQueue queue;
    SeqQueueInit(&queue);
    SeqQueuePush(&queue, root);
    int flag = 0;      //此标志是为了判断当前节点的两个孩子节点是否为空
    while(1){
        TreeNode* top = NULL;
        SeqQueueFront(&queue, &top);
        if(top == NULL){
            //遍历完了
            break;
        }
        //访问当前节点
        if(flag == 0){
            if(top->lchild != NULL && top->rchild != NULL){
                SeqQueuePush(&queue, top->lchild);
                SeqQueuePush(&queue, top->rchild);
            }
            else if(top->lchild == NULL && top->rchild != NULL){
                return 0;
            }
            else if(top->lchild != NULL && top->rchild == NULL){
                SeqQueuePush(&queue, top->lchild);
                flag = 1;
            }
            else if(top->lchild == NULL && top->rchild == NULL){
                flag = 1;
            }
        }
        else{
            if(top->lchild == NULL && top->rchild == NULL){
                //说明到目前为止还满足完全二叉树的条件
            }
            else{
                return 0;
            }
        }
        SeqQueuePop(&queue);
    }
    return 1;
}

size_t Find(TreeNodeType in_order[], size_t in_order_left, size_t in_order_right, TreeNodeType pre_order);

//in_order_left 和 in_order_right,通过这个前闭后开区间
//哪一段区域表示了当前子树的中序遍历结果
TreeNode* _ReBuildTree(TreeNodeType pre_order[], size_t pre_order_size, size_t* index, 
                       TreeNodeType in_order[], size_t in_order_left, size_t in_order_right){
    if(in_order_left >= in_order_right){
        //说明当前中序遍历序列为空
        return NULL;
    }
    if(index != NULL && *index >= pre_order_size){
        //先序遍历结束，树还原成功
        return NULL;
    }
    TreeNode* new_node = CreateTreeNode(pre_order[*index]);
    //假设取出来的 new_node 值是 A 的话，接下来递归的时候就需要取出A的下一个结点B
    ++(*index);
    size_t cur_root_in_order_index = Find(in_order, in_order_left, in_order_right, pre_order[*index]);
    assert(cur_root_in_order_index != (size_t)-1);

    //递归的处理当前根节点的左子树
    new_node->lchild = _ReBuildTree(pre_order, pre_order_size, index, in_order, in_order_left, cur_root_in_order_index);

    //递归处理当前根节点的右子树
    new_node->rchild = _ReBuildTree(pre_order, pre_order_size, index, in_order, cur_root_in_order_index + 1, in_order_right);

    return new_node;
}

//通过先序遍历的方式还原一棵树
//中序遍历的结果主要是用来判定某一个结点是左子树还是右子树
TreeNode* ReBuildTree(TreeNodeType pre_order[], size_t pre_order_size, TreeNodeType in_order[], size_t in_order_size){
    size_t index = 0;
    return _ReBuildTree(pre_order, pre_order_size, &index, in_order, 0, in_order_size);
}
