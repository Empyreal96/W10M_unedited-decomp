// SmProcessListRequestExtended 
 
int __fastcall SmProcessListRequestExtended(int a1, int a2)
{
  int v3; // r2
  int v4; // r4
  unsigned int v5; // r8
  int v6; // r7
  int v7; // r9
  int *v8; // r10
  unsigned int *v9; // r6
  unsigned int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v14; // r10
  int v15; // r6
  _DWORD *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  _DWORD *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int v24; // [sp+4h] [bp-24h]

  v3 = a1;
  v4 = 0;
  v5 = 0;
  if ( *(_BYTE *)(a2 + 1) )
  {
    v6 = 0;
    v7 = 8;
    while ( 1 )
    {
      v24 = *(_DWORD *)(a2 + 4 * v5 + 4);
      v8 = (int *)(v3 + 96 * (v24 & 0x1F));
      v9 = (unsigned int *)(v8 + 1);
      __pld(v8 + 1);
      v10 = v8[1] & 0xFFFFFFFE;
      do
        v11 = __ldrex(v9);
      while ( v11 == v10 && __strex(v10 + 2, v9) );
      __dmb(0xBu);
      if ( v11 == v10 || ExfAcquireRundownProtection(v8 + 1) )
      {
        if ( (v8[3] & 0x7FF) == v24 >> 5 )
        {
          v4 = *v8;
          goto LABEL_17;
        }
        __pld(v9);
        v12 = *v9 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v13 = __ldrex(v9);
        while ( v13 == v12 && __strex(v12 - 2, v9) );
        if ( v13 != v12 )
          ExfReleaseRundownProtection((unsigned __int8 *)v8 + 4);
      }
      v4 = 0;
LABEL_17:
      if ( v4 )
      {
        if ( *(_BYTE *)(v4 + 3516) == 1 )
        {
          v15 = SmKmFileInfoGetPath(v4 + 3660, v6 + a2 + 132, 128);
          if ( v15 < 0 )
          {
            v14 = a1;
            goto LABEL_22;
          }
        }
        else
        {
          *(_WORD *)(v6 + a2 + 132) = 0;
        }
        v14 = a1;
        v20 = (_DWORD *)(a1 + 96 * (*(_DWORD *)(v4 + 3512) & 0x1F) + 4);
        __pld(v20);
        v21 = *v20 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v22 = __ldrex(v20);
        while ( v22 == v21 && __strex(v21 - 2, v20) );
        if ( v22 != v21 )
          ExfReleaseRundownProtection((unsigned __int8 *)v20);
        v4 = 0;
      }
      else
      {
        memmove(a2 + 4 * v5 + 4, v7 + a2, 4 * (*(unsigned __int8 *)(a2 + 1) - v5 - 1));
        v6 -= 128;
        v14 = a1;
        --*(_BYTE *)(a2 + 1);
        --v5;
        v7 -= 4;
      }
      ++v5;
      v6 += 128;
      v7 += 4;
      if ( v5 >= *(unsigned __int8 *)(a2 + 1) )
        goto LABEL_39;
      v3 = a1;
    }
  }
  v14 = a1;
LABEL_39:
  v15 = 0;
LABEL_22:
  if ( v4 )
  {
    v16 = (_DWORD *)(v14 + 96 * (*(_DWORD *)(v4 + 3512) & 0x1F) + 4);
    __pld(v16);
    v17 = *v16 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v18 = __ldrex(v16);
    while ( v18 == v17 && __strex(v17 - 2, v16) );
    if ( v18 != v17 )
      ExfReleaseRundownProtection((unsigned __int8 *)v16);
  }
  return v15;
}
