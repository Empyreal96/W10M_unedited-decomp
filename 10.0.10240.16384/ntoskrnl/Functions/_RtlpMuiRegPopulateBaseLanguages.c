// _RtlpMuiRegPopulateBaseLanguages 
 
int __fastcall RtlpMuiRegPopulateBaseLanguages(int a1, int a2, _WORD *a3, unsigned int *a4)
{
  unsigned int v7; // r4
  int v8; // r2
  unsigned int v9; // r6
  int v10; // r5
  int v11; // r9
  int v12; // r10
  int v13; // r0
  int v14; // r9
  int v15; // r0
  unsigned int v16; // lr
  int v17; // r5
  _BYTE v19[505]; // [sp+27h] [bp-469h] BYREF
  unsigned __int16 v20; // [sp+228h] [bp-268h] BYREF
  unsigned int v21; // [sp+22Ch] [bp-264h] BYREF
  int v22; // [sp+230h] [bp-260h] BYREF
  int v23; // [sp+234h] [bp-25Ch]
  _WORD *v24; // [sp+238h] [bp-258h]
  unsigned int v25; // [sp+23Ch] [bp-254h]
  unsigned __int16 v26; // [sp+240h] [bp-250h] BYREF
  int v27; // [sp+244h] [bp-24Ch]
  _WORD v28[2]; // [sp+248h] [bp-248h] BYREF
  unsigned __int16 *v29; // [sp+24Ch] [bp-244h]
  int v30; // [sp+250h] [bp-240h]
  unsigned int *v31; // [sp+254h] [bp-23Ch]
  int v32; // [sp+258h] [bp-238h]
  unsigned __int16 v33; // [sp+260h] [bp-230h] BYREF
  _BYTE v34[168]; // [sp+262h] [bp-22Eh] BYREF
  unsigned __int16 v35; // [sp+310h] [bp-180h] BYREF
  _BYTE v36[168]; // [sp+312h] [bp-17Eh] BYREF
  unsigned __int16 v37; // [sp+3C0h] [bp-D0h] BYREF
  _BYTE v38[168]; // [sp+3C2h] [bp-CEh] BYREF

  v23 = a2;
  v24 = a3;
  v31 = a4;
  v7 = (unsigned int)v19 & 0xFFFFFFE0;
  v32 = 0;
  v33 = 0;
  memset(v34, 0, sizeof(v34));
  v35 = 0;
  memset(v36, 0, sizeof(v36));
  v37 = 0;
  memset(v38, 0, sizeof(v38));
  v25 = 0;
  v30 = 0;
  v20 = 0;
  v21 = 0;
  if ( !a1 || !a3 || !a2 )
    return -1073741811;
  v8 = *(unsigned __int16 *)(a1 + 4);
  v9 = 0;
  v27 = 0;
  if ( v8 )
  {
    v11 = *(unsigned __int16 *)(a1 + 6);
    v12 = *(unsigned __int16 *)(a1 + 8);
    v20 = v8;
  }
  else
  {
    v10 = NtQueryInstallUILanguage(&v20);
    if ( v10 < 0 )
      return v10;
    if ( RtlpLoadInstallLanguageFallback(a1, &v22, &v26) >= 0 )
    {
      v12 = v26;
      v11 = (unsigned __int16)v22;
    }
    else
    {
      v11 = 0;
      v12 = 0;
    }
    v13 = NtIsUILanguageComitted();
    v8 = v20;
    if ( v13 >= 0 )
    {
      *(_WORD *)(a1 + 8) = v12;
      *(_WORD *)(a1 + 6) = v11;
      *(_WORD *)(a1 + 4) = v8;
    }
  }
  if ( (unsigned __int16)v24[2] == v8
    && v11
    && (v29 = &v35, v21 = 512, v28[1] = 170, RtlLCIDToCultureName(v11, (unsigned int)v28))
    && ZwQueryValueKey() >= 0
    && RtlpMuiRegValidateAndGetInstallFallbackBase(a1, (unsigned int)v19 & 0xFFFFFFE0, v12, &v37, 512, &v21) >= 0
    && RtlpMuiRegAddBaseLanguage((_DWORD *)a1, v24, 0, (unsigned int)v19 & 0xFFFFFFE0, &v37) >= 0 )
  {
    v9 = 1;
    v14 = wcslen(&v35);
    v30 = v14;
  }
  else
  {
    v14 = 0;
  }
  RtlInitUnicodeString((unsigned int)v28, L"DefaultFallback");
  v22 = 1;
  v21 = 170;
  if ( LdrpQueryValueKey(v23, (int)v28, &v22, (int)&v33, &v21) >= 0
    && v22 == 1
    && (!v14 || RtlCompareUnicodeStrings(&v33, v21 >> 1, (int)&v35, v14, 1)) )
  {
    RtlInitUnicodeString((unsigned int)v28, &v33);
    v21 = 512;
    if ( ZwQueryValueKey() >= 0
      && *(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 4) == 7
      && RtlpMuiRegAddBaseLanguage((_DWORD *)a1, v24, v9, (unsigned int)v19 & 0xFFFFFFE0, 0) >= 0 )
    {
      ++v9;
      v25 = wcslen(&v33);
    }
  }
  while ( v9 < 4 )
  {
    v15 = ZwEnumerateValueKey();
    if ( v15 == -2147483622 || v15 < 0 )
      break;
    if ( *(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 4) == 7
      && *(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0x10) <= 0x200u )
    {
      v16 = v30;
      if ( !v25 && !v30 )
        goto LABEL_40;
      v17 = (*(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0x10) >> 1) + 10;
      v22 = *(unsigned __int16 *)(v7 + 2 * v17);
      *(_WORD *)(v7 + 2 * v17) = 0;
      if ( (!v16
         || RtlCompareUnicodeStrings(
              (unsigned __int16 *)(v7 + 20),
              *(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0x10) >> 1,
              (int)&v35,
              v16,
              1))
        && (!v25
         || RtlCompareUnicodeStrings(
              (unsigned __int16 *)(v7 + 20),
              *(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0x10) >> 1,
              (int)&v33,
              v25,
              1)) )
      {
        *(_WORD *)(v7 + 2 * v17) = v22;
LABEL_40:
        if ( RtlpMuiRegAddBaseLanguage((_DWORD *)a1, v24, v9, (unsigned int)v19 & 0xFFFFFFE0, 0) >= 0 )
          ++v9;
        goto LABEL_42;
      }
    }
LABEL_42:
    ++v27;
  }
  if ( v31 )
    *v31 = v9;
  return 0;
}
