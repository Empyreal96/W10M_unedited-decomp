// SepIsSidEqual 
 
BOOL __fastcall SepIsSidEqual(unsigned __int16 *a1, unsigned __int16 *a2)
{
  if ( a1 )
    return a2 && RtlEqualSid(a1, a2);
  return !a2;
}
