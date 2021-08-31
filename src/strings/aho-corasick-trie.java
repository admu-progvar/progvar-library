class Node {
  HashMap<Character, Node> next = new HashMap<>();
  Node fail = null;
  long count = 0;
  public void add(String s) { // adds string to trie
    Node node = this;
    for (char c : s.toCharArray()) {
      if (!node.contains(c))
        node.next.put(c, new Node());
      node = node.get(c);
    } node.count++; }
  public void prepare() {
    // prepares fail links of Aho-Corasick Trie
    Node root = this; root.fail = null;
    Queue<Node> q = new ArrayDeque<Node>();
    for (Node child : next.values()) // BFS
      { child.fail = root; q.offer(child); }
    while (!q.isEmpty()) {
      Node head = q.poll();
      for (Character letter : head.next.keySet()) {
      // traverse upwards to get nearest fail link
        Node p = head;
        Node nextNode = head.get(letter);
        do { p = p.fail; }
        while(p != root && !p.contains(letter));
        if (p.contains(letter)) { // fail link found
          p = p.get(letter);
          nextNode.fail = p;
          nextNode.count += p.count;
        } else { nextNode.fail = root; }
        q.offer(nextNode); } } }
  public BigInteger search(String s) {
    // counts the words added in trie present in s
    Node root = this, p = this;
    BigInteger ans = BigInteger.ZERO;
    for (char c : s.toCharArray()) {
      while (p != root && !p.contains(c)) p = p.fail;
      if (p.contains(c)) {
        p = p.get(c);
        ans = ans.add(BigInteger.valueOf(p.count)); }
    } return ans; }
  private Node get(char c) { return next.get(c); }
  private boolean contains(char c) {
    return next.containsKey(c); }}
// Usage: Node trie = new Node();
// for (String s : dictionary) trie.add(s);
// trie.prepare(); BigInteger m = trie.search(str);
