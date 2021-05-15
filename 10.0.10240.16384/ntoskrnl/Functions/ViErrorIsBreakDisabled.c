// ViErrorIsBreakDisabled 
 
int __fastcall ViErrorIsBreakDisabled(int a1)
{
  int result; // r0
  int *v3; // r4
  int v4; // r2
  int v5; // t1

  result = 1;
  v3 = ViErrorDescriptions;
  v4 = 0;
  while ( 1 )
  {
    v5 = *v3;
    v3 += 3;
    if ( v5 == a1 )
      break;
    if ( (unsigned int)++v4 >= 0x3F )
      return result;
  }
  if ( (ViErrorDescriptions[3 * v4 + 1] & 1) == 0 )
    result = 0;
  return result;
}
