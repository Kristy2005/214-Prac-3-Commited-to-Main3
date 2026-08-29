eventflow: main.o Subject.o Observer.o EventComponent.o EventUnit.o EventGroup.o EventControl.o Notice.o Stage.o EntranceGate.o StageGate.o Bar.o FoodVendor.o SecurityTeam.o MedicalTeam.o
	g++ main.o Subject.o Observer.o EventComponent.o EventUnit.o EventGroup.o EventControl.o Notice.o Stage.o EntranceGate.o StageGate.o Bar.o FoodVendor.o SecurityTeam.o MedicalTeam.o -o eventflow


main.o: main.cpp
	g++ main.cpp -c


Subject.o: Subject.cpp Subject.h
	g++ Subject.cpp -c


Observer.o: Observer.cpp Observer.h
	g++ Observer.cpp -c


EventComponent.o: EventComponent.cpp EventComponent.h
	g++ EventComponent.cpp -c


EventUnit.o: EventUnit.cpp EventUnit.h
	g++ EventUnit.cpp -c


EventGroup.o: EventGroup.cpp EventGroup.h
	g++ EventGroup.cpp -c


EventControl.o: EventControl.cpp EventControl.h
	g++ EventControl.cpp -c


Notice.o: Notice.cpp Notice.h
	g++ Notice.cpp -c


Stage.o: Stage.cpp Stage.h
	g++ Stage.cpp -c


EntranceGate.o: EntranceGate.cpp EntranceGate.h
	g++ EntranceGate.cpp -c


StageGate.o: StageGate.cpp StageGate.h
	g++ StageGate.cpp -c


Bar.o: Bar.cpp Bar.h
	g++ Bar.cpp -c


FoodVendor.o: FoodVendor.cpp FoodVendor.h
	g++ FoodVendor.cpp -c


SecurityTeam.o: SecurityTeam.cpp SecurityTeam.h
	g++ SecurityTeam.cpp -c


MedicalTeam.o: MedicalTeam.cpp MedicalTeam.h
	g++ MedicalTeam.cpp -c


run: eventflow
	./eventflow


valgrind: eventflow
	valgrind --leak-check=full ./eventflow


clean:
	rm -f *.o eventflow