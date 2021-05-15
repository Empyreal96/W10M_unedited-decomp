// PsSetCreateThreadNotifyRoutineEx 
 
int __fastcall PsSetCreateThreadNotifyRoutineEx(int a1, unsigned int a2)
{
  if ( a1 )
    return -1073741811;
  if ( MmVerifyCallbackFunction(a2) )
    return PspSetCreateThreadNotifyRoutine(a2, 1);
  return -1073741790;
}
