// sub_4F9730 
 
unsigned int __fastcall sub_4F9730(unsigned int result, __int16 *a2, unsigned int a3, int a4)
{
  __int16 *v4; // r4
  __int16 *v5; // r5
  unsigned int v6; // r1
  __int16 v7; // r3
  __int16 *v8; // r4
  __int16 v9; // t1

  v4 = a2;
  if ( a4 )
  {
    *a2 = 45;
    v4 = a2 + 1;
    result = -result;
  }
  v5 = v4;
  do
  {
    if ( !a3 )
      __brkdiv0();
    v6 = result % a3;
    result /= a3;
    if ( v6 <= 9 )
      v7 = v6 + 48;
    else
      v7 = v6 + 87;
    *v4++ = v7;
  }
  while ( result );
  *v4 = 0;
  v8 = v4 - 1;
  do
  {
    v9 = *v8--;
    v8[1] = *v5;
    *v5++ = v9;
  }
  while ( v5 < v8 );
  return result;
}
