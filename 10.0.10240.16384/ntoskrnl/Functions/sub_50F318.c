// sub_50F318 
 
void sub_50F318()
{
  if ( (IopIrpExtensionStatus & 1) == 0 )
    JUMPOUT(0x4F024A);
  JUMPOUT(0x4F024C);
}
