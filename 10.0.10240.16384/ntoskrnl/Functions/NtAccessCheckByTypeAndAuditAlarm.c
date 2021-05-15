// NtAccessCheckByTypeAndAuditAlarm 
 
int __fastcall NtAccessCheckByTypeAndAuditAlarm(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  return SepAccessCheckAndAuditAlarm(a1, a2, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a14, a15, a16, 0);
}
