reset
set xlabel 'N'
set ylabel 'sec'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_clock_gettime.csv" using 1:2 smooth csplines lw 2 title "Baseline", \
''using 1:3 smooth csplines lw 2 title "Baseline with OpenMP", \
''using 1:4 smooth csplines lw 2 title "AVX SIMD", \
''using 1:5 smooth csplines lw 2 title "VX SIMD + Loop unrolling", \
''using 1:6 smooth csplines lw 2 title "Leibniz_2", \
''using 1:7 smooth csplines lw 2 title "Leibniz_2 with OpenMP", \
''using 1:8 smooth csplines lw 2 title "Wallis", \
''using 1:9 smooth csplines lw 2 title "Wallis with OpenMP"

