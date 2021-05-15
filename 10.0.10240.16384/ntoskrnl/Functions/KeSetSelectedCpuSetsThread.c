// KeSetSelectedCpuSetsThread 
 
int __fastcall KeSetSelectedCpuSetsThread(_DWORD *a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  int result; // r0
  int v8; // r8
  unsigned int *v9; // r5
  unsigned int v10; // r2
  int v11; // r4
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r4
  unsigned int v19; // r3
  _DWORD *v20; // [sp+0h] [bp-20h] BYREF
  _DWORD *var1C[8]; // [sp+4h] [bp-1Ch] BYREF

  v20 = a3;
  var1C[0] = a4;
  result = KiValidateCpuSetMasks((int)a3, a2);
  if ( result >= 0 )
  {
    v8 = a1[84];
    var1C[0] = 0;
    KiAcquireProcessLockShared(v8, &v20);
    v9 = a1 + 11;
    while ( 1 )
    {
      do
        v10 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( !v10 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v9 );
    }
    if ( a2 )
      a1[273] = *a3;
    else
      a1[273] = 0;
    v11 = KiUpdateThreadCpuSets(a1, var1C);
    __dmb(0xBu);
    *v9 = 0;
    v12 = (unsigned int *)(v8 + 48);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v12);
    }
    else
    {
      __dmb(0xBu);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 & 0xBFFFFFFF, v12) );
      __dmb(0xBu);
      do
        v14 = __ldrex(v12);
      while ( __strex(v14 - 1, v12) );
    }
    if ( v11 )
    {
      v15 = *(_DWORD *)(v11 + 20);
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v15 )
      {
        v16 = (int)*(&KiProcessorBlock + v15);
        __dmb(0xBu);
        v17 = (unsigned int *)(v16 + 1676);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 | 2, v17) );
        __dmb(0xBu);
        v19 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x1414);
        HalSendSoftwareInterrupt(v15, 2);
      }
    }
    KiProcessDeferredReadyList(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, var1C, (unsigned __int8)v20);
    result = 0;
  }
  return result;
}
