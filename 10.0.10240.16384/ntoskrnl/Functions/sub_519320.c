// sub_519320 
 
void sub_519320()
{
  int v0; // r5
  char v1; // r0
  char v2; // r3

  v1 = KfRaiseIrql(2);
  v2 = *(_BYTE *)(v0 + 5);
  *(_BYTE *)(v0 + 4) = v1;
  *(_BYTE *)(v0 + 5) = v2 | 1;
  JUMPOUT(0x4DAB3A);
}
