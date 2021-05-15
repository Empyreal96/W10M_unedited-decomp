// CmpRemoveFromHiveFileList 
 
unsigned int __fastcall CmpRemoveFromHiveFileList(int a1)
{
  unsigned int result; // r0

  ZwDeleteValueKey();
  result = *(_DWORD *)(a1 + 1988);
  if ( result )
    result = ExFreePoolWithTag(result);
  return result;
}
