// IoReportInterruptActive 
 
int __fastcall IoReportInterruptActive(_DWORD *a1)
{
  int result; // r0

  if ( *a1 == 1 || *a1 == 4 )
    result = IopUnmaskInterrupt(a1[1]);
  else
    result = sub_51FB30();
  return result;
}
