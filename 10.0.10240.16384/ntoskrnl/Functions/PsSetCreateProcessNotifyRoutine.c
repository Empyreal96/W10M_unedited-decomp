// PsSetCreateProcessNotifyRoutine 
 
int __fastcall PsSetCreateProcessNotifyRoutine(int a1, int a2)
{
  return PspSetCreateProcessNotifyRoutine(a1, a2, 0);
}
