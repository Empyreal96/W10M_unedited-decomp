// KeSetAffinityThread 
 
int __fastcall KeSetAffinityThread(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r8
  unsigned int v7; // r10
  unsigned int v8; // r9
  unsigned int *v9; // r4
  int v10; // r5
  int v11; // r3
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r1
  _DWORD *v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v19 = a4;
  v17 = 0;
  v18 = a1;
  v4 = *(_DWORD *)(a1 + 336);
  v5 = *(unsigned __int16 *)(a2 + 4);
  v7 = KfRaiseIrql(2);
  v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v9 = (unsigned int *)(v4 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 48));
  }
  else
  {
    v12 = (unsigned __int8 *)(v4 + 51);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 48));
    while ( 1 )
    {
      v14 = *v9;
      if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v14 & 0x40000000) == 0 )
      {
        do
          v15 = __ldrex(v9);
        while ( v15 == v14 && __strex(v14 | 0x40000000, v9) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v10 = v4 + 4 * v5;
  v11 = *(_DWORD *)(v10 + 72);
  if ( !v11 || (v11 & *(_DWORD *)a2) != *(_DWORD *)a2 )
    KiExtendProcessAffinity(v4);
  if ( !*(_DWORD *)a2 )
    *(_DWORD *)a2 = *(_DWORD *)(v10 + 72);
  KiSetAffinityThread(v18, (int)&v17, a2);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v4 + 48), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  return KiProcessDeferredReadyList(v8 + 1408, &v17, v7);
}
