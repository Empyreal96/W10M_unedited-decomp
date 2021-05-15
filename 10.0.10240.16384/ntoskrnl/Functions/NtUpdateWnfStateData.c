// NtUpdateWnfStateData 
 
int __fastcall NtUpdateWnfStateData(int a1, int a2, unsigned int a3, _DWORD *a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r6
  int v8; // r3
  int v9; // r5
  unsigned int *v10; // r9
  _DWORD *v11; // r4
  int v12; // r8
  int v13; // r10
  int v14; // r0
  unsigned int v15; // r3
  int v16; // lr
  int v17; // r1
  int v18; // r1
  int v19; // r5
  char v20; // r0
  int v21; // lr
  int v22; // r2
  int v23; // r1
  int v24; // r4
  int v25; // r0
  int v26; // r3
  unsigned int v27; // r6
  int v28; // r5
  int v29; // r3
  unsigned int *v30; // r0
  unsigned int v31; // r4
  unsigned int v32; // r1
  unsigned int *v33; // r0
  unsigned int v34; // r6
  unsigned int v35; // r5
  int v36; // r0
  unsigned int v37; // r1
  __int16 v38; // r3
  int v40; // [sp+4h] [bp-9Ch]
  _DWORD *v41; // [sp+14h] [bp-8Ch] BYREF
  int v42; // [sp+18h] [bp-88h]
  int v43; // [sp+1Ch] [bp-84h]
  int v44; // [sp+20h] [bp-80h]
  int v45; // [sp+24h] [bp-7Ch]
  unsigned int *v46; // [sp+28h] [bp-78h]
  int v47; // [sp+2Ch] [bp-74h] BYREF
  int v48; // [sp+30h] [bp-70h]
  unsigned int v49; // [sp+34h] [bp-6Ch]
  int v50; // [sp+38h] [bp-68h]
  unsigned int v51; // [sp+3Ch] [bp-64h]
  unsigned int v52; // [sp+40h] [bp-60h]
  int v53; // [sp+44h] [bp-5Ch]
  __int64 v54; // [sp+48h] [bp-58h] BYREF
  _DWORD *v55; // [sp+50h] [bp-50h]
  _DWORD *v56; // [sp+54h] [bp-4Ch]
  unsigned int v57; // [sp+58h] [bp-48h]
  int v58; // [sp+5Ch] [bp-44h]
  int v59; // [sp+60h] [bp-40h]
  _DWORD v60[2]; // [sp+68h] [bp-38h] BYREF
  _DWORD _70[18]; // [sp+70h] [bp-30h] BYREF

  _70[14] = a1;
  _70[15] = a2;
  _70[17] = a4;
  v7 = a4;
  v49 = a3;
  _70[16] = a3;
  v52 = a2;
  v59 = a2;
  v44 = a5;
  v58 = a5;
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v43 = v9;
  v10 = 0;
  v46 = 0;
  v42 = 0;
  v47 = 0;
  v11 = 0;
  v41 = 0;
  v45 = 0;
  v53 = 0;
  v60[0] = 0;
  v60[1] = 0;
  v56 = v7;
  v12 = ExpCaptureWnfStateName(a1, &v54, v9);
  v48 = v12;
  if ( v12 < 0 )
  {
    v50 = v54;
    v51 = v57;
LABEL_40:
    v28 = v42;
    goto LABEL_41;
  }
  v13 = HIDWORD(v54);
  v50 = v54;
  v51 = ((unsigned int)v54 >> 4) & 3;
  v57 = v51;
  v14 = (v54 >> 6) & 0xF;
  v45 = v14;
  v53 = v14;
  if ( v9 )
  {
    if ( v49 )
    {
      v15 = MmUserProbeAddress;
      if ( v52 + v49 <= MmUserProbeAddress && v52 + v49 >= v52 )
      {
LABEL_9:
        if ( v7 )
        {
          if ( (unsigned int)v7 >= v15 )
            v7 = (_DWORD *)v15;
          _70[0] = *v7;
          _70[1] = v7[1];
          _70[2] = v7[2];
          _70[3] = v7[3];
          v7 = _70;
          v56 = _70;
        }
        goto LABEL_13;
      }
      *(_BYTE *)MmUserProbeAddress = 0;
    }
    v15 = MmUserProbeAddress;
    goto LABEL_9;
  }
LABEL_13:
  v12 = ExpWnfCaptureScopeInstanceId(v14);
  v48 = v12;
  if ( v12 < 0 )
    goto LABEL_40;
  v16 = v43;
  v17 = v44;
  if ( v43 )
  {
    v44 = 0;
    if ( v17 )
    {
      v12 = ExpWnfCheckCrossScopeAccess(v50, v13);
      if ( v12 < 0 )
        goto LABEL_40;
      v16 = v43;
    }
  }
  else
  {
    v44 = 1;
  }
  if ( !v16 )
  {
    v18 = 0;
    v19 = PsInitialSystemProcess;
    v20 = 1;
    v21 = v45;
LABEL_25:
    v22 = (int)v55;
    goto LABEL_26;
  }
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_DWORD *)(v18 + 0x74);
  v20 = 0;
  v21 = v45;
  if ( v45 != 3 )
    goto LABEL_25;
  v22 = (int)v55;
  if ( !v55 || v19 == *v55 )
  {
    v12 = -1073741811;
    goto LABEL_40;
  }
