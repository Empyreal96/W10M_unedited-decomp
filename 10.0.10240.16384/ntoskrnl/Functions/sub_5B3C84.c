// sub_5B3C84 
 
int __fastcall sub_5B3C84(unsigned __int16 *a1, int a2, int *a3)
{
  int v4; // r1
  int result; // r0
  int v7; // r3

  v4 = 0x7FFF;
  result = 0;
  do
  {
    if ( !*a1++ )
      break;
    --v4;
  }
  while ( v4 );
  if ( !v4 )
    result = -1073741811;
  if ( a3 )
  {
    if ( result < 0 )
      v7 = 0;
    else
      v7 = 0x7FFF - v4;
    *a3 = v7;
  }
  return result;
}
