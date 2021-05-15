// sub_51F7D0 
 
void sub_51F7D0()
{
  int v0; // r9

  if ( (IopIrpExtensionStatus & v0) == 0 )
    JUMPOUT(0x450244);
  JUMPOUT(0x450246);
}
