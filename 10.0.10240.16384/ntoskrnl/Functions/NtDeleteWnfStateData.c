// NtDeleteWnfStateData 
 
int __fastcall NtDeleteWnfStateData(int *a1, int *a2)
{
  int v2; // r3
  int v3; // r5
  int v4; // r6
  int v5; // r10
  int v6; // r9
  unsigned int v7; // r8
  int v8; // r1
  int v9; // r4
  int v10; // r2
  int *v11; // r1
  char v12; // r3
  int v13; // r1
  int v14; // r5
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r1
  int v19; // r2
  int v20; // r4
  int v21; // r9
  unsigned int v22; // r10
  int v23; // r4
  int v24; // r0
  unsigned int *v25; // r0
  unsigned int v26; // r4
  unsigned int v27; // r1
  unsigned int *v28; // r0
  unsigned int v29; // r5
  unsigned int v30; // r4
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v35; // [sp+4h] [bp-8Ch]
  int v36; // [sp+8h] [bp-88h]
  int v37; // [sp+Ch] [bp-84h]
  int v38; // [sp+10h] [bp-80h]
  int v39; // [sp+14h] [bp-7Ch]
  int v40; // [sp+18h] [bp-78h]
  int v41; // [sp+1Ch] [bp-74h]
  int v42; // [sp+20h] [bp-70h] BYREF
  int v43; // [sp+24h] [bp-6Ch]
  int *v44; // [sp+28h] [bp-68h]
  char v45; // [sp+2Ch] [bp-64h]
  int v46; // [sp+30h] [bp-60h] BYREF
  int v47; // [sp+34h] [bp-5Ch] BYREF
  unsigned int v48; // [sp+38h] [bp-58h] BYREF
  unsigned int v49; // [sp+3Ch] [bp-54h] BYREF
  int v50; // [sp+40h] [bp-50h]
  unsigned int v51[4]; // [sp+48h] [bp-48h] BYREF
  int v52; // [sp+58h] [bp-38h]
  unsigned int v53; // [sp+5Ch] [bp-34h]
  int v54; // [sp+60h] [bp-30h]
  int _68[14]; // [sp+68h] [bp-28h] BYREF

  _68[12] = (int)a1;
  v44 = a2;
  _68[13] = (int)a2;
  v2 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v2 & 0xFFFFFFC0) + 0x134);
  v43 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v45 = v43;
  v40 = 0;
  v48 = 0;
  v41 = 0;
  v47 = 0;
  v3 = 0;
  v42 = 0;
  v50 = 0;
  v52 = 0;
  _68[0] = 0;
  _68[1] = 0;
  v4 = ExpCaptureWnfStateName(a1, v51, v43);
  v54 = v4;
  if ( v4 < 0 )
  {
    v49 = v53;
LABEL_35:
    v22 = v40;
    goto LABEL_36;
  }
  v5 = v51[0];
  v6 = v51[1];
  v7 = (v51[0] >> 4) & 3;
  v49 = v7;
  v53 = v7;
  v50 = (v51[0] >> 6) & 0xF;
  v52 = v50;
  v4 = ExpWnfCaptureScopeInstanceId(v50, v44, v43, &v46, _68, v35, v36, v37, v38, v39, 0);
  v54 = v4;
  if ( v4 < 0 )
    goto LABEL_35;
  v8 = v43;
  if ( v43 )
  {
    v9 = 0;
    if ( v44 )
    {
      v4 = ExpWnfCheckCrossScopeAccess(__SPAIR64__(v6, v5));
      if ( v4 < 0 )
        goto LABEL_35;
      v8 = v43;
    }
  }
  else
  {
    v9 = 1;
  }
  if ( v8 )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(int **)(v10 + 0x74);
    v12 = 0;
  }
  else
  {
    v10 = 0;
    v11 = (int *)PsInitialSystemProcess;
    v12 = 1;
  }
  v44 = v11;
  v4 = ExpWnfResolveScopeInstance(&v47, (int)v11, v10, v50, v46, v12);
  if ( v4 < 0 )
  {
    v21 = v47;
    v22 = v40;
  }
  else
  {
    v14 = v47;
    v41 = v47;
    v15 = ExpWnfLookupNameInstance(v47, v13, v5, v6, &v42);
    v4 = v15;
    if ( v15 != -1073741772 || v7 == 3 )
    {
      v3 = v42;
      if ( v15 >= 0 )
      {
        if ( v9
          || (v23 = *(_DWORD *)(v42 + 44),
              SeCaptureSubjectContext(v51, v16, v17, -1073741772),
              SeAccessCheck(v23, (int)v51, 0, 2, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)&v47, (int)&v46),
              SeReleaseSubjectContext((int)v51),
              v4 = v46,
              v46 >= 0) )
        {
          if ( v49 != 3 || *(int **)(v3 + 84) == v44 )
          {
            if ( (v5 & 0x400) == 0
              || (v24 = ExpWnfDeletePermanentStateData(v41), v4 = v24, v24 == -1073741772)
              || v24 >= 0 )
            {
              ExpWnfDeleteStateData(v3);
              v4 = 0;
            }
          }
          else
          {
            v4 = -1073741790;
          }
        }
      }
      goto LABEL_35;
    }
    v4 = ExpWnfLookupPermanentName(__SPAIR64__(v6, v5), &v48, -1073741772);
    if ( v4 < 0 )
    {
      v22 = v48;
      v3 = v42;
LABEL_36:
      v21 = v41;
      goto LABEL_37;
    }
    v40 = v48;
    if ( !v9 )
    {
      v20 = *(_DWORD *)(v48 + 8);
      SeCaptureSubjectContext(v51, v18, v19, v48);
      SeAccessCheck(v20, (int)v51, 0, 2, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)&v49, (int)&v46);
      SeReleaseSubjectContext((int)v51);
      v4 = v46;
      if ( v46 < 0 )
        goto LABEL_18;
    }
    if ( (v5 & 0x400) == 0 )
    {
      v4 = 0;
LABEL_18:
      v3 = v42;
      goto LABEL_35;
    }
    v4 = ExpWnfDeletePermanentStateData(v14);
    v3 = v42;
    v21 = v41;
    v22 = v40;
    if ( v4 == -1073741772 )
      v4 = 0;
  }
LABEL_37:
  if ( v3 )
  {
    v25 = (unsigned int *)(v3 + 4);
    __pld((void *)(v3 + 4));
    v26 = *(_DWORD *)(v3 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex(v25);
    while ( v27 == v26 && __strex(v26 - 2, v25) );
    if ( v27 != v26 )
      ExfReleaseRundownProtection((unsigned __int8 *)v25);
  }
  if ( v21 )
  {
    v28 = (unsigned int *)(v21 + 4);
    __pld((void *)(v21 + 4));
    v29 = *(_DWORD *)(v21 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v30 = __ldrex(v28);
    while ( v30 == v29 && __strex(v29 - 2, v28) );
    if ( v30 != v29 )
      ExfReleaseRundownProtection((unsigned __int8 *)v28);
  }
  if ( v22 )
    ExFreePoolWithTag(v22);
  v31 = ExpWnfReleaseCapturedScopeInstanceId(v50, _68, v43);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x134) + 1;
  *(_WORD *)(v32 + 308) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
    KiCheckForKernelApcDelivery(v31);
  return v4;
}
