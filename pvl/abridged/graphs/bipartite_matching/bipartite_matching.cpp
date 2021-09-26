vi* adj;
bool* done;   // initially all false
int* owner;   // initially all -1
int alternating_path(int left) {
  if (done[left]) return 0;
  done[left] = true;
  for (int right : adj[left]) {
    if (owner[right] == -1 || alternating_path(owner[right])) {
      owner[right] = left; return 1; } }
  return 0; }
