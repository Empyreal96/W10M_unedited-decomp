// CmpParseCacheCompareUnicodeStrings 
 
BOOL __fastcall CmpParseCacheCompareUnicodeStrings(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int *a4)
{
  _WORD *v4; // r4
  _WORD *v5; // r6
  _WORD *v6; // r8
  int v8; // r3
  int v9; // r2
  int v10; // r7
  _WORD *v11; // r10
  int v12; // r9
  unsigned int v13; // r5
  int v14; // r7
  unsigned int v15; // r0
  __int16 v16; // r3
  BOOL result; // r0
  int v18; // [sp+0h] [bp-30h]
  int v19; // [sp+4h] [bp-2Ch]
  int v20; // [sp+8h] [bp-28h]

  v4 = (_WORD *)*((_DWORD *)a1 + 1);
  v5 = (_WORD *)*((_DWORD *)a2 + 1);
  v6 = &v4[*a1 >> 1];
  v8 = 1;
  v9 = 0;
  v10 = 1;
  v11 = &v5[*a2 >> 1];
  v19 = 1;
  v20 = a3;
  v12 = 0;
  v18 = 0;
  if ( v4 >= v6 )
    goto LABEL_14;
  while ( 1 )
  {
    if ( v5 >= v11 )
    {
LABEL_12:
      v10 = 1;
      goto LABEL_13;
    }
    if ( v8 )
    {
      for ( ; v4 < v6; ++v4 )
      {
        if ( *v4 != 92 )
          break;
      }
      do
      {
        if ( *v5 != 92 )
          break;
        ++v5;
      }
      while ( v5 < v11 );
      v8 = 0;
      v19 = 0;
      v12 = 1;
      goto LABEL_11;
    }
    v13 = (unsigned __int16)*v4;
    if ( v13 >= 0x61 )
    {
      if ( v13 > 0x7A )
        v14 = RtlUpcaseUnicodeChar((unsigned __int16)*v4);
      else
        v14 = v13 - 32;
    }
    else
    {
      v14 = (unsigned __int16)*v4;
    }
    v15 = (unsigned __int16)*v5;
    if ( v15 >= 0x61 )
    {
      if ( v15 > 0x7A )
        v15 = RtlUpcaseUnicodeChar(v15);
      else
        v15 -= 32;
    }
    if ( v14 != v15 )
      break;
    if ( v13 == 92 )
    {
      v8 = 1;
      v19 = 1;
    }
    else
    {
      v8 = v19;
      ++v4;
      ++v5;
      if ( v12 )
      {
        v12 = 0;
        v9 = ++v18;
        goto LABEL_11;
      }
    }
    v9 = v18;
LABEL_11:
    if ( v4 >= v6 )
      goto LABEL_12;
  }
  v9 = v18;
  v10 = 0;
LABEL_13:
  a3 = v20;
LABEL_14:
  v16 = 2 * (v11 - v5);
  *(_WORD *)a3 = v16;
  *(_WORD *)(a3 + 2) = v16;
  *(_DWORD *)(a3 + 4) = v5;
  *a4 = v9;
  if ( v10 )
    result = v4 == v6;
  else
    result = 0;
  return result;
}
