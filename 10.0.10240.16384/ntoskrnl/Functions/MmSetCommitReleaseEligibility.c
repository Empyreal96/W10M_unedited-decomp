// MmSetCommitReleaseEligibility 
 
int __fastcall MmSetCommitReleaseEligibility(int a1, int a2)
{
  int v4; // r7
  unsigned int *v5; // r4
  int v6; // r9
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  char v11; // r3
  char v12; // r3
  int v13; // r5
  unsigned int v14; // r1
  int v15; // [sp-4h] [bp-38h] BYREF

  v4 = 0;
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
  {
    v4 = 1;
    KiStackAttachProcess(a1, 0);
  }
  v5 = (unsigned int *)(a1 + 492);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_526F20();
  v8 = (unsigned __int8 *)(a1 + 495);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 492));
  while ( 1 )
  {
    v10 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v14 = __ldrex(v5);
      while ( v14 == v10 && __strex(v10 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( (*(_DWORD *)(a1 + 192) & 0x20) != 0 )
  {
    v13 = -1073741558;
  }
  else
  {
    v11 = *(_BYTE *)(a1 + 607);
    if ( a2 )
      v12 = v11 & 0x3F | 0x40;
    else
      v12 = v11 & 0x3F;
    *(_BYTE *)(a1 + 607) = v12;
    v13 = 0;
  }
  MiUnlockWorkingSetExclusive(a1 + 492, v6);
  if ( v4 )
    KiUnstackDetachProcess(&v15, 0);
  return v13;
}
