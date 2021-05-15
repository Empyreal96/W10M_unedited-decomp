// HvpHeaderCheckSum 
 
int __fastcall HvpHeaderCheckSum(int *a1)
{
  int result; // r0
  int v3; // r1
  int v4; // t1

  result = 0;
  v3 = 127;
  do
  {
    v4 = *a1++;
    result ^= v4;
    --v3;
  }
  while ( v3 );
  if ( result == -1 )
    result = -2;
  if ( !result )
    result = 1;
  return result;
}
