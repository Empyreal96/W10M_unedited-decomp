// EncodeAttributeName 
 
int __fastcall EncodeAttributeName(unsigned __int16 *a1, unsigned int a2, int *a3)
{
  unsigned __int16 *v3; // r5
  int v4; // r6
  _BYTE *v7; // r0
  unsigned int v8; // r8
  int v9; // r4
  int v10; // r0
  int v11; // r2
  int v12; // r4
  __int16 v13; // r3

  v3 = a1;
  v4 = 0;
  if ( !a1 || !a2 || !a3 )
    return 87;
  if ( (a2 & 1) != 0 )
    return 1336;
  v7 = SddlpAlloc(5 * a2 + 2);
  *a3 = (int)v7;
  if ( !v7 )
    return 8;
  v8 = a2 >> 1;
  if ( a2 >> 1 )
  {
    v9 = 0;
    do
    {
      v10 = IsEncodedAttributeChar(*v3);
      v11 = *a3;
      if ( v10 )
      {
        *(_WORD *)(v9 + v11) = 37;
        v12 = v9 + 2;
        *(_WORD *)(v12 + v11) = a0123456789abcd[(unsigned __int8)HIBYTE(*v3) >> 4];
        v12 += 2;
        *(_WORD *)(v12 + v11) = a0123456789abcd[*((_BYTE *)v3 + 1) & 0xF];
        v12 += 2;
        *(_WORD *)(v12 + v11) = a0123456789abcd[(*v3 >> 4) & 0xF];
        v9 = v12 + 2;
        v13 = a0123456789abcd[*(_BYTE *)v3 & 0xF];
      }
      else
      {
        v13 = *v3;
      }
      *(_WORD *)(v9 + v11) = v13;
      v9 += 2;
      ++v3;
      --v8;
    }
    while ( v8 );
  }
  return v4;
}
