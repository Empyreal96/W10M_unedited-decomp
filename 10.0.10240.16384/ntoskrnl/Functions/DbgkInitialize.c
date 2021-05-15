// DbgkInitialize 
 
int DbgkInitialize()
{
  if ( !InitializationPhase )
    return DbgkpInitializePhase0();
  if ( InitializationPhase != 1 )
    sub_96E3B4();
  return DbgkpInitializePhase1();
}
