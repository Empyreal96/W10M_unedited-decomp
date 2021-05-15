// FadePalette 
 
char *__fastcall FadePalette(int a1)
{
  char *v2; // r4
  int v3; // r7
  int v4; // lr
  char *result; // r0

  v2 = PalettePtr;
  v3 = 16;
  v4 = &MainPalette - (_UNKNOWN *)PalettePtr;
  do
  {
    result = &v2[v4];
    *v2 = (int)((unsigned __int64)(1717986919i64 * (unsigned __int8)v2[v4] * a1) >> 32) >> 3;
    v2[1] = (int)((unsigned __int64)(1717986919i64 * (unsigned __int8)v2[v4 + 1] * a1) >> 32) >> 3;
    v2[2] = (int)((unsigned __int64)(1717986919i64 * (unsigned __int8)v2[v4 + 2] * a1) >> 32) >> 3;
    v2[3] = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  return result;
}
