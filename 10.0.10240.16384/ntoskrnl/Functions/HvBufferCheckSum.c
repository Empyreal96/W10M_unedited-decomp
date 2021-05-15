// HvBufferCheckSum 
 
int __fastcall HvBufferCheckSum(int a1, unsigned int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v4; // r1
  int v5; // r4
  int v6; // r6
  int *v7; // r2
  unsigned int v8; // r0
  int v9; // t1
  unsigned int i; // r2
  int v11; // r3
  int result; // r0

  v2 = a2 >> 2;
  v3 = a2 & 3;
  v4 = 0;
  v5 = 0;
  v6 = a1 + 4 * v2;
  if ( v2 > 1 )
  {
    v7 = (int *)(a1 + 4);
    v8 = v2 - 1;
    do
    {
      v9 = *v7++;
      v4 ^= v9;
      --v8;
    }
    while ( v8 );
  }
  for ( i = 0; i < v3; v5 = v11 + (v5 << 8) )
  {
    v11 = *(unsigned __int8 *)(i + v6);
    ++i;
  }
  result = v4 ^ v5;
  if ( (v4 ^ v5) == -1 )
    result = -2;
  if ( !result )
    result = 1;
  return result;
}
