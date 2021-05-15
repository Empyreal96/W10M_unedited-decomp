// IopMemFindSuitableRange 
 
int __fastcall IopMemFindSuitableRange(int a1, int a2)
{
  int result; // r0

  if ( (*(_DWORD *)(*(_DWORD *)(a2 + 32) + 24) & 1) != 0 )
    result = sub_80E378();
  else
    result = ArbFindSuitableRange();
  return result;
}
