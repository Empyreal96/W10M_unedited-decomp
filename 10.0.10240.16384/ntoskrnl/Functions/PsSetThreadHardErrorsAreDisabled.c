// PsSetThreadHardErrorsAreDisabled 
 
unsigned int __fastcall PsSetThreadHardErrorsAreDisabled(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int result; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 960);
  if ( a2 )
  {
    do
      result = __ldrex(v2);
    while ( __strex(result | 0x10, v2) );
  }
  else
  {
    do
      result = __ldrex(v2);
    while ( __strex(result & 0xFFFFFFEF, v2) );
  }
  __dmb(0xBu);
  return result;
}
