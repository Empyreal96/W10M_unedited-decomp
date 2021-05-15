// FsRtlFastUnlockSingleExclusive 
 
int __fastcall FsRtlFastUnlockSingleExclusive(int a1, int a2, unsigned int *a3, _QWORD *a4, int a5, int a6, int a7, char a8, char a9)
{
  unsigned int v9; // r10
  unsigned int v10; // r5
  unsigned int *v12; // r4
  int v14; // r6
  unsigned int v16; // r2
  unsigned int v17; // r0
  int v18; // r3
  _DWORD *i; // r0
  _DWORD *v20; // r5
  __int64 v21; // r2
  unsigned int v22; // r2
  unsigned int v24; // [sp+Ch] [bp-34h]
  int v25[2]; // [sp+10h] [bp-30h] BYREF
  _DWORD v26[10]; // [sp+18h] [bp-28h] BYREF

  v9 = *a3;
  v10 = a3[1];
  v12 = (unsigned int *)(a1 + 16);
  v24 = v10;
  v26[0] = *a3;
  v26[1] = v10;
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51E128();
  do
    v16 = __ldrex(v12);
  while ( __strex(1u, v12) );
  __dmb(0xBu);
  if ( v16 )
    KxWaitForSpinLockAndAcquire(v12);
  v17 = v12[2];
  if ( v17 )
  {
    v18 = (*a4 + __PAIR64__(v10, v9) - 1) >> 32;
    v25[0] = *(_DWORD *)a4 + v9 - 1;
    v25[1] = v18;
    for ( i = (_DWORD *)FsRtlFindFirstOverlappingExclusiveNode(v17, v26, v25); ; i = RtlRealSuccessor(i) )
    {
      v20 = i;
      if ( !i )
        break;
      if ( i[10] == a2 && i[11] == a5 && i[9] == a6 )
      {
        LODWORD(v21) = i[5];
        HIDWORD(v21) = i[4];
        if ( v21 == __PAIR64__(v9, v24) && *((_QWORD *)i + 3) == *a4 )
        {
          if ( *(_DWORD **)(a2 + 72) == i + 4 )
            *(_DWORD *)(a2 + 72) = 0;
          v12[2] = RtlDelete(i);
          if ( *(_QWORD *)a1 == *((_QWORD *)v20 + 2) )
            FsRtlPrivateResetLowestLockOffset(a1);
          if ( !a8 && *(_DWORD *)(a1 + 12) )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(v12);
            }
            else
            {
              __dmb(0xBu);
              *v12 = 0;
            }
            KfLowerIrql(v14);
            (*(void (__fastcall **)(int, _DWORD *))(a1 + 12))(a7, v20 + 4);
            v14 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(v12);
            }
            else
            {
              do
                v22 = __ldrex(v12);
              while ( __strex(1u, v12) );
              __dmb(0xBu);
              if ( v22 )
                KxWaitForSpinLockAndAcquire(v12);
            }
          }
          ExFreeToNPagedLookasideList(&FsRtlExclusiveLockLookasideList, v20);
          if ( a9 && v12[3] )
            FsRtlPrivateCheckWaitingLocks(a1, v12, v14);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v12);
          }
          else
          {
            __dmb(0xBu);
            *v12 = 0;
          }
          KfLowerIrql(v14);
          return 0;
        }
      }
      if ( *((_QWORD *)i + 2) > __PAIR64__(v24, v9) )
        break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v12);
  }
  else
  {
    __dmb(0xBu);
    *v12 = 0;
  }
  KfLowerIrql(v14);
  return -1073741698;
}
