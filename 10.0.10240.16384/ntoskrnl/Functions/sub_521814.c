// sub_521814 
 
void sub_521814()
{
  if ( (IopIrpExtensionStatus & 1) == 0 )
    JUMPOUT(0x45592A);
  JUMPOUT(0x45592C);
}
