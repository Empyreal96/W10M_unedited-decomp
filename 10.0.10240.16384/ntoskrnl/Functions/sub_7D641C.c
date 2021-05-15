// sub_7D641C 
 
void sub_7D641C()
{
  unsigned int v0; // r6
  int v1; // r10

  if ( !WmipDereferenceEvent(v0) )
  {
    if ( v1 )
      ExFreePoolWithTag(v0);
    JUMPOUT(0x6DC1F2);
  }
  JUMPOUT(0x6DC1CA);
}
