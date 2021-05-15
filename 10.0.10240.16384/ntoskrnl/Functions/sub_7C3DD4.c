// sub_7C3DD4 
 
void __fastcall sub_7C3DD4(int a1, unsigned int a2, _DWORD *a3)
{
  int v3; // r5
  _BYTE *v4; // r6
  unsigned __int16 *v5; // r7
  _BYTE *v6; // r0
  int v7; // lr
  int v8; // t1
  unsigned int v9; // r4

  v6 = v4;
  if ( v3 )
  {
    v7 = NlsUnicodeToMbAnsiData;
    do
    {
      if ( !a2 )
        break;
      v8 = *v5++;
      v9 = *(unsigned __int16 *)(v7 + 2 * v8);
      if ( v9 >> 8 )
      {
        if ( a2-- < 2 )
          break;
        *v4++ = BYTE1(v9);
      }
      --a2;
      --v3;
      *v4++ = v9;
    }
    while ( v3 );
  }
  if ( a3 )
    *a3 = v4 - v6;
  JUMPOUT(0x6B4B1C);
}
