// sub_8A0B68 
 
int __fastcall sub_8A0B68(int a1, unsigned int a2, _DWORD *a3, int a4, unsigned int a5, unsigned int a6, _DWORD *a7, _DWORD *a8, int *a9, unsigned int *a10, unsigned int *a11)
{
  int v11; // r6
  int v12; // r7
  int *v13; // r10
  unsigned int v14; // r9
  int v15; // r5
  unsigned int v16; // r2
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r4
  int v21; // r10
  int v22; // r9
  int v23; // r7
  unsigned int v24; // r5
  _DWORD *v25; // r0
  int v26; // r2
  int v27; // r3
  unsigned int v28; // r4
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  int v33; // r3
  unsigned int v34; // r5
  int v35; // r4
  _DWORD *v36; // r2
  int v37; // r6
  unsigned int v38; // r5
  unsigned int v39; // r10
  int v40; // r1
  int v41; // r4
  unsigned int v42; // r2
  int v43; // r0
  int v44; // r4
  unsigned int v45; // r1
  unsigned int v46; // r1
  int v47; // r0
  unsigned int v48; // r1
  __int16 v49; // r3
  unsigned int v50; // r3
  unsigned int i; // r5
  int v52; // r1
  int v53; // r4
  unsigned int v54; // r5
  unsigned int v55; // r1
  int v56; // r0
  unsigned int v57; // r1
  __int16 v58; // r3
  int v59; // r0
  int v61; // [sp+8h] [bp-58h] BYREF
  int v62; // [sp+Ch] [bp-54h]
  _DWORD *v63; // [sp+10h] [bp-50h] BYREF
  int v64; // [sp+14h] [bp-4Ch]
  _DWORD *v65; // [sp+18h] [bp-48h]
  int v66; // [sp+1Ch] [bp-44h]
  _DWORD *v67; // [sp+20h] [bp-40h]
  int *v68; // [sp+24h] [bp-3Ch]
  int v69; // [sp+28h] [bp-38h]
  int v70; // [sp+2Ch] [bp-34h]
  int v71; // [sp+30h] [bp-30h]
  unsigned int v72; // [sp+34h] [bp-2Ch]
  char v73[4]; // [sp+38h] [bp-28h] BYREF
  int v74; // [sp+3Ch] [bp-24h]

  v71 = a4;
  v72 = a2;
  v11 = 0;
  v12 = 0;
  v13 = &dword_920288[10 * a1];
  v67 = a3;
  v68 = v13;
  v70 = a1;
  v61 = 0;
  v65 = 0;
  v63 = 0;
  v14 = 0;
  while ( 1 )
  {
    v62 = v11;
    if ( v11 )
    {
      ObfDereferenceObject(v11);
      v11 = 0;
      v61 = 0;
      v62 = 0;
    }
    if ( v12 )
    {
      MmUnmapViewInSystemSpace(v12);
      v12 = 0;
      v65 = 0;
      v63 = 0;
    }
    v15 = 0;
    v66 = 0;
    v64 = 0;
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v16 + 308);
    v17 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
    v18 = v17;
    do
      v19 = __ldrex(&ExpFastCacheUpdateLock);
    while ( !v19 && __strex(0x11u, &ExpFastCacheUpdateLock) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(&ExpFastCacheUpdateLock, v17, (unsigned int)&ExpFastCacheUpdateLock);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v69 = v13[4];
    if ( a5 )
    {
      v20 = a6;
      v21 = v64;
      v22 = v66;
      v23 = v70;
      v24 = a5;
      do
      {
        v25 = (_DWORD *)ExpFindFastCacheDescriptor(v23, *(_DWORD *)(v20 + 4));
        if ( v25 )
        {
          v21 += (v25[10] + 51) & 0xFFFFFFF8;
          if ( v71 )
          {
            *(_QWORD *)(*(_DWORD *)(v20 + 4) + 32) = qword_922C10 + (unsigned int)dword_920280;
          }
          else
          {
            v26 = *(_DWORD *)(v20 + 4);
            *(_DWORD *)(v26 + 32) = v25[8];
            *(_DWORD *)(v26 + 36) = v25[9];
          }
        }
        else
        {
          ++v22;
          *(_QWORD *)(*(_DWORD *)(v20 + 4) + 32) = qword_922C10 + (unsigned int)dword_920280;
        }
        v20 += 8;
        --v24;
      }
      while ( v24 );
      v64 = v21;
      v11 = v62;
      v15 = v21;
      v12 = (int)v65;
      v13 = v68;
      v66 = v22;
      v14 = 0;
    }
    v27 = v13[1];
    if ( v27 )
      v28 = *(_DWORD *)(v27 + 8) - v15 + 24;
    else
      v28 = 24;
    __dmb(0xBu);
    do
      v29 = __ldrex(&ExpFastCacheUpdateLock);
    while ( v29 == 17 && __strex(0, &ExpFastCacheUpdateLock) );
    if ( v29 != 17 )
      ExfReleasePushLockShared(&ExpFastCacheUpdateLock);
    v30 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = *(_WORD *)(v31 + 0x134) + 1;
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v30);
    v33 = v67[2];
    v34 = v33 + v28;
    if ( v33 + v28 < v28 || v34 > v72 )
    {
      v35 = -1073700220;
      goto LABEL_82;
    }
    v35 = sub_7A2A90(v34, &v61, (int *)&v63);
    v12 = (int)v63;
    if ( v35 < 0 )
      goto LABEL_78;
    v36 = v67;
    v65 = v63;
    v37 = (int)(v63 + 6);
    *v63 = *v67;
    *(_DWORD *)(v12 + 4) = v36[1];
    *(_DWORD *)(v12 + 8) = v34 - 24;
    if ( a5 )
    {
      v38 = a6;
      v39 = a5;
      do
      {
        v40 = *(_DWORD *)(v38 + 4);
        v41 = *(_DWORD *)(v40 + 40);
        memmove(v37, v40, v41 + 44);
        v37 += (v41 + 51) & 0xFFFFFFF8;
        v38 += 8;
        --v39;
      }
      while ( v39 );
      v13 = v68;
    }
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v42 + 308);
    v43 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
    v44 = v43;
    do
      v45 = __ldrex(&ExpFastCacheUpdateLock);
    while ( !v45 && __strex(0x11u, &ExpFastCacheUpdateLock) );
    __dmb(0xBu);
    if ( v45 )
      ExfAcquirePushLockSharedEx(&ExpFastCacheUpdateLock, v43, (unsigned int)&ExpFastCacheUpdateLock);
    if ( v44 )
      *(_BYTE *)(v44 + 14) |= 1u;
    if ( v69 == v13[4] )
      break;
    __dmb(0xBu);
    do
      v46 = __ldrex(&ExpFastCacheUpdateLock);
    while ( v46 == 17 && __strex(0, &ExpFastCacheUpdateLock) );
    if ( v46 != 17 )
      ExfReleasePushLockShared(&ExpFastCacheUpdateLock);
    v47 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
    v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v49 = *(_WORD *)(v48 + 0x134) + 1;
    *(_WORD *)(v48 + 308) = v49;
    if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
      KiCheckForKernelApcDelivery(v47);
    v11 = v61;
  }
  v50 = v13[3];
  for ( i = 0; i < v50; ++i )
  {
    v73[0] = 1;
    v74 = *(_DWORD *)(v13[2] + 8 * i + 4);
    if ( !bsearch((int)v73, a6, a5, 8, (int (*)(void))ExpFastCacheDescriptorCompare) )
    {
      v52 = *(_DWORD *)(v13[2] + 8 * i + 4);
      v53 = *(_DWORD *)(v52 + 40);
      memmove(v37, v52, v53 + 44);
      v37 += (v53 + 51) & 0xFFFFFFF8;
    }
    v50 = v13[3];
  }
  v54 = v50 + v66;
  if ( v50 + v66 < v50 )
  {
    v35 = -1073741675;
    v54 = -1;
  }
  else
  {
    v35 = 0;
  }
  __dmb(0xBu);
  do
    v55 = __ldrex(&ExpFastCacheUpdateLock);
  while ( v55 == 17 && __strex(0, &ExpFastCacheUpdateLock) );
  if ( v55 != 17 )
    ExfReleasePushLockShared(&ExpFastCacheUpdateLock);
  v56 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
  v57 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v58 = *(_WORD *)(v57 + 0x134) + 1;
  *(_WORD *)(v57 + 308) = v58;
  if ( !v58 && *(_DWORD *)(v57 + 100) != v57 + 100 && !*(_WORD *)(v57 + 310) )
    KiCheckForKernelApcDelivery(v56);
  if ( v35 < 0 )
    goto LABEL_78;
  v59 = ExAllocatePoolWithTag(1, 8 * v54, 542329939);
  v14 = v59;
  if ( !v59 )
  {
    v35 = -1073741801;
LABEL_78:
    v11 = v61;
    goto LABEL_82;
  }
  v35 = ExpParseFastCache(v12, v59, v54, 0);
  if ( v35 < 0 )
    goto LABEL_78;
  qsort(v14, v54, 8u, (int (__fastcall *)(unsigned int, _BYTE *))ExpFastCacheDescriptorCompare);
  v11 = 0;
  *a7 = v69;
  *a8 = v61;
  *a9 = v12;
  v12 = 0;
  *a10 = v54;
  *a11 = v14;
  v14 = 0;
LABEL_82:
  if ( v11 )
    ObfDereferenceObject(v11);
  if ( v12 )
    MmUnmapViewInSystemSpace(v12);
  if ( v14 )
    ExFreePoolWithTag(v14);
  return v35;
}