LABEL_26:
  v12 = ExpWnfResolveScopeInstance(&v47, v19, v18, v21, v22, v20);
  if ( v12 < 0 )
  {
    v28 = v47;
  }
  else
  {
    v24 = v50;
    v42 = v47;
    v25 = ExpWnfLookupNameInstance(v47, v23, v50, v13, (int *)&v41);
    v12 = v25;
    if ( v25 != -1073741772 || v51 == 3 )
    {
      v11 = v41;
      if ( v25 < 0 )
        goto LABEL_40;
      v29 = (int)v7;
      v27 = v49;
      v12 = ExpWnfValidatePubSubPreconditions(2, v41 + 9, v49, v29, v44);
      v28 = v42;
    }
    else
    {
      v12 = ExpWnfLookupPermanentName(v24);
      v10 = v46;
      if ( v12 < 0
        || (v26 = (int)v7, v27 = v49, v12 = ExpWnfValidatePubSubPreconditions(2, v46, v49, v26, v44), v12 < 0) )
      {
        v11 = v41;
        goto LABEL_40;
      }
      v40 = v19;
      v28 = v42;
      v12 = ExpWnfCreateNameInstance(v42, &v41, v24, v13, v10, v40, &v41);
      ExFreePoolWithTag((unsigned int)v10);
      v10 = 0;
      v46 = 0;
      v11 = v41;
    }
    if ( v12 >= 0 )
    {
      v12 = ExpWnfWriteStateData(v11, v52, v27, a6, a7);
      v48 = v12;
      if ( v12 >= 0 )
      {
        ExpWnfNotifyNameSubscribers((int)v11, 1, 1, v43 != 0);
        v12 = 0;
      }
    }
  }
LABEL_41:
  if ( v11 )
  {
    v30 = v11 + 1;
    __pld(v11 + 1);
    v31 = v11[1] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v32 = __ldrex(v30);
    while ( v32 == v31 && __strex(v31 - 2, v30) );
    if ( v32 != v31 )
      ExfReleaseRundownProtection((unsigned __int8 *)v30);
  }
  if ( v28 )
  {
    v33 = (unsigned int *)(v28 + 4);
    __pld((void *)(v28 + 4));
    v34 = *(_DWORD *)(v28 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v35 = __ldrex(v33);
    while ( v35 == v34 && __strex(v34 - 2, v33) );
    if ( v35 != v34 )
      ExfReleaseRundownProtection((unsigned __int8 *)v33);
  }
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  v36 = ExpWnfReleaseCapturedScopeInstanceId(v45, v60, v43);
  v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v38 = *(_WORD *)(v37 + 0x134) + 1;
  *(_WORD *)(v37 + 308) = v38;
  if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
    KiCheckForKernelApcDelivery(v36);
  return v12;
}
