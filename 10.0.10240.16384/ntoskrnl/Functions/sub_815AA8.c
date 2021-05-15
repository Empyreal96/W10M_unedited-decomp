// sub_815AA8 
 
void sub_815AA8()
{
  int v0; // r4

  KeSetEvent(*(_DWORD *)(v0 + 64), 0, 0);
  *(_DWORD *)(v0 + 8) &= 0xFFFFFFF7;
  JUMPOUT(0x7ABEA0);
}
