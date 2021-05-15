// sub_554EC4 
 
void __fastcall sub_554EC4(_DWORD *a1)
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
  JUMPOUT(0x4F721E);
}
