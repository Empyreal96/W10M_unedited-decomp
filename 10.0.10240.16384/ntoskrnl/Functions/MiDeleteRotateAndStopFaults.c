// MiDeleteRotateAndStopFaults 
 
int __fastcall MiDeleteRotateAndStopFaults(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v6; // r6
  unsigned int *v7; // r4
  int v8; // r8
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  _DWORD v14[12]; // [sp+8h] [bp-30h] BYREF

  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v7 = (unsigned int *)(v6 + 492);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v6 + 492));
  }
  else
  {
    v10 = (unsigned __int8 *)(v6 + 495);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v6 + 492));
    while ( 1 )
    {
      v12 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(v7);
        while ( v13 == v12 && __strex(v12 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *a3 = *(_DWORD *)(v6 + 260);
  *(_DWORD *)(v6 + 260) = a3;
  MiDeleteVirtualAddresses(a1, a2, 0, v8, (int)v14);
  return MiUnlockWorkingSetExclusive(v6 + 492, v8);
}
