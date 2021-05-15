// IopLiveDumpResetCorralContext 
 
_DWORD *__fastcall IopLiveDumpResetCorralContext(_DWORD *result)
{
  result[1] = 0;
  __dmb(0xBu);
  result[2] = 0;
  __dmb(0xBu);
  result[3] = 0;
  __dmb(0xBu);
  result[4] = 0;
  result[17] = 0;
  result[18] = 0;
  result[19] = 0;
  return result;
}
