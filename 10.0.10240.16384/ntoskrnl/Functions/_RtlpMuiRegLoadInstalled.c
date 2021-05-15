// _RtlpMuiRegLoadInstalled 
 
int __fastcall RtlpMuiRegLoadInstalled(int a1)
{
  unsigned int v2; // r10
  int v3; // r5
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int *v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r6
  int v12; // r0
  __int16 v13; // r6
  int v14; // r1
  int v15; // r3
  int v16; // r3
  int v17; // [sp+0h] [bp-288h]
  int *v18; // [sp+4h] [bp-284h]
  _BYTE v19[505]; // [sp+27h] [bp-261h] BYREF
  int v20; // [sp+228h] [bp-60h]
  int v21; // [sp+22Ch] [bp-5Ch]
  int v22; // [sp+230h] [bp-58h]
  int v23; // [sp+234h] [bp-54h] BYREF
  __int16 v24; // [sp+238h] [bp-50h] BYREF
  int v25; // [sp+23Ch] [bp-4Ch] BYREF
  _BYTE v26[8]; // [sp+240h] [bp-48h] BYREF
  int v27; // [sp+248h] [bp-40h]
  int v28; // [sp+24Ch] [bp-3Ch]
  _BYTE *v29; // [sp+250h] [bp-38h]
  int v30; // [sp+254h] [bp-34h]
  int v31; // [sp+258h] [bp-30h]
  int v32; // [sp+25Ch] [bp-2Ch]
  unsigned int v33; // [sp+260h] [bp-28h] BYREF
  int v34[9]; // [sp+264h] [bp-24h] BYREF

  v2 = (unsigned int)v19 & 0xFFFFFFE0;
  v3 = 0;
  v24 = -1;
  v21 = 0;
  v22 = 0;
  v25 = 0;
  v23 = 0;
  if ( !a1 )
    return sub_80C108();
  if ( NtIsUILanguageComitted() >= 0 )
  {
    v3 = ZwQueryInstallUILanguage();
    if ( v3 < 0 )
      goto LABEL_36;
    v16 = *(unsigned __int16 *)(a1 + 4);
    if ( v16 == 4096 || v16 == 5120 )
      goto LABEL_36;
    RtlpLoadInstallLanguageFallback(a1, a1 + 6, a1 + 8);
  }
  v5 = RtlpMuiRegFreeRegistryInfo(a1, 1023);
  v6 = RtlpMuiRegCreateLanguages(v5);
  *(_DWORD *)(a1 + 20) = v6;
  if ( v6 )
  {
    *(_DWORD *)a1 |= 1u;
    v7 = RtlpMuiRegCreateStringPool(-1, -1);
    *(_DWORD *)(a1 + 24) = v7;
    if ( v7 )
    {
      *(_DWORD *)a1 |= 2u;
      RtlInitUnicodeString(
        (unsigned int)v26,
        L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages");
      v21 = 0;
      v27 = 24;
      v28 = 0;
      v30 = 576;
      v29 = v26;
      v31 = 0;
      v32 = 0;
      if ( ZwOpenKey() >= 0 )
      {
        v11 = 0;
        v20 = 0;
        do
        {
          v18 = &v25;
          v17 = 512;
          v12 = ZwEnumerateKey();
          v3 = v12;
          if ( v12 < 0 )
          {
            if ( v12 != -2147483622 )
              goto LABEL_36;
          }
          else if ( (unsigned int)(*(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0xC) + 24) <= 0x200 )
          {
            *(_WORD *)(((unsigned int)v19 & 0xFFFFFFE0)
                     + 2 * (*(_DWORD *)(((unsigned int)v19 & 0xFFFFFFE0) + 0xC) >> 1)
                     + 0x10) = 0;
            RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)(v2 + 16));
            v22 = 0;
            v27 = 24;
            v28 = v21;
            v30 = 576;
            v29 = v26;
            v31 = 0;
            v32 = 0;
            if ( ZwOpenKey() >= 0 )
            {
              RtlInitUnicodeString((unsigned int)v26, L"Type");
              v33 = 4;
              v34[0] = 4;
              if ( LdrpQueryValueKey(v22, (int)v26, v34, (int)&v23, &v33) >= 0 )
              {
                v13 = v23;
                if ( ValidateRegistrLangType(v23) >= 0 )
                {
                  v14 = v13 & 0x419F;
                  v23 = v14;
                  v9 = v13 & 7;
                  if ( (v13 & 7) != 0 && (-v9 & v9) == v9 )
                  {
                    v9 = v13 & 0x180;
                    if ( (v13 & 0x180) == 0 || (-v9 & v9) != v9 )
                    {
                      v14 = v13 & 0x401F | 0x80;
                      v23 = v14;
                    }
                    v15 = v14 & 0x18;
                    if ( (v14 & 0x18) != 0 )
                    {
                      v9 = -v15 & v15;
                      if ( v9 == v15 && ((v14 & 8) == 0 || (v14 & 4) != 0) )
                        RtlpMuiRegAddLanguageByName(a1, v22, (unsigned __int16 *)(v2 + 16), v14, v17, (int)&v24);
                    }
                  }
                }
                v11 = v20;
              }
            }
          }
          if ( v22 )
          {
            NtClose();
            v22 = 0;
          }
          v20 = ++v11;
          v10 = 512;
          v8 = &v25;
        }
        while ( v3 != -2147483622 );
        if ( v21 )
        {
          NtClose();
          v10 = 0;
          v21 = 0;
        }
      }
      v3 = RtlpMuiRegValidateInstalled(a1, v8, v9, v10, v17, v18);
      if ( v3 >= 0 )
        return v3;
    }
  }
  else
  {
    v3 = -1073741801;
  }
LABEL_36:
  RtlpMuiRegFreeRegistryInfo(a1, 1023);
  return v3;
}
