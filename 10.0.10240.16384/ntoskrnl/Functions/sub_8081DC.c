// sub_8081DC 
 
void sub_8081DC()
{
  unsigned int v0; // r4

  if ( EtwpAddGuidEntry(v0, 2) )
    JUMPOUT(0x75A660);
  JUMPOUT(0x75A758);
}
