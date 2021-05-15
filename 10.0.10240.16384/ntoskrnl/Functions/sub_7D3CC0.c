// sub_7D3CC0 
 
void __fastcall sub_7D3CC0(int a1)
{
  int v1; // r5
  int v2; // r4

  do
  {
    v2 = *(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 16) = v1;
    KeSetEvent(a1, 0, 0);
    a1 = v2;
  }
  while ( v2 );
  JUMPOUT(0x6D42E8);
}
