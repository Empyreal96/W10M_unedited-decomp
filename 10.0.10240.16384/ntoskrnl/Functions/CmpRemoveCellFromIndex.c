// CmpRemoveCellFromIndex 
 
unsigned __int16 *__fastcall CmpRemoveCellFromIndex(unsigned __int16 *result, int a2)
{
  int v2; // r2
  unsigned __int16 v4; // r2
  int v5; // r3
  unsigned int v6; // r2
  int v7; // r1
  int v8; // r0
  unsigned __int16 v9; // r2
  int v10; // r3
  unsigned __int16 *v11; // r0

  v2 = *result;
  if ( v2 == 26220 || v2 == 26732 )
  {
    v9 = result[1];
    v10 = (unsigned __int16)(v9 - 1);
    result[1] = v10;
    if ( v9 == 1 )
      return result;
    v11 = &result[4 * a2];
    v6 = 8 * (v10 - a2);
    v7 = (int)(v11 + 6);
    v8 = (int)(v11 + 2);
  }
  else
  {
    v4 = result[1];
    v5 = (unsigned __int16)(v4 - 1);
    result[1] = v5;
    if ( v4 == 1 )
      return result;
    v6 = 4 * (v5 - a2);
    v7 = (int)&result[2 * a2 + 4];
    v8 = (int)&result[2 * a2 + 2];
  }
  return (unsigned __int16 *)memmove(v8, v7, v6);
}
