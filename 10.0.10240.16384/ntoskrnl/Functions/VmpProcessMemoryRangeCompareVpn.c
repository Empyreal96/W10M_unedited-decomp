// VmpProcessMemoryRangeCompareVpn 
 
int __fastcall VmpProcessMemoryRangeCompareVpn(unsigned int *a1, int a2)
{
  unsigned int v2; // r2
  int result; // r0

  v2 = *a1;
  if ( *a1 > *(_DWORD *)(a2 + 36) )
    return 1;
  result = -1;
  if ( v2 >= *(_DWORD *)(a2 + 32) )
    result = 0;
  return result;
}
