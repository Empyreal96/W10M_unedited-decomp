// sub_7C0B0C 
 
void __fastcall sub_7C0B0C(int a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r4

  while ( 1 )
  {
    if ( a3[2] == a2 + 384 )
      a3[2] = *(_DWORD *)(a2 + 388);
    a3 = (_DWORD *)*a3;
    if ( a3 == v3 )
      JUMPOUT(0x6A8586);
  }
}
