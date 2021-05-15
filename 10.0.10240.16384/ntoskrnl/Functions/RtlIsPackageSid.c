// RtlIsPackageSid 
 
BOOL __fastcall RtlIsPackageSid(int a1)
{
  return *(unsigned __int8 *)(a1 + 1) >= 2u
      && *(_BYTE *)a1 == 1
      && RtlCompareMemory((unsigned __int8 *)(a1 + 2), (int)&RtlpAppPackageAuthority, 6) == 6
      && *(_DWORD *)(a1 + 8) == 2;
}
