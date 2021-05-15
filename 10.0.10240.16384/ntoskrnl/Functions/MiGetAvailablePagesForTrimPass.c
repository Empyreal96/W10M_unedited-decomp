// MiGetAvailablePagesForTrimPass 
 
int __fastcall MiGetAvailablePagesForTrimPass(int a1, unsigned int a2)
{
  int result; // r0

  if ( a2 >= 4 )
    result = *(_DWORD *)(a1 + 3712);
  else
    result = MiGetAvailablePagesBelowPriority(a1, 6);
  return result;
}
