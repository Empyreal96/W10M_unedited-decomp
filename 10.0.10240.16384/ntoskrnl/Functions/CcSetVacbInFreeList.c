// CcSetVacbInFreeList 
 
int __fastcall CcSetVacbInFreeList(int a1, int a2)
{
  int result; // r0
  int v4; // r0

  --CcNumberOfMappedVacbs;
  if ( a2 )
    return sub_53DDCC();
  CcSetVacbIntoList(a1, &CcVacbFreeList);
  v4 = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 4) = 0;
  result = CcDereferenceVacbArray(v4, 1);
  ++CcNumberOfFreeVacbs;
  return result;
}
