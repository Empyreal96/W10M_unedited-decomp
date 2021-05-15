// sub_810F20 
 
void sub_810F20()
{
  int v0; // r5
  unsigned int v1; // r7
  int v2; // r2

  if ( v1 >= 0x40 )
    v2 = 1;
  else
    v2 = WmipLoggerContext[v1];
  if ( (v2 & v0) == 0 )
  {
    if ( *(_DWORD *)(v2 + 104) )
      JUMPOUT(0x79EFFC);
    *(_DWORD *)(v2 + 608) |= 0x4000u;
  }
  JUMPOUT(0x79EFAC);
}
