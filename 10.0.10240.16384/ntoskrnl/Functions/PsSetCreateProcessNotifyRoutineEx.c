// PsSetCreateProcessNotifyRoutineEx 
 
int __fastcall PsSetCreateProcessNotifyRoutineEx(int a1, int a2)
{
  return PspSetCreateProcessNotifyRoutine(a1, a2, 1);
}
