// SepBuildCapPolicyTable 
 
int __fastcall SepBuildCapPolicyTable(int a1, _DWORD *a2)
{
  int v3; // r4
  int v5; // [sp+0h] [bp-28h] BYREF
  int v6; // [sp+4h] [bp-24h] BYREF
  int v7; // [sp+8h] [bp-20h] BYREF
  int v8; // [sp+Ch] [bp-1Ch] BYREF
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  *a2 = 0;
  v8 = 0;
  v9[0] = 0;
  v6 = 0;
  v7 = 0;
  v5 = 0;
  if ( SepRegOpenKey(
         L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies",
         513,
         v9) < 0
    || SepRegOpenKey(
         L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPEs",
         513,
         &v7) < 0
    || SepRegOpenKey(
         L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs",
         513,
         &v6) < 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = SepReadAndPopulateCapes(v7, a1, &v8, &v5);
    if ( v3 < 0 )
      JUMPOUT(0x55349E);
    if ( v8 )
      return sub_553458();
  }
  if ( v6 )
    ZwClose();
  if ( v7 )
    ZwClose();
  if ( v9[0] )
    ZwClose();
  return v3;
}
