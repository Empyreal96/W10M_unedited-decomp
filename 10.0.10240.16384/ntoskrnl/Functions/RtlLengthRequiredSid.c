// RtlLengthRequiredSid 
 
int __fastcall RtlLengthRequiredSid(unsigned int a1)
{
  int result; // r0

  if ( a1 > 0x3FFFFFF7 )
    result = -1;
  else
    result = 4 * (a1 + 2);
  return result;
}
