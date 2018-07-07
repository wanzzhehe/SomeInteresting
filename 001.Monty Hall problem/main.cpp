#include <bits/stdc++.h>
using namespace std;

template<class T>
class Random{ 
#ifdef __linux
	private:
		T res;
		FILE *f;
	public:
		Random() { 
			f = fopen("/dev/random", "r");
		}
		~Random() { 
			fclose(f);
		}
		T operator () (void) { 
			fread(&res, sizeof(T), 1, f);
			return res;
		}
#endif
#ifdef _WIN32
	public:
		Random() { 
			srand(time(NULL));
		}
		T operator () (void) { 
			return rand();
		}
#endif
};

Random<unsigned> a;
unsigned long long Casenum;
int WhichDoor, FirstSelect;
int SecontSelect;
unsigned long long cnt0, cnt1, cnt;
bool Selected[3];

int main() { 
	printf("Please enter the number of repetitions: ");
	scanf("%llu", &Casenum);
	cnt = Casenum;
	while(Casenum--) { 
		memset(Selected, 0x00, sizeof(Selected));
		WhichDoor = a() % 3;
		FirstSelect = a() % 3;
		Selected[FirstSelect] = true;
		do{ 
			SecontSelect = a() % 3;
		}while(Selected[SecontSelect] || SecontSelect == WhichDoor);
		Selected[SecontSelect] = true;
		if(FirstSelect == WhichDoor) ++cnt1;
		for(int i = 0; i != 3; ++i)
			if(!Selected[i] && i == WhichDoor) { 
				++cnt0; break;
			}
	}
	printf("Total : %llu\n", cnt);
	printf("If you change your choice:\n");
	printf("You win : %llu\n", cnt0);
	printf("You lose: %llu\n", cnt - cnt0);
	printf("If you not change your choice:\n");
	printf("You win : %llu\n", cnt1);
	printf("You lose : %llu\n", cnt - cnt1);
	return 0;
}
