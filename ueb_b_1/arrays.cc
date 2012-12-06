int* createArray(int n) {
  return new int[n];
}

void releaseArray(int*& arr) {
  delete[] arr;
  arr = NULL;
}

int main(void) {
  int* a = createArray(10);
  releaseArray(a);
  return 0;
}
