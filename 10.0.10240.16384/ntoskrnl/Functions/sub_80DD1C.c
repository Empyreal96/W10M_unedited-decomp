// sub_80DD1C 
 
void sub_80DD1C()
{
  int v0; // r4
  int v1; // r6
  unsigned int v2; // r0

  v2 = *(_DWORD *)(v0 + 20);
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *(_DWORD *)(v0 + 20) = v1;
  }
  JUMPOUT(0x7953A8);
}
