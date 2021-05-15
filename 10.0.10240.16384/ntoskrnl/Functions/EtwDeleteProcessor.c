// EtwDeleteProcessor 
 
int __fastcall EtwDeleteProcessor(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 3596);
  if ( result )
  {
    EtwpCCSwapDeleteProcessor(result);
    result = ExFreePoolWithTag(*(_DWORD *)(a1 + 3596));
    *(_DWORD *)(a1 + 3596) = 0;
  }
  return result;
}
