#! /bin/bash
times=(50000 100000 250000 500000 1000000 2500000)
#times=(1 10 100 1000)
for i in ${times[@]};do
  for j in {1..10};do
    ./hw4 $i 0 >> log0;
    ./hw4 $i 1 >> log1;
    ./hw4 $i 2 >> log2;
  done
done