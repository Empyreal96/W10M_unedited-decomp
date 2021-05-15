// SeInitSystem 
 
int SeInitSystem()
{
  if ( !InitializationPhase )
    return SepInitializationPhase0();
  if ( InitializationPhase != 1 )
    sub_96C5A8();
  return SepInitializationPhase1();
}
