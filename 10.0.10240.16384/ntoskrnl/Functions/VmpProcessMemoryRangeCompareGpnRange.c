// VmpProcessMemoryRangeCompareGpnRange 
 
int __fastcall VmpProcessMemoryRangeCompareGpnRange(int a1, int a2)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 28) >= *(_DWORD *)(a2 + 12) )
    result = *(_DWORD *)(a1 + 24) > *(_DWORD *)(a2 + 16);
  else
    result = -1;
  return result;
}
