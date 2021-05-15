// GetUTF32 
 
int __fastcall GetUTF32(unsigned __int16 *a1)
{
  int v1; // r1
  int v2; // r2
  int result; // r0

  if ( IsSurrogate(*a1) )
    result = *(unsigned __int16 *)(v1 + 2) + ((v2 - 55287) << 10);
  else
    result = v2;
  return result;
}
