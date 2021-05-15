// PnpNotifyHwProfileChange 
 
int __fastcall PnpNotifyHwProfileChange(int *a1, _DWORD *a2, unsigned __int16 *a3)
{
  int v4; // r8
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r4
  void **v8; // r7
  __int16 v9; // r3
  unsigned __int8 v10; // r4
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r3
  GUID *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  void **v22; // r10
  int v23; // r4
  int v24; // r5
  unsigned int v25; // r2
  int v26; // r5
  unsigned __int8 v27; // r4
  unsigned int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // r4
  int v35; // r9
  unsigned int v36; // r2
  unsigned __int8 v37; // r4
  unsigned int v38; // r1
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  int v43; // r4
  int v44; // r5
  unsigned int v45; // r2
  int v46; // [sp+0h] [bp-50h] BYREF
  int v47; // [sp+4h] [bp-4Ch]
  int *v48; // [sp+8h] [bp-48h]
  _DWORD *v49; // [sp+Ch] [bp-44h]
  void **v50; // [sp+10h] [bp-40h]
  __int16 v51; // [sp+18h] [bp-38h] BYREF
  __int16 v52; // [sp+1Ah] [bp-36h]
  int v53; // [sp+1Ch] [bp-34h]
  int v54; // [sp+20h] [bp-30h]
  int v55; // [sp+24h] [bp-2Ch]
  int v56; // [sp+28h] [bp-28h]

  v48 = a1;
  v49 = a2;
  v4 = 0;
  v46 = 0;
  v5 = KeAbPreAcquire((unsigned int)&PnpHwProfileNotifyLock, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)&PnpHwProfileNotifyLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PnpHwProfileNotifyLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PnpHwProfileNotifyLock, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_630D44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630D5C = v6;
  v8 = (void **)PnpProfileNotifyList;
  if ( PnpProfileNotifyList != &PnpProfileNotifyList )
  {
    do
    {
      v9 = *((_WORD *)v8 + 16);
      v50 = v8;
      *((_WORD *)v8 + 16) = v9 + 1;
      dword_630D44 = 0;
      v10 = dword_630D5C;
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&PnpHwProfileNotifyLock);
      while ( !v11 && __strex(1u, (unsigned int *)&PnpHwProfileNotifyLock) );
      if ( v11 )
        ExpReleaseFastMutexContended((unsigned int *)&PnpHwProfileNotifyLock, v11);
      KfLowerIrql(v10);
      KeAbPostRelease((unsigned int)&PnpHwProfileNotifyLock);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(__int16 *)(v12 + 0x134) - 1;
      *(_WORD *)(v12 + 308) = v13;
      ExAcquireResourceExclusiveLite((int)v8[10], 1, v12, v13);
      if ( *((_BYTE *)v8 + 34) )
      {
        v40 = ExReleaseResourceLite((int)v8[10]);
        v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v42 = *(_WORD *)(v41 + 0x134) + 1;
        *(_WORD *)(v41 + 308) = v42;
        if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
          KiCheckForKernelApcDelivery(v40);
      }
      else
      {
        v14 = (GUID *)v48;
        v51 = 1;
        v52 = 20;
        v15 = v48[1];
        v16 = v48[2];
        v17 = v48[3];
        v53 = *v48;
        v54 = v15;
        v55 = v16;
        v56 = v17;
        v18 = PnpNotifyDriverCallback(v8, (int)&v51, &v46);
        v19 = ExReleaseResourceLite((int)v8[10]);
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v21 = *(_WORD *)(v20 + 0x134) + 1;
        *(_WORD *)(v20 + 308) = v21;
        if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
          KiCheckForKernelApcDelivery(v19);
        if ( v18 >= 0 )
        {
          v4 = v46;
        }
        else
        {
          v4 = 0;
          v46 = 0;
        }
        v47 = v4;
        if ( v4 < 0
          && (v14 == &GUID_HWPROFILE_QUERY_CHANGE
           || RtlCompareMemory((unsigned __int8 *)v14, (int)&GUID_HWPROFILE_QUERY_CHANGE, 16) == 16) )
        {
          if ( v49 )
            *v49 = 7;
          if ( a3 )
          {
            *a3 = 0;
            RtlCopyUnicodeString(a3, (unsigned __int16 *)v8[7] + 14);
          }
          v53 = -885374974;
          v54 = 298862320;
          v55 = 1610649520;
          v56 = 1057297303;
          v52 = 16;
          v22 = v8;
          v23 = KeAbPreAcquire((unsigned int)&PnpHwProfileNotifyLock, 0, 0);
          v24 = KfRaiseIrql(1);
          do
            v25 = __ldrex((unsigned __int8 *)&PnpHwProfileNotifyLock);
          while ( __strex(v25 & 0xFE, (unsigned __int8 *)&PnpHwProfileNotifyLock) );
          __dmb(0xBu);
          if ( (v25 & 1) == 0 )
            ExpAcquireFastMutexContended((int)&PnpHwProfileNotifyLock, v23);
          if ( v23 )
            *(_BYTE *)(v23 + 14) |= 1u;
          dword_630D44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          dword_630D5C = v24;
          do
          {
            v26 = (int)v8;
            ++*((_WORD *)v8 + 16);
            dword_630D44 = 0;
            v27 = dword_630D5C;
            __dmb(0xBu);
            do
              v28 = __ldrex((unsigned int *)&PnpHwProfileNotifyLock);
            while ( !v28 && __strex(1u, (unsigned int *)&PnpHwProfileNotifyLock) );
            if ( v28 )
              ExpReleaseFastMutexContended((unsigned int *)&PnpHwProfileNotifyLock, v28);
            KfLowerIrql(v27);
            KeAbPostRelease((unsigned int)&PnpHwProfileNotifyLock);
            v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v30 = *(__int16 *)(v29 + 0x134) - 1;
            *(_WORD *)(v29 + 308) = v30;
            ExAcquireResourceExclusiveLite((int)v8[10], 1, v29, v30);
            if ( !*((_BYTE *)v8 + 34) )
              PnpNotifyDriverCallback(v8, (int)&v51, 0);
            v31 = ExReleaseResourceLite((int)v8[10]);
            v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v33 = *(_WORD *)(v32 + 0x134) + 1;
            *(_WORD *)(v32 + 308) = v33;
            if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
              KiCheckForKernelApcDelivery(v31);
            v34 = KeAbPreAcquire((unsigned int)&PnpHwProfileNotifyLock, 0, 0);
            v35 = KfRaiseIrql(1);
            do
              v36 = __ldrex((unsigned __int8 *)&PnpHwProfileNotifyLock);
            while ( __strex(v36 & 0xFE, (unsigned __int8 *)&PnpHwProfileNotifyLock) );
            __dmb(0xBu);
            if ( (v36 & 1) == 0 )
              ExpAcquireFastMutexContended((int)&PnpHwProfileNotifyLock, v34);
            if ( v34 )
              *(_BYTE *)(v34 + 14) |= 1u;
            dword_630D44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            dword_630D5C = v35;
            v8 = (void **)v8[1];
            PnpDereferenceNotify(v26);
            if ( (void **)v26 == v22 )
              PnpDereferenceNotify(v26);
          }
          while ( v8 != &PnpProfileNotifyList );
          v4 = v47;
          break;
        }
      }
      v43 = KeAbPreAcquire((unsigned int)&PnpHwProfileNotifyLock, 0, 0);
      v44 = KfRaiseIrql(1);
      do
        v45 = __ldrex((unsigned __int8 *)&PnpHwProfileNotifyLock);
      while ( __strex(v45 & 0xFE, (unsigned __int8 *)&PnpHwProfileNotifyLock) );
      __dmb(0xBu);
      if ( (v45 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PnpHwProfileNotifyLock, v43);
      if ( v43 )
        *(_BYTE *)(v43 + 14) |= 1u;
      dword_630D44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_630D5C = v44;
      v8 = (void **)*v8;
      PnpDereferenceNotify((int)v50);
    }
    while ( v8 != &PnpProfileNotifyList );
  }
  dword_630D44 = 0;
  v37 = dword_630D5C;
  __dmb(0xBu);
  do
    v38 = __ldrex((unsigned int *)&PnpHwProfileNotifyLock);
  while ( !v38 && __strex(1u, (unsigned int *)&PnpHwProfileNotifyLock) );
  if ( v38 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpHwProfileNotifyLock, v38);
  KfLowerIrql(v37);
  KeAbPostRelease((unsigned int)&PnpHwProfileNotifyLock);
  return v4;
}
