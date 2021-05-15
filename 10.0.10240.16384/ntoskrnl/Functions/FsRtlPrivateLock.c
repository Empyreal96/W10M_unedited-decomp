// FsRtlPrivateLock 
 
int __fastcall FsRtlPrivateLock(int a1, int a2, __int64 *a3, __int64 *a4, int a5, int a6, char a7, char a8, int *a9, int a10, int a11)
{
  int v14; // r9
  unsigned int *v15; // r5
  int v16; // r2
  int v17; // r10
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r0
  _DWORD *v21; // r0
  unsigned int *v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r6
  int v26; // r5
  unsigned __int8 v28; // [sp+8h] [bp-60h]
  char v29; // [sp+9h] [bp-5Fh]
  unsigned __int8 v30; // [sp+Ah] [bp-5Eh]
  _DWORD *v31; // [sp+Ch] [bp-5Ch]
  int v32; // [sp+10h] [bp-58h]
  int v33; // [sp+14h] [bp-54h] BYREF
  __int64 *v34; // [sp+18h] [bp-50h]
  int v35; // [sp+1Ch] [bp-4Ch]
  unsigned __int64 v36; // [sp+20h] [bp-48h] BYREF
  __int64 v37; // [sp+28h] [bp-40h]
  char v38; // [sp+30h] [bp-38h]
  int v39; // [sp+34h] [bp-34h]
  int v40; // [sp+38h] [bp-30h]
  int v41; // [sp+3Ch] [bp-2Ch]
  unsigned __int64 v42; // [sp+40h] [bp-28h]
  int varg_r0; // [sp+70h] [bp+8h]
  int varg_r1; // [sp+74h] [bp+Ch]
  __int64 *varg_r2; // [sp+78h] [bp+10h]
  __int64 *varg_r3; // [sp+7Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v34 = a3;
  v35 = a2;
  varg_r1 = a2;
  v29 = 0;
  v31 = 0;
  v30 = -1;
  v33 = a10 == 0;
  v14 = *(_DWORD *)(a1 + 12);
  v32 = v14;
  if ( !v14 )
  {
    if ( !FsRtlPrivateInitializeFileLock(a1, a10 == 0) )
    {
LABEL_3:
      v28 = 0;
      goto LABEL_44;
    }
    *(_BYTE *)(a1 + 8) = 1;
    v14 = *(_DWORD *)(a1 + 12);
    v32 = v14;
    a3 = v34;
  }
  v36 = *a3;
  v37 = *a4;
  v42 = v37 + v36 - 1;
  v39 = a6;
  v40 = a2;
  v41 = a5;
  v38 = a8;
  v15 = (unsigned int *)(v14 + 16);
  v31 = (_DWORD *)(v14 + 16);
  if ( v42 < v36 && v37 )
  {
    v16 = -1073741407;
  }
  else
  {
    v29 = 1;
    v17 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v14 + 16);
    }
    else
    {
      do
        v18 = __ldrex(v15);
      while ( __strex(1u, v15) );
      __dmb(0xBu);
      if ( v18 )
        KxWaitForSpinLockAndAcquire(v14 + 16);
    }
    v30 = v17;
    v19 = v14 + 16;
    if ( a8 )
      v20 = FsRtlPrivateCheckForExclusiveLockAccess(v19, &v36);
    else
      v20 = FsRtlPrivateCheckForSharedLockAccess(v19, &v36);
    if ( v20 )
    {
      if ( !FsRtlPrivateInsertLock(v14, v35, &v36) )
      {
        if ( !v33 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v14 + 16);
          }
          else
          {
            __dmb(0xBu);
            *v15 = 0;
          }
          KfLowerIrql(v17);
          RtlRaiseStatus(-1073741670);
        }
        goto LABEL_3;
      }
      v16 = 0;
    }
    else if ( a7 )
    {
      v16 = -1073741739;
    }
    else
    {
      if ( !a10 )
        goto LABEL_3;
      v21 = (_DWORD *)ExAllocateFromNPagedLookasideList(&FsRtlWaitingLockLookasideList);
      if ( !v21 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v14 + 16);
        }
        else
        {
          __dmb(0xBu);
          *v15 = 0;
        }
        KfLowerIrql(v17);
        RtlRaiseStatus(-1073741670);
      }
      v21[3] = a10;
      v21[2] = a11;
      v21[1] = *(_DWORD *)(v14 + 8);
      *(_BYTE *)(*(_DWORD *)(a10 + 96) + 3) |= 1u;
      *v21 = 0;
      if ( *(_DWORD *)(v14 + 28) )
        **(_DWORD **)(v14 + 32) = v21;
      else
        *(_DWORD *)(v14 + 28) = v21;
      *(_DWORD *)(v14 + 32) = v21;
      *(_DWORD *)(a10 + 28) = v14;
      __dmb(0xBu);
      v22 = (unsigned int *)(a10 + 56);
      do
        v23 = __ldrex(v22);
      while ( __strex((unsigned int)FsRtlPrivateCancelFileLockIrp, v22) );
      __dmb(0xBu);
      if ( *(_BYTE *)(a10 + 36) )
      {
        __dmb(0xBu);
        do
          v24 = __ldrex(v22);
        while ( __strex(0, v22) );
        __dmb(0xBu);
        if ( v24 )
        {
          *(_BYTE *)(a10 + 37) = v17;
          FsRtlPrivateCancelFileLockIrp(0, a10);
          v29 = 0;
        }
      }
      v16 = 259;
    }
  }
  *a9 = v16;
  v28 = 1;
LABEL_44:
  if ( v29 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v31);
    }
    else
    {
      __dmb(0xBu);
      *v31 = 0;
    }
    KfLowerIrql(v30);
  }
  if ( a10 && *a9 != 259 )
  {
    v25 = varg_r1;
    ObfReferenceObjectWithTag(varg_r1, 1953261124);
    FsRtlCompleteLockIrpReal(*(_DWORD *)(v32 + 8), a11, a10, *a9, &v33, v25);
    v26 = v33;
    if ( v33 < 0 && *a9 >= 0 )
      FsRtlPrivateRemoveLock(v32, &v36, 1);
    ObfDereferenceObjectWithTag(v25);
    *a9 = v26;
  }
  return v28;
}
