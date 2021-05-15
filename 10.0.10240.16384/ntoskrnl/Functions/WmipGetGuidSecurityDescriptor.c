// WmipGetGuidSecurityDescriptor 
 
int __fastcall WmipGetGuidSecurityDescriptor(int a1, _DWORD *a2)
{
  int v4; // r0
  int v5; // r0
  int v7; // [sp-4h] [bp-70h]
  int v8; // [sp+4h] [bp-68h] BYREF
  int v9; // [sp+8h] [bp-64h] BYREF
  int v10[24]; // [sp+Ch] [bp-60h] BYREF

  v8 = 0;
  v9 = 0;
  memset(v10, 0, 84);
  v10[0] = (int)WmipSDRegistryQueryRoutine;
  v10[3] = (int)&v9;
  v10[2] = *(_DWORD *)(a1 + 4);
  v10[4] = 3;
  v10[7] = (int)WmipSDRegistryQueryRoutine;
  v10[8] = 0;
  v10[10] = (int)&v8;
  v10[9] = (int)L"00000000-0000-0000-0000-000000000000";
  v10[11] = 3;
  v4 = RtlpQueryRegistryValues(2, L"WMI\\Security", v10, 0, v7, 1u);
  *a2 = 0;
  if ( v4 < 0 )
    goto LABEL_8;
  if ( v9 )
  {
    v5 = v8;
    *a2 = v9;
    if ( v5 )
      return sub_815A28();
  }
  else
  {
    if ( !v8 )
      goto LABEL_8;
    *a2 = v8;
  }
  if ( !*a2 )
LABEL_8:
    *a2 = WmipDefaultAccessSd;
  return 0;
}
