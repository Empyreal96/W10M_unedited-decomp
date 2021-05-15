// sub_80DD6C 
 
void sub_80DD6C()
{
  unsigned int v0; // r5
  unsigned int v1; // r0

  v1 = *(_DWORD *)(v0 + 36);
  if ( v1 )
  {
    ExFreePoolWithTag(v1);
    *(_DWORD *)(v0 + 36) = 0;
  }
  ExFreePoolWithTag(v0);
  JUMPOUT(0x795548);
}
