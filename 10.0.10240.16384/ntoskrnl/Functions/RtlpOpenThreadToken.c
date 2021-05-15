// RtlpOpenThreadToken 
 
int RtlpOpenThreadToken()
{
  int result; // r0

  result = ZwOpenThreadTokenEx();
  if ( result < 0 )
    result = sub_7E8F28();
  return result;
}
