hw3.out : main.o AccountSystems.o Accounts.o Account.o AccountChecking.o AccountSaving.o
	g++ main.o AccountSystems.o Accounts.o Account.o AccountChecking.o AccountSaving.o -o hw3.out

main.o : main.cpp AccountSystems.h
	g++ -Wall -c main.cpp

AccountSystems.o : AccountSystems.cpp AccountSystems.h Accounts.h Account.h AccountChecking.h AccountSaving.h
	g++ -Wall -c AccountSystems.cpp

Accounts.o : Accounts.cpp Accounts.h Account.h
	g++ -Wall -c Accounts.cpp

Account.o : Account.cpp Account.h
	g++ -Wall -c Account.cpp

AccountChecking.o : AccountChecking.cpp AccountChecking.h Account.h
	g++ -Wall -c AccountChecking.cpp

AccountSaving.o : AccountSaving.cpp AccountSaving.h Account.h
	g++ -Wall -c AccountSaving.cpp

clean :
	rm *.o hw3.out

