// FioFwReadUshortAtOffset 
 
int __fastcall FioFwReadUshortAtOffset(int a1, int a2, _WORD *a3)
{
  int result; // r0

  result = FioFwReadBytesAtOffset(a1, a2, 2, a3);
  if ( result >= 0 )
  {
    result = 0;
    *a3 = __rev16((unsigned __int16)*a3);
  }
  return result;
}
