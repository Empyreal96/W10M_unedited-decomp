// sub_80DD44 
 
void sub_80DD44()
{
  int v0; // r4
  int v1; // r8
  unsigned int v2; // r0
  unsigned int v3; // r0

  v2 = *(_DWORD *)(v0 + 360);
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *(_DWORD *)(v0 + 360) = v1;
  }
  v3 = *(_DWORD *)(v0 + 364);
  if ( v3 )
  {
    ExFreePoolWithTag(v3);
    *(_DWORD *)(v0 + 364) = v1;
  }
  JUMPOUT(0x7954C8);
}
