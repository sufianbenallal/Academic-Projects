void dispatcher( int workfd, long numwp, long nstep);
void worker( int workfd, int resultfd);
void gatherer( int resultfd);

struct work {
  double x_start;
  double x_end;
  long n_steps;
};
