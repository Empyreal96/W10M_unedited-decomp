// RtlpMuiRegLoadLicInformation 
 
int __fastcall RtlpMuiRegLoadLicInformation(_DWORD *a1)
{
  int v2; // r5
  int v3; // r10
  int v4; // r8
  int result; // r0
  unsigned int v6; // r2
  int v7; // r4
  _BYTE *v8; // r0
  int *v9; // r7
  unsigned __int16 *v10; // r6
  int v11; // r4
  _WORD *v12; // r5
  unsigned int v13; // r2
  int v14; // r4
  _BYTE *v15; // r0
  int *v16; // r7
  unsigned __int16 *v17; // r6
  int v18; // r4
  _WORD *v19; // r5
  unsigned int v20; // r2
  int v21; // r4
  unsigned __int16 *v22; // r0
  int v23; // r3
  int *v24; // r6
  int v25; // r4
  unsigned __int16 *v26; // r5
  _WORD *v27; // r7
  int *v28; // r0
  int v29; // r4
  int v30; // r3
  int v31; // r0
  int v32; // r3
  int *v33; // [sp+0h] [bp-50h] BYREF
  unsigned int v34; // [sp+4h] [bp-4Ch] BYREF
  unsigned __int16 *v35; // [sp+8h] [bp-48h]
  char v36[4]; // [sp+Ch] [bp-44h] BYREF
  char v37[4]; // [sp+10h] [bp-40h] BYREF
  int v38; // [sp+14h] [bp-3Ch]
  unsigned int v39; // [sp+18h] [bp-38h]
  unsigned int v40; // [sp+1Ch] [bp-34h]
  int v41; // [sp+20h] [bp-30h]
  int v42; // [sp+24h] [bp-2Ch]
  char v43[40]; // [sp+28h] [bp-28h] BYREF

  v35 = 0;
  v41 = 0;
  v2 = 0;
  v42 = -1;
  v33 = 0;
  v3 = 0;
  v38 = 0;
  v39 = 0;
  v4 = 0;
  v40 = 0;
  if ( !a1 )
    return sub_54DD2C();
  if ( RtlpGetWindowsPolicy(L"WindowsExcludedProcs", v37, &v34, &v33) >= 0 )
  {
    v41 = 1;
    if ( v33 )
      ExFreePoolWithTag(v33, 0);
    v33 = 0;
  }
  if ( RtlpGetWindowsPolicy(L"Kernel-MUI-Number-Allowed", v37, &v34, &v33) >= 0 )
  {
    v42 = *v33;
    ExFreePoolWithTag(v33, 0);
    v33 = 0;
  }
  if ( RtlpGetWindowsPolicy(L"Kernel-MUI-Language-Allowed", v37, &v34, &v33) >= 0 )
  {
    v6 = v34;
    v7 = v34 + 4;
    v39 = v34 + 4;
    if ( v34 == -4 )
    {
      v3 = 0;
    }
    else
    {
      v8 = (_BYTE *)ExAllocatePoolWithTag(1, v34 + 4);
      v3 = (int)v8;
      if ( v8 )
        memset(v8, 0, v7);
      v6 = v34;
    }
    if ( !v3 )
    {
      v39 = 0;
LABEL_68:
      v29 = -1073741801;
      v28 = v33;
      goto LABEL_57;
    }
    v9 = v33;
    memmove(v3, (int)v33, v6);
    v10 = (unsigned __int16 *)v3;
    v11 = 0;
    v12 = (_WORD *)wcspbrk(v3, L";");
    if ( v12 )
    {
      do
      {
        *v12 = 0;
        RtlInitUnicodeString((unsigned int)v43, v10);
        if ( RtlCultureNameToLCID(v43, v36) )
          ++v11;
        v10 = v12 + 1;
        v12 = (_WORD *)wcspbrk(v12 + 1, L";");
      }
      while ( v12 );
      v9 = v33;
    }
    if ( *v10 )
    {
      RtlInitUnicodeString((unsigned int)v43, v10);
      if ( RtlCultureNameToLCID(v43, v36) )
        ++v11;
    }
    if ( !v11 )
    {
      ExFreePoolWithTag(v3, 0);
      v39 = 0;
      v3 = 0;
    }
    if ( v9 )
      ExFreePoolWithTag(v9, 0);
    v33 = 0;
  }
  if ( RtlpGetWindowsPolicy(L"Kernel-MUI-Language-Disallowed", v37, &v34, &v33) < 0 )
    goto LABEL_36;
  v13 = v34;
  v14 = v34 + 4;
  v38 = v34 + 4;
  if ( v34 == -4 )
  {
    v4 = 0;
  }
  else
  {
    v15 = (_BYTE *)ExAllocatePoolWithTag(1, v34 + 4);
    v4 = (int)v15;
    if ( v15 )
      memset(v15, 0, v14);
    v13 = v34;
  }
  if ( !v4 )
  {
    v2 = 0;
    goto LABEL_68;
  }
  v16 = v33;
  memmove(v4, (int)v33, v13);
  v17 = (unsigned __int16 *)v4;
  v18 = 0;
  v19 = (_WORD *)wcspbrk(v4, L";");
  if ( v19 )
  {
    do
    {
      *v19 = 0;
      RtlInitUnicodeString((unsigned int)v43, v17);
      if ( RtlCultureNameToLCID(v43, v36) )
        ++v18;
      v17 = v19 + 1;
      v19 = (_WORD *)wcspbrk(v19 + 1, L";");
    }
    while ( v19 );
    v16 = v33;
  }
  if ( *v17 )
  {
    RtlInitUnicodeString((unsigned int)v43, v17);
    if ( RtlCultureNameToLCID(v43, v36) )
      ++v18;
  }
  if ( !v18 )
  {
    ExFreePoolWithTag(v4, 0);
    v38 = 0;
    v4 = 0;
  }
  if ( v16 )
    ExFreePoolWithTag(v16, 0);
  v33 = 0;
LABEL_36:
  if ( RtlpGetWindowsPolicy(L"Kernel-MUI-Language-SKU", v37, &v34, &v33) < 0 )
  {
    v28 = v33;
  }
  else
  {
    v20 = v34;
    v21 = v34 + 4;
    v40 = v34 + 4;
    if ( v34 == -4 )
    {
      v23 = 0;
      v35 = 0;
    }
    else
    {
      v22 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v34 + 4);
      v23 = (int)v22;
      v35 = v22;
      if ( v22 )
      {
        memset(v22, 0, v21);
        v23 = (int)v35;
      }
      v20 = v34;
    }
    if ( !v23 )
    {
      v29 = -1073741801;
      v28 = v33;
      v40 = 0;
      goto LABEL_56;
    }
    v24 = v33;
    memmove(v23, (int)v33, v20);
    v25 = 0;
    v26 = v35;
    v27 = (_WORD *)wcspbrk(v35, L";");
    if ( v27 )
    {
      do
      {
        *v27 = 0;
        RtlInitUnicodeString((unsigned int)v43, v26);
        if ( RtlCultureNameToLCID(v43, v36) )
          ++v25;
        v26 = v27 + 1;
        v27 = (_WORD *)wcspbrk(v27 + 1, L";");
      }
      while ( v27 );
      v24 = v33;
    }
    if ( *v26 )
    {
      RtlInitUnicodeString((unsigned int)v43, v26);
      if ( RtlCultureNameToLCID(v43, v36) )
        ++v25;
    }
    if ( !v25 )
    {
      ExFreePoolWithTag(v35, 0);
      v40 = 0;
      v35 = 0;
    }
    if ( v24 )
      ExFreePoolWithTag(v24, 0);
    v28 = 0;
  }
  v29 = 0;
LABEL_56:
  v2 = v38;
LABEL_57:
  if ( v28 )
    ExFreePoolWithTag(v28, 0);
  if ( v3 )
  {
    if ( v4 )
    {
      ExFreePoolWithTag(v4, 0);
      v4 = 0;
      v2 = 0;
    }
  }
  v30 = v41;
  v31 = (int)v35;
  a1[19] = v3;
  a1[20] = v31;
  a1[17] = v30;
  v32 = v42;
  a1[23] = v4;
  a1[24] = v2;
  result = v29;
  a1[18] = v32;
  a1[22] = v39;
  a1[21] = v40;
  *a1 |= 0x800u;
  return result;
}
