// _RtlpRemovePendingDeleteLanguages 
 
int __fastcall RtlpRemovePendingDeleteLanguages(int a1)
{
  int result; // r0
  _DWORD v2[3]; // [sp+22Ch] [bp-34h] BYREF
  _BYTE v3[40]; // [sp+238h] [bp-28h] BYREF

  v2[0] = 0;
  v2[1] = 0;
  if ( !a1 )
    return -1073741811;
  RtlInitUnicodeString(
    (unsigned int)v3,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages\\PendingDelete");
  if ( LdrpOpenKey(v3, 0, 131097, v2) < 0 )
    result = 0;
  else
    result = sub_5537F8();
  return result;
}
