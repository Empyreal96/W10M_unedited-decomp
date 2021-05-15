// MiClearNonPagedBitMapBits 
 
int __fastcall MiClearNonPagedBitMapBits(int a1, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  _BYTE *v4; // r8
  int v8; // r9
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1

  v4 = *(_BYTE **)(a1 + 44);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5191D0();
  v10 = (unsigned __int8 *)a2 + 3;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a2);
  while ( 1 )
  {
    v12 = *a2;
    if ( (*a2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v12 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(a2);
      while ( v13 == v12 && __strex(v12 | 0x40000000, a2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  RtlClearBits(v4, a3, a4);
  return MiUnlockWorkingSetExclusive((int)a2, v8);
}
