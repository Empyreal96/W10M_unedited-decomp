// PfpPrivSourceEnum 
 
int __fastcall PfpPrivSourceEnum(int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // lr
  unsigned int v5; // r5
  int v6; // r10
  int i; // r9
  int v8; // r6
  int *v9; // r8
  unsigned int v10; // r1
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r8
  unsigned __int64 v16; // r2
  unsigned int v17; // r3
  char v18; // r8
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r4
  char v22; // r5
  int v23; // r1
  int v24; // r2
  int v25; // r3
  bool v26; // r0
  unsigned int v27; // r4
  unsigned int v28; // r2
  int v29; // r1
  unsigned __int8 v31; // [sp-4h] [bp-168h] BYREF
  unsigned int v32; // [sp+0h] [bp-164h] BYREF
  int v33; // [sp+4h] [bp-160h]
  int *v34; // [sp+Ch] [bp-158h] BYREF
  unsigned int v35; // [sp+10h] [bp-154h]
  int v36; // [sp+14h] [bp-150h]
  unsigned int v37; // [sp+18h] [bp-14Ch]
  int *v38; // [sp+1Ch] [bp-148h]
  int *v39; // [sp+20h] [bp-144h]
  int v40; // [sp+24h] [bp-140h]
  _DWORD v41[19]; // [sp+2Ch] [bp-138h] BYREF
  int v42; // [sp+78h] [bp-ECh]
  int v43; // [sp+7Ch] [bp-E8h]
  int v44; // [sp+80h] [bp-E4h]
  _DWORD v45[6]; // [sp+84h] [bp-E0h] BYREF
  int v46; // [sp+9Ch] [bp-C8h] BYREF
  unsigned __int64 v47; // [sp+B4h] [bp-B0h]
  unsigned int v48[4]; // [sp+BCh] [bp-A8h] BYREF
  unsigned int v49; // [sp+CCh] [bp-98h]
  int v50; // [sp+F4h] [bp-70h]
  unsigned int v51; // [sp+F8h] [bp-6Ch]
  int v52; // [sp+FCh] [bp-68h]
  int varg_r0; // [sp+16Ch] [bp+8h]
  int varg_r1; // [sp+170h] [bp+Ch]
  _DWORD *varg_r2; // [sp+174h] [bp+10h]
  int varg_r3; // [sp+178h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v39 = a3;
  v4 = (char)a2;
  v42 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v40 = a1;
  v44 = a1;
  v32 = (unsigned int)a3;
  v34 = 0;
  v5 = 0;
  v35 = 0;
  v6 = 0;
  v36 = 0;
  v37 = 0;
  i = 0;
  v43 = 0;
  v8 = 0;
  v41[17] = 0;
  v33 = 0;
  v41[18] = 0;
  v9 = *(int **)(a1 + 12);
  v38 = v9;
  v41[16] = v9;
  v10 = *(_DWORD *)(a1 + 16);
  if ( v10 < 0xC )
    goto LABEL_2;
  if ( v4 )
  {
    ProbeForWrite(v9, v10, 4);
    v4 = v42;
  }
  v12 = v9[1];
  v13 = v9[2];
  v50 = *v9;
  v51 = v12;
  v52 = v13;
  v9[2] = 0;
  if ( v50 != 8 || (v32 = v51, (v51 & 0xFFFFFFFC) != 0) || (v51 & 3) == 3 )
  {
    v11 = -1073741811;
    goto LABEL_56;
  }
  if ( SeSinglePrivilegeCheck(SeProfileSingleProcessPrivilege, dword_922B94, v4) )
  {
    v15 = 0;
    v31 = 0;
  }
  else
  {
    v14 = SeIsAppContainerOrIdentifyLevelContext(0, &v31);
    v11 = v14;
    if ( v14 == -1073741659 )
    {
      v15 = 1;
      v31 = 1;
      goto LABEL_19;
    }
    if ( v14 < 0 )
      goto LABEL_56;
    v15 = v31;
  }
  if ( !v15 )
  {
    v5 = 1;
    v35 = 1;
    i = MmGetNextSession();
    if ( i )
    {
      do
      {
        ++v5;
        i = MmGetNextSession();
      }
      while ( i );
      v35 = v5;
    }
  }
LABEL_19:
  v8 = ExGetNextProcess(0, 0);
  if ( v8 )
  {
    do
    {
      ++v5;
      v8 = ExGetNextProcess(v8, 0);
    }
    while ( v8 );
    v35 = v5;
  }
  v16 = (v5 << 6) + __PAIR64__(v5 >> 26, 12);
  if ( HIDWORD(v16) )
  {
    v11 = -1073741670;
    goto LABEL_56;
  }
  v33 = (v5 << 6) + 12;
  v17 = *(_DWORD *)(v40 + 16);
  if ( (unsigned int)v16 > v17 )
  {
LABEL_2:
    v11 = -1073741789;
    goto LABEL_56;
  }
  v37 = (v17 - 12) >> 6;
  v34 = v38;
  if ( !v15 )
  {
    memset(v41, 0, 64);
    v41[0] = 0;
    RtlStringCbCopyA((int)&v41[8]);
    v11 = ZwQuerySystemInformation();
    if ( v11 < 0 )
      goto LABEL_56;
    v11 = MmQuerySystemMemoryInformation((int *)v48);
    if ( v11 < 0 )
      goto LABEL_56;
    v41[5] = v49 >> 12;
    v41[6] = v48[0];
    if ( v48[0] <= v49 >> 12 )
      v41[6] = v49 >> 12;
    v11 = PfpPrivSourceAdd(&v34, v41);
    if ( v11 < 0 )
    {
LABEL_53:
      v6 = v36;
      v5 = v35;
      goto LABEL_56;
    }
    for ( i = MmGetNextSession(); i; i = MmGetNextSession() )
    {
      memset(v41, 0, 64);
      v41[0] = 1;
      v41[1] = MmGetSessionIdEx(i);
      v41[4] = MmGetSessionGlobalVA(i);
      MiFillSessionWorkingSetEntry(v45, *(_DWORD **)(i + 324));
      v41[5] = v45[4];
      v41[13] = v45[1];
      v41[6] = v45[2];
      v41[12] = v45[3];
      RtlStringCbCopyA((int)&v41[8]);
      v11 = PfpPrivSourceAdd(&v34, v41);
      if ( v11 < 0 )
        goto LABEL_53;
    }
    v6 = v36;
    v5 = v35;
  }
  v8 = ExGetNextProcess(0, v15);
  if ( v8 )
  {
    v18 = v32;
    while ( 1 )
    {
      memset(v41, 0, 64);
      v41[0] = 2;
      v41[1] = *(_DWORD *)(v8 + 176);
      v41[2] = *(_DWORD *)(v8 + 408);
      v41[3] = (*(_DWORD *)(v8 + 200) >> 3) & 0x1C000000 ^ (*(_DWORD *)(v8 + 204) ^ *(_DWORD *)(v8 + 200) ^ v8) & 0x1FFFFFFF;
      v41[4] = v8;
      v19 = *(_DWORD *)(v8 + 556);
      v41[5] = v19;
      if ( v19 <= *(_DWORD *)(v8 + 552) )
        v41[13] = *(_DWORD *)(v8 + 552);
      else
        v41[13] = v19;
      v20 = *(_DWORD *)(v8 + 276);
      v41[6] = v20;
      __dmb(0xBu);
      if ( v20 <= v41[5] )
        v41[6] = v41[5];
      v41[7] = MmGetSessionIdEx(v8);
      v21 = PsReferencePrimaryToken(v8);
      v22 = SeSecurityAttributePresent(v21, &PspSysAppIdClaim);
      ObFastDereferenceObject((_DWORD *)(v8 + 244), v21);
      v26 = SmStoreExistsForProcess(v8, v23, v24, v25);
      v27 = v22 & 1 | (8 * v26) | v41[15] & 0xFFFFFFF6;
      v41[15] = v27;
      PsGetProcessDeepFreezeStats(v8, &v46);
      if ( v47 )
      {
        v27 |= 2u;
        v41[15] = v27;
        v41[14] = _rt_udiv64(10000i64, v47);
      }
      if ( *(_BYTE *)(v8 + 606) == 2 )
        v41[15] = v27 | 4;
      RtlStringCbCopyA((int)&v41[8]);
      if ( (v18 & 1) != 0 )
      {
        MmQueryProcessWorkingSetSwapPages(v8);
      }
      else if ( (v51 & 2) != 0 && SmProcessQueryStoreStats(v8, &v32, 0) >= 0 )
      {
        v41[12] = v32 >> 12;
      }
      v11 = PfpPrivSourceAdd(&v34, v41);
      if ( v11 < 0 )
        goto LABEL_53;
      v8 = ExGetNextProcess(v8, v31);
      if ( !v8 )
      {
        v6 = v36;
        v5 = v35;
        break;
      }
    }
  }
  v33 = (v6 << 6) + 12;
  v11 = 0;
LABEL_56:
  if ( i )
    ObfDereferenceObject(i);
  if ( v8 )
    ObfDereferenceObjectWithTag(v8);
  if ( v11 == -1073741789 )
  {
    v28 = v6 + 1;
    if ( v6 + 1 <= v5 )
      v28 = v5;
    v29 = (v28 << 6) + 12;
    if ( ((v28 << 6) + __PAIR64__(v28 >> 26, 12)) >> 32 )
    {
      v29 = 0;
      v11 = -1073741670;
    }
  }
  else
  {
    v29 = v33;
  }
  *v39 = v29;
  return v11;
}
