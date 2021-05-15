// ExpCovQueryInformation 
 
int __fastcall ExpCovQueryInformation(unsigned int a1, unsigned int a2, unsigned int *a3, int a4)
{
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r8
  int v9; // r1
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  int v15; // r0
  int v16; // r4
  int v17; // r9
  int v18; // r1
  int v19; // r4
  int v20; // r9
  int v21; // r9
  unsigned int v22; // lr
  unsigned int v23; // r9
  unsigned int v24; // r3
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r3
  int v31; // [sp-4h] [bp-E0h]
  int v32; // [sp+0h] [bp-DCh]
  unsigned int v33; // [sp+8h] [bp-D4h]
  int v34; // [sp+14h] [bp-C8h] BYREF
  int v35; // [sp+18h] [bp-C4h]
  unsigned int v36; // [sp+1Ch] [bp-C0h]
  unsigned int v37; // [sp+20h] [bp-BCh]
  unsigned int v38; // [sp+24h] [bp-B8h]
  int v39; // [sp+28h] [bp-B4h]
  unsigned int *v40; // [sp+2Ch] [bp-B0h]
  unsigned int v41; // [sp+30h] [bp-ACh]
  int v42[2]; // [sp+34h] [bp-A8h] BYREF
  int v43; // [sp+3Ch] [bp-A0h]
  int v44; // [sp+40h] [bp-9Ch]
  _DWORD v45[2]; // [sp+44h] [bp-98h] BYREF
  bool v46; // [sp+4Ch] [bp-90h]
  int v47; // [sp+50h] [bp-8Ch] BYREF
  int v48; // [sp+54h] [bp-88h]
  int v49; // [sp+58h] [bp-84h]
  int v50; // [sp+5Ch] [bp-80h]
  int v51; // [sp+60h] [bp-7Ch]
  int v52; // [sp+64h] [bp-78h]
  int v53; // [sp+68h] [bp-74h]
  int v54; // [sp+6Ch] [bp-70h]
  unsigned int v55; // [sp+70h] [bp-6Ch]
  int v56; // [sp+74h] [bp-68h] BYREF
  int v57; // [sp+7Ch] [bp-60h] BYREF
  _DWORD _AC[18]; // [sp+ACh] [bp-30h] BYREF

  _AC[14] = a1;
  _AC[16] = a3;
  _AC[17] = a4;
  v36 = a2;
  _AC[15] = a2;
  v37 = a1;
  v38 = a1;
  v40 = a3;
  v35 = 0;
  LOWORD(v34) = 0;
  v48 = 0;
  v6 = 0;
  LOWORD(v47) = 0;
  v54 = 0;
  v55 = 52;
  v45[1] = a2;
  if ( !ExCovMaxPagedPoolToUse )
    return -1073741790;
  if ( a3 )
    *a3 = 52;
  if ( a2 < 0x34 )
    return -1073741820;
  v8 = a1 + 28;
  v9 = a1;
  if ( a1 >= MmUserProbeAddress )
    v9 = MmUserProbeAddress;
  memmove((int)&v56, v9, 0x34u);
  v10 = v56;
  v46 = v56 == 1;
  v7 = ExpCovReadRequestBuffer(&v57, &v34, _AC, v42);
  if ( v7 < 0 )
  {
    v29 = v35;
    goto LABEL_62;
  }
  v53 = v42[0];
  v49 = _AC[0];
  v50 = _AC[1];
  v51 = _AC[2];
  v52 = _AC[3];
  v31 = v35;
  if ( v35 )
  {
    v7 = RtlDuplicateUnicodeString(1, (int)&v34, (int)&v47);
    if ( v7 < 0 )
    {
LABEL_61:
      v29 = v31;
      goto LABEL_62;
    }
  }
  v6 = ExAllocatePoolWithTag(512, a2, 1920364355);
  v45[0] = v6;
  if ( !v6 )
  {
    v7 = -1073741670;
    goto LABEL_61;
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  v12 = MmEnumerateSystemImages(ExpCovQueryInfoCallBack, (int)v45);
  v7 = v12;
  if ( v12 < 0 )
  {
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    goto LABEL_61;
  }
  v33 = v55;
  v41 = v55;
  v15 = v54;
  v32 = v54;
  v39 = v54;
  if ( a2 < v55 )
    goto LABEL_25;
  if ( (v45[0] - v6) / 24 )
  {
    v16 = v6;
    while ( v15 )
    {
      v17 = *(_DWORD *)(v16 + 16) + v8 + 24;
      *(_DWORD *)v8 = *(_DWORD *)v16;
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v16 + 4);
      *(_DWORD *)(v8 + 16) = *(_DWORD *)(v16 + 16);
      memmove(v8 + 20, v16 + 20, *(_DWORD *)(v16 + 16));
      *(_WORD *)(v8 + 8) = *(_WORD *)(v16 + 8);
      *(_WORD *)(v8 + 10) = *(_WORD *)(v16 + 10);
      *(_DWORD *)(v8 + 12) = v17;
      memmove(v17, *(_DWORD *)(v16 + 12), *(unsigned __int16 *)(v16 + 8));
      v8 += *(_DWORD *)v16;
      v16 += *(_DWORD *)v16;
      v15 = --v54;
    }
    v10 = v56;
    goto LABEL_27;
  }
  if ( a2 < v55 )
LABEL_25:
    v7 = -1073741820;
LABEL_27:
  if ( v10 == 1 )
    ExfAcquirePushLockExclusive((int)&ExpCovPushLock);
  else
    ExfAcquirePushLockShared((int)&ExpCovPushLock);
  v19 = ExpCovUnloadedModuleList;
LABEL_31:
  v20 = v32;
  while ( (int *)v19 != &ExpCovUnloadedModuleList )
  {
    v43 = v19;
    v42[1] = v19;
    v21 = *(_DWORD *)(v19 + 28);
    if ( !v21 )
    {
      v19 = *(_DWORD *)v19;
      goto LABEL_31;
    }
    if ( !ExpCovIsUnLoadedModulePresent(v19, v42[0], (unsigned __int16 *)&v34, (unsigned __int8 *)_AC) )
      goto LABEL_36;
    if ( v56 == 1 )
      v22 = *(_DWORD *)(v19 + 24);
    else
      v22 = *(_DWORD *)(v19 + 24) - *(_DWORD *)(v21 + 28);
    if ( v22 >= 0xFFFFFFE8 || (v23 = *(unsigned __int16 *)(v19 + 16) + v22 + 24, v23 < 0x18) )
      v23 = -1;
    v24 = v23 + v33;
    if ( v23 + v33 < v33 )
    {
      DbgPrintEx(126, 2, (int)"COV: Overflow when calculating total required length for %wZ\n", v19 + 16);
LABEL_36:
      v20 = v32;
      goto LABEL_37;
    }
    v33 += v23;
    v41 = v24;
    if ( v36 >= v24 )
    {
      v44 = v22 + v8 + 24;
      *(_DWORD *)v8 = v23;
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)(v8 + 16) = v22;
      memmove(v8 + 20, *(_DWORD *)(v19 + 28), v22);
      *(_WORD *)(v8 + 8) = *(_WORD *)(v19 + 16);
      *(_WORD *)(v8 + 10) = *(_WORD *)(v19 + 16);
      v25 = v44;
      *(_DWORD *)(v8 + 12) = v44;
      memmove(v25, *(_DWORD *)(v19 + 20), *(unsigned __int16 *)(v19 + 16));
      v8 += v23;
      v18 = v43;
      if ( v56 == 1 )
      {
        v19 = *(_DWORD *)(v19 + 4);
        ExpCovDeleteUnloadedModuleEntry(v43);
      }
    }
    else
    {
      if ( a3 )
        *a3 = v24;
      v7 = -1073741820;
    }
    v20 = v32 + 1;
    v32 = v20;
    v39 = v20;
LABEL_37:
    v19 = *(_DWORD *)v19;
  }
  v26 = ExfReleasePushLock(&ExpCovPushLock, v18);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    KiCheckForKernelApcDelivery(v26);
  if ( a3 )
    *a3 = v33;
  *(_DWORD *)(v37 + 4) = v20;
  v29 = v31;
LABEL_62:
  if ( v29 )
    RtlFreeAnsiString(&v34);
  if ( v48 )
    RtlFreeAnsiString(&v47);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v7;
}
