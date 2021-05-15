// MiGetWsAndInsertVad 
 
int __fastcall MiGetWsAndInsertVad(_DWORD *a1)
{
  int v2; // r7
  unsigned int *v3; // r5
  int v4; // r8
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r6
  int v9; // r0
  unsigned int v10; // r1

  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = (unsigned int *)(v2 + 492);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_545A38();
  v6 = (unsigned __int8 *)(v2 + 495);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v2 + 492));
  while ( 1 )
  {
    v8 = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v8 & 0x40000000) == 0 )
    {
      do
        v10 = __ldrex(v3);
      while ( v10 == v8 && __strex(v8 | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  MiInsertVad(a1, v2);
  result = MiUnlockWorkingSetExclusive(v2 + 492, v4);
  if ( (a1[7] & 0x8000) == 0 )
  {
    v9 = a1[11];
    a1[16] = v2 | 1;
    result = MiManageSubsectionView(v9, a1 + 14, 3);
  }
  return result;
}
