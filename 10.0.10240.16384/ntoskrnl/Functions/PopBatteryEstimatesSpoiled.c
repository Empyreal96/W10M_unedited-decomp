// PopBatteryEstimatesSpoiled 
 
int PopBatteryEstimatesSpoiled()
{
  unsigned __int64 v0; // r0
  int v1; // r4

  LODWORD(v0) = KeQueryInterruptTime();
  if ( PopEstimateSpoiledUntilTime < v0 )
    return 0;
  v1 = 1;
  DbgPrintEx(146, 3, (int)"Battery estimate suppressed\n", SHIDWORD(PopEstimateSpoiledUntilTime));
  return v1;
}
