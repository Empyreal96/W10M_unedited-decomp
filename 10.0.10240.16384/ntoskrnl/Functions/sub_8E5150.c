// sub_8E5150 
 
void sub_8E5150()
{
  int v0; // r5

  XdvEnabled = ViXdvDriverLoadImage(v0);
  if ( XdvEnabled )
    VfNotifyVerifierExtensions(0, 0);
  JUMPOUT(0x8E4BF2);
}
