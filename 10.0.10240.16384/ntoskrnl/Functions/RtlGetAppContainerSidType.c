// RtlGetAppContainerSidType 
 
int __fastcall RtlGetAppContainerSidType(int a1, _DWORD *a2)
{
  int result; // r0

  if ( *(unsigned __int8 *)(a1 + 1) < 2u
    || *(_BYTE *)a1 != 1
    || RtlCompareMemory((unsigned __int8 *)(a1 + 2), (int)&RtlpAppPackageAuthority, 6) != 6
    || *(_DWORD *)(a1 + 8) != 2 )
  {
    JUMPOUT(0x7EA12C);
  }
  if ( *(_BYTE *)RtlSubAuthorityCountSid(a1) != 8 )
    return sub_7EA120();
  result = 0;
  *a2 = 2;
  return result;
}
