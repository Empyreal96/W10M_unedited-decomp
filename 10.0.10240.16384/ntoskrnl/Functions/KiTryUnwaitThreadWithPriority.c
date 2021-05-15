// KiTryUnwaitThreadWithPriority 
 
int __fastcall KiTryUnwaitThreadWithPriority(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int *v6; // r9
  int v8; // r10
  unsigned int v9; // r5
  int result; // r0
  int v11; // r3
  int v12; // r3
  unsigned __int64 *v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r4
  unsigned __int64 v16; // kr10_8
  unsigned __int64 v17; // kr18_8
  unsigned __int64 *v18; // r3
  unsigned __int64 v19; // kr20_8
  int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned __int8 *v25; // r3
  unsigned int v26; // r2

  v4 = *(_DWORD *)(a2 + 12);
  v6 = (unsigned int *)(v4 + 44);
  v8 = 0;
  do
    v9 = __ldrex(v6);
  while ( __strex(1u, v6) );
  __dmb(0xBu);
  if ( v9 )
    return sub_51569C(a1, a2, a3, 1);
  if ( *(_BYTE *)(v4 + 132) == 5 )
  {
    v11 = *(_DWORD *)(v4 + 332);
    if ( (unsigned __int8)v11 != a4 )
    {
      if ( (v11 & 0x100) == 0 )
      {
        v20 = *(_DWORD *)(v4 + 152);
        __dmb(0xBu);
        v21 = (unsigned int *)(v20 + 4 * ((unsigned __int8)v11 + 68));
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 - 1, v21) );
        __dmb(0xBu);
        v23 = (unsigned int *)(v20 + 4 * (a4 + 68));
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 + 1, v23) );
        __dmb(0xBu);
      }
      *(_DWORD *)(v4 + 332) = (unsigned __int8)a4 | v11 & 0x100;
    }
    v8 = KiSignalThread();
    if ( v8 )
    {
      *(_BYTE *)(v4 + 397) = 0;
      KiAbProcessThreadPriorityModification(v4, (char)a4, 0);
      v12 = *(char *)(v4 + 348);
      *(_BYTE *)(v4 + 347) = a4;
      if ( v12 )
      {
        if ( (v12 & 0xF) != 0 )
          *(_DWORD *)(v4 + 812) = KeTickCount;
        *(_BYTE *)(v4 + 348) = 0;
      }
      if ( a4 != *(char *)(v4 + 123) )
      {
        v13 = (unsigned __int64 *)(v4 + 48);
        while ( 1 )
        {
          v14 = *(_DWORD *)(v4 + 52);
          v15 = *(_DWORD *)v13;
          do
            v16 = __ldrexd(v13);
          while ( __PAIR64__(v16, HIDWORD(v16)) == __PAIR64__(v15, v14) && __strexd(__PAIR64__(v14, v15), v13) );
          if ( __PAIR64__(v15, v14) == __PAIR64__(v16, HIDWORD(v16)) )
            break;
          __dmb(0xAu);
          __yield();
        }
        v17 = __PAIR64__(v14, (unsigned int)*(unsigned __int8 *)(v4 + 403) * KiCyclesPerClockQuantum) + v15;
        if ( (*(_DWORD *)(v4 + 80) & 0x10) != 0 )
        {
          __dmb(0xBu);
          v25 = (unsigned __int8 *)(v4 + 80);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 & 0xEF, v25) );
          __dmb(0xBu);
        }
        __dmb(0xBu);
        v18 = (unsigned __int64 *)(v4 + 24);
        do
          v19 = __ldrexd(v18);
        while ( __strexd(v17, v18) );
        __dmb(0xBu);
        KiSetPriorityThread(v4, 0, a4);
      }
    }
  }
  __dmb(0xBu);
  *v6 = 0;
  result = v8;
  ++*(_BYTE *)(a2 + 9);
  return result;
}
