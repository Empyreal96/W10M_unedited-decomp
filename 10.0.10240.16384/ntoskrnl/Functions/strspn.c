// strspn 
 
int __fastcall strspn(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // r4
  int v3; // r3
  bool v4; // cf
  unsigned int v6; // r3
  unsigned int v7; // t1
  unsigned int v8; // r2
  int result; // r0
  _BYTE v10[48]; // [sp-4h] [bp-30h] BYREF

  v2 = a2;
  v3 = 0;
  v4 = 0;
  do
  {
    if ( v4 )
      _report_rangecheckfailure(a1);
    v10[v3] = 0;
    v4 = (unsigned int)++v3 >= 0x20;
  }
  while ( v3 < 32 );
  v6 = (unsigned __int8)*a2;
  if ( *a2 )
  {
    do
    {
      v10[v6 >> 3] |= 1 << (v6 & 7);
      v7 = (unsigned __int8)*++v2;
      v6 = v7;
    }
    while ( v7 );
  }
  v8 = (unsigned __int8)*a1;
  if ( !*a1 )
    return 0;
  result = 0;
  if ( ((1 << (v8 & 7)) & (unsigned __int8)v10[v8 >> 3]) != 0 )
  {
    do
      ++result;
    while ( ((1 << (a1[result] & 7)) & (unsigned __int8)v10[(unsigned __int8)a1[result] >> 3]) != 0 );
  }
  return result;
}
