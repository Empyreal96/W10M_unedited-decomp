// sub_4FBA18 
 
int __fastcall sub_4FBA18(int result, int a2, int *a3)
{
  int v5; // r3

  if ( ((*(_DWORD *)(a2 + 12) & 0x40) == 0 || *(_DWORD *)(a2 + 8))
    && (result = fputwc_nolock(result, a2), result == 0xFFFF)
    && (*(_DWORD *)(a2 + 12) & 0x20) != 0 )
  {
    v5 = -1;
  }
  else
  {
    v5 = *a3 + 1;
  }
  *a3 = v5;
  return result;
}
