// BiCloseKey 
 
int BiCloseKey()
{
  unsigned int v0; // r5

  v0 = BiCreateKeySecurityDescriptor(393241);
  if ( v0 )
  {
    BiZwSetSecurityObject();
    ExFreePoolWithTag(v0);
  }
  return BiZwClose();
}
