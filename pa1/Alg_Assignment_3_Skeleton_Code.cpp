#include <cstdio>
#include <chrono>
#include <algorithm>
#include <stack>

using namespace std;

/////////////////////////////////////////////////
//////////////// YOUR PLAYGROUND ////////////////
/////////////////////////////////////////////////


void MyVeryFastSort(int n, int *d)
{
	stack<int> s;
	int pivot, temp, i, j;
	int l, r;
	l = 0;
	r = n-1;
	s.push(r);
	s.push(l);

	while(!s.empty()) {
		l = s.top();
		s.pop();
		r = s.top();
		s.pop();

		if(r-l+1 > 10) {
			pivot = d[r];
			i = l-1;
			j = r;

			while(1) {
				while(d[++i] < pivot) ; 
				while(d[--j] > pivot) ;
				
				if(i>=j) break;
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}

			temp = d[i];
			d[i] = d[r];
			d[r] = temp;

			s.push(r);
			s.push(i+1);
			s.push(i-1);
			s.push(l);

		} else {
			int x,y,t;
			for(x=0; x<(r-l+1); x++) {
				t = d[l+x];
				y=x;
				
				while(d[l+y-1] > t && y > 0) {
					d[l+y] = d[l+y-1];
					y--;
				}
				
				d[l+y] = t;
			}		
		}
	}
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////


// Utilized to check the correctness
bool Validate(int n, int *d)
{
	int *gt = new int [ n ];
	for(int i=0;i<n;i++) { gt[i] = d[i]; }
	std::sort( &(gt[0]) , &(gt[n]) );
	for(int i=0;i<n;i++)
	{
		if( gt[i] != d[i] )
		{
			delete [] gt;
			return false;
		}
	}
	delete [] gt;
	return true;
}

int main(int argc, char **argv)
{
	if( argc != 3 )
	{
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}


	// Get input from a binary file whose name is provided from the command line
	int n, *d;
	FILE *input = fopen( argv[1] , "rb" );
	int e = fread( &n , sizeof(int) , 1 , input );
	d = new int [ n ];
	e = fread( d , sizeof(int) , n , input );
	fclose(input);

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	// Call your sorting algorithm
	MyVeryFastSort( n , d );

	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	double res_time = elapsed_time.count();

	bool res_validate = Validate( n , d );

	// Write the results (corretness and time)
	FILE *output = fopen( argv[2] , "w" );
	if( res_validate ) { fprintf( output , "OKAY\n" ); printf("OKAY\n"); }
	else { fprintf( output , "WRONG\n" ); printf("WRONG\n");  }
	fprintf( output , "%d\n" , (int)res_time );
	printf( "%d\n" , (int)res_time );
	fclose(output);

	delete [] d;

	return 1;
}
