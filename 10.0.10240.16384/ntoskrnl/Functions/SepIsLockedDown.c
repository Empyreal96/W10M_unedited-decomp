// SepIsLockedDown 
 
int __fastcall SepIsLockedDown(_BYTE *a1)
{
  int v2; // r4
  int v3; // r0
  bool v5; // [sp+8h] [bp-20h] BYREF
  BOOL v6; // [sp+Ch] [bp-1Ch]
  __int16 v7[2]; // [sp+18h] [bp-10h] BYREF
  const __int16 *v8; // [sp+1Ch] [bp-Ch]

  v5 = 0;
  *a1 = 1;
  v2 = 0;
  if ( (unsigned __int8)SeILSigningPolicy < 4u )
    goto LABEL_9;
  v7[0] = 38;
  v7[1] = 40;
  v8 = L"AllowAllTrustedApps";
  v2 = KIsUnlockSettingEnabled((int)v7, &v5);
  if ( v2 < 0 )
    return v2;
  v6 = v5;
  if ( v5 )
    goto LABEL_9;
  v3 = ZwQueryLicenseValue();
  v2 = v3;
  if ( v3 != -1073741772 )
  {
    if ( v3 < 0 )
      return v2;
    if ( !v6 )
      goto LABEL_8;
LABEL_9:
    *a1 = 0;
    return v2;
  }
  v6 = 0;
  v2 = 0;
LABEL_8:
  if ( ExQueryFastCacheDevLicense() )
    goto LABEL_9;
  return v2;
}
