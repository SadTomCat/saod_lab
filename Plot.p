set termoption enhanced
set terminal svg size 800,600 font "Arial, 16"
set output "plot.svg"

set format x "%5.0f"
set format y "%.2f"

set xlabel "Количество элементов в массиве"
set ylabel "Время выполнения, с"
set grid

set logscale y
set xtics 100000
set mxtics
set style line 1 lc rgb "0x11144c" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x3a9679" lt 1 lw 4 pt 7 ps 1
set style line 3 lc rgb "0xe16262" lt 1 lw 4 pt 5 ps 1

plot "graph.dat" using 1:2 title "Selection" with linespoints ls 1, \
"graph.dat" using 1:3 title "Radix" with linespoints ls 2, \
"graph2.dat" using 1:2 title "Quick" with linespoints ls 3
