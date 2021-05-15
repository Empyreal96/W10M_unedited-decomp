// ExGetExpirationDate 
 
int __fastcall ExGetExpirationDate(_DWORD *a1)
{
  int v2; // r0
  int v3; // r4
  char v5[9]; // [sp+28h] [bp-38h] BYREF
  int v6; // [sp+31h] [bp-2Fh]
  int v7; // [sp+35h] [bp-2Bh]
  int v8; // [sp+39h] [bp-27h]
  __int16 v9; // [sp+3Dh] [bp-23h]
  char v10; // [sp+3Fh] [bp-21h]
  char v11; // [sp+40h] [bp-20h]
  int v12; // [sp+41h] [bp-1Fh]
  int v13; // [sp+45h] [bp-1Bh]
  int v14; // [sp+49h] [bp-17h]
  __int16 v15; // [sp+4Dh] [bp-13h]
  char v16; // [sp+4Fh] [bp-11h]

  v5[8] = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  if ( !a1 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v5, L"Kernel-ExpirationDate");
  v2 = ZwQueryLicenseValue();
  v3 = v2;
  if ( v2 == -1073741789 )
    return sub_7DB5DC();
  if ( v2 >= 0 )
    v3 = -1073741823;
  *a1 = 0;
  a1[1] = 0;
  return v3;
}
