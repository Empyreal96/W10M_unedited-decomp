// NtQueryWnfStateNameInformation 
 
int __fastcall NtQueryWnfStateNameInformation(int *a1, int a2, int *a3, int *a4, unsigned int a5)
{
  int v7; // r4
  _DWORD *v8; // r4
  int v9; // r6
  int v10; // r9
  __int64 v11; // r0
  int v12; // lr
  int v13; // r9
  int v14; // r5
  int v15; // r10
  int v16; // r2
  int v17; // r1
  char v18; // r0
  int v19; // r3
  int v20; // r4
  int v21; // r0
  unsigned int v22; // r10
  int v23; // r3
  int *v24; // r1
  unsigned int *v25; // r0
  unsigned int v26; // r4
  unsigned int v27; // r1
  unsigned int *v28; // r0
  unsigned int v29; // r5
  unsigned int v30; // r4
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v35; // [sp+4h] [bp-74h]
  int v36; // [sp+8h] [bp-70h]
  int v38; // [sp+10h] [bp-68h]
  int v39; // [sp+14h] [bp-64h]
  _DWORD *v40; // [sp+18h] [bp-60h] BYREF
  int v41; // [sp+1Ch] [bp-5Ch]
  unsigned int v42; // [sp+20h] [bp-58h] BYREF
  int v43; // [sp+24h] [bp-54h]
  int v44; // [sp+28h] [bp-50h]
  int v45; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int v46; // [sp+30h] [bp-48h] BYREF
  int v47; // [sp+34h] [bp-44h]
  unsigned int v48; // [sp+38h] [bp-40h]
  int v49; // [sp+3Ch] [bp-3Ch]
  int v50; // [sp+40h] [bp-38h]
  int v51; // [sp+44h] [bp-34h]
  int v52; // [sp+48h] [bp-30h] BYREF
  int v53; // [sp+4Ch] [bp-2Ch]
  int _50[16]; // [sp+50h] [bp-28h] BYREF

  _50[12] = (int)a1;
  _50[15] = (int)a4;
  _50[14] = (int)a3;
  _50[13] = a2;
  v7 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
  v38 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  LOBYTE(v36) = v38;
  v39 = 0;
  v42 = 0;
  v43 = 0;
  v45 = 0;
  v8 = 0;
  v40 = 0;
  v44 = 0;
  v49 = 0;
  _50[0] = 0;
  _50[1] = 0;
  v9 = ExpCaptureWnfStateName(a1, &v46, v38);
  v41 = v9;
  if ( v9 < 0 )
  {
    v50 = v47;
    v48 = v46;
    v51 = v53;
LABEL_57:
    v22 = v39;
    goto LABEL_58;
  }
  v48 = v46;
  v50 = v47;
  v51 = (v46 >> 4) & 3;
  v53 = v51;
  v44 = (v46 >> 6) & 0xF;
  v49 = v44;
  v10 = v38;
  v9 = ExpWnfCaptureScopeInstanceId(v44, a3, v38, &v52, _50, v35, v36, (int)a4, v38, 0, (int)v40);
  v41 = v9;
  if ( v9 < 0 )
    goto LABEL_57;
  if ( a2 < 0 || a2 > 2 )
  {
    v9 = -1073741821;
    v41 = -1073741821;
    goto LABEL_57;
  }
  if ( a5 < 4 )
  {
    v9 = -1073741811;
    v41 = -1073741811;
    goto LABEL_57;
  }
  if ( v10 )
    ProbeForWrite(a4, a5, 4);
  LODWORD(v11) = v48;
  v12 = v38;
  if ( a2 )
  {
    v13 = 0;
  }
  else
  {
    v13 = 1;
    if ( a3 )
    {
      v9 = -1073741811;
      goto LABEL_57;
    }
  }
  if ( v38 && a2 )
  {
    v14 = 0;
    if ( a3 )
    {
      HIDWORD(v11) = v50;
      v9 = ExpWnfCheckCrossScopeAccess(v11);
      if ( v9 < 0 )
        goto LABEL_57;
      v12 = v38;
    }
  }
  else
  {
    v14 = 1;
  }
  v15 = 0;
  if ( !v14 && (a2 == 1 || a2 == 2) )
    v15 = 2;
  v16 = 0;
  if ( v12 )
  {
    v18 = 0;
    v19 = __mrc(15, 0, 13, 0, 3);
    if ( !v13 )
      v16 = v19 & 0xFFFFFFC0;
    v17 = *(_DWORD *)((v19 & 0xFFFFFFC0) + 0x74);
  }
  else
  {
    v17 = PsInitialSystemProcess;
    v18 = 1;
  }
  v9 = ExpWnfResolveScopeInstance(&v45, v17, v16, v44, v52, v18);
  if ( v9 < 0 )
  {
    v43 = v45;
    goto LABEL_57;
  }
  v20 = v50;
  v43 = v45;
  v21 = ExpWnfLookupNameInstance(v45, v45, v48, v50, (int *)&v40);
  v9 = v21;
  if ( v21 != -1073741772 || v51 == 3 )
  {
    if ( v21 >= 0 )
    {
      v8 = v40;
      if ( !v14 )
      {
        v9 = ExpWnfCheckCallerAccess(v40[11], v15);
        if ( v9 < 0 )
          goto LABEL_57;
      }
      goto LABEL_42;
    }
LABEL_55:
    v8 = v40;
    goto LABEL_57;
  }
  v9 = ExpWnfLookupPermanentName(__SPAIR64__(v20, v48), &v42, v51);
  if ( v9 < 0 )
  {
    v22 = v42;
    v8 = v40;
LABEL_58:
    v24 = a4;
    goto LABEL_59;
  }
  if ( v14 )
  {
    v22 = v42;
    v8 = v40;
    goto LABEL_43;
  }
  v39 = v42;
  v9 = ExpWnfCheckCallerAccess(*(_DWORD *)(v42 + 8), v15);
  if ( v9 < 0 )
    goto LABEL_55;
  v8 = v40;
LABEL_42:
  v22 = v39;
LABEL_43:
  if ( !a2 )
  {
    v24 = a4;
    *a4 = 1;
    goto LABEL_54;
  }
  if ( a2 == 1 )
  {
    if ( v8 && v8[22] )
      goto LABEL_50;
LABEL_51:
    v23 = 0;
    goto LABEL_52;
  }
  if ( v8 && v8[23] )
    goto LABEL_51;
LABEL_50:
  v23 = 1;
LABEL_52:
  v24 = a4;
  *a4 = v23;
LABEL_54:
  v9 = 0;
  v41 = 0;
LABEL_59:
  if ( v9 == -1073741772 && !a2 )
  {
    *v24 = 0;
    v9 = 0;
    v41 = 0;
  }
  if ( v8 )
  {
    v25 = v8 + 1;
    __pld(v8 + 1);
    v26 = v8[1] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex(v25);
    while ( v27 == v26 && __strex(v26 - 2, v25) );
    if ( v27 != v26 )
      ExfReleaseRundownProtection((unsigned __int8 *)v25);
  }
  if ( v43 )
  {
    v28 = (unsigned int *)(v43 + 4);
    __pld((void *)(v43 + 4));
    v29 = *(_DWORD *)(v43 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v30 = __ldrex(v28);
    while ( v30 == v29 && __strex(v29 - 2, v28) );
    if ( v30 != v29 )
      ExfReleaseRundownProtection((unsigned __int8 *)v28);
  }
  if ( v22 )
    ExFreePoolWithTag(v22);
  v31 = ExpWnfReleaseCapturedScopeInstanceId(v44, _50, v38);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x134) + 1;
  *(_WORD *)(v32 + 308) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
    KiCheckForKernelApcDelivery(v31);
  return v9;
}
