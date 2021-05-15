// sub_6E2B78 
 
int __fastcall sub_6E2B78(unsigned __int16 *a1, int a2, int a3, int a4, unsigned int *a5)
{
  int v5; // r4
  int v6; // r6
  int (*v7)[17]; // r10
  int v8; // r8
  unsigned int v9; // r9
  unsigned __int16 *v10; // r1
  unsigned int v11; // r3
  int (**v12)[17]; // r5
  int v13; // r2
  unsigned int v14; // lr
  int v15; // r1
  _WORD *v16; // r0
  unsigned int v17; // r2
  int v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r2
  int v25; // r4
  unsigned int v26; // r1
  int v27; // r3
  int *v28; // r3
  unsigned int v29; // r3
  unsigned int v30; // r1
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r6
  unsigned int v37; // r1
  unsigned int v38; // r0
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  int (*v42)[17]; // r8
  int v43; // r6
  unsigned int v44; // r9
  unsigned __int16 *v45; // r3
  unsigned int v46; // r10
  int (**v47)[17]; // r5
  int v48; // r2
  unsigned int v49; // lr
  int v50; // r1
  _WORD *v51; // r0
  int v52; // r0
  char v54[4]; // [sp+8h] [bp-B0h] BYREF
  int v55; // [sp+Ch] [bp-ACh]
  unsigned int v56; // [sp+10h] [bp-A8h]
  unsigned int v57; // [sp+14h] [bp-A4h]
  unsigned int *v58; // [sp+18h] [bp-A0h]
  unsigned int v59; // [sp+1Ch] [bp-9Ch]
  char v60[4]; // [sp+20h] [bp-98h] BYREF
  unsigned __int16 *v61; // [sp+24h] [bp-94h]
  int v62; // [sp+28h] [bp-90h]
  int v63; // [sp+2Ch] [bp-8Ch]
  int v64; // [sp+30h] [bp-88h]
  unsigned int *v65; // [sp+34h] [bp-84h]
  int v66; // [sp+38h] [bp-80h]
  int v67; // [sp+3Ch] [bp-7Ch]
  int v68; // [sp+40h] [bp-78h]
  int v69; // [sp+44h] [bp-74h]
  _DWORD _48[33]; // [sp+48h] [bp-70h] BYREF
  int varg_r3; // [sp+CCh] [bp+14h]

  _48[30] = a1;
  _48[31] = a2;
  _48[32] = a3;
  v57 = a4;
  varg_r3 = a4;
  v62 = a3;
  v63 = a2;
  v66 = a2;
  v64 = a3;
  v58 = a5;
  v65 = a5;
  v55 = 0;
  v60[0] = 0;
  v61 = 0;
  v54[0] = 0;
  if ( !a1 || !a5 || (v5 = 0, v69 = 0, v55 = 0, !*((_DWORD *)a1 + 1)) || !*a1 || *a1 < 2u )
  {
    v5 = -1073741811;
    v55 = -1073741811;
    return v5;
  }
  v60[0] = 1;
  v61 = a1;
  v6 = sub_6E3014();
  v67 = v6;
  v56 = v6;
  v7 = 0;
  v8 = 1;
  v9 = 0;
  v10 = v61;
  v11 = *v61;
  v59 = v11;
  v12 = &off_8C62B0;
  while ( 1 )
  {
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( v11 != v13 )
    {
      v8 += v13;
      goto LABEL_15;
    }
    v14 = v11 >> 1;
    if ( v11 >> 1 )
    {
      v15 = *((_DWORD *)v10 + 1);
      v16 = _48;
      v68 = v15 - (_DWORD)_48;
      do
      {
        *v16 = *(_WORD *)((char *)v16 + v15 - (_DWORD)_48) ^ ((v8 + 1) | ((_WORD)v8 << 8) | 0x5555);
        ++v16;
        v8 += 2;
        --v14;
      }
      while ( v14 );
      v5 = v69;
      v6 = v67;
    }
    if ( !memcmp((unsigned int)_48, (unsigned int)*v12, v13) )
      break;
    v11 = v59;
    v10 = v61;
LABEL_15:
    ++v9;
    v12 += 4;
    if ( v9 >= 8 )
      goto LABEL_18;
  }
  v7 = v12[2];
LABEL_18:
  if ( v7 )
  {
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v17 + 308);
    v18 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    do
      v19 = __ldrex((unsigned int *)&dword_922C40);
    while ( !v19 && __strex(0x11u, (unsigned int *)&dword_922C40) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(&dword_922C40, v18, (unsigned int)&dword_922C40);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v5 = ((int (__fastcall *)(int, int, unsigned int, unsigned int *, char *))v7)(v63, v62, v57, v58, v54);
    v55 = v5;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)&dword_922C40);
    while ( v20 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
    if ( v20 != 17 )
      ExfReleasePushLockShared(&dword_922C40);
    v21 = KeAbPostRelease((unsigned int)&dword_922C40);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v21);
  }
  if ( v54[0] )
  {
    if ( v5 >= 0 && *v58 > v57 )
    {
      v5 = -1073741789;
      v55 = -1073741789;
    }
    return v5;
  }
  if ( v6 < 0 )
  {
    v5 = v6;
    v55 = v6;
    return v5;
  }
  v55 = 0;
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v24 + 308);
  v25 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  v59 = 0;
  v56 = 17;
  do
    v26 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v26 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  v56 = v26;
  if ( v26 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v25, (unsigned int)&dword_922C40);
  if ( v25 )
    *(_BYTE *)(v25 + 14) |= 1u;
  if ( byte_920AF3 == 1 && !dword_922C3C )
  {
LABEL_51:
    v27 = -1073741772;
    goto LABEL_58;
  }
  v28 = off_920350;
  if ( !off_920350 )
  {
    v28 = (int *)dword_922C44;
    if ( !dword_922C44 )
      goto LABEL_57;
  }
  v29 = *v28;
  if ( v29 == 24 )
    goto LABEL_51;
  if ( v29 >= 0x18 )
  {
    v55 = sub_6E3298(v60, v63, v62, v57, v58);
  }
  else
  {
LABEL_57:
    v27 = -1073741762;
LABEL_58:
    v55 = v27;
  }
  __dmb(0xBu);
  do
    v30 = __ldrex((unsigned int *)&dword_922C40);
  while ( v30 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v30 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v31 = KeAbPostRelease((unsigned int)&dword_922C40);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x134) + 1;
  *(_WORD *)(v32 + 308) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
    KiCheckForKernelApcDelivery(v31);
  v5 = v55;
  if ( v55 == -1073741762 )
  {
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v34 + 308);
    v35 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v36 = v35;
    do
      v37 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v37 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v37 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_922C40, v35, (unsigned int)&dword_922C40);
    if ( v36 )
      *(_BYTE *)(v36 + 14) |= 1u;
    byte_920AF2 = 1;
    __dmb(0xBu);
    do
      v38 = __ldrex((unsigned int *)&dword_922C40);
    while ( __strex(v38 - 1, (unsigned int *)&dword_922C40) );
    if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_922C40);
    v39 = KeAbPostRelease((unsigned int)&dword_922C40);
    v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v41 = *(_WORD *)(v40 + 0x134) + 1;
    *(_WORD *)(v40 + 308) = v41;
    if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
      KiCheckForKernelApcDelivery(v39);
  }
  v42 = 0;
  v43 = 1;
  v44 = 0;
  v45 = v61;
  v46 = *v61;
  v59 = v46;
  v47 = &off_8C62B0;
  while ( 2 )
  {
    v48 = *((unsigned __int16 *)v47 + 2);
    if ( v46 != v48 )
    {
      v43 += v48;
LABEL_93:
      ++v44;
      v47 += 4;
      if ( v44 >= 8 )
        goto LABEL_96;
      continue;
    }
    break;
  }
  v49 = v46 >> 1;
  if ( v46 >> 1 )
  {
    v50 = *((_DWORD *)v45 + 1);
    v51 = _48;
    v56 = v50 - (_DWORD)_48;
    do
    {
      *v51 = *(_WORD *)((char *)v51 + v50 - (_DWORD)_48) ^ ((v43 + 1) | ((_WORD)v43 << 8) | 0x5555);
      ++v51;
      v43 += 2;
      --v49;
    }
    while ( v49 );
    v42 = 0;
    v46 = v59;
  }
  if ( memcmp((unsigned int)_48, (unsigned int)*v47, v48) )
  {
    v45 = v61;
    goto LABEL_93;
  }
  v42 = v47[3];
LABEL_96:
  if ( v42 && (v5 >= 0 || v5 == -1073741772 || v5 == -1073741275) )
  {
    v52 = ((int (__fastcall *)(int, int, int, unsigned int *, char *))v42)(v66, v64, varg_r3, v65, v54);
    if ( v54[0] )
    {
      v5 = v52;
      v55 = v52;
    }
  }
  return v5;
}
