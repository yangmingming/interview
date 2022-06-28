#include <iostream>
#include <string>
#include <vector>

void Print(const std::vector<int> &vec){
    for(auto &item: vec){
        std::cout << item << "\t";
    }

    std::cout << std::endl;
}

void Merge(std::vector<int> &vec, int begin, int middle, int end){
    // 申请外部存储
    std::vector<int> vec_new;

    int i = begin, j = middle + 1;
    while(i <= middle && j <= end){
        if(vec[i] < vec[j]){
            vec_new.emplace_back(vec[i++]);
        }else{
            vec_new.emplace_back(vec[j++]);
        }
    }

    while(i <= middle){
            vec_new.emplace_back(vec[i++]);
    }

    while(j <= end){
            vec_new.emplace_back(vec[j++]);
    }

    // 回写数据
    for(auto i = 0; i < vec_new.size(); i++){
        vec[begin + i] = vec_new[i];
    }
}

void SortMergeSub(std::vector<int> &vec, int begin, int end){
    // begin == end 对应只有一个元素
    if(begin >= end){
        return;
    }
    int middle = begin + (end - begin) / 2;
    SortMergeSub(vec, begin, middle);
    SortMergeSub(vec, middle+1, end);
    
    // 合并，需要依赖外部存储
    Merge(vec, begin, middle, end);
}

// 归并排序
void SortMerge(std::vector<int> &vec){
    // 空列表直接返回
    if(vec.empty()){
        return;
    }

    SortMergeSub(vec, 0, vec.size() - 1);
}

void Swap(std::vector<int> &vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

int GetProid(std::vector<int> &vec, int begin, int end){
    int proid = end;
    int value = vec[proid];

    // 双游标方式,慢指针指向待交换位置,快指针指向对比位置
    int slow = begin, fast = begin;
    // 快游标判断即可,无需包括end值
    while(fast < end){
        // 通过fast游标和proid进行对比
        if(vec[fast] < vec[proid]){
            if(slow != fast){
                Swap(vec, slow, fast);
            }
            slow++;
            fast++;
        }else{
            fast++;
        }
    }

    if(slow != end){
        Swap(vec, slow, end);
    }

    return slow;
}

void SortFastSub(std::vector<int> &vec, int begin, int end){
    if(begin >= end){
        return;
    }

    int proid = GetProid(vec, begin, end);

    // 子排序的时候，无需包括proid下标的数据
    SortFastSub(vec, begin, proid - 1);
    SortFastSub(vec, proid + 1, end);
}

// 快速排序
void SortFast(std::vector<int> &vec){
    SortFastSub(vec, 0, vec.size() - 1);
}

int main(){
    std::vector<int> vec{1,3,5,7,2,4,6};
    Print(vec);
    // SortMerge(vec);
    SortFast(vec);

    Print(vec);
    return 0;
}
