// sub_7E0DD4 
 
void sub_7E0DD4()
{
  _DWORD *v0; // r4
  int v1; // r6
  unsigned int v2; // [sp+Ch] [bp-1Ch]

  v0[40] = *(_DWORD *)(v1 + 100);
  v0[41] = *(_DWORD *)(v1 + 104);
  v0[42] |= 0x2000u;
  if ( v2 )
    ExFreePoolWithTag(v2);
  JUMPOUT(0x778178);
}
