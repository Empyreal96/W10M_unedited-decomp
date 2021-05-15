// RtlpMuiRegCreateKernelRegistryInfo 
 
int __fastcall RtlpMuiRegCreateKernelRegistryInfo(_DWORD *a1, int a2, _DWORD *a3, int a4, _DWORD *a5, int a6, _DWORD *a7)
{
  _DWORD *v7; // r10
  int v8; // r0
  int v10; // r6
  int v11; // r4
  int v12; // r3
  int v13; // r2
  __int16 *v14; // r1
  int v15; // r10
  char v16; // r3
  __int16 v17; // t1
  int v18; // r3
  int v19; // r4
  _BYTE *v20; // r0
  _BYTE *v21; // r5
  _DWORD *v22; // r2
  int v23; // [sp+8h] [bp-50h] BYREF
  int v24; // [sp+Ch] [bp-4Ch] BYREF
  int v25[2]; // [sp+10h] [bp-48h] BYREF
  int v26; // [sp+18h] [bp-40h]
  _DWORD *v27; // [sp+1Ch] [bp-3Ch]
  int v28; // [sp+20h] [bp-38h]
  _DWORD *v29; // [sp+24h] [bp-34h]
  _DWORD *v30; // [sp+28h] [bp-30h]
  char v31[40]; // [sp+30h] [bp-28h] BYREF

  v27 = a3;
  v28 = a4;
  v25[1] = 0;
  v26 = 0;
  v23 = 0;
  v29 = a1;
  v30 = (_DWORD *)a2;
  if ( !a1 || !a2 || !a3 || !a5 || (v7 = a7) == 0 )
    JUMPOUT(0x55396C);
  RtlInitUnicodeString((unsigned int)v31, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings");
  v8 = LdrpOpenKey(v31, 0, 983103, &v23);
  if ( v8 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v31, L"MultiUILanguageId");
    v25[0] = 1;
    v24 = 0;
    if ( LdrpQueryValueKey(v23, v31, v25, 0, &v24) != -1073741772 )
      return sub_5538BC();
    v8 = NtClose(v23);
    v23 = 0;
  }
  v10 = RtlpMuiRegCreateRegistryInfo(v8);
  if ( !v10 )
    JUMPOUT(0x553966);
  v11 = RtlpMuiRegLoadRegistryInfo();
  if ( v11 >= 0 )
  {
    v12 = *(_DWORD *)(v10 + 20);
    v13 = *(unsigned __int16 *)(v12 + 6);
    if ( *(_WORD *)(v12 + 6) )
    {
      v14 = *(__int16 **)(v12 + 12);
      v15 = 0;
      do
      {
        v17 = *v14;
        v14 += 14;
        v16 = v17;
        if ( (v17 & 0x9000) == 0 && (v16 & 0x20) != 0 && (v16 & 3) != 0 )
          ++v15;
        --v13;
      }
      while ( v13 );
      v26 = v15;
      v7 = a7;
    }
    *v27 = v26;
    v18 = v28;
    *a5 = 0;
    if ( v18 && RtlpMuiRegGetInstalledLanguageIndexByLangId(v10, (unsigned __int16)v18, 1, 0) >= 0 )
      *a5 = 1;
    *v7 = 0;
    if ( a6 && RtlpMuiRegGetInstalledLanguageIndexByLangId(v10, (unsigned __int16)a6, 1, 0) >= 0 )
      *v7 = 1;
    v24 = 0;
    v11 = RtlpMuiRegSerializeRegistryInfo(v10, 0, &v24);
    if ( v11 >= 0 )
    {
      v19 = v24;
      if ( v24 )
      {
        v20 = (_BYTE *)ExAllocatePoolWithTag(1, v24);
        v21 = v20;
        if ( !v20 )
        {
LABEL_37:
          v11 = -1073741801;
          goto LABEL_33;
        }
        memset(v20, 0, v19);
      }
      else
      {
        v21 = 0;
      }
      if ( v21 )
      {
        v11 = RtlpMuiRegSerializeRegistryInfo(v10, v21, &v24);
        if ( v11 < 0 )
          JUMPOUT(0x55396E);
        v22 = v30;
        *v29 = v21;
        *v22 = v24;
        goto LABEL_33;
      }
      goto LABEL_37;
    }
  }
LABEL_33:
  RtlpMuiRegFreeRegistryInfo(v10, 4095);
  ExFreePoolWithTag(v10, 0);
  if ( v23 )
    NtClose(v23);
  return v11;
}
