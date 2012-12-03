int* createArray(int n) {
  return new int[n];
}

void releaseArray(int*& arr) {
  delete[] arr;
}

int main(void) {
  int* a = createArray(10);
  releaseArray(a);
  return 0;
}
