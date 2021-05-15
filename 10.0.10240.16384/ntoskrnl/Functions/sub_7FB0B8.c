// sub_7FB0B8 
 
unsigned int __fastcall sub_7FB0B8(int a1, int a2, int a3)
{
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r6
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v10; // r3
  unsigned int v11; // r0
  _DWORD *v12; // r7
  int v13; // r5
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r3
  unsigned int v17; // r0
  int v18; // r4
  int v19; // r8
  unsigned int *v20; // r9
  unsigned int *v21; // r6
  unsigned int *v22; // r10
  unsigned int v23; // r2
  int v24; // r1
  unsigned __int8 *v25; // r0
  unsigned int v26; // r2
  __int64 v27; // kr00_8
  int v28; // r1
  unsigned int v29; // lr
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  int v33; // r3
  _DWORD *v34; // r0
  unsigned int v35; // r1
  int v36; // r6
  unsigned int v37; // r2
  unsigned int v38; // r2
  char *v39; // r2
  int v40; // r8
  int v41; // r10
  char v42; // r3
  char v43; // t1
  int v44; // lr
  __int64 v45; // r2
  unsigned int *v46; // r1
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned int v49; // r2
  unsigned int v50; // [sp+0h] [bp-40h]
  __int64 *v51; // [sp+0h] [bp-40h]
  unsigned int v52; // [sp+4h] [bp-3Ch]
  int v53; // [sp+4h] [bp-3Ch]
  char *v54; // [sp+4h] [bp-3Ch]
  int v55; // [sp+8h] [bp-38h]
  unsigned int *v56; // [sp+10h] [bp-30h]
  int v57; // [sp+14h] [bp-2Ch]

  v51 = (__int64 *)(v18 - 16);
  if ( (a3 & 2) != 0 )
    v19 = v18 - ObpInfoMaskToOffset[a3 & 3];
  else
    v19 = 0;
  v55 = v19;
  if ( (a3 & 4) != 0 )
    v20 = (unsigned int *)(v18 - ObpInfoMaskToOffset[a3 & 7]);
  else
    v20 = 0;
  if ( (a3 & 8) != 0 )
    v21 = (unsigned int *)(v18 - ObpInfoMaskToOffset[a3 & 0xF]);
  else
    v21 = 0;
  if ( (a3 & 0x20) != 0 )
    v22 = (unsigned int *)(v18 - ObpInfoMaskToOffset[a3 & 0x3F]);
  else
    v22 = 0;
  v56 = v22;
  v12 = (_DWORD *)(v18 - ObpInfoMaskToOffset[a3]);
  if ( (a3 & 0x80) != 0 )
    v12 = (_DWORD *)((char *)v12 - *v12 + 4);
  v13 = ObTypeIndexTable[BYTE1(v18) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v18 + 12)];
  if ( v18 != 16 && *(_DWORD *)(v18 - 16) != v18 - 16 )
  {
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v23 + 310);
    v24 = KeAbPreAcquire(v13 + 128, 0, 0);
    v53 = v24;
    v25 = (unsigned __int8 *)(v13 + 128);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 | 1, v25) );
    __dmb(0xBu);
    if ( (v26 & 1) != 0 )
    {
      ExfAcquirePushLockExclusiveEx(v25, v24, v13 + 128);
      v24 = v53;
      v25 = (unsigned __int8 *)(v13 + 128);
    }
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
    v27 = *v51;
    if ( *(__int64 **)(*(_DWORD *)v51 + 4) != v51 || *(__int64 **)HIDWORD(v27) != v51 )
      __fastfail(3u);
    __pld(v25);
    *(_DWORD *)HIDWORD(v27) = v27;
    *(_DWORD *)(v27 + 4) = HIDWORD(v27);
    v28 = *(_DWORD *)v25;
    if ( (*(_DWORD *)v25 & 0xFFFFFFF0) <= 0x10 )
      v29 = 0;
    else
      v29 = v28 - 16;
    if ( (v28 & 2) != 0 )
      goto LABEL_30;
    __dmb(0xBu);
    do
      v30 = __ldrex((unsigned int *)v25);
    while ( v30 == v28 && __strex(v29, (unsigned int *)v25) );
    if ( v30 != v28 )
    {
LABEL_30:
      ExfReleasePushLock(v25, v28);
      v25 = (unsigned __int8 *)(v13 + 128);
    }
    v31 = KeAbPostRelease((unsigned int)v25);
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = (__int16)(*(_WORD *)(v32 + 0x136) + 1);
    *(_WORD *)(v32 + 310) = v33;
    if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 )
      KiCheckForKernelApcDelivery(v31);
  }
  __dmb(0xBu);
  v14 = (unsigned int *)(v13 + 24);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 - 1, v14) );
  __dmb(0xBu);
  v16 = *(_DWORD *)(v18 + 16);
  if ( (*(_BYTE *)(v18 + 15) & 1) == 0 )
  {
    if ( !v16 )
      goto LABEL_73;
    if ( v21 )
    {
      v3 = v21[1];
      v4 = v21[3];
      v50 = v3;
      v52 = *v21;
      v57 = v4;
      if ( v4 )
      {
        v10 = v21[2];
        if ( v4 != 1 )
        {
          if ( v10 )
          {
            PspReturnQuota(v4, 0, 1, v10);
            v4 = v57;
          }
          PspDereferenceQuotaBlock(v4);
          v3 = v50;
        }
      }
    }
    else
    {
      v3 = *(_DWORD *)(v13 + 84);
      v50 = v3;
      v52 = *(_DWORD *)(v13 + 80);
    }
    v5 = *(_DWORD *)(v18 + 16);
    if ( v5 == 1 )
      goto LABEL_72;
    if ( v52 )
    {
      PspReturnQuota(*(_DWORD *)(v18 + 16), 0, 1, v52);
      v3 = v50;
    }
    if ( v3 )
      PspReturnQuota(v5, 0, 0, v3);
    __dmb(0xBu);
    v6 = (unsigned int *)(v5 + 1024);
    do
    {
      v7 = __ldrex(v6);
      v8 = v7 - 1;
    }
    while ( __strex(v8, v6) );
    __dmb(0xBu);
    if ( v8 )
    {
LABEL_72:
      *(_DWORD *)(v18 + 16) = 0;
      goto LABEL_73;
    }
    v39 = PspResourceFlags;
    v40 = 0;
    v41 = v5;
    while ( 1 )
    {
      v43 = *v39;
      v39 += 8;
      v42 = v43;
      v54 = v39;
      if ( (v43 & 2) != 0 || (v42 & 1) == 0 )
        goto LABEL_57;
      v44 = *(_DWORD *)(v41 + 136) != 0;
      v45 = *(_QWORD *)(v41 + 128);
      if ( HIDWORD(v45) + (_DWORD)v45 )
      {
        if ( *(_DWORD *)(v41 + 136) )
        {
          __dmb(0xBu);
          v46 = (unsigned int *)(v41 + 128);
          v47 = (unsigned int *)(v41 + 132);
          do
            v48 = __ldrex(v47);
          while ( __strex(0, v47) );
          __dmb(0xBu);
          do
            v49 = __ldrex(v46);
          while ( __strex(0, v46) );
          __dmb(0xBu);
          LODWORD(v45) = v49 + v48;
        }
        if ( (_DWORD)v45 )
        {
LABEL_55:
          PspReturnResourceQuota(v40, v41, v45, v44);
          goto LABEL_56;
        }
      }
      else
      {
        LODWORD(v45) = 0;
      }
      if ( v44 )
        goto LABEL_55;
LABEL_56:
      v39 = v54;
LABEL_57:
      ++v40;
      v41 += 256;
      if ( v40 >= 4 )
      {
        PspRemoveQuotaBlock(v5);
        ExFreePoolWithTag(v5);
        v19 = v55;
        v22 = v56;
        goto LABEL_72;
      }
    }
  }
  if ( v16 )
  {
    v17 = *(_DWORD *)(v16 + 24);
    if ( v17 )
    {
      SeReleaseSecurityDescriptor(v17, *(_BYTE *)(v16 + 8), 1);
      *(_DWORD *)(*(_DWORD *)(v18 + 16) + 24) = 0;
    }
    v34 = *(_DWORD **)(v18 + 16);
    v35 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v36 = *(_DWORD *)(v35 + 2848);
    v37 = *(unsigned __int16 *)(v36 + 8);
    ++*(_DWORD *)(v36 + 20);
    if ( *(unsigned __int16 *)(v36 + 4) < v37
      || (++*(_DWORD *)(v36 + 24),
          v36 = *(_DWORD *)(v35 + 2852),
          v38 = *(unsigned __int16 *)(v36 + 8),
          ++*(_DWORD *)(v36 + 20),
          *(unsigned __int16 *)(v36 + 4) < v38) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v36, v34);
    }
    else
    {
      ++*(_DWORD *)(v36 + 24);
      (*(void (__fastcall **)(_DWORD *))(v36 + 44))(v34);
    }
    *(_DWORD *)(v18 + 16) = 0;
  }
LABEL_73:
  if ( v20 && (*(_BYTE *)(v18 + 15) & 0x40) == 0 )
  {
    ExFreePoolWithTag(*v20);
    *v20 = 0;
  }
  if ( v19 )
  {
    v11 = *(_DWORD *)(v19 + 8);
    if ( v11 )
    {
      ExFreePoolWithTag(v11);
      *(_DWORD *)(v19 + 8) = 0;
    }
  }
  if ( v22 && *v22 )
  {
    ExFreePoolWithTag(*v22);
    *v22 = 0;
  }
  *(_BYTE *)(v18 + 12) = ObHeaderCookie ^ BYTE1(v18) ^ 1;
  return ExFreePoolWithTag((unsigned int)v12);
}
