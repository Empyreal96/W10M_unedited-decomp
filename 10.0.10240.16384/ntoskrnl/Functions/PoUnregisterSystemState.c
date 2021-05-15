// PoUnregisterSystemState 
 
int __fastcall PoUnregisterSystemState(int result)
{
  if ( result )
    result = PoDeletePowerRequest();
  return result;
}
