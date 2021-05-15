// PspAssignProcessQuotaBlock 
 
int __fastcall PspAssignProcessQuotaBlock(int a1, int a2, int a3)
{
  unsigned int v4; // r6
  int v5; // r0
  unsigned int v7; // r7
  char *v8; // r8
  int v9; // r4
  int v10; // r5
  char *v11; // r10
  unsigned int v12; // r5
  unsigned int *v13; // r6
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // r0
  __int16 v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r2
  unsigned int v23; // r2
  int v24; // r0
  __int16 v25; // r3
  int v26; // r0
  int v27; // r5
  unsigned int *v28; // r2
  unsigned int v29; // r1
  unsigned int *v30; // r2
  int *v31; // r1
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int v34; // [sp+0h] [bp-80h] BYREF
  int v35; // [sp+4h] [bp-7Ch]
  char v36[72]; // [sp+8h] [bp-78h] BYREF
  char v37[48]; // [sp+50h] [bp-30h] BYREF

  v35 = a2;
  __mrc(15, 0, 13, 0, 3);
  v4 = 0;
  v5 = SeQueryUserSidToken(a3, (int)v36, 0x44u, &v34);
  if ( a1 )
    return sub_7E8384(v5);
  v7 = v34;
  v8 = v36;
  v9 = PspLookupProcessQuotaBlock(v36, v34, 0, 0);
  if ( v9 )
    goto LABEL_25;
  v10 = PspReadUserQuotaLimits(v36, &v34, v37);
  if ( v10 >= 0 )
  {
    if ( v34 )
    {
      v8 = 0;
      v11 = (char *)&PspDefaultResourceLimits;
      v7 = 0;
      v34 = 1;
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = (unsigned int *)PspQuotaBlockTable;
      --*(_WORD *)(v12 + 308);
      v14 = KeAbPreAcquire((unsigned int)v13, 0, 0);
      v15 = v14;
      do
        v16 = __ldrex(v13);
      while ( !v16 && __strex(0x11u, v13) );
      __dmb(0xBu);
      if ( v16 )
        ExfAcquirePushLockSharedEx(v13, v14, (unsigned int)v13);
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      v9 = PspDefaultQuotaBlock;
      if ( PspDefaultQuotaBlock && PspSafeReferenceQuotaBlock(PspDefaultQuotaBlock) )
      {
        __dmb(0xBu);
        do
          v17 = __ldrex(v13);
        while ( v17 == 17 && __strex(0, v13) );
        if ( v17 != 17 )
          ExfReleasePushLockShared(v13);
        v18 = KeAbPostRelease((unsigned int)v13);
        v19 = *(_WORD *)(v12 + 308) + 1;
        *(_WORD *)(v12 + 308) = v19;
        if ( !v19 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
          KiCheckForKernelApcDelivery(v18);
        __dmb(0xBu);
        v20 = (unsigned int *)(v9 + 1028);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 + 1, v20) );
        __dmb(0xBu);
        goto LABEL_25;
      }
      __dmb(0xBu);
      do
        v23 = __ldrex(v13);
      while ( v23 == 17 && __strex(0, v13) );
      if ( v23 != 17 )
        ExfReleasePushLockShared(v13);
      v24 = KeAbPostRelease((unsigned int)v13);
      v25 = *(_WORD *)(v12 + 308) + 1;
      *(_WORD *)(v12 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v24);
      v4 = v34;
    }
    else
    {
      v11 = v37;
    }
    v26 = ExAllocatePoolWithTag(516, v7 + 1152, 1649505104);
    v9 = v26;
    if ( !v26 )
      return -1073741670;
    v10 = PspInitializeQuotaBlock(0, v11, v26);
    if ( v10 < 0 )
      goto LABEL_57;
    if ( v8 )
      RtlCopySid(v7, v9 + 1152, (int)v36);
    v27 = PspLookupProcessQuotaBlock(v8, v7, v4, v9);
    if ( v27 )
    {
      __dmb(0xBu);
      v28 = (unsigned int *)(v9 + 1028);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 - 1, v28) );
      __dmb(0xBu);
      PspDereferenceQuotaBlock(v9);
      v9 = v27;
    }
LABEL_25:
    v22 = v35;
    if ( !*(_DWORD *)(v35 + 332) )
    {
      *(_DWORD *)(v35 + 332) = v9;
      return 0;
    }
    __dmb(0xBu);
    v30 = (unsigned int *)(v22 + 332);
    do
      v31 = (int *)__ldrex(v30);
    while ( v31 == PspSystemQuotaBlock && __strex(v9, v30) );
    __dmb(0xBu);
    if ( v31 == PspSystemQuotaBlock )
      return 0;
    v10 = -1073741823;
LABEL_57:
    if ( v9 )
    {
      __dmb(0xBu);
      v32 = (unsigned int *)(v9 + 1028);
      do
        v33 = __ldrex(v32);
      while ( __strex(v33 - 1, v32) );
      __dmb(0xBu);
      PspDereferenceQuotaBlock(v9);
    }
  }
  return v10;
}
