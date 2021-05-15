// PopPepWaitForDeviceRelease 
 
__int64 __fastcall PopPepWaitForDeviceRelease(int a1)
{
  unsigned int *v1; // r4
  int v2; // r7
  unsigned __int8 *v3; // r3
  unsigned int v4; // r1
  unsigned int v5; // r0
  unsigned int v6; // r1
  int vars4; // [sp+14h] [bp+4h]

  v1 = (unsigned int *)(a1 + 44);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v1);
  }
  else
  {
    v3 = (unsigned __int8 *)v1 + 3;
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x80, v3) );
    __dmb(0xBu);
    if ( v4 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v1);
    while ( 1 )
    {
      v5 = *v1;
      if ( (*v1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v5 & 0x40000000) == 0 )
      {
        do
          v6 = __ldrex(v1);
        while ( v6 == v5 && __strex(v5 | 0x40000000, v1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v1 = 0;
  }
  return KfLowerIrql(v2);
}
