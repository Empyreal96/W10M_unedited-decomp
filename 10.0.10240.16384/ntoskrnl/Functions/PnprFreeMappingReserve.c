// PnprFreeMappingReserve 
 
int __fastcall PnprFreeMappingReserve(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = *(_DWORD *)a1;
  if ( v2 )
  {
    IoFreeMdl(v2);
    *(_DWORD *)a1 = 0;
  }
  result = *(_DWORD *)(a1 + 4);
  if ( result )
  {
    result = MmFreeMappingAddress(result, 1366322768);
    *(_DWORD *)(a1 + 4) = 0;
  }
  *(_WORD *)(a1 + 8) = 0;
  return result;
}
