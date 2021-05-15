// ExpParseFastCache 
 
int __fastcall ExpParseFastCache(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v4; // r8
  unsigned int v5; // r4
  int v6; // r0
  int v7; // r9
  int v8; // r5
  unsigned int v9; // lr
  unsigned int v10; // r1
  int result; // r0

  v4 = *(_DWORD *)(a1 + 8);
  v5 = 0;
  v6 = a1 + 24;
  v7 = a2;
  if ( v4 )
  {
    v8 = a2;
    while ( (v6 & 7) == 0 )
    {
      v9 = *(_DWORD *)(v6 + 40);
      if ( v9 >= 0xFFFFFFD4 )
        break;
      if ( v9 + 51 < v9 + 44 )
        break;
      v10 = (v9 + 51) & 0xFFFFFFF8;
      if ( v4 < v10 || !v9 )
        break;
      if ( v7 && v5 < a3 )
      {
        *(_BYTE *)v8 = 2;
        *(_DWORD *)(v8 + 4) = v6;
      }
      v4 -= v10;
      v6 += v10;
      ++v5;
      v8 += 8;
      if ( !v4 )
        goto LABEL_12;
    }
    return -1073741762;
  }
LABEL_12:
  if ( a3 > v5 )
    return -1073741762;
  if ( a4 )
    *a4 = v5;
  if ( v5 > a3 )
    result = -1073741789;
  else
    result = 0;
  return result;
}
