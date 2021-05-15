// PsSetCreateThreadNotifyRoutine 
 
int __fastcall PsSetCreateThreadNotifyRoutine(int a1)
{
  return PspSetCreateThreadNotifyRoutine(a1, 0);
}
