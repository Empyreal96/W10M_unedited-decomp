// NtQueryWnfStateData 
 
int __fastcall NtQueryWnfStateData(int a1, _DWORD *a2, int a3, _DWORD *a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r5
  int v10; // r4
  int v11; // r8
  _DWORD *v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r9
  _DWORD *v15; // r2
  int v16; // r10
  int v17; // r1
  int v18; // r0
  int v19; // r2
  int v20; // r1
  char v21; // r3
  int v22; // r4
  int v23; // r0
  int v24; // r3
  unsigned int *v25; // r6
  unsigned int *v26; // r10
  _DWORD *v27; // r3
  int v28; // r6
  unsigned int *v29; // r0
  unsigned int v30; // r4
  unsigned int v31; // r1
  unsigned int *v32; // r0
  unsigned int v33; // r6
  unsigned int v34; // r5
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v39; // [sp+10h] [bp-A8h]
  int v40; // [sp+14h] [bp-A4h] BYREF
  char v41; // [sp+18h] [bp-A0h]
  unsigned int *v42; // [sp+1Ch] [bp-9Ch]
  int v43; // [sp+20h] [bp-98h]
  int v44; // [sp+24h] [bp-94h]
  unsigned int *v45; // [sp+28h] [bp-90h]
  int v46; // [sp+2Ch] [bp-8Ch]
  int v47; // [sp+30h] [bp-88h]
  int v48; // [sp+34h] [bp-84h] BYREF
  int v49; // [sp+38h] [bp-80h]
  int v50; // [sp+3Ch] [bp-7Ch]
  _DWORD *v51; // [sp+40h] [bp-78h]
  int v52; // [sp+44h] [bp-74h]
  int v53; // [sp+48h] [bp-70h]
  int v54; // [sp+4Ch] [bp-6Ch]
  _DWORD v55[2]; // [sp+50h] [bp-68h] BYREF
  _DWORD *v56; // [sp+58h] [bp-60h]
  unsigned int v57; // [sp+5Ch] [bp-5Ch]
  _DWORD *v58; // [sp+60h] [bp-58h]
  int v59; // [sp+64h] [bp-54h]
  int v60; // [sp+68h] [bp-50h]
  _DWORD *v61; // [sp+6Ch] [bp-4Ch]
  _DWORD *v62; // [sp+70h] [bp-48h]
  _DWORD v63[4]; // [sp+78h] [bp-40h] BYREF
  _DWORD v64[12]; // [sp+88h] [bp-30h] BYREF

  v56 = a4;
  v44 = a3;
  v49 = a3;
  v61 = a4;
  v54 = a5;
  v63[2] = a5;
  v51 = a6;
  v62 = a6;
  v8 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v43 = v9;
  v41 = v9;
  v42 = 0;
  v45 = 0;
  v39 = 0;
  v48 = 0;
  v10 = 0;
  v40 = 0;
  v46 = 0;
  v53 = 0;
  v63[0] = 0;
  v63[1] = 0;
  v58 = a2;
  v11 = ExpCaptureWnfStateName(a1, v55, v9);
  v47 = v11;
  if ( v11 < 0 )
  {
    v50 = v55[0];
    v52 = v59;
LABEL_45:
    v26 = v42;
    goto LABEL_46;
  }
  if ( v9 )
  {
    if ( a2 )
    {
      if ( (unsigned int)a2 >= MmUserProbeAddress )
        a2 = (_DWORD *)MmUserProbeAddress;
      v64[0] = *a2;
      v64[1] = a2[1];
      v64[2] = a2[2];
      v64[3] = a2[3];
      a2 = v64;
      v58 = v64;
    }
    v12 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
    v13 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v13 = (unsigned int *)MmUserProbeAddress;
    v14 = *v13;
    v57 = *v13;
    v15 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
    if ( v14 )
      ProbeForWrite(v54, v14, 1);
  }
  else
  {
    v14 = *a6;
    v57 = *a6;
  }
  v50 = v55[0];
  v16 = v55[1];
  v52 = (v55[0] >> 4) & 3;
  v59 = v52;
  v46 = (v55[0] >> 6) & 0xF;
  v53 = v46;
  v11 = ExpWnfCaptureScopeInstanceId(v46);
  v47 = v11;
  if ( v11 < 0 )
    goto LABEL_45;
  v17 = v43;
  v18 = v44;
  if ( v43 )
  {
    v44 = 0;
    if ( v18 )
    {
      v11 = ExpWnfCheckCrossScopeAccess(v50, v16);
      if ( v11 < 0 )
        goto LABEL_45;
      v17 = v43;
    }
  }
  else
  {
    v44 = 1;
  }
  if ( v17 )
  {
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_DWORD *)(v19 + 0x74);
    v21 = 0;
  }
  else
  {
    v19 = 0;
    v20 = PsInitialSystemProcess;
    v21 = 1;
  }
  v49 = v20;
  v11 = ExpWnfResolveScopeInstance(&v48, v20, v19, v46, v60, v21);
  if ( v11 < 0 )
  {
    v28 = v48;
    v26 = v42;
    goto LABEL_47;
  }
  v22 = v50;
  v39 = v48;
  v23 = ExpWnfLookupNameInstance(v48, v48, v50, v16, &v40);
  v11 = v23;
  if ( v23 != -1073741772 || v52 == 3 )
  {
    v10 = v40;
    if ( v23 < 0 )
      goto LABEL_45;
    v11 = ExpWnfValidatePubSubPreconditions(1, (unsigned int *)(v40 + 36), 0, (int)a2, v44);
    if ( v11 < 0 )
      goto LABEL_45;
  }
  else
  {
    v11 = ExpWnfLookupPermanentName(v22);
    if ( v11 < 0 )
    {
      v26 = v45;
      v10 = v40;
LABEL_46:
      v28 = v39;
      goto LABEL_47;
    }
    v24 = (int)a2;
    v25 = v45;
    v42 = v45;
    v11 = ExpWnfValidatePubSubPreconditions(1, v45, 0, v24, v44);
    if ( v11 < 0 )
    {
      v10 = v40;
      goto LABEL_45;
    }
    if ( (v22 & 0x400) != 0 )
    {
      v11 = ExpWnfCreateNameInstance(v39, &v40, v22, v16, v25, v49, &v40);
      ExFreePoolWithTag((unsigned int)v25);
      v26 = 0;
      v45 = 0;
      v10 = v40;
      if ( v11 < 0 )
        goto LABEL_46;
      goto LABEL_40;
    }
    v10 = v40;
  }
  v26 = v42;
