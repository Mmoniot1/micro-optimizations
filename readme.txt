micro optimization submission by Monica Moniot

This repo contains multiple different attempts at making the convertall procedure faster. The primary one I submitted is the one in the file named "quad_converter.c", if that one is not acceptable then I submit "last_converter.c" as it's replacement.

I relied heavily on Godbolt.org to analyze the assembly of my procedures and make more informed decisions about what optimizations could be done. All of my tests were ran on my laptop on the reed VM using a Intel i7-6700HQ CPU @ 2.6Ghz.

Here is a summary of the history of each file in order of creation, and their run-times:
0. converter.c "atoi"   (.108855s)
The example code distributed with the project. According to the assembly, even with -O3, the program calls out to libc instead of inlining the prodecure. This is probably why it's an order of magnitude slower than anything I tried.

1. inline_converter.c   (.006843s)
My first attempt was to simply inline the atoi prodecure manually, and assume there would be no malformed input to handle. I also decided to only use raw pointers instead of an index variable, to cut out some unnecessary adds in the assembly.

2. cheating_converter.c (.004824s)
I noticed that all input numbers are within the range 3-5 characters long, which makes sense. If these are real stock quotes, we can safely assume they will all be within a certain order of magnitude of each other. This may be a bad assumption, but it works very well for the given example quotes.

3. stylish_converter.c  (.005179s)
Since the assembly of cheating_converter was no longer necessarily order dependent, I had the idea to rearrange the same instructions to see if this would improve performance. In particular I wanted the cpu to notice that the instructions where not order dependent and execute them in parallel. This did not work, but the core idea of it eventually paid off.

4. nonce_converter.c    (.005841s)
I decided to manually unroll part of the core loop in inline_converter to do 4 bytes at a time. My idea was to get the cpu to notice that it could do more of this loop in parallel, or at the very least, speculatively execute more instruction than it was. It seemed to work, doing 4 bytes at a time in the loop gave a major speedup. I'm not entirely sure why this worked, since I feel like the cpu should have been able to do this before, and the assembly outputted by nonce_converter is more or less equivalent to inline_converter with the core loop doing 4 bytes at a time.

5. quad_converter.c     (.004381s)
Following the same idea as with nonce_converter, I unrolled the core loop of cheating_converter to do 4 strings at once, not just bytes. At first this did little, but then I decided to rearrage the instructions, and I got a speed up. The compiler actually did something interesting to the assembly. It inserted what I believe were wide register instruction for writting out the ints to the array. I am fairly certain that the unrolled loop had been successfully parallelized by the cpu. This was the absolute fastest procedure I wrote, however it was built off of cheating_converter, which may or may not have made an acceptable assumption.

6. last_converter.c     (.005080s)
I modified nonce_converter to do 4 strings at a time instead of 1 at a time the same as in quad_converter. Quite straightforward, and I got a speed up. This was the fastest procedure I could write without assuming strings of a length in a finite range, e.g. without using cheating_converter.
