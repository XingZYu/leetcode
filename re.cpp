#include <stdio.h>
#include <algorithm>
#include <string.h>

const int N = 1100;

bool isMatch(const char *s, const char *p)
{
	bool f[N][N];
	int n = strlen(s), m = strlen(p);
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j) if (f[i][j])
		{
			if (p[j + 1] == '*')
			{
				if (s[i] == p[j] || p[j] == '.')
					f[i + 1][j] = 1;
				f[i][j + 2] = 1;
			}
			else 
			{
				if (s[i] == p[j] || p[j] == '.') f[i + 1][j + 1] = 1;
			}
		}
	for (int j = 0; j < m; ++ j) if (f[n][j])
		if (p[j + 1] == '*')
			f[n][j + 2] = 1;
	return f[n][m];
}

int main()
{
	char a[N], b[N];
	scanf(" %s %s", a, b);
	printf("%d", isMatch(a,b));
}