// VerifierInitSystem 
 
int VerifierInitSystem()
{
  if ( !InitializationPhase )
    return ViInitSystemPhase0();
  if ( InitializationPhase != 1 )
    sub_96EE14();
  return ViInitSystemPhase1();
}
