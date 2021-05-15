// sub_7EECEC 
 
void sub_7EECEC()
{
  int v0; // r4
  int v1; // r5
  unsigned int v2; // r0

  v2 = *(_DWORD *)(v0 + 648);
  *(_WORD *)(v0 + 644) = v1;
  ExFreePoolWithTag(v2);
  *(_DWORD *)(v0 + 648) = v1;
  JUMPOUT(0x780FE6);
}
