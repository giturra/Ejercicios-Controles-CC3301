
typedef double (*Funcion)(void *p, double x);
double integral(Funcion f, void *p, double xi, double xf, int n);

double g(double x, double y);
double integral_g_dx_dy(double xi, double xf, int n,
                        double yi, double yf, int m);

double integral_g_dx_dy_par(double xi, double xf, int n,
                            double yi, double yf, int m);
