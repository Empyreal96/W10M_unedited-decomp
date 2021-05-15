// IoCreateSymbolicLink 
 
int IoCreateSymbolicLink()
{
  int v0; // r4

  v0 = ZwCreateSymbolicLinkObject();
  if ( v0 >= 0 )
    ZwClose();
  return v0;
}
