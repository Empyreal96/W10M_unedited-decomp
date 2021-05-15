// _RtlpMuiRegInitLIPLanguage 
 
int __fastcall RtlpMuiRegInitLIPLanguage(_DWORD *a1, int a2, _WORD *a3)
{
  unsigned int v6; // r5
  int v7; // r0
  int v8; // r0
  int v9; // r4
  int v10; // r9
  int v11; // r3
  _BYTE v13[505]; // [sp+27h] [bp-2F9h] BYREF
  int v14; // [sp+228h] [bp-F8h] BYREF
  unsigned int v15; // [sp+22Ch] [bp-F4h] BYREF
  int v16; // [sp+230h] [bp-F0h]
  unsigned __int16 v17; // [sp+238h] [bp-E8h] BYREF
  unsigned __int16 *v18; // [sp+23Ch] [bp-E4h]
  _DWORD *v19; // [sp+240h] [bp-E0h]
  unsigned int v20; // [sp+244h] [bp-DCh]
  int v21; // [sp+248h] [bp-D8h]
  unsigned __int16 v22; // [sp+250h] [bp-D0h] BYREF
  _BYTE v23[168]; // [sp+252h] [bp-CEh] BYREF

  v19 = a1;
  v6 = 0;
  v21 = 0;
  v22 = 0;
  v16 = 0;
  memset(v23, 0, sizeof(v23));
  v20 = 0;
  if ( !a1 || !a2 || !a3 || (*a3 & 4) == 0 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)&v17, L"DefaultFallback");
  v15 = 170;
  v14 = 1;
  v7 = LdrpQueryValueKey(a2, (int)&v17, &v14, (int)&v22, &v15);
  v15 = -2147483622;
  if ( v7 < 0 || v14 != 1 )
    goto LABEL_28;
  RtlInitUnicodeString((unsigned int)&v17, &v22);
  v14 = 7;
  v8 = LdrpQueryValueKey(a2, (int)&v17, &v14, 0, 0);
  v9 = v8;
  if ( (!v8 || v8 == -2147483643) && (v14 == 7 || v14 == 1) && RtlMuiRegAddLIPParent(v19, (int)a3, 0, &v22) >= 0 )
  {
    v6 = 1;
    v20 = wcslen(&v22);
  }
  if ( v9 != v15 )
  {
LABEL_28:
    do
    {
      if ( v6 >= 4 )
        break;
      v10 = ZwEnumerateValueKey();
      if ( v10 >= 0 )
      {
        v11 = *(_DWORD *)(((unsigned int)v13 & 0xFFFFFFE0) + 4);
        if ( (v11 == 7 || v11 == 1)
          && (unsigned int)(*(_DWORD *)(((unsigned int)v13 & 0xFFFFFFE0) + 0x10) + 24) <= 0x200 )
        {
          *(_WORD *)(((unsigned int)v13 & 0xFFFFFFE0)
                   + 2 * (*(_DWORD *)(((unsigned int)v13 & 0xFFFFFFE0) + 0x10) >> 1)
                   + 0x14) = 0;
          RtlInitUnicodeString((unsigned int)&v17, (unsigned __int16 *)(((unsigned int)v13 & 0xFFFFFFE0) + 20));
          if ( (!v20 || RtlCompareUnicodeStrings(v18, v17 >> 1, (int)&v22, v20, 1))
            && RtlMuiRegAddLIPParent(v19, (int)a3, v6, v18) >= 0 )
          {
            ++v6;
          }
        }
      }
      ++v16;
    }
    while ( v10 != v15 );
  }
  return 0;
}
