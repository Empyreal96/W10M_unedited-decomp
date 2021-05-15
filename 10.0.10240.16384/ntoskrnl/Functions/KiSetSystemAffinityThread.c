// KiSetSystemAffinityThread 
 
int __fastcall KiSetSystemAffinityThread(int a1, int a2, unsigned int a3, int a4)
{
  int v5; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r1
  unsigned int v11; // r3
  int result; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r2
  unsigned int *v15; // r4
  unsigned int v16; // r2

  v5 = *(_DWORD *)(a1 + 4);
  *(_WORD *)(v5 + 360) = *(_WORD *)(a2 + 4);
  *(_DWORD *)(v5 + 356) = *(_DWORD *)a2;
  if ( a3 < 0x20 )
  {
    *(_DWORD *)(v5 + 364) = a3;
    v8 = (int)*(&KiProcessorBlock + a3);
  }
  else
  {
    v7 = *(unsigned __int16 *)(a2 + 4);
    v8 = (int)*(&KiProcessorBlock + *(_DWORD *)(v5 + 364));
    if ( *(unsigned __int8 *)(v8 + 1052) != v7 || (*(_DWORD *)(v8 + 1048) & *(_DWORD *)a2) == 0 )
    {
      v9 = *(_DWORD *)a2;
      v10 = *(_DWORD *)(v8 + 2360);
      if ( v7 == *(unsigned __int16 *)(v10 + 264) && (*(_DWORD *)(v10 + 260) & v9) != 0 )
        v9 &= *(_DWORD *)(v10 + 260);
      v11 = 31 - __clz(v9);
      *(_DWORD *)(v5 + 364) = v11;
      v8 = (int)*(&KiProcessorBlock + v11);
    }
  }
  if ( (*(_DWORD *)(v5 + 76) & 8) != 0 || (result = KiComputeThreadAffinity(v5)) == 0 )
  {
    KiUpdateSharedReadyQueueAffinityThread(v8, v5);
    result = KiUpdateNodeAffinitizedFlag(v5);
  }
  if ( *(unsigned __int8 *)(a1 + 1052) != *(unsigned __int16 *)(v5 + 360)
    || (*(_DWORD *)(a1 + 1048) & *(_DWORD *)(v5 + 356)) == 0 )
  {
    v13 = (unsigned __int8 *)(v5 + 81);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 8, v13) );
    if ( !*(_DWORD *)(a1 + 8) )
    {
      v15 = (unsigned int *)(a1 + 24);
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
      if ( !*(_DWORD *)(a1 + 8) )
        result = KiSelectNextThread(a1, a4);
      __dmb(0xBu);
      *v15 = 0;
    }
  }
  return result;
}