LABEL_40:
  v27 = v51;
  if ( v10 )
  {
    v11 = ExpWnfReadStateData(v10, v56, v54, v14, v51);
  }
  else
  {
    v11 = 0;
    *v56 = 0;
    *v27 = 0;
  }
  v47 = v11;
  v28 = v39;
LABEL_47:
  if ( v10 )
  {
    v29 = (unsigned int *)(v10 + 4);
    __pld((void *)(v10 + 4));
    v30 = *(_DWORD *)(v10 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v31 = __ldrex(v29);
    while ( v31 == v30 && __strex(v30 - 2, v29) );
    if ( v31 != v30 )
      ExfReleaseRundownProtection((unsigned __int8 *)v29);
  }
  if ( v28 )
  {
    v32 = (unsigned int *)(v28 + 4);
    __pld((void *)(v28 + 4));
    v33 = *(_DWORD *)(v28 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v34 = __ldrex(v32);
    while ( v34 == v33 && __strex(v33 - 2, v32) );
    if ( v34 != v33 )
      ExfReleaseRundownProtection((unsigned __int8 *)v32);
  }
  if ( v26 )
    ExFreePoolWithTag((unsigned int)v26);
  v35 = ExpWnfReleaseCapturedScopeInstanceId(v46, v63, v43);
  v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v37 = *(_WORD *)(v36 + 0x134) + 1;
  *(_WORD *)(v36 + 308) = v37;
  if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
    KiCheckForKernelApcDelivery(v35);
  return v11;
}
