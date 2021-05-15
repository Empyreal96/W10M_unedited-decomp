// CmpFindSecurityCellCacheIndex 
 
int __fastcall CmpFindSecurityCellCacheIndex(_DWORD *a1, int a2, int *a3)
{
  int v3; // r3
  int v5; // r9
  int v6; // r2
  unsigned int v7; // r5
  int v8; // r6
  int v9; // r7
  int v10; // r3
  int v11; // r1
  int v12; // r3
  int result; // r0

  v3 = a1[498];
  v5 = 0;
  if ( v3 )
  {
    v6 = a1[500];
    v7 = v3 - 1;
    v8 = 0;
    if ( v6 < 0 || v6 > v7 )
      v6 = v7 >> 1;
    v9 = a2 & 0x7FFFFFFF;
    if ( a2 < 0 )
      v9 = -v9;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = *(_DWORD *)(a1[501] + 8 * v6);
        v11 = v10 & 0x7FFFFFFF;
        if ( (v10 & 0x80000000) != 0 )
          v11 = -v11;
        v12 = v9 - v11;
        if ( v9 == v11 )
        {
          a1[500] = v6;
          result = 1;
          *a3 = v6;
          return result;
        }
        if ( v5 )
          break;
        if ( v12 < 0 )
          v7 = v6;
        else
          v8 = v6;
        if ( v7 - v8 <= 1 )
        {
          v6 = v8;
          v5 = 1;
        }
        else
        {
          v6 = v8 + ((v7 - v8) >> 1);
        }
      }
      if ( v5 != 1 )
        break;
      if ( v12 < 0 )
        goto LABEL_23;
      if ( v8 == v7 )
        goto LABEL_24;
      v5 = 2;
      v6 = v7;
    }
    if ( v12 < 0 )
    {
LABEL_23:
      result = 0;
      *a3 = v6;
      return result;
    }
LABEL_24:
    *a3 = v6 + 1;
    result = 0;
  }
  else
  {
    *a3 = 0;
    result = 0;
  }
  return result;
}
