// ExInitializeLookasideListExInternal 
 
int __fastcall ExInitializeLookasideListExInternal(int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, unsigned __int16 a8, int a9)
{
  __int16 v9; // r6
  int v14; // r0
  int v15; // r1
  int *v16; // r7
  int *v17; // r5
  __int16 v18; // r3
  int v19; // r8
  unsigned int v20; // r2
  int v21; // r3
  int **v22; // r1
  int v23; // r2
  int v24; // r3

  v9 = a8;
  if ( a8 )
  {
    if ( a8 < 0x100u || a8 > 0x400u )
      return -1073741578;
  }
  else
  {
    v9 = 256;
  }
  if ( a9 )
    return sub_5236A8();
  v14 = a6;
  if ( a6 <= 4 )
    v14 = 4;
  if ( (a5 & 0xFFFFFFFC) != 0 || ((a5 - 1) & a5) != 0 )
    return -1073741581;
  v15 = 0;
  if ( (a5 & 1) != 0 )
  {
    v15 = 16;
  }
  else if ( a5 )
  {
    v15 = 8;
  }
  if ( (a4 & 0xFFFFFC18) != 0 || (a4 & 3) == 3 )
    return -1073741582;
  if ( (a4 & 1) != 0 )
  {
    v16 = &ExPagedLookasideListHead;
    v17 = &ExPagedLookasideLock;
  }
  else
  {
    v16 = &ExNPagedLookasideListHead;
    v17 = &ExNPagedLookasideLock;
  }
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v18 = ExMinimumLookasideDepth;
  __dmb(0xBu);
  *(_WORD *)(a1 + 8) = v18;
  *(_WORD *)(a1 + 10) = v9;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = v15 | a4;
  *(_DWORD *)(a1 + 32) = a7;
  *(_DWORD *)(a1 + 36) = v14;
  if ( a2 )
    *(_DWORD *)(a1 + 40) = a2;
  else
    *(_DWORD *)(a1 + 40) = ExAllocatePoolEx;
  if ( a3 )
    *(_DWORD *)(a1 + 44) = a3;
  else
    *(_DWORD *)(a1 + 44) = ST_STORE<SM_TRAITS>::StDmSparseBitmapFree;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  v19 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v17);
  }
  else
  {
    do
      v20 = __ldrex((unsigned int *)v17);
    while ( __strex(1u, (unsigned int *)v17) );
    __dmb(0xBu);
    if ( v20 )
      KxWaitForSpinLockAndAcquire(v17);
  }
  v21 = (unsigned __int16)ExMinimumLookasideDepth;
  __dmb(0xBu);
  if ( !v21 )
  {
    *(_WORD *)(a1 + 10) = -1;
    *(_WORD *)(a1 + 8) = 0;
  }
  v22 = (int **)v16[1];
  v23 = a1 + 48;
  *(_DWORD *)(a1 + 48) = v16;
  *(_DWORD *)(a1 + 52) = v22;
  if ( *v22 != v16 )
    __fastfail(3u);
  *v22 = (int *)v23;
  v24 = dword_682604;
  v16[1] = v23;
  if ( (v24 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v17);
  }
  else
  {
    __dmb(0xBu);
    *v17 = 0;
  }
  KfLowerIrql(v19);
  return 0;
}
