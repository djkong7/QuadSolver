Validate that the line was entered as 3 floats and return them as doubles


ret = validate(line, n, &a, &b, &c)

Check
	a != 0
	a, b, c are floats
		Not infinity, -infinity, NaN

What are legal inputs
	1
	1.00134e7

What are not legal inputs
	1.8e420
	

