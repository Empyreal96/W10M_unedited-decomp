// FsRtlFastUnlockSingleShared 
 
int __fastcall FsRtlFastUnlockSingleShared(int a1, int a2, int *a3, _QWORD *a4, int a5, int a6, int a7, char a8, char a9)
{
  int v9; // r5
  int v10; // r6
  _QWORD *v11; // r7
  unsigned int *v13; // r4
  int v14; // r8
  unsigned int v16; // r2
  unsigned int v17; // r0
  int v18; // r0
  _DWORD *v19; // r6
  unsigned int v20; // r1
  unsigned int v21; // lr
  int *v22; // r5
  _DWORD *v23; // r7
  int v24; // r0
  __int64 v25; // r2
  unsigned __int64 v26; // kr10_8
  unsigned int v27; // r2
  int v28; // [sp+8h] [bp-48h]
  unsigned int v29; // [sp+Ch] [bp-44h]
  int v30; // [sp+10h] [bp-40h]
  int v33[2]; // [sp+20h] [bp-30h] BYREF
  _QWORD v34[5]; // [sp+28h] [bp-28h] BYREF

  v9 = *a3;
  v10 = a3[1];
  v11 = a4;
  v13 = (unsigned int *)(a1 + 16);
  v28 = *a3;
  v33[0] = *a3;
  v33[1] = v10;
  v30 = v10;
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51E1F4();
  do
    v16 = __ldrex(v13);
  while ( __strex(1u, v13) );
  __dmb(0xBu);
  if ( v16 )
    KxWaitForSpinLockAndAcquire(v13);
  v17 = v13[1];
  if ( v17 )
  {
    v34[0] = *v11 + __PAIR64__(v10, v9) - 1;
    v18 = FsRtlFindFirstOverlappingSharedNode(v17, v33, v34, 0, 0);
    v33[0] = v18;
    if ( v18 )
    {
      v19 = (_DWORD *)(v18 - 16);
      v20 = 0;
      v21 = 0;
      v34[0] = 0i64;
      v22 = *(int **)(v18 - 16);
      v29 = 0;
      v23 = (_DWORD *)(v18 - 16);
      while ( 1 )
      {
        if ( !v22 )
          goto LABEL_42;
        if ( v22[8] != a2 || v22[9] != a5 )
          goto LABEL_37;
        v24 = v28;
        if ( v22[7] == a6 )
        {
          LODWORD(v25) = v22[3];
          HIDWORD(v25) = v22[2];
          if ( v25 == __PAIR64__(v28, v30) )
            break;
        }
LABEL_38:
        if ( *((_QWORD *)v22 + 1) > __PAIR64__(v30, v24) )
          goto LABEL_42;
        v26 = *((_QWORD *)v22 + 5);
        if ( __PAIR64__(v20, v21) < v26 )
        {
          v20 = HIDWORD(v26);
          v29 = HIDWORD(v26);
          v21 = v26;
          v34[0] = v26;
        }
        v23 = v22;
        v22 = (int *)*v22;
      }
      if ( *((_QWORD *)v22 + 2) == *a4 )
      {
        if ( *(int **)(a2 + 72) == v22 + 2 )
          *(_DWORD *)(a2 + 72) = 0;
        if ( *v23 == v19[7] )
          v19[7] = v23;
        *v23 = *v22;
        if ( v23 == v19 )
        {
          if ( !*v19 )
          {
            v13[1] = RtlDelete(v33[0]);
            ExFreeToNPagedLookasideList(&FsRtlLockTreeNodeLookasideList, v19);
            v19 = 0;
          }
          if ( *(_QWORD *)a1 == *((_QWORD *)v22 + 1) )
            FsRtlPrivateResetLowestLockOffset(a1);
        }
        if ( v19 )
          FsRtlSplitLocks(v19, v23, v22 + 10, v34);
        if ( !a8 && *(_DWORD *)(a1 + 12) )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v13);
          }
          else
          {
            __dmb(0xBu);
            *v13 = 0;
          }
          KfLowerIrql(v14);
          (*(void (__fastcall **)(int, int *))(a1 + 12))(a7, v22 + 2);
          v14 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v13);
          }
          else
          {
            do
              v27 = __ldrex(v13);
            while ( __strex(1u, v13) );
            __dmb(0xBu);
            if ( v27 )
              KxWaitForSpinLockAndAcquire(v13);
          }
        }
        ExFreeToNPagedLookasideList(&FsRtlSharedLockLookasideList, v22);
        if ( a9 && v13[3] )
          FsRtlPrivateCheckWaitingLocks(a1, v13, v14);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v13);
        }
        else
        {
          __dmb(0xBu);
          *v13 = 0;
        }
        KfLowerIrql(v14);
        return 0;
      }
      v20 = v29;
LABEL_37:
      v24 = v28;
      goto LABEL_38;
    }
    if ( (dword_682604 & 0x10000) == 0 )
      goto LABEL_35;
LABEL_54:
    KiReleaseSpinLockInstrumented(v13);
    goto LABEL_36;
  }
LABEL_42:
  if ( (dword_682604 & 0x10000) != 0 )
    goto LABEL_54;
LABEL_35:
  __dmb(0xBu);
  *v13 = 0;
LABEL_36:
  KfLowerIrql(v14);
  return -1073741698;
}
