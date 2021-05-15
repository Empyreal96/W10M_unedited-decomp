// sub_524DD4 
 
void __fastcall sub_524DD4(_DWORD *a1)
{
  int v1; // r5
  _DWORD *v2; // r4

  do
  {
    v2 = (_DWORD *)*a1;
    (*(void (**)(void))(v1 + 44))();
    a1 = v2;
  }
  while ( v2 );
  JUMPOUT(0x45E316);
}
