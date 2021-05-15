// PopPrintUserActivityPresence 
 
const __int16 *__fastcall PopPrintUserActivityPresence(int a1)
{
  if ( !a1 )
    return L"PowerUserPresent";
  if ( a1 == 2 )
    return L"PowerUserInactive";
  return (const __int16 *)sub_7F2540();
}
