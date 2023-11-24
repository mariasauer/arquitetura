# arquitetura
Trabalho desenvolvido para a matéria de arquitetura.


o que cada coisa significa no vtune
http://portal.nacad.ufrj.br/online/intel/vtune2017/help/GUID-8F36D27D-637D-470B-B6D5-336B3B333B9B.html
http://portal.nacad.ufrj.br/online/intel/vtune2017/help/GUID-B41CF6D2-AB40-4915-922A-496EF6E3C43E.html

USANDO O VTUNE:

echo 0 | sudo tee /proc/sys/kernel/perf_event_paranoid 

source ./setvars.sh

vtune-gui .

_________________________________________________________________________________________________________

Modo de gerar uma entrada com entry_generator

> ./entry_generator -q _QUANTIDADE_ -a _MÍNIMO_ -z _MÁXIMO_

entry generator gera o arquivo entry.txt para ser usado em vector_test e list_test

===========

Modo de realizar um teste tanto para vector_test, quanto list_test

> ./executável < entry.txt

_________________________________________________________________________________________________________

