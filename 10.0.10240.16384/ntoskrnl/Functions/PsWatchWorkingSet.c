// PsWatchWorkingSet 
 
int __fastcall PsWatchWorkingSet(int result, unsigned int a2, int a3)
{
  int v3; // r10
  unsigned int v4; // r4
  unsigned int *v5; // r5
  int v6; // r7
  unsigned int v7; // r9
  unsigned int v8; // r6
  unsigned int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r1
  unsigned __int64 *v16; // r5
  unsigned __int64 v17; // kr00_8
  unsigned int *v18; // r6
  int v19; // r5
  unsigned int v20; // r1
  __int16 v21; // r3
  int v24; // [sp+8h] [bp-20h]

  v3 = a3;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(unsigned int **)(*(_DWORD *)(v4 + 0x74) + 304);
  if ( v5 )
  {
    if ( result >= 276 )
    {
      v6 = 0;
      v7 = 0x80000000;
    }
    else
    {
      v6 = 1;
      v7 = 0x40000000;
    }
    v8 = *v5;
    __dmb(0xBu);
    v24 = KeGetCurrentIrql(result);
    if ( !v24 )
      --*(_WORD *)(v4 + 308);
    result = 0x10000;
    if ( (v8 & 1) == 0 )
    {
      do
      {
        if ( (v8 & 0xFFFE) >= 0x800 )
          break;
        v9 = (((v8 & 0xFFFFFFFE) + 2) ^ v8) & 0xFFFE ^ v8;
        v10 = v8;
        __dmb(0xBu);
        v11 = v9 ^ (((v9 & 0xFFFF0000) + 0x10000) ^ v9) & 0x7FFF0000;
        do
          v8 = __ldrex(v5);
        while ( v8 == v10 && __strex(v11, v5) );
        __dmb(0xBu);
        if ( v8 == v10 )
          break;
      }
      while ( (v8 & 1) == 0 );
      v3 = a3;
    }
    if ( (v8 & 1) != 0 || (v12 = (unsigned __int16)v8 >> 1, v12 >= 0x400) )
    {
      v18 = v5 + 1;
      v19 = v5[1];
      __dmb(0xBu);
      do
      {
        if ( v19 == -1 )
          break;
        result = v19;
        __dmb(0xBu);
        do
          v20 = __ldrex(v18);
        while ( v20 == v19 && __strex(v19 + 1, v18) );
        v19 = v20;
        __dmb(0xBu);
      }
      while ( v20 != result );
    }
    else
    {
      v13 = &v5[3 * v12];
      v13[6] = a2;
      if ( v6 )
        v14 = v3 | 1;
      else
        v14 = v3 & 0xFFFFFFFE;
      v13[7] = v14;
      v13[8] = *(_DWORD *)(v4 + 880);
      __dmb(0xBu);
      do
        v15 = __ldrex(v5);
      while ( __strex(v15 - 0x10000, v5) );
      __dmb(0xBu);
      if ( (v15 & 1) != 0 && (v15 & 0x7FFF0000) == 0x10000 )
        result = KeSignalGate((int)(v5 + 2), 0);
      v16 = *(unsigned __int64 **)(v4 + 236);
      if ( v16 )
      {
        __dmb(0xBu);
        do
        {
          v17 = __ldrexd(v16);
          result = v17;
        }
        while ( __strexd(__PAIR64__(HIDWORD(v17) | v7, v17), v16) );
        __dmb(0xBu);
      }
    }
    if ( !v24 )
    {
      v21 = *(_WORD *)(v4 + 308) + 1;
      *(_WORD *)(v4 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
  return result;
}
