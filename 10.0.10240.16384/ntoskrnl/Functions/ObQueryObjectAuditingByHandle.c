// ObQueryObjectAuditingByHandle 
 
int ObQueryObjectAuditingByHandle()
{
  __mrc(15, 0, 13, 0, 3);
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    JUMPOUT(0x7E946E);
  return sub_7E9450();
}
