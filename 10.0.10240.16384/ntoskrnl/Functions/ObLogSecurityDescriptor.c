// ObLogSecurityDescriptor 
 
int __fastcall ObLogSecurityDescriptor(unsigned int a1, _DWORD *a2, int a3)
{
  int *v3; // r8
  int v4; // r0
  unsigned int v5; // r7
  unsigned int v6; // r5
  unsigned int v7; // r9
  int *v8; // r6
  unsigned int v10; // r4
  int v11; // t1
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int **v14; // r10
  unsigned int *v15; // r6
  unsigned int v16; // r8
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  unsigned int *v20; // r9
  unsigned int *v21; // r4
  unsigned int v22; // r3
  unsigned int v23; // r2
  int v24; // r0
  __int16 v25; // r3
  int v26; // r0
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r2
  unsigned int *v30; // r2
  int v31; // r0
  int v32; // r1
  unsigned int v33; // r0
  unsigned int v34; // r2
  int v35; // r0
  __int16 v36; // r3
  unsigned int **v37; // r2
  unsigned int v38; // r1
  int v39; // r0
  __int16 v40; // r3
  int v41; // t1
  unsigned int v42; // [sp+0h] [bp-30h]

  v3 = (int *)a1;
  v4 = RtlLengthSecurityDescriptor(a1);
  v5 = 0;
  v6 = 0;
  v42 = v4;
  v7 = (unsigned int)v3 + v4;
  v8 = v3;
  if ( v3 > (int *)((char *)v3 + (v4 & 0xFFFFFFFC)) )
    return sub_7FB810();
  v10 = ((v4 & 0xFFFFFFFC) + 3) >> 2;
  if ( v10 )
  {
    do
    {
      v11 = *v8++;
      ++v6;
      v5 = __ROR4__(v11 ^ v5, 29);
    }
    while ( v6 < v10 );
  }
  v12 = 0;
  v13 = v7 - (_DWORD)v8;
  if ( (unsigned int)v8 > v7 )
    v13 = 0;
  if ( v13 )
  {
    do
    {
      v41 = *(unsigned __int8 *)v8;
      v8 = (int *)((char *)v8 + 1);
      ++v12;
      v5 = __ROR4__(v41 ^ v5, 29);
    }
    while ( v12 < v13 );
  }
  v14 = 0;
  v15 = (unsigned int *)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)];
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v16 + 0x134);
  v17 = KeAbPreAcquire((unsigned int)v15, 0, 0);
  v18 = v17;
  do
    v19 = __ldrex(v15);
  while ( !v19 && __strex(0x11u, v15) );
  __dmb(0xBu);
  if ( v19 )
    ExfAcquirePushLockSharedEx(
      &ObsSecurityDescriptorCache[3 * (v5 % 0x101)],
      v17,
      (unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
  if ( v18 )
    *(_BYTE *)(v18 + 14) |= 1u;
  v20 = v15 + 1;
  while ( 1 )
  {
    v21 = (unsigned int *)v15[1];
    if ( v21 != v20 )
      break;
LABEL_20:
    if ( v14 )
    {
      v37 = (unsigned int **)v21[1];
      *v14 = v21;
      v14[1] = (unsigned int *)v37;
      if ( *v37 != v21 )
        __fastfail(3u);
      *v37 = (unsigned int *)v14;
      v21[1] = (unsigned int)v14;
      __dmb(0xBu);
      do
        v38 = __ldrex(v15);
      while ( __strex(v38 - 1, v15) );
      if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
      v39 = KeAbPostRelease((unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
      v40 = *(_WORD *)(v16 + 308) + 1;
      *(_WORD *)(v16 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v39);
      *a2 = v14 + 4;
      return 0;
    }
    __dmb(0xBu);
    do
      v23 = __ldrex(v15);
    while ( v23 == 17 && __strex(0, v15) );
    if ( v23 != 17 )
      ExfReleasePushLockShared(&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
    v24 = KeAbPostRelease((unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
    v25 = *(_WORD *)(v16 + 308) + 1;
    *(_WORD *)(v16 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v24);
    if ( v42 + 24 < v42 )
      return -1073741670;
    v26 = ExAllocatePoolWithTag(1, v42 + 16, 1666409039);
    v14 = (unsigned int **)v26;
    if ( !v26 )
      return -1073741670;
    *(_DWORD *)(v26 + 8) = a3;
    *(_DWORD *)(v26 + 12) = v5;
    memmove(v26 + 16, a1, v42);
    --*(_WORD *)(v16 + 308);
    v27 = KeAbPreAcquire((unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)], 0, 0);
    v28 = v27;
    do
      v29 = __ldrex((unsigned __int8 *)v15);
    while ( __strex(v29 | 1, (unsigned __int8 *)v15) );
    __dmb(0xBu);
    if ( (v29 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(
        &ObsSecurityDescriptorCache[3 * (v5 % 0x101)],
        v27,
        (unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
    if ( v28 )
      *(_BYTE *)(v28 + 14) |= 1u;
  }
  while ( 1 )
  {
    v22 = v21[3];
    if ( v22 != v5 )
    {
      if ( v22 > v5 )
        goto LABEL_20;
      goto LABEL_19;
    }
    if ( v42 == RtlLengthSecurityDescriptor(v21 + 4) && !memcmp(a1, (unsigned int)(v21 + 4), v42) )
      break;
LABEL_19:
    v21 = (unsigned int *)*v21;
    if ( v21 == v20 )
      goto LABEL_20;
  }
  v30 = v21 + 2;
  do
    v31 = __ldrex(v30);
  while ( __strex(v31 + a3, v30) );
  if ( v31 <= 0 )
    __fastfail(0xEu);
  __pld(v15);
  v32 = *v15;
  if ( (*v15 & 0xFFFFFFF0) > 0x10 )
    v33 = v32 - 16;
  else
    v33 = 0;
  if ( (v32 & 2) != 0 )
    goto LABEL_61;
  __dmb(0xBu);
  do
    v34 = __ldrex(v15);
  while ( v34 == v32 && __strex(v33, v15) );
  if ( v34 != v32 )
LABEL_61:
    ExfReleasePushLock(&ObsSecurityDescriptorCache[3 * (v5 % 0x101)], v32);
  v35 = KeAbPostRelease((unsigned int)&ObsSecurityDescriptorCache[3 * (v5 % 0x101)]);
  v36 = *(_WORD *)(v16 + 308) + 1;
  *(_WORD *)(v16 + 308) = v36;
  if ( !v36 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v35);
  *a2 = v21 + 4;
  if ( !v14 )
    return 0;
  ExFreePoolWithTag((unsigned int)v14);
  return 0;
}
