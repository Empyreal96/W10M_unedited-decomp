// EtwpApplyStackWalkFilterOnUserEvent 
 
BOOL __fastcall EtwpApplyStackWalkFilterOnUserEvent(int a1, int a2, int a3, int a4)
{
  return EtwpApplyStackWalkFilter(*(unsigned __int16 *)(a1 + 40), a2, a3, 1);
}
