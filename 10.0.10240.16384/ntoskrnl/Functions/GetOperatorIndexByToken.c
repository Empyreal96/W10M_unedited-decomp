// GetOperatorIndexByToken 
 
unsigned int __fastcall GetOperatorIndexByToken(int a1)
{
  __int16 **v1; // r2
  unsigned int result; // r0

  v1 = &Operators;
  result = 0;
  while ( *((unsigned __int8 *)v1 + 4) != a1 )
  {
    ++result;
    v1 += 5;
    if ( result >= 0x17 )
      return -1;
  }
  return result;
}
