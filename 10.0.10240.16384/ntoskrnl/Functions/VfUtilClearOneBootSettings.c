// VfUtilClearOneBootSettings 
 
int VfUtilClearOneBootSettings()
{
  char v1[8]; // [sp+10h] [bp-28h] BYREF
  int v2; // [sp+18h] [bp-20h]
  int v3; // [sp+1Ch] [bp-1Ch]
  void *v4; // [sp+20h] [bp-18h]
  int v5; // [sp+24h] [bp-14h]
  int v6; // [sp+28h] [bp-10h]
  int v7; // [sp+2Ch] [bp-Ch]

  v2 = 24;
  v3 = 0;
  v5 = 576;
  v4 = &CmRegistryMachineSystemCurrentControlSetControlSessionManagerMemoryManagement;
  v6 = 0;
  v7 = 0;
  if ( ZwOpenKey() < 0 )
    return VfUtilDbgPrint((int)"Driver Verifier: Failed to open Memory Management key with status: 0x%x\n"
                               " Registry updates aborted!");
  RtlInitUnicodeString((unsigned int)v1, L"VerifierOptions");
  if ( ZwSetValueKey() < 0 )
  {
    VfUtilDbgPrint((int)"Driver Verifier: Failed to set VerifierOptionFlags key value with status: 0x%x\n"
                        " Registry updates aborted!");
  }
  else
  {
    RtlInitUnicodeString((unsigned int)v1, L"VerifyDriverLevel");
    if ( ZwDeleteValueKey() < 0 )
      VfUtilDbgPrint((int)"Driver Verifier: Failed to delete VerifyDriverLevel key value with status: 0x%x\n");
    RtlInitUnicodeString((unsigned int)v1, L"VerifyDrivers");
    if ( ZwDeleteValueKey() < 0 )
      VfUtilDbgPrint((int)"Driver Verifier: Failed to delete VerifyDrivers key value with status: 0x%x\n");
    ZwFlushKey();
  }
  return ZwClose();
}
