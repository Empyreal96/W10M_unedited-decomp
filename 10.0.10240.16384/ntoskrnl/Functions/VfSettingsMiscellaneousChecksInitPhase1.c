// VfSettingsMiscellaneousChecksInitPhase1 
 
int VfSettingsMiscellaneousChecksInitPhase1()
{
  int result; // r0

  if ( (MmVerifierData & 0x800) != 0 )
    result = ViSettingsEnableKernelHandleChecking(1);
  return result;
}
