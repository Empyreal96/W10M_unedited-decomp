// WdipSemCleanupGroupPolicy 
 
int WdipSemCleanupGroupPolicy()
{
  int result; // r0

  result = WdipSemDisabledScenarioTable;
  if ( WdipSemDisabledScenarioTable )
    result = sub_7D0E54();
  return result;
}
