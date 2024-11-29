#include <db/ColumnStats.hpp>

using namespace db;

ColumnStats::ColumnStats(unsigned buckets, int min, int max)
// TODO pa4: some code goes here
{
  // TODO pa4: some code goes here
  this->buckets = buckets;
  this->min = min;
  this->max = max;
  this->bucket_length = (max - min + buckets - 1) / buckets;
  for(int i = 0; i < buckets; i++){
    nums[i] = 0;
  }
}

void ColumnStats::addValue(int v) {
  // TODO pa4: some code goes here
  if (v >= min && v <= max){
    int v_index = (v - min) / bucket_length;
    nums[v_index] += 1;
  }
}

size_t ColumnStats::estimateCardinality(PredicateOp op, int v) const {
  // TODO pa4: some code goes here

  int v_index = (v - min) / bucket_length;
  int all = 0;
  int v_inbucket_index = (v - min) - (v_index*bucket_length);
  if (v_index < 0){
    v_index = 0;
    v = min;
  }
  if(v_index > buckets){
    v_index = buckets-1;
    v = max;
  }
  for(int i = 0; i < buckets; i++){
    all += nums.at(i);
  }
  switch (op)
  {
  case PredicateOp::EQ:
    return nums.at(v_index)/bucket_length;
    break;
  case PredicateOp::NE:
    return all - nums.at(v_index)/bucket_length;
    break;
  case PredicateOp::LT:
  {
    int ans = 0;
    for(int i = 0; i < v_index; i++){
      ans += nums.at(i);
    }
    ans += nums.at(v_index) * v_inbucket_index / bucket_length;
    return ans;
  };
  case PredicateOp::LE:
  {
    int ans = 0;
    for(int i = 0; i < v_index; i++){
      ans += nums.at(i);
    }
    ans += nums.at(v_index) * (v_inbucket_index+1) / bucket_length;
    return ans;
  };
  case PredicateOp::GT:
  {
    int ans = 0;
    for(int i = v_index+1; i < buckets; i++){
      ans += nums.at(i);
    }
    ans += nums.at(v_index) * (bucket_length-v_inbucket_index-1) / bucket_length;
    return ans;
  };  
  case PredicateOp::GE:
  {
    int ans = 0;
    for(int i = v_index+1; i < buckets; i++){
      ans += nums.at(i);
    }
    ans += nums.at(v_index) * (bucket_length-v_inbucket_index) / bucket_length;
    return ans;
  }; 
  default:
    break;
  }
}
