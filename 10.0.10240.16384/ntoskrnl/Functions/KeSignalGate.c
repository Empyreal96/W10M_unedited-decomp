// KeSignalGate 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeSignalGate(int a1, int a2)
{
  unsigned int v3; // r10
  unsigned int v4; // r2
  _QWORD *v6; // r8
  _QWORD *v7; // r4
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  int v10; // r3
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r6
  unsigned int v14; // r3
  unsigned int v15; // r0
  int v16; // r7
  BOOL v17; // r2
  unsigned int v18; // r2
  _DWORD *v19; // r1
  unsigned int v20; // r1
  int v21; // r3
  unsigned int v22; // [sp+8h] [bp-28h]
  int v23; // [sp+Ch] [bp-24h]

  v23 = KfRaiseIrql(2);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  do
    v4 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    return sub_523E1C();
  if ( !*(_DWORD *)(a1 + 4) )
  {
    v6 = *(_QWORD **)(a1 + 8);
    *(_DWORD *)(a1 + 4) = 1;
    while ( v6 != (_QWORD *)(a1 + 8) )
    {
      v7 = v6;
      *(_QWORD *)&v8 = *v6;
      v6 = *(_QWORD **)v6;
      if ( *(_QWORD **)(v8 + 4) != v7 || (_QWORD *)*v9 != v7 )
        __fastfail(3u);
      *v9 = v8;
      *(_DWORD *)(v8 + 4) = v9;
      v10 = *((unsigned __int8 *)v7 + 8);
      if ( v10 == 1 )
      {
        if ( KiTryUnwaitThread(v3 + 1408, v7, *((unsigned __int16 *)v7 + 5), 0) )
        {
          v11 = *(_DWORD *)(a1 + 4) - 1;
          *(_DWORD *)(a1 + 4) = v11;
          if ( !v11 )
            break;
        }
      }
      else if ( v10 == 2 )
      {
        *((_BYTE *)v7 + 9) = 5;
        v13 = *((_DWORD *)v7 + 3);
        *(_DWORD *)v7 = 0;
        KfRaiseIrql(2);
        v14 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v15 = v14 + 1408;
        v16 = *(_DWORD *)(v14 + 1412);
        v22 = v14 + 1408;
        if ( (dword_682604 & 0x1000000) != 0 )
        {
          v17 = *(_BYTE *)(v16 + 132) == 2
             && *(_DWORD *)(v16 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
          EtwTraceEnqueueWork(v16, v7, v17);
          v15 = v22;
        }
        do
          v18 = __ldrex((unsigned __int8 *)v13);
        while ( __strex(v18 | 0x80, (unsigned __int8 *)v13) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v18 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v13 & 0x80) != 0 );
          do
            v18 = __ldrex((unsigned __int8 *)v13);
          while ( __strex(v18 | 0x80, (unsigned __int8 *)v13) );
        }
        if ( *(_DWORD *)(v13 + 12) == v13 + 8
          || *(_DWORD *)(v13 + 24) >= *(_DWORD *)(v13 + 28)
          || *(_DWORD *)(v16 + 152) == v13 && *(_BYTE *)(v16 + 395) == 15
          || !KiWakeQueueWaiter(v15, v13, v7) )
        {
          ++*(_DWORD *)(v13 + 4);
          v19 = *(_DWORD **)(v13 + 20);
          *(_DWORD *)v7 = v13 + 16;
          *((_DWORD *)v7 + 1) = v19;
          if ( *v19 != v13 + 16 )
            __fastfail(3u);
          *v19 = v7;
          *(_DWORD *)(v13 + 20) = v7;
        }
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)v13);
        while ( __strex(v20 & 0xFFFFFF7F, (unsigned int *)v13) );
        v21 = *(_DWORD *)(a1 + 4) - 1;
        *(_DWORD *)(a1 + 4) = v21;
        if ( !v21 )
          break;
      }
      else
      {
        KiTryUnwaitThread(v3 + 1408, v7, 256, 0);
      }
    }
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)a1);
  while ( __strex(v12 & 0xFFFFFF7F, (unsigned int *)a1) );
  return KiExitDispatcher(v3 + 1408, 0, 1, a2, v23);
}
