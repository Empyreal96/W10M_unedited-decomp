// KsepPoolFreePaged 
 
int __fastcall KsepPoolFreePaged(int result)
{
  unsigned int v1; // r1

  if ( result )
  {
    result = ExFreePoolWithTag(result, 1631933259);
    __dmb(0xBu);
    do
      v1 = __ldrex(dword_621724);
    while ( __strex(v1 + 1, dword_621724) );
    __dmb(0xBu);
  }
  return result;
}
