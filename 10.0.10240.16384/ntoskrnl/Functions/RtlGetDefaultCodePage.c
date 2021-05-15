// RtlGetDefaultCodePage 
 
_WORD *__fastcall RtlGetDefaultCodePage(_WORD *result, _WORD *a2)
{
  *result = NlsAnsiCodePage;
  *a2 = NlsOemCodePage;
  return result;
}
