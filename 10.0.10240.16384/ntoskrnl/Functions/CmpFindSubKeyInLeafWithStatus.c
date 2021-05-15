// CmpFindSubKeyInLeafWithStatus 
 
int __fastcall CmpFindSubKeyInLeafWithStatus(int a1, int a2, int a3, _DWORD *a4, unsigned int *a5)
{
  unsigned int v5; // r7
  unsigned int v7; // r8
  unsigned int v8; // r6
  int v11; // r0
  int result; // r0
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r2
  int v16; // [sp+8h] [bp-20h]

  v5 = 0;
  v7 = *(unsigned __int16 *)(a2 + 2) - 1;
  v8 = v7 >> 1;
  v16 = a1;
  if ( !*(_WORD *)(a2 + 2) )
  {
    result = -1073741772;
    v15 = 0;
LABEL_18:
    *a4 = -1;
    *a5 = v15;
    return result;
  }
  while ( 1 )
  {
    v11 = CmpCompareInIndex(a1, a3, v8, a2, a4);
    if ( v11 == 2 )
      goto LABEL_22;
    if ( v11 < 0 )
    {
      v7 = v8;
    }
    else
    {
      if ( !v11 )
      {
        *a5 = v8;
        return 0;
      }
      v5 = v8;
    }
    if ( v7 - v5 <= 1 )
      break;
    a1 = v16;
    v8 = v5 + ((v7 - v5) >> 1);
  }
  v13 = CmpCompareInIndex(v16, a3, v5, a2, a4);
  if ( v13 == 2 )
  {
LABEL_22:
    result = -1073741670;
    v15 = 0x80000000;
    goto LABEL_18;
  }
  if ( v13 < 0 )
  {
    result = -1073741772;
  }
  else
  {
    if ( v13 )
    {
      v14 = CmpCompareInIndex(v16, a3, v7, a2, a4);
      if ( v14 != 2 )
      {
        *a5 = v7;
        if ( v14 )
          return -1073741772;
        return 0;
      }
      goto LABEL_22;
    }
    result = 0;
  }
  *a5 = v5;
  return result;
}
