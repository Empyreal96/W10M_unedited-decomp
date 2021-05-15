// RtlStackTraceHashFunction 
 
int __fastcall RtlStackTraceHashFunction(int a1, unsigned __int16 *a2)
{
  int v2; // r4
  unsigned int v3; // r0
  int v4; // r2
  int v5; // t1

  v2 = 0;
  if ( 2 * a1 )
  {
    v3 = ((unsigned int)(2 * a1 - 1) >> 1) + 1;
    do
    {
      v4 = a2[1];
      v5 = *a2;
      a2 += 2;
      v2 += v5 ^ v4;
      --v3;
    }
    while ( v3 );
  }
  return v2;
}
