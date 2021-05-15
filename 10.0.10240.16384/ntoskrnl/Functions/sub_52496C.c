// sub_52496C 
 
void sub_52496C()
{
  int v0; // r4
  int v1; // r9
  int v2; // r10
  unsigned int *v3; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  v3 = (unsigned int *)(v0 + 36);
  KfRaiseIrql(2);
  if ( (*(_DWORD *)(v2 + 4) & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 36));
  }
  else
  {
    v4 = (unsigned __int8 *)(v0 + 39);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v0 + 36));
    while ( 1 )
    {
      v6 = *v3;
      if ( (*v3 & 0xBFFFFFFF) == v1 )
        break;
      if ( (v6 & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex(v3);
        while ( v7 == v6 && __strex(v6 | 0x40000000, v3) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  JUMPOUT(0x45D23E);
}
