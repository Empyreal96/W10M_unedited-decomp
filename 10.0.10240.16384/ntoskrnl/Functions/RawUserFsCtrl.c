// RawUserFsCtrl 
 
int __fastcall RawUserFsCtrl(int a1, int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r8
  int v6; // r7
  int v7; // r5
  unsigned int v10; // r5
  int v11; // r9
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // r3
  unsigned __int8 *v17; // r9
  int v18; // r1
  unsigned int v19; // r2
  int v20; // r2
  int v21; // r10
  unsigned int v22; // r1
  int v23; // r1
  int v24; // r3
  int v25; // r9
  unsigned int v26; // r1
  int v27; // r9
  int v28; // r1
  unsigned int v29; // r2
  int v30; // r4
  unsigned int v31; // r1
  int v32; // r1
  unsigned int v33; // r2
  int v34; // r3
  int v35; // r3
  int v37; // [sp+0h] [bp-28h]
  int v38; // [sp+0h] [bp-28h]
  int v39; // [sp+0h] [bp-28h]
  int v40; // [sp+4h] [bp-24h]
  int v41; // [sp+4h] [bp-24h]
  int v42; // [sp+4h] [bp-24h]
  int v43; // [sp+4h] [bp-24h]

  v3 = *(_DWORD *)(a2 + 16);
  v37 = 0;
  v4 = *(_DWORD *)(a2 + 28);
  v6 = 0;
  v7 = 0;
  if ( v3 == 589848 )
  {
    FsRtlNotifyVolumeEvent(v4, 3);
  }
  else if ( v3 == 589856 )
  {
    FsRtlNotifyVolumeEvent(v4, 1);
    v10 = a3 + 160;
    v11 = KeAbPreAcquire(a3 + 160, 0, 0);
    v12 = KfRaiseIrql(1);
    v40 = v12;
    do
      v13 = __ldrex((unsigned __int8 *)v10);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)v10) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(a3 + 160, v11);
      v12 = v40;
    }
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(a3 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a3 + 188) = v12;
    v14 = *(_DWORD *)(a3 + 72);
    if ( (v14 & 2) != 0 )
    {
      v6 = -1073741202;
    }
    else
    {
      *(_DWORD *)(a3 + 72) = v14 | 2;
      v37 = 1;
    }
    v25 = *(_DWORD *)(a3 + 188);
    *(_DWORD *)(a3 + 164) = 0;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)v10);
    while ( !v26 && __strex(1u, (unsigned int *)v10) );
    if ( v26 )
      ExpReleaseFastMutexContended((unsigned int *)(a3 + 160), v26);
    KfLowerIrql((unsigned __int8)v25);
    KeAbPostRelease(a3 + 160);
    if ( v37 )
    {
      ExWaitForRundownProtectionReleaseCacheAware(*(_DWORD **)(a3 + 156));
      v27 = KeAbPreAcquire(a3 + 160, 0, 0);
      v28 = KfRaiseIrql(1);
      v42 = v28;
      do
        v29 = __ldrex((unsigned __int8 *)v10);
      while ( __strex(v29 & 0xFE, (unsigned __int8 *)v10) );
      __dmb(0xBu);
      if ( (v29 & 1) == 0 )
      {
        ExpAcquireFastMutexContended(a3 + 160, v27);
        v28 = v42;
      }
      if ( v27 )
        *(_BYTE *)(v27 + 14) |= 1u;
      *(_DWORD *)(a3 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(a3 + 188) = v28;
      *(_DWORD *)(a3 + 148) = v4;
      v30 = *(_DWORD *)(a3 + 188);
      *(_DWORD *)(v10 + 4) = 0;
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned int *)v10);
      while ( !v31 && __strex(1u, (unsigned int *)v10) );
      if ( v31 )
        ExpReleaseFastMutexContended((unsigned int *)v10, v31);
      KfLowerIrql((unsigned __int8)v30);
      KeAbPostRelease(v10);
    }
    goto LABEL_92;
  }
  if ( v3 > 0x90018 )
  {
    if ( v3 != 589852 )
    {
      if ( v3 == 590412 )
      {
        v24 = *(_DWORD *)(a3 + 148);
        v7 = 1;
        if ( !v24 || v4 != v24 )
          v7 = ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 156), 1);
        if ( v7 )
        {
          v6 = RawQueryFileSystemInformation(a1, a2, a3);
          goto LABEL_88;
        }
        goto LABEL_52;
      }
