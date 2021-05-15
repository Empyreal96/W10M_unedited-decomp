// wcsnlen 
 
unsigned int __fastcall wcsnlen(unsigned __int16 *a1, unsigned int a2)
{
  unsigned int result; // r0

  for ( result = 0; result < a2; ++result )
  {
    if ( !*a1++ )
      break;
  }
  return result;
}
