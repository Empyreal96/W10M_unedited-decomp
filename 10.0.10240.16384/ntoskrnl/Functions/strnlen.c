// strnlen 
 
unsigned int __fastcall strnlen(char *a1, unsigned int a2)
{
  unsigned int result; // r0

  for ( result = 0; result < a2; ++result )
  {
    if ( !*a1++ )
      break;
  }
  return result;
}
