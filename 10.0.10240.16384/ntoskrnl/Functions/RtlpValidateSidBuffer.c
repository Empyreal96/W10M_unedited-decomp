// RtlpValidateSidBuffer 
 
BOOL __fastcall RtlpValidateSidBuffer(_BYTE *a1, unsigned int a2)
{
  unsigned __int8 *v4; // r0
  BOOL result; // r0

  if ( a2 < RtlLengthRequiredSid(0)
    || (v4 = (unsigned __int8 *)RtlSubAuthorityCountSid((int)a1), a2 < RtlLengthRequiredSid(*v4)) )
  {
    result = 0;
  }
  else
  {
    result = RtlValidSid(a1);
  }
  return result;
}
