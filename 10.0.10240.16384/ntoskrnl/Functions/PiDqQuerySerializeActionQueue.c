// PiDqQuerySerializeActionQueue 
 
int __fastcall PiDqQuerySerializeActionQueue(_DWORD *a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r5
  unsigned int v7; // r2
  unsigned __int8 *v8; // r4
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r2
  BOOL v12; // r8
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r0
  int v20; // r3
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r8
  unsigned int v24; // r2
  int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  _DWORD *v31; // r2
  unsigned int v32; // r2
  unsigned __int8 *v33; // r4
  int v34; // r0
  int v35; // r8
  unsigned int v36; // r2
  int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r2
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned int v43; // r2
  unsigned __int8 *v44; // r4
  int v45; // r0
  int v46; // r8
  unsigned int v47; // r2
  int **v48; // r2
  int v49; // r1
  unsigned int v50; // r0
  unsigned int v51; // r2
  int v52; // r0
  unsigned int v53; // r1
  int v54; // r3
  int *v55; // r8
  int v56; // r1
  int v57; // r1
  unsigned int v58; // r0
  unsigned int v59; // r2
  int v60; // r0
  unsigned int v61; // r1
  __int16 v62; // r3
  int *v64; // [sp+0h] [bp-50h]
  int v65; // [sp+4h] [bp-4Ch]
  int v66; // [sp+8h] [bp-48h] BYREF
  _DWORD *v67; // [sp+Ch] [bp-44h]
  int v68; // [sp+10h] [bp-40h]
  int v69; // [sp+18h] [bp-38h]
  int v70; // [sp+1Ch] [bp-34h]
  int v71; // [sp+20h] [bp-30h]
  unsigned int v72; // [sp+24h] [bp-2Ch]
  int v73; // [sp+28h] [bp-28h]
  char v74; // [sp+2Ch] [bp-24h]
  char v75; // [sp+2Dh] [bp-23h]
  _DWORD *varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  _DWORD *varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  v67 = a4;
  varg_r3 = a4;
  varg_r0 = a1;
  v6 = 0;
  v68 = 0;
  v66 = 0;
  v69 = a2;
  v70 = a3;
  v71 = 16;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned __int8 *)(a1 + 8);
  v9 = KeAbPreAcquire((unsigned int)(a1 + 8), 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v9, (unsigned int)v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = (a1[29] & 0x20) != 0;
  __pld(v8);
  v13 = *(_DWORD *)v8;
  if ( (*(_DWORD *)v8 & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  else
    v14 = v13 - 16;
  if ( (v13 & 2) != 0 )
    goto LABEL_15;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v8);
  while ( v15 == v13 && __strex(v14, (unsigned int *)v8) );
  if ( v15 != v13 )
LABEL_15:
    ExfReleasePushLock(v8, v13);
  v16 = KeAbPostRelease((unsigned int)v8);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  if ( !v12 )
  {
    v19 = PiDqQueryGetObjectManager(a1);
    v6 = PiDqObjectManagerEnumerateAndRegisterQuery(v19, a1);
  }
  if ( v6 < 0
    || (v6 = MesEncodeIncrementalHandleCreate_0(), v6 < 0)
    || ((a1[29] & 2) == 0 ? (v20 = 0) : (v20 = 2), v65 = v20, v64 = 0, v6 = MesIncrementalHandleReset_0(), v6 < 0) )
  {
LABEL_113:
    v31 = a5;
    goto LABEL_114;
  }
  *v67 = v71;
  *a5 = 0;
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v21 + 308);
  v22 = KeAbPreAcquire((unsigned int)v8, 0, 0);
  v23 = v22;
  do
    v24 = __ldrex(v8);
  while ( __strex(v24 | 1, v8) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v22, (unsigned int)v8);
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  v66 = a1[24];
  a1[24] = 0;
  __pld(v8);
  v25 = *(_DWORD *)v8;
  if ( (*(_DWORD *)v8 & 0xFFFFFFF0) <= 0x10 )
    v26 = 0;
  else
    v26 = v25 - 16;
  if ( (v25 & 2) != 0 )
    goto LABEL_42;
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)v8);
  while ( v27 == v25 && __strex(v26, (unsigned int *)v8) );
  if ( v27 != v25 )
