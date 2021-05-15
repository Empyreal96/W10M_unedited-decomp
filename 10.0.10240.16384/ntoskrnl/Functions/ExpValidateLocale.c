// ExpValidateLocale 
 
int __fastcall ExpValidateLocale(int a1)
{
  int v1; // r5
  int v2; // r4
  unsigned __int16 *v3; // r2
  unsigned int v4; // r3
  bool v5; // zf
  unsigned int v6; // r2
  unsigned __int16 *v7; // r3
  int v8; // r2
  unsigned __int16 v10[4]; // [sp+8h] [bp-210h] BYREF
  unsigned __int16 v11[2]; // [sp+20h] [bp-1F8h] BYREF
  char *v12; // [sp+24h] [bp-1F4h]
  int v13; // [sp+28h] [bp-1F0h]
  int v14; // [sp+2Ch] [bp-1ECh]
  char *v15; // [sp+30h] [bp-1E8h]
  int v16; // [sp+34h] [bp-1E4h]
  int v17; // [sp+38h] [bp-1E0h]
  int v18; // [sp+3Ch] [bp-1DCh]
  int v19; // [sp+40h] [bp-1D8h]
  int v20; // [sp+44h] [bp-1D4h]
  char *v21; // [sp+48h] [bp-1D0h]
  int v22; // [sp+4Ch] [bp-1CCh]
  int v23; // [sp+50h] [bp-1C8h]
  int v24; // [sp+54h] [bp-1C4h]
  int v25; // [sp+58h] [bp-1C0h]
  int v26; // [sp+5Ch] [bp-1BCh]
  char *v27; // [sp+60h] [bp-1B8h]
  int v28; // [sp+64h] [bp-1B4h]
  int v29; // [sp+68h] [bp-1B0h]
  int v30; // [sp+6Ch] [bp-1ACh]
  char v31[8]; // [sp+70h] [bp-1A8h] BYREF
  char v32[8]; // [sp+78h] [bp-1A0h] BYREF
  char v33[8]; // [sp+80h] [bp-198h] BYREF
  unsigned __int16 v34[32]; // [sp+88h] [bp-190h] BYREF
  int v35; // [sp+CCh] [bp-14Ch]
  unsigned int v36; // [sp+D0h] [bp-148h]
  unsigned __int16 v37[122]; // [sp+D4h] [bp-144h] BYREF
  char v38; // [sp+1C8h] [bp-50h] BYREF

  v1 = -1073741811;
  if ( a1 == 3072 )
    return 0;
  v11[0] = 32;
  v11[1] = 32;
  v12 = &v38;
  v2 = RtlIntegerToUnicodeString(a1, 16, v11);
  if ( v2 < 0 )
    return v2;
  v3 = v34;
  v4 = v11[0] >> 1;
  if ( v4 < 8 )
  {
    v6 = 8 - v4;
    v5 = v4 == 8;
    v7 = v34;
    if ( !v5 )
    {
      do
        *v7++ = 48;
      while ( v7 != &v34[v6] );
    }
    v3 = &v34[v6];
  }
  *v3 = 0;
  RtlInitUnicodeString((unsigned int)v10, v34);
  v10[1] = 32;
  RtlAppendUnicodeToString(v10, (int)v12, v8, 32);
  RtlInitUnicodeString((unsigned int)v33, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Locale");
  v19 = 24;
  v20 = 0;
  v21 = v33;
  v23 = 0;
  v24 = 0;
  v22 = 576;
  v2 = ZwOpenKey();
  if ( v2 < 0 )
    return v2;
  RtlInitUnicodeString(
    (unsigned int)v31,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Locale\\Alternate Sorts");
  v25 = 24;
  v26 = 0;
  v27 = v31;
  v28 = 576;
  v29 = 0;
  v30 = 0;
  v2 = ZwOpenKey();
  if ( v2 >= 0 )
  {
    RtlInitUnicodeString(
      (unsigned int)v32,
      L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language Groups");
    v13 = 24;
    v14 = 0;
    v15 = v32;
    v16 = 576;
    v17 = 0;
    v18 = 0;
    v2 = ZwOpenKey();
    if ( v2 >= 0 )
    {
      v2 = ZwQueryValueKey();
      if ( v2 >= 0 || (v2 = ZwQueryValueKey(), v2 >= 0) )
      {
        if ( v36 > 2 )
        {
          RtlInitUnicodeString((unsigned int)v10, v37);
          v2 = ZwQueryValueKey();
          if ( v2 >= 0 && v35 == 1 && v36 > 2 && v37[0] == 49 && !v37[1] )
            v1 = 0;
        }
      }
      ZwClose();
    }
    ZwClose();
  }
  ZwClose();
  if ( v2 < 0 )
    return v2;
  return v1;
}
