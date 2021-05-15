// sub_528DF8 
 
void sub_528DF8()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r0

  v2 = IoFindDeviceThatFailedIrp(v1);
  if ( v2 )
    *v0 = *(_DWORD *)(v2 + 8);
  JUMPOUT(0x4DF23A);
}
