// KiInitSystem 
 
int KiInitSystem()
{
  if ( !KiForceSymbolReferencesTrigger )
    JUMPOUT(0x9668B8);
  return sub_9668B4();
}
