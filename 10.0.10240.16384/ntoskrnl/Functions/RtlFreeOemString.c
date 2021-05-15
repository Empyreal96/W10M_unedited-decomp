// RtlFreeOemString 
 
unsigned int __fastcall RtlFreeOemString(int a1)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 4);
  if ( result )
    result = ExFreePool(result);
  return result;
}
