// sub_53A084 
 
void sub_53A084()
{
  int v0; // r4
  int v1; // r2
  int v2; // r3

  if ( MiGetPagePrivilege() )
  {
    v2 = *(unsigned __int8 *)(v0 + 18) | 0x20;
    *(_BYTE *)(v0 + 18) = v2;
    MiClearPfnImageVerified(v0, 28, v1, v2);
  }
  JUMPOUT(0x499A22);
}
