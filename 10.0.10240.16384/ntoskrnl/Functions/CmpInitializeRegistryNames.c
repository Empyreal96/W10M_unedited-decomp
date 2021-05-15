// CmpInitializeRegistryNames 
 
unsigned int CmpInitializeRegistryNames()
{
  char *v0; // r4
  int v1; // r6
  unsigned __int16 **v2; // r5
  unsigned __int16 *v3; // t1
  unsigned int result; // r0

  RtlInitUnicodeString((unsigned int)CmRegistryRootName, L"\\REGISTRY");
  RtlInitUnicodeString((unsigned int)CmRegistryMachineName, L"\\REGISTRY\\MACHINE");
  RtlInitUnicodeString((unsigned int)CmRegistryMachineHardwareName, L"\\REGISTRY\\MACHINE\\HARDWARE");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineHardwareDescriptionName,
    L"\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION");
  RtlInitUnicodeString(
    (unsigned int)CmRegistryMachineHardwareDescriptionSystemName,
    L"\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION\\SYSTEM");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineHardwareDeviceMapName,
    L"\\REGISTRY\\MACHINE\\HARDWARE\\DEVICEMAP");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineHardwareResourceMapName,
    L"\\REGISTRY\\MACHINE\\HARDWARE\\RESOURCEMAP");
  RtlInitUnicodeString((unsigned int)&CmRegistryMachineHardwareOwnerMapName, L"\\REGISTRY\\MACHINE\\HARDWARE\\OWNERMAP");
  RtlInitUnicodeString((unsigned int)CmRegistryMachineSystemName, L"\\REGISTRY\\MACHINE\\SYSTEM");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSet,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET");
  RtlInitUnicodeString((unsigned int)&CmRegistryUserName, L"\\REGISTRY\\USER");
  RtlInitUnicodeString((unsigned int)&CmRegistryAppName, L"\\REGISTRY\\A");
  RtlInitUnicodeString((unsigned int)&CmRegistrySystemCloneName, L"\\REGISTRY\\MACHINE\\CLONE");
  RtlInitUnicodeString((unsigned int)&CmpSystemFileName, L"SYSTEM");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetEnumName,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetEnumRootName,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM\\ROOT");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetServices,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetHardwareProfilesCurrent,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\HARDWARE PROFILES\\CURRENT");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetControlClass,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\CLASS");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetControlSafeBoot,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SAFEBOOT");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetControlSessionManagerMemoryManagement,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\MEMORY MANAGEMENT");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetControlBootLog,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\BOOTLOG");
  RtlInitUnicodeString(
    (unsigned int)&CmRegistryMachineSystemCurrentControlSetServicesEventLog,
    L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES\\EVENTLOG");
  RtlInitUnicodeString((unsigned int)CmSymbolicLinkValueName, L"SymbolicLinkValue");
  v0 = (char *)&CmTypeName;
  v1 = 42;
  v2 = (unsigned __int16 **)CmTypeString;
  do
  {
    v3 = *v2++;
    result = RtlInitUnicodeString((unsigned int)v0, v3);
    v0 += 8;
    --v1;
  }
  while ( v1 );
  return result;
}
