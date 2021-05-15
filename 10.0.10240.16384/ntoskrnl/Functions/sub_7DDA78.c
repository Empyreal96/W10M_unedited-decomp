// sub_7DDA78 
 
void sub_7DDA78()
{
  unsigned int v0; // r4
  int v1; // r5

  ExpFreeTablePagedPool(*(_DWORD *)(v1 + 12), v0, 0x1000u);
  JUMPOUT(0x6ED142);
}
