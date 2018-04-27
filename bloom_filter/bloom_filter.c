#define _CRT_SECURE_NO_WARNINGS 1

#include "bloom_filter.h"

size_t HashFunc0(const char* str)
{
	size_t hash = 0;		
	size_t ch;
	while (ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..  
		        
		// ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;  	        
		// ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�  	       
		// �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����          
		// ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�  	      
		// ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������         
		// ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������  	       
		// ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������  	       
		// ������Ҫ4��ʱ������      
		// ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴�          
	}
	return hash;

}

size_t HashFunc1(const char* str)
{
	size_t hash = 0;
	size_t ch;
	while (ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;

}

void BloomFilterInit(BloomFilter* bf)
{
	BitMapInit(&bf->bitmap, BitMapCapacity);
	bf->hash_func[0] = HashFunc0;
	bf->hash_func[1] = HashFunc1;
}

void BloomFilterInsert(BloomFilter* bf, const char* str)      //����
{
	if (bf == NULL || str == NULL)
	{
		return;
	}
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i)
	{
		size_t offset = bf->hash_func[i](str) % BitMapCapacity;
		BitMapSet(&bf->bitmap, offset);
	}
	return;
}

int BloomFilterIsExist(BloomFilter* bf, const char* str)     //�ж�
{
	if (bf == NULL || str == NULL)
	{
		return 0;
	}
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i)
	{
		size_t offset = bf->hash_func[i](str) % BitMapCapacity;
		int ret = BitMapTest(&bf->bitmap, offset);
		if (ret == 0)
		{
			return 0;
		}
	}
	//���й�ϣ����������λͼ��
	//���Խ�����Ϊ�ַ��������ڼ�����
	return 1;
}

void BloomFilterDestroy(BloomFilter* bf)
{
	if (bf == NULL)
	{
		return;
	}
	BitMapDestroy(&bf->bitmap);
	bf->hash_func[0] = NULL;
	bf->hash_func[1] = NULL;
}
