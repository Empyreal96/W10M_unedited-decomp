// sub_7EEB48 
 
void sub_7EEB48()
{
  unsigned int v0; // r5
  int v1; // r7
  _BYTE *v2; // r0

  if ( v1 )
  {
    v2 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, v0, 538996816);
    if ( !v2 )
      JUMPOUT(0x780D3C);
    memset(v2, 0, v0);
  }
  JUMPOUT(0x780CF6);
}
