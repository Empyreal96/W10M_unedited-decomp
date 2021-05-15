// RtlpSanitizeContextFlags 
 
int __fastcall RtlpSanitizeContextFlags(int *a1)
{
  int result; // r0

  result = RtlpValidateContextFlags(*a1, 0);
  if ( result >= 0 && (*a1 & 0x200000) == 0 )
    result = -1073741811;
  if ( result == -1073741811 )
    result = sub_803660();
  return result;
}
