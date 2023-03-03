# BitPacking

This algorithm involves packing the data into as few bits as possible and then concatenating the resulting bit sequences to create the full data. This approach can be efficient for certain types of data, but may not be suitable for all use cases.

# src.cpp

This code defines two functions, pack and unpack, which convert between a vector of 32-bit integers and a vector of 8-bit bytes using a simple bit-packing scheme. The pack function iterates over each value in the input vector and repeatedly appends 7-bit chunks to the output byte vector, with the high bit of each chunk set to indicate whether more chunks follow. The unpack function reverses this process, reading each byte in the input vector and combining its 7-bit chunks into a 32-bit integer until a byte with the high bit unset is encountered, at which point the integer is added to the output vector and a new one is started.
