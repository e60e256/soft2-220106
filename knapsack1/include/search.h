#pragma once
#include "item.h"

typedef struct ans
{
    double value;
    unsigned int flags;
} Answer;

//ソルバー関数: 指定された設定でナップサック問題をとく [現状、未完成]
Answer solve(const Itemset *list, double capacity);

// solve 内で呼ぶ再帰的な探索関数 : 指定されたindex以降の組み合わせで最適な価値の総和を返す
Answer search(int index, const Itemset *list, double capacity, unsigned int flags, double sum_v, double sum_w);
