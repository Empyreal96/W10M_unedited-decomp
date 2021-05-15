// MiBeginProcessClean 
 
int __fastcall MiBeginProcessClean(int a1, int a2)
{
  unsigned int *v4; // r5
  int v5; // r8
  int result; // r0
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r4
  int v12; // r2
  unsigned int v13; // r4
  unsigned int v14; // r1

  if ( (*(_DWORD *)(a2 + 192) & 0x20) != 0 )
    goto LABEL_17;
  LOCK_ADDRESS_SPACE(a1, a2);
  v4 = (unsigned int *)(a2 + 492);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_524B0C();
  v7 = (unsigned __int8 *)(a2 + 495);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a2 + 492));
  while ( 1 )
  {
    v9 = *v4;
    if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v14 = __ldrex(v4);
      while ( v14 == v9 && __strex(v9 | 0x40000000, v4) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(a2 + 192);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x20, v10) );
  __dmb(0xBu);
  v12 = *(unsigned __int8 *)(a2 + 607) | 2;
  *(_BYTE *)(a2 + 607) = v12;
  if ( (v12 & 0xFFFFFFC0) != 192 )
    *(_BYTE *)(a2 + 607) = v12 & 0x3F;
  MiUnlockWorkingSetExclusive(a2 + 492, v5);
  UNLOCK_ADDRESS_SPACE(a1, a2);
  v13 = MiOutlawInswaps(a2);
  if ( v13 > 2 )
    MiFreeWorkingSetSwapContext(MiSystemPartition, v13);
  if ( v13 )
LABEL_17:
    result = 1;
  else
    result = 0;
  return result;
}
