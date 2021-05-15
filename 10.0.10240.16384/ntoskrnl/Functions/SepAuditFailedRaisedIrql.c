// SepAuditFailedRaisedIrql 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepAuditFailedRaisedIrql(int result)
{
  int v1; // r4 OVERLAPPED
  int (__fastcall *v2)(_DWORD); // r3

  v1 = result;
  if ( SepCrashOnAuditFail )
  {
    if ( (unsigned int)KeGetCurrentIrql(result) >= 2 )
    {
      v2 = SepAuditFailed;
      *(_QWORD *)&algn_61D3C4[4] = *(_QWORD *)(&v1 - 1);
      SepAdtCrashOnAuditFailWorkItem = 0;
      result = ExQueueWorkItem(&SepAdtCrashOnAuditFailWorkItem, 2);
    }
    else
    {
      result = SepAuditFailed(v1);
    }
  }
  return result;
}
