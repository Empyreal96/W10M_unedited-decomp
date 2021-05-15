// ExInitializeNPagedLookasideListInternal 
 
int __fastcall ExInitializeNPagedLookasideListInternal(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8)
{
  __int16 v9; // r4
  int v10; // r7
  unsigned int v12; // r2
  int v13; // r3
  int **v14; // r0

  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v9 = ExMinimumLookasideDepth;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = a4;
  *(_WORD *)(a1 + 8) = v9;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 32) = a6;
  *(_WORD *)(a1 + 10) = 256;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 36) = a5;
  if ( a2 )
    *(_DWORD *)(a1 + 40) = a2;
  else
    *(_DWORD *)(a1 + 40) = ExAllocatePoolWithTag;
  if ( a3 )
    *(_DWORD *)(a1 + 44) = a3;
  else
    *(_DWORD *)(a1 + 44) = ExFreePool;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50B970();
  do
    v12 = __ldrex((unsigned int *)&ExNPagedLookasideLock);
  while ( __strex(1u, (unsigned int *)&ExNPagedLookasideLock) );
  __dmb(0xBu);
  if ( v12 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&ExNPagedLookasideLock);
  if ( a8 )
  {
    *(_WORD *)(a1 + 10) = -1;
    *(_WORD *)(a1 + 8) = a7;
  }
  else
  {
    v13 = (unsigned __int16)ExMinimumLookasideDepth;
    __dmb(0xBu);
    if ( !v13 )
    {
      *(_WORD *)(a1 + 10) = -1;
      *(_WORD *)(a1 + 8) = 0;
    }
  }
  v14 = (int **)dword_61A0A4;
  *(_DWORD *)(a1 + 48) = &ExNPagedLookasideListHead;
  *(_DWORD *)(a1 + 52) = v14;
  if ( *v14 != &ExNPagedLookasideListHead )
    __fastfail(3u);
  *v14 = (int *)(a1 + 48);
  dword_61A0A4 = a1 + 48;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ExNPagedLookasideLock);
  }
  else
  {
    __dmb(0xBu);
    ExNPagedLookasideLock = 0;
  }
  return KfLowerIrql(v10);
}
