// KeSetCpuSetsProcess 
 
int __fastcall KeSetCpuSetsProcess(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  int result; // r0
  _DWORD *v9; // r4
  _DWORD *v10; // r6
  unsigned int *v11; // r4
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r0
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r2
  char v19[4]; // [sp+0h] [bp-28h] BYREF
  _DWORD *var24[11]; // [sp+4h] [bp-24h] BYREF

  var24[0] = a3;
  var24[1] = a4;
  result = KiValidateCpuSetMasks((int)a3, a2);
  if ( result >= 0 )
  {
    if ( a4 )
      v9 = (_DWORD *)(a1 + 880);
    else
      v9 = (_DWORD *)(a1 + 884);
    KiAcquireProcessLockExclusive(a1, v19);
    if ( a2 )
      *v9 = *a3;
    else
      *v9 = 0;
    v10 = *(_DWORD **)(a1 + 40);
    var24[0] = 0;
    while ( v10 != (_DWORD *)(a1 + 40) )
    {
      v11 = v10 - 106;
      while ( 1 )
      {
        do
          v12 = __ldrex(v11);
        while ( __strex(1u, v11) );
        __dmb(0xBu);
        if ( !v12 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v11 );
      }
      v13 = KiUpdateThreadCpuSets(v10 - 117, var24);
      __dmb(0xBu);
      *v11 = 0;
      if ( v13 )
      {
        v14 = *(_DWORD *)(v13 + 20);
        if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v14 )
        {
          v15 = (int)*(&KiProcessorBlock + v14);
          __dmb(0xBu);
          v16 = (unsigned int *)(v15 + 1676);
          do
            v17 = __ldrex(v16);
          while ( __strex(v17 | 2, v16) );
          __dmb(0xBu);
          v18 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
          ++*(_DWORD *)(v18 + 3732);
          HalSendSoftwareInterrupt(v14, 2);
        }
      }
      v10 = (_DWORD *)*v10;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(a1 + 48), (int)var24[10]);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(a1 + 48) = 0;
    }
    KiProcessDeferredReadyList(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, var24, (unsigned __int8)v19[0]);
    result = 0;
  }
  return result;
}
