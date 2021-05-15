// sub_555F7C 
 
int __fastcall sub_555F7C(char *a1, int a2, int *a3)
{
  int result; // r0
  int v5; // r1
  int v7; // r3

  result = 0;
  v5 = 256;
  do
  {
    if ( !*a1++ )
      break;
    --v5;
  }
  while ( v5 );
  if ( !v5 )
    result = -1073741811;
  if ( a3 )
  {
    v7 = 256 - v5;
    if ( result < 0 )
      v7 = 0;
    *a3 = v7;
  }
  return result;
}
