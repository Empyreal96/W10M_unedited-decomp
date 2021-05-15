// MiDereferenceControlArea 
 
int __fastcall MiDereferenceControlArea(_DWORD *a1)
{
  unsigned int *v2; // r4
  int v3; // r7
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r1

  v2 = a1 + 9;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5193E4();
  v5 = (unsigned __int8 *)v2 + 3;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v7 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v7 & 0x40000000) == 0 )
    {
      do
        v8 = __ldrex(v2);
      while ( v8 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  --a1[5];
  --a1[6];
  return MiCheckControlArea(a1, v3);
}
