bool hasPath(char* matrix, int rows, int cols, char* str)
{//matrix为存放数据的数组（即题目中给的矩阵），str是目标字符串
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
	{
		return false;
	}
	bool* visited = new bool[rows*cols];//定义一个布尔矩阵 
	memset(visited, 0, rows* cols);//把数组中的所有值都赋为0
	int pathLength = 0;//指示目标字符串的下标
	for (int row = 0; row < rows; row++)//行
	{
		for (int col; col < cols; col++)//列
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
			{
				return true;
			}
		}
	}
	delete[]visited;
	return false;
}
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
	{
		return true;
	}
	bool hasPath = false;
	//递归的时候如果匹配就进入，不匹配直接return
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
	{
		++pathLength;
		visited[row*cols + col] = true;//走过后就把值改为true，则不能再进入了
		//四个方向都可以走，使用递归的思想，如果匹配就一直递归下去，如果不匹配就跳出递归
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
		if (!hasPath)//回退，如果下一步四个方向都没有匹配的字符，就退回上一步
		{
			--pathLength;//退回上一步需要把字符串的下标回跳一位
			visited[row*cols + col] = false;//同时需要把所在的这一步的值重新赋为false
		}
	}
	return hasPath;
}