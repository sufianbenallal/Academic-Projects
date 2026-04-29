#define SHM_NAME "/my_shm"

struct shared_data {
  long x;
  sem_t sem;
};
