// ObpDeleteSymbolicLink 
 
unsigned int __fastcall ObpDeleteSymbolicLink(int a1)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 12);
  if ( result )
    result = ExFreePoolWithTag(result);
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
