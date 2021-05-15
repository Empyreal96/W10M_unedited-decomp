// sub_555CEC 
 
void sub_555CEC()
{
  int v0; // r5

  EtwTraceSystemTimeChange();
  v0 = KfRaiseIrql(2);
  ExNotifyWithProcessing(ExCbSetSystemTime, 0, 0, 0);
  PopGetPolicyWorker(16);
  PopCheckForWork();
  KfLowerIrql(v0);
  JUMPOUT(0x4F92AE);
}
