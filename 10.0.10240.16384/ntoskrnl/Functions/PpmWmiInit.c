// PpmWmiInit 
 
_DWORD *PpmWmiInit()
{
  _DWORD *result; // r0

  result = KeInitializeTimerEx(PpmWmiIdleAccountingTimer, 0);
  PpmWmiIdleAccountingDpc = 19;
  byte_61DF81 = 1;
  word_61DF82 = 0;
  dword_61DF8C = (int)PpmWmiIdleAccountingProcedure;
  dword_61DF90 = 0;
  dword_61DF9C = 0;
  dword_61DF88 = 0;
  return result;
}
