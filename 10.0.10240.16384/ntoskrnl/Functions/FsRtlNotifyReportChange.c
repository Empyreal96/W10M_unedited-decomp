// FsRtlNotifyReportChange 
 
int __fastcall FsRtlNotifyReportChange(int a1, int a2, _WORD *a3, _WORD *a4, int a5)
{
  return FsRtlNotifyFilterReportChange(a1, a2, (int)a3, (unsigned __int16)(*a3 - *a4), 0, 0, a5, 0, 0, 0);
}
