// MmStoreFlushOutstandingEvictions 
 
int MmStoreFlushOutstandingEvictions()
{
  int v0; // r9
  int v1; // r3
  unsigned int v2; // r1
  int v3; // r6
  unsigned int v4; // r0
  int vars4; // [sp+24h] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_63F9E0);
  }
  else
  {
    do
      v2 = __ldrex((unsigned __int8 *)&dword_63F9E0 + 3);
    while ( __strex(v2 | 0x80, (unsigned __int8 *)&dword_63F9E0 + 3) );
    __dmb(0xBu);
    if ( v2 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F9E0);
    while ( 1 )
    {
      v3 = dword_63F9E0;
      if ( (dword_63F9E0 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_63F9E0 & 0x40000000) == 0 )
      {
        do
          v4 = __ldrex((unsigned int *)&dword_63F9E0);
        while ( v4 == v3 && __strex(v3 | 0x40000000, (unsigned int *)&dword_63F9E0) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v1 = dword_63F9A8;
  if ( !dword_63F9A8 )
  {
    KeResetEvent((int)&unk_63F9C8);
    v1 = dword_63F9A8;
  }
  dword_63F9A8 = v1 + 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F9E0, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_63F9E0 = 0;
  }
  KfLowerIrql(v0);
  KeSetEvent((int)&unk_63F9B8, 0, 0);
  return KeWaitForSingleObject((unsigned int)&unk_63F9C8, 26, 0, 0, 0);
}
