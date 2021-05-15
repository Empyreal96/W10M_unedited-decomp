// MiMakeSystemAddressValidSystemWs 
 
int __fastcall MiMakeSystemAddressValidSystemWs(unsigned int *a1, unsigned int a2, int a3, int a4)
{
  int v6; // r7
  unsigned __int8 *v7; // r8
  int v8; // r7
  unsigned int v10; // r2
  unsigned int v11; // r0
  int v12; // r3
  unsigned int v13; // r1

  v6 = a3;
  if ( MiIsAddressValid(a2, 1, a3, a4) )
    return 0;
  v7 = (unsigned __int8 *)a1 + 3;
  do
  {
    MiUnlockWorkingSetExclusive((int)a1, v6);
    v8 = MmAccessFault(0, a2, 0, 0);
    if ( v8 < 0 )
    {
      MmFlushAllFilesystemPages(1);
      KeBugCheck2(122, 2, v8, 0, a2, 0);
    }
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_54F970();
    do
      v10 = __ldrex(v7);
    while ( __strex(v10 | 0x80, v7) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1);
    while ( 1 )
    {
      v11 = *a1;
      v12 = *a1 & 0xBFFFFFFF;
      if ( v12 == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        v10 = v11 | 0x40000000;
        do
          v13 = __ldrex(a1);
        while ( v13 == v11 && __strex(v10, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  while ( !MiIsAddressValid(a2, 1, v10, v12) );
  return 1;
}
