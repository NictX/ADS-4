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

int cbinsearch(int *arr, int size, int value, int l) {
  int r = size - 1;
  int count = 0;
  while (r >= l) {
    if (arr[(l + r) / 2] == value) {
      count++;
      break;
    }
    if (arr[(l + r) / 2] < value) {
      l = (l + r) / 2 + 1;
    }
    if (arr[(l + r) / 2] > value) {
      r = (l + r) / 2 - 1;
    }
  }
  if (count != 0) {
    for (int i = (l + r) / 2 + 1; arr[i] == value && i <= size - 1; i++) {
      count++;
    }
    for (int i = (l + r) / 2 - 1; arr[i] == value && i >= 0; i--) {
      count++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    count += cbinsearch(arr, len, value - arr[i], i);
  }
  return count;
}


