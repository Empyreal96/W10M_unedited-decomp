// PnpValidateMultiSz 
 
int __fastcall PnpValidateMultiSz(int a1, int a2, int a3, int a4)
{
  int result; // r0
  unsigned int v6; // r4
  unsigned int v8; // r3
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  result = -1073741811;
  v6 = 0;
  if ( a1 )
  {
    do
    {
      result = RtlStringCchLengthW((unsigned __int16 *)(a1 + 2 * v6), a2 - v6, v9);
      if ( result < 0 )
        break;
      v8 = v9[0] + v6;
      if ( v9[0] + v6 < v6 )
        return -1073741675;
      v6 = v8 + 1;
      if ( v8 + 1 < v8 )
        return -1073741675;
      result = 0;
    }
    while ( v9[0] );
  }
  return result;
}
