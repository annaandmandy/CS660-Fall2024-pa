## writeup

### design decisions
I used switch case to deal with different PredicateOp. 
I used underordered map to save the numbers of each bucket. And I used bucket_length to save the length of bucket. 
For the less and greater part, I first calculated the in bucket index, then use the index or the bucket_length-v_inbucket_index-1 to get the position that need to be added.

### time spent
2 hours

### confusion
the greater or lesser part is the hardest part in this pa, but after I figured out, it was pretty easy.