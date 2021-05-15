// RtlAddressInSectionTable 
 
int __fastcall RtlAddressInSectionTable(int a1, unsigned int a2, int a3)
{
  int v5; // r0
  int result; // r0

  v5 = RtlSectionTableFromVirtualAddress();
  if ( !v5 )
    return 0;
  result = *(_DWORD *)(v5 + 20) - *(_DWORD *)(v5 + 12) + a2 + a3;
  if ( a2 < MmHighestUserAddress )
    result = sub_54DC80(result);
  return result;
}
