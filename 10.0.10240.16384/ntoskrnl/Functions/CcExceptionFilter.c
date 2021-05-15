// CcExceptionFilter 
 
BOOL __fastcall CcExceptionFilter(int a1)
{
  return FsRtlIsNtstatusExpected(a1);
}
