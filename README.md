# Computer-Architecture (Ins. J. W. Lee)
Computer Architecture 2023-2 Programming assignments for homework repo.

## PA1
Manually compiling C code into Assembly using risc-v architecture. For example, I translated a sum of digits algorithm, recursive fibonacci, and a tree traversal algorithm.

## PA2
This assignment was implementing a given function only using permitted bit operations. I myself think that the `nibbleReverse` algorithm was the most challenging one.

## PA3
This assignment was implementing a pipeline processor structure using `Verilog`. We had to implement forwarding, data hazard resolving, and static branch prediction in the `ID` stage.

## PA4
This assignment was implementing a 2-level inclusive cache. There were a lot of branches such as follows. `L1 hit`, `L1 miss`, `L2 hit`, `L1 eviction`, `L2 miss`, `L2 eviction`. Two types of methods were used, a `FIFO` method and `LRU` method to find priority of eviction.

## PA5
This assignment was a rather simple implementation of matrix multiplication optimizing. I used blocking, loop ordering, and `SIMD` operations. Result was 450% of the desired performance.