LABEL_44:
      v6 = -1073741811;
      goto LABEL_45;
    }
    v17 = (unsigned __int8 *)(a3 + 160);
    v39 = KeAbPreAcquire(a3 + 160, 0, 0);
    v32 = KfRaiseIrql(1);
    v43 = v32;
    do
      v33 = __ldrex(v17);
    while ( __strex(v33 & 0xFE, v17) );
    __dmb(0xBu);
    if ( (v33 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(a3 + 160, v39);
      v32 = v43;
    }
    if ( v39 )
      *(_BYTE *)(v39 + 14) |= 1u;
    *(_DWORD *)(a3 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a3 + 188) = v32;
    v34 = *(_DWORD *)(a3 + 72);
    if ( (v34 & 1) != 0 )
    {
      *(_DWORD *)(a3 + 72) = v34 & 0xFFFFFFFE;
      *(_DWORD *)(a3 + 152) = 0;
    }
    else
    {
      v6 = -1073741782;
    }
    v21 = *(_DWORD *)(a3 + 188);
    *(_DWORD *)(a3 + 164) = 0;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v17);
    while ( !v22 && __strex(1u, (unsigned int *)v17) );
LABEL_85:
    if ( v22 )
      ExpReleaseFastMutexContended((unsigned int *)v17, v22);
    KfLowerIrql((unsigned __int8)v21);
    KeAbPostRelease((unsigned int)v17);
    goto LABEL_88;
  }
  if ( v3 == 589848 )
  {
    v16 = *(_DWORD *)(a3 + 148);
    v7 = 1;
    if ( !v16 || v4 != v16 )
      v7 = ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 156), 1);
    if ( !v7 )
      v6 = -1073741202;
    v17 = (unsigned __int8 *)(a3 + 160);
    v38 = KeAbPreAcquire(a3 + 160, 0, 0);
    v18 = KfRaiseIrql(1);
    v41 = v18;
    do
      v19 = __ldrex(v17);
    while ( __strex(v19 & 0xFE, v17) );
    __dmb(0xBu);
    if ( (v19 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(a3 + 160, v38);
      v18 = v41;
    }
    if ( v38 )
      *(_BYTE *)(v38 + 14) |= 1u;
    *(_DWORD *)(a3 + 164) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a3 + 188) = v18;
    v20 = *(_DWORD *)(a3 + 72);
    if ( (v20 & 1) != 0 || *(_DWORD *)(a3 + 76) != 1 )
    {
      v6 = -1073741790;
    }
    else
    {
      *(_DWORD *)(a3 + 72) = v20 | 1;
      *(_DWORD *)(a3 + 152) = v4;
    }
    v21 = *(_DWORD *)(a3 + 188);
    *(_DWORD *)(a3 + 164) = 0;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v17);
    while ( !v22 && __strex(1u, (unsigned int *)v17) );
    goto LABEL_85;
  }
  if ( v3 != 589824 && v3 != 589828 && v3 != 589836 && v3 != 589844 )
    goto LABEL_44;
  v15 = *(_DWORD *)(a3 + 148);
  v7 = 1;
  if ( !v15 || v4 != v15 )
    v7 = ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 156), 1);
  if ( !v7 )
  {
LABEL_52:
    v6 = -1073741202;
    goto LABEL_88;
  }
  v6 = -1073741822;
LABEL_88:
  if ( v7 )
  {
    v35 = *(_DWORD *)(a3 + 148);
    if ( !v35 || v4 != v35 )
      ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 156), 1);
  }
LABEL_92:
  if ( v6 >= 0 )
  {
    if ( v3 == 589852 )
    {
      v23 = 5;
      goto LABEL_96;
    }
    return v6;
  }
LABEL_45:
  if ( v3 == 589848 )
  {
    v23 = 4;
    goto LABEL_96;
  }
  if ( v3 == 589856 )
  {
    v23 = 2;
LABEL_96:
    FsRtlNotifyVolumeEvent(v4, v23);
  }
  return v6;
}
