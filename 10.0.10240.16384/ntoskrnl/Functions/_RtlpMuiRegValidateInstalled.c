// _RtlpMuiRegValidateInstalled 
 
int __fastcall RtlpMuiRegValidateInstalled(int a1)
{
  int v2; // r7
  unsigned int v3; // r8
  _WORD *v4; // r9
  int result; // r0
  int v6; // r1
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r2
  int v11; // r6
  int v12; // r9
  int v13; // r5
  __int16 v14; // r3
  int v15; // r2
  int v16; // r0
  int v17; // r9
  int v18; // r1
  int v19; // r5
  __int16 v20; // r2
  int v21; // r2
  int v22; // r5
  int v23; // r6
  __int16 v24; // r2
  char *v25; // r3
  char *v26; // r3
  int v27; // r2
  unsigned __int16 v28; // [sp+0h] [bp-110h] BYREF
  __int16 v29; // [sp+2h] [bp-10Eh] BYREF
  __int16 v30; // [sp+4h] [bp-10Ch] BYREF
  _WORD *v31; // [sp+8h] [bp-108h]
  int v32; // [sp+Ch] [bp-104h]
  char v33[2]; // [sp+10h] [bp-100h] BYREF
  __int16 v34; // [sp+12h] [bp-FEh]
  __int16 *v35; // [sp+14h] [bp-FCh]
  char v36[4]; // [sp+18h] [bp-F8h] BYREF
  _WORD *v37; // [sp+1Ch] [bp-F4h]
  __int16 v38[6]; // [sp+20h] [bp-F0h] BYREF
  char v39; // [sp+2Ch] [bp-E4h] BYREF
  char v40[8]; // [sp+34h] [bp-DCh] BYREF
  int v41; // [sp+3Ch] [bp-D4h] BYREF
  __int16 v42; // [sp+40h] [bp-D0h] BYREF
  char v43[168]; // [sp+42h] [bp-CEh] BYREF

  v2 = -1;
  v29 = -1;
  v28 = 0;
  v3 = 0;
  v4 = 0;
  v31 = 0;
  v42 = 0;
  memset(v43, 0, sizeof(v43));
  if ( !NtIsUILanguageComitted() )
    return sub_817CC8();
  v6 = *(unsigned __int16 *)(a1 + 4);
  v32 = 0;
  if ( v6 )
  {
    v28 = v6;
  }
  else
  {
    result = NtQueryInstallUILanguage(&v28);
    if ( result < 0 )
      return result;
    v6 = v28;
  }
  v7 = RtlpMuiRegGetInstalledLanguageIndexByLangId(a1, v6, 0, &v29);
  v9 = -1073741772;
  if ( v7 == -1073741772 || (v9 = -1073741637, v7 == -1073741637) )
  {
    v30 = -1;
    v4 = sub_4F4434(v7, 0x55u, v8, v9);
    v31 = v4;
    if ( !v4 )
      return -1073741801;
    v37 = v4;
    if ( !RtlLCIDToCultureName(v28, (unsigned int)v36) )
      goto LABEL_14;
    v24 = RtlpMuiRegGetOrAddString((_DWORD *)a1, v37, 1, &v30) >= 0 ? v30 : -1;
    v38[0] = 49;
    v38[1] = 0;
    v38[3] = v24;
    v38[2] = v28;
    v38[4] = 0;
    v25 = &v39;
    do
    {
      *(_WORD *)v25 = 0;
      v25 += 2;
    }
    while ( v25 != v40 );
    v26 = v40;
    do
    {
      *(_WORD *)v26 = 0;
      v26 += 2;
    }
    while ( v26 != (char *)&v41 );
    RtlpMuiRegAddNeutralLanguage(a1, (int)v38);
    if ( RtlpMuiRegGetOrAddLangInfo(a1 + 20, v38, 0) < 0 )
      goto LABEL_14;
    v2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 20) + 6) - 1;
    goto LABEL_10;
  }
  if ( v7 >= 0 )
  {
    v2 = v29;
LABEL_10:
    if ( v2 != -1 )
    {
      v35 = &v42;
      v34 = 170;
      if ( RtlpGetNameFromLangInfoNode(
             a1,
             *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + 28 * v2,
             (int)v33,
             *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12)) >= 0 )
      {
        if ( RtlpIsALicensedRegularLanguage((_DWORD *)a1) < 0 )
        {
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + 28 * v2) &= 0xFFDFu;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + 28 * v2) |= 0x8000u;
        }
        else
        {
          v3 = 1;
        }
      }
    }
  }
LABEL_14:
  RtlpRemovePendingDeleteLanguages(a1);
  v10 = *(_DWORD *)(a1 + 20);
  v11 = 0;
  if ( *(_WORD *)(v10 + 6) )
  {
    v12 = v32;
    v13 = 0;
    do
    {
      v14 = *(_WORD *)(*(_DWORD *)(v10 + 12) + v13);
      if ( (v14 & 2) != 0 && (v14 & 0x20) != 0 )
      {
        RtlpMuiRegValidatePartialLanguage(a1, v11);
        v27 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12);
        if ( (*(_WORD *)(v27 + v13) & 0x1000) == 0 )
          ++v3;
        if ( v12 && v11 != v2 && v3 > *(_DWORD *)(a1 + 72) )
        {
          *(_WORD *)(v27 + v13) &= 0xFFDFu;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + v13) |= 0x8000u;
        }
      }
      v10 = *(_DWORD *)(a1 + 20);
      ++v11;
      v13 += 28;
    }
    while ( v11 < *(unsigned __int16 *)(v10 + 6) );
    v4 = v31;
  }
  v15 = *(_DWORD *)(a1 + 20);
  v16 = 0;
  if ( *(_WORD *)(v15 + 6) )
  {
    v17 = v32;
    v18 = 0;
    do
    {
      v19 = *(_DWORD *)(v15 + 12);
      v20 = *(_WORD *)(v19 + v18);
      if ( (v20 & 1) != 0 && (v20 & 0x20) != 0 )
      {
        if ( (*(_WORD *)(v19 + v18) & 0x1000) == 0 )
          ++v3;
        if ( v17 && v16 != v2 && v3 > *(_DWORD *)(a1 + 72) )
        {
          *(_WORD *)(v19 + v18) = v20 & 0xFFDF;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + v18) |= 0x8000u;
        }
      }
      v15 = *(_DWORD *)(a1 + 20);
      ++v16;
      v18 += 28;
    }
    while ( v16 < *(unsigned __int16 *)(v15 + 6) );
    v4 = v31;
  }
  v21 = *(_DWORD *)(a1 + 20);
  v22 = 0;
  if ( *(_WORD *)(v21 + 6) )
  {
    v23 = 0;
    do
    {
      if ( (*(_WORD *)(*(_DWORD *)(v21 + 12) + v23) & 4) != 0 )
        RtlpMuiRegValidateLIPLanguage(a1, v22);
      v21 = *(_DWORD *)(a1 + 20);
      ++v22;
      v23 += 28;
    }
    while ( v22 < *(unsigned __int16 *)(v21 + 6) );
  }
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return 0;
}
