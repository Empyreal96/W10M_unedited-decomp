// AuthzBasepIsCompareRelevantAttribute 
 
int __fastcall AuthzBasepIsCompareRelevantAttribute(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 28) & 0x40) != 0 )
    result = 0;
  else
    result = sub_7E7E04();
  return result;
}
