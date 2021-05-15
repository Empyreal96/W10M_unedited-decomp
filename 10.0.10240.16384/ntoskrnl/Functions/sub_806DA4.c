// sub_806DA4 
 
void sub_806DA4()
{
  int v0; // r5
  unsigned int v1; // r2

  v0 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xB38);
  v1 = *(unsigned __int16 *)(v0 + 8);
  ++*(_DWORD *)(v0 + 20);
  if ( *(unsigned __int16 *)(v0 + 4) < v1 )
    JUMPOUT(0x757A84);
  JUMPOUT(0x757A5C);
}
