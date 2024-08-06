bool canJump(int* nums, int numsSize) {
    int end = numsSize-1;
    int start = 0;
    while(start < end){
        if(nums[start]+start >= end){
            end = start;
            start = 0;
        }
        else{
            start++;
        }
    }
    if(end == 0)return true;
    else{
        return false;
    }
}