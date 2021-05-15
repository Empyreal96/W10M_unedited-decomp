// ExpRemoveGeneralLookaside 
 
int __fastcall ExpRemoveGeneralLookaside(unsigned int *a1, int a2)
{
  int v4; // r7
  int result; // r0
  unsigned int v6; // r2
  __int64 v7; // r0

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_524DE8();
  do
    v6 = __ldrex(a1);
  while ( __strex(1u, a1) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(a1);
  v7 = *(_QWORD *)(a2 + 48);
  if ( *(_DWORD *)(v7 + 4) != a2 + 48 || *(_DWORD *)HIDWORD(v7) != a2 + 48 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v7) = v7;
  *(_DWORD *)(v7 + 4) = HIDWORD(v7);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *a1 = 0;
  }
  result = KfLowerIrql(v4);
  *(_WORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 48) = MmBadPointer;
  return result;
}
