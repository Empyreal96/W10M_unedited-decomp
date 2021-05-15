// sub_7E7FD8 
 
void sub_7E7FD8()
{
  unsigned int v0; // r4

  if ( !AlpcpAllocateMessageFromExtendedTables(v0 + 24) )
  {
    ExFreePoolWithTag(v0);
    JUMPOUT(0x6F9EFA);
  }
  JUMPOUT(0x6F9EF2);
}
