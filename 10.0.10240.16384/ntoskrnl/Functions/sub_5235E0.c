// sub_5235E0 
 
void sub_5235E0()
{
  int v0; // r6

  __dmb(0xBu);
  *(_DWORD *)(v0 + 16) |= 1u;
  JUMPOUT(0x459BAC);
}
