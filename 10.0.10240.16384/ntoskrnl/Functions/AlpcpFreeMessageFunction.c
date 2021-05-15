// AlpcpFreeMessageFunction 
 
unsigned int __fastcall AlpcpFreeMessageFunction(unsigned int a1)
{
  unsigned int result; // r0

  if ( (*(_DWORD *)(a1 + 160) & 0x7FFFFFFF) != 0 )
    result = sub_7F6CA4();
  else
    result = ExFreePoolWithTag(a1);
  return result;
}
