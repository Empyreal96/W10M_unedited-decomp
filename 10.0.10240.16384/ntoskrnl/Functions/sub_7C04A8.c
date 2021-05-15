// sub_7C04A8 
 
void sub_7C04A8()
{
  int v0; // r6
  unsigned int v1; // r7
  int v2; // r0

  if ( v0 )
  {
    v2 = *(_DWORD *)(v0 + 12);
    if ( v2 )
      PsReturnSharedPoolQuota(v2, v1, 0);
  }
  JUMPOUT(0x6A7190);
}
