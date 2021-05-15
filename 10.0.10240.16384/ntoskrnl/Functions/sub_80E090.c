// sub_80E090 
 
void __fastcall sub_80E090(int a1)
{
  unsigned int v1; // r4
  _DWORD **v2; // r0
  _DWORD *i; // r3
  unsigned int v4; // r1

  if ( a1 == 2 )
    a1 = 1;
  v2 = (_DWORD **)((char *)&IopLegacyBusInformationTable + 8 * a1);
  for ( i = *v2; i != v2; i = (_DWORD *)*i )
  {
    v4 = *(i - 24);
    if ( v4 == v1 || v4 > v1 )
      break;
  }
  JUMPOUT(0x795EFA);
}
