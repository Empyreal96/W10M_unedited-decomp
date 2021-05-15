// PfSnAsyncPrefetchWorker 
 
unsigned int __fastcall PfSnAsyncPrefetchWorker(_DWORD *a1)
{
  int v1; // r8
  int v3; // r9
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r0
  unsigned int v8; // r0
  int v9; // r0
  char v10; // r7
  unsigned int v11; // r5
  _DWORD *v12; // r0
  unsigned int v13; // r4
  unsigned int v14; // r1
  unsigned int *v15; // r1
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r2
  unsigned int v21; // r1
  _DWORD *v22; // r0
  unsigned int v23; // r5
  unsigned int v24; // r4
  int v25; // [sp+0h] [bp-D8h] BYREF
  int v26; // [sp+8h] [bp-D0h] BYREF
  char v27[120]; // [sp+Ch] [bp-CCh] BYREF
  int v28; // [sp+84h] [bp-54h]
  int v29; // [sp+88h] [bp-50h]
  int v30; // [sp+8Ch] [bp-4Ch]
  int v31; // [sp+90h] [bp-48h]
  int v32; // [sp+94h] [bp-44h]
  char v33[56]; // [sp+A0h] [bp-38h] BYREF

  v1 = a1[32];
  v3 = 0;
  v4 = 0;
  PfSnInitializePrefetchHeader(&v26);
  v5 = a1[36];
  v26 = v1;
  __mrc(15, 0, 13, 0, 3);
  PfSnLogAsyncWorker(v1, PfSnEvt_AsyncWorker_Start);
  if ( (a1[37] & 1) != 0 )
  {
    PfSnPowerBoost(a1 + 6, 1);
    v4 = 1;
  }
  KiStackAttachProcess(a1[33], 0, (int)v33);
  v6 = MmGetDefaultPagePriority();
  if ( v5 <= v6 - 1 )
    return sub_808F38();
  v28 = v6 - 1;
  v29 = v6;
  if ( PfSnPreallocatePrefetchHeader(&v26) >= 0 )
  {
    v8 = MmGetAvailablePagesBelowPriority(v29 + 1);
    v9 = v8 < 0xF00 ? 0 : v8 - 3840;
    v30 = v9;
    if ( v9 )
    {
      if ( PfpPrefetchSharedStart(v27) >= 0 && PfSnOpenVolumesForPrefetch(&v26, &v25) >= 0 )
      {
        if ( *(_DWORD *)(v1 + 80) == 1 )
          v10 = v25 | 1;
        else
          v10 = v25;
        if ( (dword_637270 & 4) != 0 )
        {
          v11 = 0;
          v10 &= 0xFDu;
LABEL_24:
          if ( v11 < *(_DWORD *)(v1 + 124) && (v10 & 2) == 0 )
          {
            __dmb(0xBu);
            v15 = (unsigned int *)(a1[33] + 792);
            do
              v16 = __ldrex(v15);
            while ( __strex(0x1388u, v15) );
            __dmb(0xBu);
            for ( ; v11 < *(_DWORD *)(v1 + 124); ++v11 )
            {
              if ( PfSnAsyncPrefetchStep(a1, &v26, 1 << v11) < 0 )
                break;
            }
          }
          goto LABEL_31;
        }
        if ( (v10 & 1) != 0 )
          v11 = *(_DWORD *)(v1 + 124);
        else
          v11 = 1;
        if ( 1 << v11 == 1 || PfSnAsyncPrefetchStep(a1, &v26, (1 << v11) - 1) >= 0 )
        {
          v12 = (_DWORD *)a1[4];
          __pld(v12);
          v13 = *v12 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v14 = __ldrex(v12);
          while ( v14 == v13 && __strex(v13 - 2, v12) );
          if ( v14 != v13 )
            ExfReleaseRundownProtection((unsigned __int8 *)v12);
          v3 = 1;
          PfSnLogAsyncWorker(v1, PfSnEvt_SyncPrefetchingDone_Info);
          goto LABEL_24;
        }
      }
    }
  }
LABEL_31:
  __dmb(0xBu);
  v17 = (unsigned int *)(a1[33] + 792);
  do
    v18 = __ldrex(v17);
  while ( __strex(0, v17) );
  __dmb(0xBu);
  v19 = a1[34];
  if ( v19 )
  {
    *(_DWORD *)(v19 + 336) = v31;
    v31 = 0;
    v20 = v32;
    __dmb(0xBu);
    *(_DWORD *)(a1[34] + 340) = v20;
  }
  PfSnCleanupPrefetchHeader((unsigned int *)&v26);
  __dmb(0xBu);
  do
    v21 = __ldrex(dword_6373B0);
  while ( __strex(v21 - 1, dword_6373B0) );
  __dmb(0xBu);
  if ( v4 )
    PfSnPowerBoost(a1 + 6, 0);
  KiUnstackDetachProcess((unsigned int)v33, 0);
  if ( !v3 )
  {
    v22 = (_DWORD *)a1[4];
    __pld(v22);
    v23 = *v22 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( v24 == v23 && __strex(v23 - 2, v22) );
    if ( v24 != v23 )
      ExfReleaseRundownProtection((unsigned __int8 *)v22);
    PfSnLogAsyncWorker(v1, PfSnEvt_SyncPrefetchingDone_Info);
  }
  PfSnLogAsyncWorker(v1, PfSnEvt_AsyncWorker_Stop);
  PfSnAsyncContextCleanup(a1);
  return ExFreePoolWithTag((unsigned int)a1);
}
