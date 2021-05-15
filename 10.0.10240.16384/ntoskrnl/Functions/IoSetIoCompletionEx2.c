// IoSetIoCompletionEx2 
 
int __fastcall IoSetIoCompletionEx2(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, _DWORD *a7, char a8)
{
  int v12; // r9
  int v13; // r6
  unsigned int v14; // r7
  int v15; // r10
  unsigned int v16; // r2
  unsigned int v17; // r1
  BOOL v18; // r1
  unsigned int v19; // r0
  _DWORD *v21; // r1
  _DWORD *v22; // r0
  _DWORD *v23; // r5
  unsigned int v24; // r8
  int v25; // r10
  unsigned int v26; // r2
  unsigned int v27; // r1
  _DWORD *v28; // r1
  unsigned int v29; // r2
  BOOL v30; // r2
  unsigned int v31; // r2
  BOOL v32; // r2
  int v33; // [sp+8h] [bp-20h]

  v12 = 0;
  if ( a7 )
  {
    a7[3] = a2;
    a7[4] = a3;
    a7[5] = a4;
    a7[6] = a5;
    v13 = a1 + 8;
    v33 = KfRaiseIrql(2);
    v14 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v15 = *(_DWORD *)(v14 + 1412);
    if ( (dword_682604 & 0x1000000) != 0 )
    {
      v32 = *(_BYTE *)(v15 + 132) == 2
         && *(_DWORD *)(v15 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      EtwTraceEnqueueWork(*(_DWORD *)(v14 + 1412), a7, v32);
    }
    do
      v16 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v16 | 0x80, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( v16 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)a1 & 0x80) != 0 );
        do
          v29 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v29 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
      }
      while ( v29 >> 7 );
    }
    if ( *(_DWORD *)(a1 + 12) == v13
      || *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 28)
      || *(_DWORD *)(v15 + 152) == a1 && *(_BYTE *)(v15 + 395) == 15
      || !KiWakeQueueWaiter(v14 + 1408, a1, a7) )
    {
      ++*(_DWORD *)(a1 + 4);
      v21 = *(_DWORD **)(a1 + 20);
      *a7 = a1 + 16;
      a7[1] = v21;
      if ( *v21 != a1 + 16 )
        __fastfail(3u);
      *v21 = a7;
      *(_DWORD *)(a1 + 20) = a7;
    }
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)a1);
    while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)a1) );
    v18 = a8 != 0;
    v19 = v14 + 1408;
LABEL_12:
    KiExitDispatcher(v19, v18, 1, 0, v33);
    return v12;
  }
  v22 = (_DWORD *)IopAllocateMiniCompletionPacket(1, a6);
  v23 = v22;
  if ( !v22 )
    return -1073741670;
  v22[3] = a2;
  v22[4] = a3;
  v22[5] = a4;
  v22[6] = a5;
  if ( !a8 )
  {
    v33 = KfRaiseIrql(2);
    v24 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v25 = *(_DWORD *)(v24 + 1412);
    if ( (dword_682604 & 0x1000000) != 0 )
    {
      v30 = *(_BYTE *)(v25 + 132) == 2
         && *(_DWORD *)(v25 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      EtwTraceEnqueueWork(*(_DWORD *)(v24 + 1412), v23, v30);
    }
    do
      v26 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v26 | 0x80, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( v26 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)a1 & 0x80) != 0 );
        do
          v31 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v31 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
      }
      while ( v31 >> 7 );
    }
    if ( *(_DWORD *)(a1 + 12) == a1 + 8
      || *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 28)
      || *(_DWORD *)(v25 + 152) == a1 && *(_BYTE *)(v25 + 395) == 15
      || !KiWakeQueueWaiter(v24 + 1408, a1, v23) )
    {
      ++*(_DWORD *)(a1 + 4);
      v28 = *(_DWORD **)(a1 + 20);
      *v23 = a1 + 16;
      v23[1] = v28;
      if ( *v28 != a1 + 16 )
        __fastfail(3u);
      *v28 = v23;
      *(_DWORD *)(a1 + 20) = v23;
    }
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)a1);
    while ( __strex(v27 & 0xFFFFFF7F, (unsigned int *)a1) );
    v18 = 0;
    v19 = v24 + 1408;
    goto LABEL_12;
  }
  return sub_52C5B0();
}
