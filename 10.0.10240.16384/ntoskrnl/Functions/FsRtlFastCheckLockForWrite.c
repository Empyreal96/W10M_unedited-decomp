// FsRtlFastCheckLockForWrite 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlFastCheckLockForWrite(int a1, unsigned int *a2, _QWORD *a3, int a4, int a5, int a6)
{
  int v6; // r5
  unsigned int v9; // r1 OVERLAPPED
  unsigned int v10; // r2 OVERLAPPED
  unsigned int v11; // r0
  unsigned int v12; // r3
  unsigned int *v13; // r4
  unsigned __int64 v14; // kr08_8
  int v15; // r8
  unsigned int v17; // r2
  int v18; // r5
  int v19; // r2
  unsigned int v20; // [sp+8h] [bp-40h]
  unsigned int v21; // [sp+Ch] [bp-3Ch]
  unsigned __int64 v22; // [sp+18h] [bp-30h] BYREF
  __int64 v23[5]; // [sp+20h] [bp-28h] BYREF

  v6 = *(_DWORD *)(a1 + 12);
  if ( v6 && (*(_DWORD *)(v6 + 20) || *(_DWORD *)(v6 + 24)) )
  {
    *(_QWORD *)&v9 = *a3;
    if ( __PAIR64__(v10, v9) )
    {
      v11 = a2[1];
      v12 = *a2;
      v13 = (unsigned int *)(v6 + 16);
      v20 = v11;
      v21 = v12;
      v23[0] = __PAIR64__(v11, v12);
      v14 = __PAIR64__(v10, v12) + __PAIR64__(v11, v9) - 1;
      v22 = v14;
      v15 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_5281F0();
      do
        v17 = __ldrex(v13);
      while ( __strex(1u, v13) );
      __dmb(0xBu);
      if ( v17 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v6 + 16));
      if ( v14 >= *(_QWORD *)v6 )
      {
        v19 = *(_DWORD *)(a5 + 72);
        if ( v19
          && __PAIR64__(v20, v21) >= *(_QWORD *)v19
          && v14 <= *(_QWORD *)(v19 + 32)
          && *(_DWORD *)(v19 + 20) == a4
          && *(_DWORD *)(v19 + 28) == a6
          && *(_BYTE *)(v19 + 16) )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v6 + 16);
          }
          else
          {
            __dmb(0xBu);
            *v13 = 0;
          }
          v18 = 1;
        }
        else
        {
          v18 = FsRtlCheckNoSharedConflict(v6 + 16, v23, &v22);
          if ( v18 == 1 )
            v18 = FsRtlCheckNoExclusiveConflict(v13, v23, &v22, a4, a5, a6);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v13);
          }
          else
          {
            __dmb(0xBu);
            *v13 = 0;
          }
        }
        KfLowerIrql(v15);
        return v18;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v6 + 16);
      }
      else
      {
        __dmb(0xBu);
        *v13 = 0;
      }
      KfLowerIrql(v15);
    }
  }
  return 1;
}
