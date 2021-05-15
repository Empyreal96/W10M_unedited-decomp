// KeAlertResumeThread 
 
int __fastcall KeAlertResumeThread(int a1)
{
  int v2; // r5
  int v3; // r4

  v2 = KfRaiseIrql(2);
  KeAlertThread(a1, 0);
  v3 = KeResumeThread(a1);
  KfLowerIrql(v2);
  return v3;
}
