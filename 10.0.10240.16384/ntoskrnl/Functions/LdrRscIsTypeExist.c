// LdrRscIsTypeExist 
 
int __fastcall LdrRscIsTypeExist(_DWORD *a1, unsigned int a2, int a3, _DWORD *a4)
{
  unsigned int v5; // lr
  int v7; // r8
  int v8; // r9
  unsigned __int16 *v9; // r6
  unsigned int v10; // r0
  int v12; // r6
  unsigned __int16 *v13; // r5
  unsigned int v14; // r0
  int v16; // r2
  int *v17; // r1
  int v18; // t1
  int v19; // r2
  int *v20; // r1
  int v21; // t1

  v5 = a2;
  v7 = 0;
  if ( !a1 || !a4 )
    return -1073741811;
  if ( a2 < 0x10000 )
  {
    v16 = a1[24] >> 2;
    v17 = (_DWORD *)((char *)a1 + a1[23]);
    while ( --v16 >= 0 )
    {
      v18 = *v17++;
      if ( v5 == v18 )
        goto LABEL_32;
    }
    *a4 |= 0x40000u;
LABEL_32:
    v19 = a1[28] >> 2;
    v20 = (_DWORD *)((char *)a1 + a1[27]);
    while ( --v19 >= 0 )
    {
      v21 = *v20++;
      if ( v5 == v21 )
        return v7;
    }
    goto LABEL_36;
  }
  v8 = a1[22] >> 1;
  v9 = (unsigned __int16 *)((char *)a1 + a1[21]);
  if ( (unsigned int)v9 > 0x10000 )
  {
    while ( v8 > 0 && *v9 )
    {
      if ( !wcsicmp(v5, v9) )
      {
        v5 = a2;
        break;
      }
      v10 = wcslen(v9);
      v9 += v10 + 1;
      v8 -= v10 + 1;
      v5 = a2;
    }
  }
  if ( !*v9 || v8 <= 0 )
    *a4 |= 0x40000u;
  v12 = a1[26] >> 1;
  v13 = (unsigned __int16 *)((char *)a1 + a1[25]);
  if ( (unsigned int)v13 > 0x10000 )
  {
    while ( v12 > 0 && *v13 && wcsicmp(v5, v13) )
    {
      v14 = wcslen(v13);
      v13 += v14 + 1;
      v12 -= v14 + 1;
      v5 = a2;
    }
  }
  if ( !*v13 || v12 <= 0 )
LABEL_36:
    *a4 |= 0x20000u;
  return v7;
}
