// PopThermalUpdatePassiveTimeTracking 
 
int __fastcall PopThermalUpdatePassiveTimeTracking(__int64 a1)
{
  int v1; // r7
  int v2; // r4

  v1 = a1;
  if ( !*(_BYTE *)a1 )
  {
    v2 = 20;
    do
    {
      if ( HIDWORD(a1) >= PopThermalTrackingThresholds[v2 - 1] )
        break;
      --v2;
    }
    while ( v2 );
    LODWORD(a1) = KeQueryInterruptTime();
    *(_QWORD *)(v1 + 8 * v2 + 8) = *(_QWORD *)(v1 + 8 * v2 + 8) - *(_QWORD *)(v1 + 8) + a1;
    *(_QWORD *)(v1 + 8) = a1;
  }
  return a1;
}
