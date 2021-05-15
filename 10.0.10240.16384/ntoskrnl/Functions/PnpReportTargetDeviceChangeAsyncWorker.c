// PnpReportTargetDeviceChangeAsyncWorker 
 
unsigned int __fastcall PnpReportTargetDeviceChangeAsyncWorker(int *a1)
{
  PnpSetCustomTargetEvent(a1[4], 0, 0, a1[5], a1[6], a1[7]);
  ObfDereferenceObject(a1[4]);
  return ExFreePoolWithTag((unsigned int)a1);
}
