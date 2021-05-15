// FsRtlFastCheckLockForRead 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlFastCheckLockForRead(int a1, unsigned int *a2, _QWORD *a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v9; // r5
  unsigned int v11; // r1 OVERLAPPED
  unsigned int v12; // r2 OVERLAPPED
  unsigned int v13; // r0
  unsigned int v14; // r3
  unsigned int *v15; // r4
  unsigned __int64 v16; // r8
  int v17; // r10
  unsigned int v18; // r2
  int v19; // r2
  unsigned int v20; // [sp+8h] [bp-38h]
  unsigned int v21; // [sp+Ch] [bp-34h]
  unsigned __int64 v22; // [sp+10h] [bp-30h] BYREF
  unsigned __int64 v23[5]; // [sp+18h] [bp-28h] BYREF

  v6 = *(_DWORD *)(a1 + 12);
  if ( !v6 )
    return 1;
  if ( !*(_DWORD *)(v6 + 24) )
    return 1;
  *(_QWORD *)&v11 = *a3;
  if ( !__PAIR64__(v12, v11) )
    return 1;
  v13 = a2[1];
  v14 = *a2;
  v15 = (unsigned int *)(v6 + 16);
  v20 = v13;
  v21 = v14;
  v23[0] = __PAIR64__(v13, v14);
  v16 = __PAIR64__(v12, v14) + __PAIR64__(v13, v11) - 1;
  v22 = v16;
  v17 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) == 0 )
  {
    do
      v18 = __ldrex(v15);
    while ( __strex(1u, v15) );
    __dmb(0xBu);
    if ( v18 )
      KxWaitForSpinLockAndAcquire(v6 + 16);
    if ( v16 >= *(_QWORD *)v6 )
    {
      v19 = *(_DWORD *)(a5 + 72);
      if ( v19
        && __PAIR64__(v20, v21) >= *(_QWORD *)v19
        && v16 <= *(_QWORD *)(v19 + 32)
        && *(_DWORD *)(v19 + 20) == a4
        && *(_DWORD *)(v19 + 28) == a6 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v15);
        }
        else
        {
          __dmb(0xBu);
          *v15 = 0;
        }
        v9 = 1;
      }
      else
      {
        v9 = FsRtlCheckNoExclusiveConflict(v15, v23, &v22, a4, a5, a6);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v15);
        }
        else
        {
          __dmb(0xBu);
          *v15 = 0;
        }
      }
      KfLowerIrql(v17);
      return v9;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v6 + 16);
    }
    else
    {
      __dmb(0xBu);
      *v15 = 0;
    }
    KfLowerIrql(v17);
    return 1;
  }
  return sub_520824();
}
