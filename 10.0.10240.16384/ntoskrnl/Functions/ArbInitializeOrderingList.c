// ArbInitializeOrderingList 
 
int __fastcall ArbInitializeOrderingList(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = ExAllocatePoolWithTag(1, 256, 1281520193);
  *(_DWORD *)(a1 + 4) = v2;
  if ( !v2 )
    return sub_80E830();
  *(_WORD *)a1 = 0;
  result = 0;
  *(_WORD *)(a1 + 2) = 16;
  return result;
}
