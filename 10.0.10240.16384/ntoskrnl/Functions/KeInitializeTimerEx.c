// KeInitializeTimerEx 
 
_DWORD *__fastcall KeInitializeTimerEx(_DWORD *result, char a2)
{
  *result = 0;
  result[1] = 0;
  *(_BYTE *)result = a2 + 8;
  result[2] = result + 2;
  result[3] = result + 2;
  result[4] = 0;
  result[5] = 0;
  result[9] = 0;
  result[10] = 0;
  return result;
}
