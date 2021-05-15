// RtlEqualSid 
 
BOOL __fastcall RtlEqualSid(unsigned __int16 *a1, unsigned __int16 *a2)
{
  BOOL result; // r0

  if ( *a1 == *a2 )
    result = memcmp((unsigned int)a1, (unsigned int)a2, 4 * (*((unsigned __int8 *)a1 + 1) + 2)) == 0;
  else
    result = 0;
  return result;
}
