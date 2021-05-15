// sub_56522C 
 
int __fastcall sub_56522C(char *a1, int a2, int *a3)
{
  int v4; // r1
  int result; // r0
  int v7; // r3

  v4 = 257;
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
      v7 = 257 - v4;
    *a3 = v7;
  }
  return result;
}
