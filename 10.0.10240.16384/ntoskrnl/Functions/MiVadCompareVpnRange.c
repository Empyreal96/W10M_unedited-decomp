// MiVadCompareVpnRange 
 
int __fastcall MiVadCompareVpnRange(_DWORD *a1, int a2)
{
  int result; // r0

  if ( a1[1] < *(_DWORD *)(a2 + 12) )
    result = -1;
  else
    result = *a1 > *(_DWORD *)(a2 + 16);
  return result;
}
