// WdipSemLoadNextContextProvider 
 
int __fastcall WdipSemLoadNextContextProvider(int a1, int a2, unsigned int a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v12; // [sp+8h] [bp-D8h] BYREF
  int v13; // [sp+Ch] [bp-D4h] BYREF
  unsigned int v14; // [sp+10h] [bp-D0h] BYREF
  int v15; // [sp+14h] [bp-CCh] BYREF
  int v16; // [sp+18h] [bp-C8h] BYREF
  __int64 v17; // [sp+20h] [bp-C0h] BYREF
  unsigned __int16 v18[4]; // [sp+28h] [bp-B8h] BYREF
  int v19[44]; // [sp+30h] [bp-B0h] BYREF

  v12 = 0;
  v13 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0i64;
  v14 = 0;
  if ( !a1 || !a3 )
    return -1073741811;
  memset(v19, 0, 152);
  v6 = ZwEnumerateKey();
  v5 = v6;
  if ( v6 == -2147483622 || v6 < 0 )
    goto LABEL_33;
  if ( v19[3] >= 0x80u )
  {
    v5 = -2147483643;
    goto LABEL_33;
  }
  *((_WORD *)&v19[4] + ((unsigned int)v19[3] >> 1)) = 0;
  RtlInitUnicodeString((unsigned int)v18, (unsigned __int16 *)&v19[4]);
  v5 = RtlGUIDFromString(v18, (_BYTE *)a3);
  if ( v5 < 0 )
    goto LABEL_33;
  if ( !memcmp(a3, (unsigned int)WDI_SEM_PROVIDER, 16) )
  {
    v5 = -1073741823;
    goto LABEL_33;
  }
  v5 = WdipSemOpenRegistryKey(&v19[4], a1, &v12);
  if ( v5 < 0 )
    goto LABEL_33;
  v7 = WdipSemQueryValueFromRegistry(v12, L"Level", 4, 4, &v15, &v13);
  v5 = v7;
  if ( v7 < 0 )
  {
    if ( v7 != -1073741772 )
      goto LABEL_33;
    goto LABEL_16;
  }
  if ( !v15 )
  {
LABEL_16:
    *(_BYTE *)(a3 + 18) = -1;
    goto LABEL_18;
  }
  *(_BYTE *)(a3 + 18) = v15;
LABEL_18:
  v8 = WdipSemQueryValueFromRegistry(v12, L"Keyword", 11, 8, &v17, &v13);
  v5 = v8;
  if ( v8 >= 0 )
  {
    if ( v17 )
    {
      *(_QWORD *)(a3 + 24) = v17;
      goto LABEL_24;
    }
  }
  else if ( v8 != -1073741772 )
  {
    goto LABEL_33;
  }
  *(_DWORD *)(a3 + 24) = -1;
  *(_DWORD *)(a3 + 28) = -1;
LABEL_24:
  v9 = WdipSemQueryValueFromRegistry(v12, L"CaptureState", 4, 4, &v14, &v13);
  v5 = v9;
  if ( v9 >= 0 )
  {
    *(_DWORD *)(a3 + 32) = v14;
LABEL_29:
    v10 = WdipSemQueryValueFromRegistry(v12, L"EnableProperty", 4, 4, &v16, &v13);
    v5 = v10;
    if ( v10 >= 0 )
    {
      *(_DWORD *)(a3 + 36) = v16;
    }
    else if ( v10 == -1073741772 )
    {
      v5 = 0;
      *(_DWORD *)(a3 + 36) = 0;
    }
    goto LABEL_33;
  }
  if ( v9 == -1073741772 || v14 >= 3 )
  {
    *(_DWORD *)(a3 + 32) = 0;
    goto LABEL_29;
  }
LABEL_33:
  if ( v12 )
    ZwClose();
  return v5;
}
