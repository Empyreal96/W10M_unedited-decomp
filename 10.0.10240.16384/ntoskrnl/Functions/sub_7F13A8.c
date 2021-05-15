// sub_7F13A8 
 
void sub_7F13A8()
{
  if ( (PoDebug & 1) != 0 )
    DbgPrint("PopCreateHiberFileSecurityDescriptor: couldn't allocate ACL\n");
  JUMPOUT(0x78C0E4);
}
