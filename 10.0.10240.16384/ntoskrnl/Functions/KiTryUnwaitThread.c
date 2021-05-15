// KiTryUnwaitThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiTryUnwaitThread(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r6
  int result; // r0
  unsigned int *v9; // lr
  unsigned int v11; // r5
  char v12; // r2
  _BYTE *v13; // r2
  int v14; // r3
  unsigned int *v15; // r4
  unsigned int v16; // r2
  int v17; // r1 OVERLAPPED
  _DWORD *v18; // r2 OVERLAPPED
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int *v24; // r1
  char v25; // r2
  int v26; // r3
  int *v27; // r2
  int **v28; // r4
  int v29; // [sp+0h] [bp-30h]

  v5 = *(_DWORD *)(a2 + 12);
  result = 0;
  v9 = (unsigned int *)(v5 + 44);
  while ( 1 )
  {
    do
      v11 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v11 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  if ( *(_BYTE *)(v5 + 132) != 5 )
  {
LABEL_18:
    __dmb(0xBu);
    *v9 = 0;
    ++*(_BYTE *)(a2 + 9);
    return result;
  }
  v12 = *(_BYTE *)(v5 + 72);
  if ( (v12 & 7) == 1 || (v12 & 7) == 4 )
  {
    v13 = *(_BYTE **)(v5 + 152);
    if ( v13 )
    {
      if ( (*v13 & 0x7F) == 21 )
      {
        v21 = *(unsigned __int8 *)(v5 + 332);
        *(_DWORD *)(v5 + 332) = v21;
        __dmb(0xBu);
        v22 = (unsigned int *)&v13[4 * v21 + 272];
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 + 1, v22) );
      }
      else
      {
        __dmb(0xBu);
        v19 = (unsigned int *)(v13 + 24);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 + 1, v19) );
      }
      __dmb(0xBu);
    }
    v14 = *(_DWORD *)(v5 + 436);
    if ( v14 )
    {
      v15 = (unsigned int *)(v14 + 1928);
      while ( 1 )
      {
        do
          v16 = __ldrex(v15);
        while ( __strex(1u, v15) );
        __dmb(0xBu);
        if ( !v16 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v15 );
      }
      if ( *(_DWORD *)(v5 + 436) )
      {
        *(_QWORD *)&v17 = *(_QWORD *)(v5 + 144);
        if ( *(_DWORD *)(v17 + 4) != v5 + 144 || *v18 != v5 + 144 )
          __fastfail(3u);
        *v18 = v17;
        *(_DWORD *)(v17 + 4) = v18;
        *(_DWORD *)(v5 + 436) = 0;
      }
      __dmb(0xBu);
      *v15 = 0;
    }
    *(_BYTE *)(v5 + 132) = 7;
    result = 1;
    *(_DWORD *)(v5 + 144) = *(_DWORD *)(a1 + 1540);
    *(_DWORD *)(a1 + 1540) = v5 + 144;
    *(_DWORD *)(v5 + 136) = a3;
    goto LABEL_17;
  }
  if ( (v12 & 7) == 0 )
  {
    *(_BYTE *)(v5 + 72) = v12 & 0xF8 | 2;
    *(_DWORD *)(v5 + 136) = a3;
    *(_BYTE *)(a2 + 9) = 0;
    result = 1;
LABEL_17:
    if ( a4 )
    {
      *a4 = v5;
      v24 = *(int **)(a2 + 16);
      if ( (*(_BYTE *)v24 & 0x7F) == 2 )
      {
        *(_WORD *)(v5 + 308) -= *((unsigned __int8 *)v24 + 29);
        if ( *(_DWORD *)(a1 + 4) == v5 )
          v25 = *(_BYTE *)(a1 + 1754);
        else
          v25 = 0;
        v29 = *v24;
        BYTE2(v29) = v25;
        *v24 = v29;
        v26 = *((unsigned __int8 *)v24 + 28);
        v24[6] = v5;
        if ( v26 )
        {
          *((_BYTE *)v24 + 28) = 0;
          *(_DWORD *)(v5 + 136) |= 0x80u;
        }
        v27 = v24 + 4;
        v28 = *(int ***)(v5 + 480);
        v24[4] = v5 + 476;
        v24[5] = (int)v28;
        if ( *v28 != (int *)(v5 + 476) )
          __fastfail(3u);
        *v28 = v27;
        *(_DWORD *)(v5 + 480) = v27;
      }
    }
    goto LABEL_18;
  }
  return sub_50C79C(0);
}
