final: main.o Control.o ReportForRegionPercent.o ReportForAnimalPercent.o ReportForHighestSubregion.o  ReportGenerator.o Record.o View.o
	g++ -o final main.o Control.o ReportForRegionPercent.o ReportForAnimalPercent.o ReportForHighestSubregion.o ReportGenerator.o Record.o View.o

main.o: Control.h Control.cc main.cc
	g++ -c main.cc

Control.o: Control.h Control.cc ReportGenerator.h ReportGenerator.cc ReportForRegionPercent.h ReportForRegionPercent.cc ReportForAnimalPercent.h ReportForAnimalPercent.cc View.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h
	g++ -c Control.cc

ReportForRegionPercent.o: ReportGenerator.h ReportGenerator.cc ReportForRegionPercent.h ReportForRegionPercent.cc Record.h Record.cc ReportData.h Map.h
	g++ -c ReportForRegionPercent.cc

ReportForAnimalPercent.o: ReportGenerator.h ReportGenerator.cc ReportForAnimalPercent.h ReportForAnimalPercent.cc Record.h Record.cc ReportData.h Map.h
	g++ -c ReportForAnimalPercent.cc

ReportForHighestSubregion.o: ReportGenerator.h ReportGenerator.cc ReportForHighestSubregion.h ReportForHighestSubregion.cc Record.h Record.cc ReportData.h Map.h
	g++ -c ReportForHighestSubregion.cc

ReportGenerator.o: ReportGenerator.h ReportGenerator.cc Map.h Record.h
	g++ -c ReportGenerator.cc

Record.o: Record.h Record.cc
	g++ -c Record.cc

View.o: View.h View.cc
	g++ -c View.cc

clean:
	rm -f *.o final