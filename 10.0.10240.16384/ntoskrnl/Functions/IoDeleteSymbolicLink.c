// IoDeleteSymbolicLink 
 
int IoDeleteSymbolicLink()
{
  int v0; // r4

  v0 = ZwOpenSymbolicLinkObject();
  if ( v0 >= 0 )
  {
    v0 = ZwMakeTemporaryObject();
    if ( v0 >= 0 )
      ZwClose();
  }
  return v0;
}
