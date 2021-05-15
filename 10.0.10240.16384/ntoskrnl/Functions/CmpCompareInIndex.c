// CmpCompareInIndex 
 
int __fastcall CmpCompareInIndex(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4, _DWORD *a5)
{
  _DWORD *v5; // r7
  int v6; // r5
  int v7; // r8
  unsigned __int16 *v8; // lr
  unsigned __int16 *v9; // r4
  int result; // r0
  unsigned __int16 *v11; // r9
  _DWORD *v12; // r4
  int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r7
  unsigned int v17; // r4
  unsigned __int16 *v18; // r3
  unsigned __int16 *v19; // r5
  unsigned int v20; // r0
  unsigned int v21; // r6
  unsigned int v22; // r10
  unsigned __int16 *v23; // [sp+0h] [bp-28h]
  int v25; // [sp+8h] [bp-20h]

  v5 = a5;
  v6 = *a4;
  v7 = -1;
  *a5 = -1;
  v8 = a2;
  v25 = a1;
  if ( v6 != 26220 && v6 != 26732 )
  {
    v9 = &a4[2 * a3];
    result = CmpDoCompareKeyName(a1, a2, *((_DWORD *)v9 + 1));
    if ( result != 2 )
    {
      if ( result )
        return result;
      v13 = *((_DWORD *)v9 + 1);
LABEL_32:
      *v5 = v13;
      return result;
    }
    return 2;
  }
  v11 = &a4[4 * a3];
  v12 = v11 + 2;
  if ( v6 == 26220 )
  {
    v14 = 4;
    v15 = 0;
    while ( *((_BYTE *)v12 + v15 + 4) )
    {
      if ( ++v15 >= 4 )
        goto LABEL_13;
    }
    v14 = v15;
LABEL_13:
    v16 = *v8 >> 1;
    if ( v16 >= v14 )
      v16 = v14;
    v17 = 0;
    if ( v16 )
    {
      v18 = (unsigned __int16 *)*((_DWORD *)v8 + 1);
      v19 = v11;
      while ( 1 )
      {
        v20 = *v18;
        v21 = *((unsigned __int8 *)v19 + 8);
        v23 = v18 + 1;
        if ( v20 >= 0x61 )
        {
          if ( v20 > 0x7A )
            v22 = RtlUpcaseUnicodeChar(v20);
          else
            v22 = v20 - 32;
        }
        else
        {
          v22 = *v18;
        }
        if ( v21 >= 0x61 )
        {
          if ( v21 > 0x7A )
            v21 = RtlUpcaseUnicodeChar(v21);
          else
            v21 -= 32;
        }
        if ( v22 != v21 )
          break;
        ++v17;
        v18 = v23;
        v19 = (unsigned __int16 *)((char *)v19 + 1);
        if ( v17 >= v16 )
        {
          v8 = a2;
          a1 = v25;
          goto LABEL_23;
        }
      }
      if ( (int)(v22 - v21) > 0 )
        v7 = 1;
      return v7;
    }
LABEL_23:
    v5 = a5;
    v12 = v11 + 2;
  }
  result = CmpDoCompareKeyName(a1, v8, *((_DWORD *)v11 + 1));
  if ( result == 2 )
    return 2;
  if ( !result )
  {
    v13 = *v12;
    goto LABEL_32;
  }
  return result;
}
