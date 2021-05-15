// MiIrpCompletionApcRoutine 
 
int __fastcall MiIrpCompletionApcRoutine(int a1)
{
  return KeSetEvent(a1, 0, 0);
}
