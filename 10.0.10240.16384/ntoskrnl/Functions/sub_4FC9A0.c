// sub_4FC9A0 
 
int __fastcall sub_4FC9A0(unsigned __int64 a1, _WORD *a2, unsigned int a3, unsigned int a4, int a5)
{
  int v5; // r4
  _WORD *v6; // r5
  unsigned int v8; // r3
  unsigned int v9; // r7
  __int16 *v10; // r4
  __int16 *v11; // r6
  unsigned int v12; // r2
  __int16 v13; // r3
  __int16 *v14; // r4
  __int16 v15; // t1

  v6 = a2;
  if ( !a2 )
    goto LABEL_27;
  if ( !a3 )
    v5 = 22;
  if ( !a3 )
    goto LABEL_23;
  *a2 = 0;
  if ( a5 )
    v8 = 2;
  else
    v8 = 1;
  if ( a3 <= v8 )
  {
LABEL_22:
    v5 = 34;
LABEL_23:
    PopPoCoalescinCallback();
    return v5;
  }
  if ( a4 - 2 > 0x22 )
  {
LABEL_27:
    PopPoCoalescinCallback();
    return 22;
  }
  v9 = 0;
  v10 = a2;
  if ( a5 )
  {
    *a2 = 45;
    v10 = a2 + 1;
    v9 = 1;
    a1 = -(__int64)a1;
  }
  v11 = v10;
  do
  {
    if ( !a4 )
      __brkdiv0();
    LODWORD(a1) = _rt_udiv64(a4, a1);
    if ( v12 <= 9 )
      v13 = v12 + 48;
    else
      v13 = v12 + 87;
    ++v9;
    *v10++ = v13;
  }
  while ( a1 && v9 < a3 );
  if ( v9 >= a3 )
  {
    *v6 = 0;
    goto LABEL_22;
  }
  *v10 = 0;
  v14 = v10 - 1;
  do
  {
    v15 = *v14--;
    v14[1] = *v11;
    *v11++ = v15;
  }
  while ( v11 < v14 );
  return 0;
}
