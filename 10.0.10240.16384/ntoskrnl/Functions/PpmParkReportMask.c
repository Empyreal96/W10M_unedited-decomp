// PpmParkReportMask 
 
int PpmParkReportMask()
{
  if ( !PpmIsParkingEnabled || dword_616318 == dword_616324 )
    return 1;
  PpmPerfReportedCoreParkingMask = PpmPerfCoreParkingMask[0];
  unk_616320 = PpmPerfCoreParkingMask[1];
  dword_616324 = dword_616318;
  if ( PpmParkMaskHandler )
    PpmParkMaskHandler(PpmCheckTime, dword_61E04C, PpmPerfCoreParkingMask);
  KeCpuSetReportParkedProcessors((int)PpmPerfCoreParkingMask, 2);
  return 1;
}
