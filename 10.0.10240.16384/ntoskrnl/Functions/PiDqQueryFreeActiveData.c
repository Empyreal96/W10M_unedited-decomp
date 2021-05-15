// PiDqQueryFreeActiveData 
 
int __fastcall PiDqQueryFreeActiveData(int a1)
{
  while ( !RtlIsGenericTableEmptyAvl(a1 + 36) )
    PiDqQueryDeleteObjectFromResultSet(a1, *(_DWORD *)(*(_DWORD *)(a1 + 44) + 16));
  return sub_7C80CC();
}
