# CRTP design pattern
## Use gprof 
```shell
g++ -pg -o prog simple-crtp.cpp  
./prog  
gprof prog gmon.out > analysis.txt
```  

and the call graph is:  
```txt
granularity: each sample hit covers 4 byte(s) no time propagated

index % time    self  children    called     name
                0.00    0.00       1/1           _GLOBAL__sub_I_main [13]
[8]      0.0    0.00    0.00       1         __static_initialization_and_destruction_0(int, int) [8]
-----------------------------------------------
                0.00    0.00       1/1           Base<D1>::name() [11]
[9]      0.0    0.00    0.00       1         D1::impl() [9]
-----------------------------------------------
                0.00    0.00       1/1           Base<D2>::name() [12]
[10]     0.0    0.00    0.00       1         D2::impl() [10]
-----------------------------------------------
                0.00    0.00       1/1           main [6]
[11]     0.0    0.00    0.00       1         Base<D1>::name() [11]
                0.00    0.00       1/1           D1::impl() [9]
-----------------------------------------------
                0.00    0.00       1/1           main [6]
[12]     0.0    0.00    0.00       1         Base<D2>::name() [12]
                0.00    0.00       1/1           D2::impl() [10]
-----------------------------------------------
```

## References 
1. [CRTP cppreference](https://en.cppreference.com/w/cpp/language/crtp)