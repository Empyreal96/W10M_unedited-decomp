// sub_80DB7C 
 
void __fastcall sub_80DB7C(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  _DWORD *v4; // r1
  int v5; // r0

  v3 = 0;
  if ( a3[4] )
  {
    v4 = a3;
    do
    {
      v5 = v4[5];
      if ( *(_BYTE *)(v5 + 8) )
      {
        if ( *a3 == 1 )
          *(_DWORD *)(v5 + 48) |= 1u;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < a3[4] );
  }
  JUMPOUT(0x795260);
}
