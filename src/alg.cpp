// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int x = i + 1; x < len; x++) {
      if (arr[i] + arr[x] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int x = len - 1 ; x > i; x--) {
      if (arr[i] + arr[x] == value)
        count++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int l = i + 1;
    int r = len - 1;
    while (l < r) {
      if (arr[(l + r) / 2] + arr[i] < value) {
        l = (l + r) / 2 + 1;
      } else {
        r = (l + r) / 2;
      }
    }
    while (arr[l] + arr[i] == value) {
      count++;
      l++;
    }
  }
  return count;
}


