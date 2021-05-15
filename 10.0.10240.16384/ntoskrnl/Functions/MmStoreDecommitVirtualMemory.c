// MmStoreDecommitVirtualMemory 
 
int __fastcall MmStoreDecommitVirtualMemory(unsigned int a1, int a2)
{
  int v3; // r8
  unsigned int v4; // r9
  unsigned int *v5; // r5
  int v6; // r10
  _DWORD *v7; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  _DWORD v13[12]; // [sp+8h] [bp-30h] BYREF

  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v4 = a1 + a2 - 1;
  v5 = (unsigned int *)(v3 + 492);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v3 + 492));
  }
  else
  {
    v9 = (unsigned __int8 *)(v3 + 495);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v3 + 492));
    while ( 1 )
    {
      v11 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v12 = __ldrex(v5);
        while ( v12 == v11 && __strex(v11 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = MiLocateAddress(a1);
  MiUnlockWorkingSetExclusive(v3 + 492, v6);
  return MiDecommitPages(a1, ((v4 >> 10) & 0x3FFFFC) - 0x40000000, v3, (int)v7, 0, v13);
}
