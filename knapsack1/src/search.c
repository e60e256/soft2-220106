// search.c 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "search.h"
#include "item.h"

// ソルバーは search を index = 0 で呼び出すだけ
Answer solve(const Itemset *list,  double capacity)
{
    unsigned int flags = 0; // 32ビット: 品物を入れたかどうかを記録するフラグ変数（全探索では利用しない）
    return search(0,list,capacity,flags, 0.0, 0.0);
}

// 全探索関数
Answer search(int index, const Itemset *list, double capacity, unsigned int flags, double sum_v, double sum_w)
 {
     int max_index = list->number;
     assert(index >= 0 && sum_v >= 0 && sum_w >= 0);
// 再帰の停止条件
     if (index == max_index){
 	const char *format_ok = ", total_value = %5.1f, total_weight = %5.1f\n";
 	const char *format_ng = ", total_value = %5.1f, total_weight = %5.1f NG\n";
 	
	for (unsigned int i = 0 ; i < max_index ; i++){
	    printf("%d", (flags & (1 << (max_index - i - 1)))?1:0);
	}
	bool pruned = (sum_w > capacity);
	printf((pruned)?format_ng:format_ok, sum_v, sum_w);
	return (Answer){ .value = (pruned)?0:sum_v, .flags = (pruned)?0:flags};	
     }
 

    // 再帰の更新式
    // 当該インデックスの品物を入れない場合は特に演算せず、indexのみ増やす
    const Answer a0 = search(index+1, list, capacity, flags, sum_v, sum_w);
     
    // 入れる場合はフラグを立てる
    flags |= 1 << (list->number-1-index);
     Item item = get_item(list, index);
    bool pruned = (sum_w + get_itemweight(item) > capacity);
    const Answer a1 = (pruned)?(Answer){ .value = 0, .flags = 0}:search(index+1, list, capacity, flags, sum_v + get_itemvalue(item), sum_w + get_itemweight(item));
 
     // 使った場合の結果と使わなかった場合の結果を比較して返す
    return (a0.value > a1.value)? a0 : a1;
 }