#include <cmath>
#include <fstream>
using namespace std;

void solve_explicit(double* const,double* const, const double, const int);
void streamout(const double* const, const double* const, const double, const int);
void solve_implicit(double* const, double* const, const double, const int);

int main(){
const double dt=M_PI/100; const double x0=1; const double x0_dot=0; const double t_end=20*M_PI; const int s=int(t_end/dt+1);
const int dimension=2;
double y1f[s]; double y2f[s]; double y1b[s]; double y2b[s];
y1f[0]=x0; y2f[0]=x0_dot; y1b[0]=x0; y2b[0]=x0_dot;

solve_explicit(y1f,y2f,dt,s); solve_implicit(y1b,y2b,dt,s); streamout(y1f,y1b,dt,s);

return 0;
}

void solve_explicit(double* const y1, double* const y2, const double dt, const int s){
double a=y1[0]; double b=y2[0];
	for(int i=1;i<s;i++){
		y2[i]=b-a*dt;
		y1[i]=a+b*dt;
		b=y2[i];a=y1[i];
	}
}

void solve_implicit(double* const y1, double* const y2, const double dt, const int s){
double a=y1[0]; double b=y2[0];
	for(int i=1;i<s;i++){
		y2[i]=(y2[i-1]-dt*y1[i-1])/(1+dt*dt);
		y1[i]=y1[i-1]+y2[i]*dt;
	}
}

void streamout(const double* const y1f, const double* const y1b, const double dt, const int s){
ofstream out("Data_euler.txt");
for(int i=0; i<s; i++) out << i*dt << "\t" << cos(i*dt) << "\t" << y1f[i] << "\t" << y1b[i] <<endl;
out.close();
}
