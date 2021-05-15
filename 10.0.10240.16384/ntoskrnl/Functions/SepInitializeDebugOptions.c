// SepInitializeDebugOptions 
 
int SepInitializeDebugOptions()
{
  int result; // r0

  if ( KdDebuggerEnabled && !KdDebuggerNotPresent && (SeCiDebugOptions & 1) == 0 )
    SeCiDebugOptions |= 2u;
  if ( SeILSigningPolicy )
    result = sub_96EDC0();
  return result;
}
