// sub_51E04C 
 
void sub_51E04C()
{
  _DWORD *v0; // r5
  int v1; // r7

  ExFreeToNPagedLookasideList(v1 + 128, v0);
  JUMPOUT(0x44C52E);
}
