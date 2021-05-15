// sub_96BE64 
 
void __fastcall sub_96BE64(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  _DWORD *i; // r4
  unsigned __int8 *v6; // r0

  if ( a3 )
  {
    for ( i = *(_DWORD **)(a3 + 8); i; i = (_DWORD *)*i )
    {
      v6 = (unsigned __int8 *)i[1];
      if ( v6 && !strnicmp(v6, (unsigned __int8 *)(v3 + 1), v4 - 2) && !*(_BYTE *)(i[1] + v4 - 2) )
        break;
    }
  }
  JUMPOUT(0x958806);
}
