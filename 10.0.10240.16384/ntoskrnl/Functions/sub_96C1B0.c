// sub_96C1B0 
 
void sub_96C1B0()
{
  int v0; // r7
  unsigned int v1; // r0

  v1 = *(_DWORD *)(*(_DWORD *)v0 + 8);
  if ( v1 )
    ExFreePoolWithTag(v1);
  JUMPOUT(0x9592F0);
}
