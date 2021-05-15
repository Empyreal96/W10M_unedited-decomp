// sub_551EEC 
 
void sub_551EEC()
{
  int v0; // r4
  int v1; // r7
  char v2; // r8

  if ( !*(_BYTE *)(v0 + 39) )
  {
    PopSqmThermalCriticalShutdown(v0);
    PopDiagTraceZoneCriticalTripPointExceeded(v0 + 160, v1);
    *(_BYTE *)(v0 + 39) = v2;
  }
  JUMPOUT(0x4F08E0);
}
