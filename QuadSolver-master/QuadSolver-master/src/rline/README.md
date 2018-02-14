Read a line from the user

ret = rline(n, &line)

Array (&line) of size (n)

Return values:
	0 - OK
	Anything else is bad

Issues the might arise
	Too long of a line
	Null is entered
	*No outputs from this function other than the return*

Validate arguments
	N is an int >= 1
	char line[100] != null
	