// sub_819778 
 
void __fastcall sub_819778(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r4

  do
  {
    v4 = (_DWORD *)*a4;
    KeSetEvent((int)(a4 + 1), 1, 0);
    a4 = v4;
  }
  while ( v4 );
  JUMPOUT(0x7B5620);
}
