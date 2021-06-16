#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	wchar_t eu = L'😇';
	wchar_t emojis[10] = L"😀😃😄😁😆";

	printf("%lc\n", eu);
	printf("%ls\n", emojis);
}