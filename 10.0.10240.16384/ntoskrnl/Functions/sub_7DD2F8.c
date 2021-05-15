// sub_7DD2F8 
 
void __fastcall sub_7DD2F8(int a1, int a2, _DWORD *a3)
{
  _BYTE *v3; // r5
  unsigned int v4; // r6
  unsigned __int16 *v5; // r8
  int v6; // lr
  _BYTE *v7; // r0
  int v8; // r4
  int v9; // t1
  unsigned int v10; // r1

  v7 = v3;
  if ( v6 )
  {
    v8 = NlsUnicodeToMbOemData;
    do
    {
      if ( !v4 )
        break;
      v9 = *v5++;
      v10 = *(unsigned __int16 *)(v8 + 2 * v9);
      if ( v10 >> 8 )
      {
        if ( v4-- < 2 )
          break;
        *v3++ = BYTE1(v10);
      }
      --v4;
      --v6;
      *v3++ = v10;
    }
    while ( v6 );
  }
  if ( a3 )
    *a3 = v3 - v7;
  JUMPOUT(0x6E9ACA);
}
