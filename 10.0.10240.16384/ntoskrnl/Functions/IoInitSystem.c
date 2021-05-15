// IoInitSystem 
 
int __fastcall IoInitSystem(int a1)
{
  if ( !IoInitSystemPreDrivers(a1) )
    JUMPOUT(0x9670FE);
  if ( !IopInitializeSystemDrivers() )
    return sub_9670F0();
  if ( !PnpBootOptions )
    PnpSerializeBoot();
  if ( ViVerifierEnabled )
    VfNotifyVerifierOfEvent(0);
  IopRegistryInitializeCallbacks();
  return 1;
}