LABEL_42:
    ExfReleasePushLock(v8, v25);
  v28 = KeAbPostRelease((unsigned int)v8);
  v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v30 = *(_WORD *)(v29 + 0x134) + 1;
  *(_WORD *)(v29 + 308) = v30;
  if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
    KiCheckForKernelApcDelivery(v28);
  while ( !v66 )
  {
LABEL_73:
    v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v43 + 308);
    v44 = (unsigned __int8 *)(a1 + 8);
    v45 = KeAbPreAcquire((unsigned int)(a1 + 8), 0, 0);
    v46 = v45;
    do
      v47 = __ldrex(v44);
    while ( __strex(v47 | 1, v44) );
    __dmb(0xBu);
    if ( (v47 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 8, v45, (unsigned int)(a1 + 8));
    if ( v46 )
      *(_BYTE *)(v46 + 14) |= 1u;
    v48 = (int **)(a1 + 25);
    if ( (_DWORD *)a1[25] == a1 + 25 )
    {
      __pld(v44);
      v49 = *(_DWORD *)v44;
      if ( (*(_DWORD *)v44 & 0xFFFFFFF0) <= 0x10 )
        v50 = 0;
      else
        v50 = v49 - 16;
      if ( (v49 & 2) != 0 )
        goto LABEL_88;
      __dmb(0xBu);
      do
        v51 = __ldrex((unsigned int *)v44);
      while ( v51 == v49 && __strex(v50, (unsigned int *)v44) );
      if ( v51 != v49 )
LABEL_88:
        ExfReleasePushLock(a1 + 8, v49);
      v52 = KeAbPostRelease((unsigned int)(a1 + 8));
      v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v54 = (__int16)(*(_WORD *)(v53 + 0x134) + 1);
      *(_WORD *)(v53 + 308) = v54;
      if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
        KiCheckForKernelApcDelivery(v52);
      goto LABEL_113;
    }
    v55 = *v48;
    v56 = **v48;
    if ( (int **)(*v48)[1] != v48 || *(int **)(v56 + 4) != v55 )
      __fastfail(3u);
    *v48 = (int *)v56;
    *(_DWORD *)(v56 + 4) = v48;
    --a1[27];
    __pld(v44);
    v57 = *(_DWORD *)v44;
    if ( (*(_DWORD *)v44 & 0xFFFFFFF0) <= 0x10 )
      v58 = 0;
    else
      v58 = v57 - 16;
    if ( (v57 & 2) != 0 )
      goto LABEL_103;
    __dmb(0xBu);
    do
      v59 = __ldrex((unsigned int *)v44);
    while ( v59 == v57 && __strex(v58, (unsigned int *)v44) );
    if ( v59 != v57 )
LABEL_103:
      ExfReleasePushLock(a1 + 8, v57);
    v60 = KeAbPostRelease((unsigned int)(a1 + 8));
    v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v62 = *(_WORD *)(v61 + 0x134) + 1;
    *(_WORD *)(v61 + 308) = v62;
    if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
      KiCheckForKernelApcDelivery(v60);
    v6 = PiDqActionDataCreate(a1[3], a1 + 4, v55, &v66, v64, v65);
    PiDqQueryActionQueueEntryFree(v55);
    if ( v6 == -1073741772 )
      v6 = 0;
    if ( v6 < 0 )
      goto LABEL_113;
  }
  v64 = &v66;
  NdrMesTypeEncode2_0();
  if ( v75 )
  {
    v6 = -1073741819;
    v31 = a5;
    goto LABEL_115;
  }
  if ( !v74 )
  {
    *v67 = v71;
    PiDqActionDataFree(v66);
    v66 = 0;
    goto LABEL_73;
  }
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v32 + 308);
  v33 = (unsigned __int8 *)(a1 + 8);
  v34 = KeAbPreAcquire((unsigned int)(a1 + 8), 0, 0);
  v35 = v34;
  do
    v36 = __ldrex(v33);
  while ( __strex(v36 | 1, v33) );
  __dmb(0xBu);
  if ( (v36 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 8, v34, (unsigned int)(a1 + 8));
  if ( v35 )
    *(_BYTE *)(v35 + 14) |= 1u;
  a1[24] = v66;
  v66 = 0;
  __pld(v33);
  v37 = *(_DWORD *)v33;
  if ( (*(_DWORD *)v33 & 0xFFFFFFF0) <= 0x10 )
    v38 = 0;
  else
    v38 = v37 - 16;
  if ( (v37 & 2) != 0 )
    goto LABEL_67;
  __dmb(0xBu);
  do
    v39 = __ldrex((unsigned int *)v33);
  while ( v39 == v37 && __strex(v38, (unsigned int *)v33) );
  if ( v39 != v37 )
LABEL_67:
    ExfReleasePushLock(a1 + 8, v37);
  v40 = KeAbPostRelease((unsigned int)(a1 + 8));
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42 = *(_WORD *)(v41 + 0x134) + 1;
  *(_WORD *)(v41 + 308) = v42;
  if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
    KiCheckForKernelApcDelivery(v40);
  v31 = a5;
  *a5 = v73 + 16;
LABEL_114:
  if ( v6 < 0 )
  {
LABEL_115:
    *v67 = 0;
    *v31 = 0;
  }
  if ( v66 )
    PiDqActionDataFree(v66);
  if ( v72 )
    ExFreePoolWithTag(v72);
  if ( v68 )
    MesHandleFree_0();
  return v6;
}
