// PfpFileCheckAttributesForPrefetch 
 
int __fastcall PfpFileCheckAttributesForPrefetch(int a1)
{
  int result; // r0
  _DWORD v2[2]; // [sp+8h] [bp-18h] BYREF
  int v3; // [sp+10h] [bp-10h] BYREF

  v2[0] = 0;
  v2[1] = 0;
  result = ((int (__fastcall *)(int, _DWORD *, int *, int, int))NtQueryInformationFile)(a1, v2, &v3, 8, 35);
  if ( result >= 0 )
  {
    if ( result == 259 )
      sub_5238BC();
    if ( (v3 & 0x5300) != 0 )
      result = -1073741660;
    else
      result = 0;
  }
  return result;
}
