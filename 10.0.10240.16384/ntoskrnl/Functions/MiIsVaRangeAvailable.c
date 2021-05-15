// MiIsVaRangeAvailable 
 
int __fastcall MiIsVaRangeAvailable(int a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r2

  if ( !a4 )
    return sub_802DD8();
  v5 = a2 + a3 - 1;
  return (a2 >= 0x10000 || *(_DWORD *)(a1 + 780)) && v5 <= a4 && v5 > a2 && !MiCheckForConflictingVadExistence();
}
