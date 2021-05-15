// KiUpdateInterruptObjectActiveCount 
 
int __fastcall KiUpdateInterruptObjectActiveCount(int result, int a2)
{
  __int16 v2; // r3

  if ( a2 )
    v2 = *(_WORD *)(result + 58) + 1;
  else
    v2 = *(_WORD *)(result + 58) - 1;
  *(_WORD *)(result + 58) = v2;
  return result;
}
