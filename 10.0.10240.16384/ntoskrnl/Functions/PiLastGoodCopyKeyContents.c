// PiLastGoodCopyKeyContents 
 
int PiLastGoodCopyKeyContents()
{
  int v0; // r5
  int v1; // r4

  v0 = ExAllocatePoolWithTag(1, 1048, 1733062736);
  if ( !v0 )
    return -1073741670;
  v1 = ZwOpenKey();
  if ( v1 >= 0 )
    return sub_96ECAC();
  ExFreePoolWithTag(v0);
  return v1;
}
