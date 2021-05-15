// CmSetTraceNotifyRoutines 
 
int __fastcall CmSetTraceNotifyRoutines(__int64 a1, int a2)
{
  if ( a2 )
  {
    CmpTraceRoutine = 0;
    CmpTraceTxrRoutine = 0;
  }
  else
  {
    *(_QWORD *)&CmpTraceRoutine = a1;
  }
  return 0;
}
