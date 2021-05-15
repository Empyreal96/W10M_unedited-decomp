// VmpProcessMemoryRangeCompareVpnRange 
 
int __fastcall VmpProcessMemoryRangeCompareVpnRange(int a1, int a2)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 36) >= *(_DWORD *)(a2 + 32) )
    result = *(_DWORD *)(a1 + 32) > *(_DWORD *)(a2 + 36);
  else
    result = -1;
  return result;
}
