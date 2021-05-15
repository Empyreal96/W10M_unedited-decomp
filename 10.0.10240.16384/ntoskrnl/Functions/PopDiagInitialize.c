// PopDiagInitialize 
 
int PopDiagInitialize()
{
  __int64 v0; // r0

  if ( EtwRegister((int)POP_ETW_PROVIDER, (int)PopDiagTraceControlCallback, (int)&PopDiagHandle) >= 0 )
    PopDiagHandleRegistered = 1;
  dword_61E1F8 = (int)PopDiagDeviceRundownWorker;
  dword_61E1FC = 0;
  PopDiagDeviceRundownWorkItem = 0;
  TraceLoggingRegisterEx((int)&dword_6163C8, (unsigned int)&dword_6163C8);
  if ( EtwRegister((int)POP_TRIGGER_ETW_PROVIDER, 0, 0) >= 0 )
    PopTriggerDiagHandleRegistered = 1;
  unk_61E204 = 0;
  PopTelemetryOsState = 0;
  KeQuerySystemTime(dword_61E210);
  LODWORD(v0) = KeQueryInterruptTime();
  *(_QWORD *)&dword_61E210[2] = v0;
  return sub_966528(MEMORY[0xFFFF93B0], MEMORY[0xFFFF93B4]);
}
