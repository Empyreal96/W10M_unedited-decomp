// RtlAbsoluteToSelfRelativeSD 
 
int __fastcall RtlAbsoluteToSelfRelativeSD(int a1)
{
  int result; // r0

  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    result = -1073741593;
  else
    result = RtlMakeSelfRelativeSD();
  return result;
}
