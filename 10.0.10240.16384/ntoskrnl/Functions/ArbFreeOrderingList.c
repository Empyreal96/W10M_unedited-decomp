// ArbFreeOrderingList 
 
int __fastcall ArbFreeOrderingList(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 4);
  if ( result )
    return sub_80E840();
  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 2) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
