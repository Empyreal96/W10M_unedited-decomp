// IoReportInterruptInactive 
 
int __fastcall IoReportInterruptInactive(_DWORD *a1)
{
  int result; // r0

  if ( *a1 == 1 || *a1 == 4 )
    result = IopMaskInterrupt(a1[1]);
  else
    result = sub_51FB94();
  return result;
}
