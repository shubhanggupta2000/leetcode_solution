int sum = 0;
while (head != null) {
	sum = sum * 2 + head.val;
	head = head.next;
}
return sum;