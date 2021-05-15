// PpInitSystem 
 
int PpInitSystem()
{
  int v1; // r0

  if ( InitializationPhase )
  {
    if ( InitializationPhase != 1 )
      sub_9705C8();
  }
  else
  {
    v1 = ExInitializeResourceLite((int)&PnpRegistryDeviceResource);
    PnpInitializeDeviceReferenceTable(v1);
  }
  return 1;
}
