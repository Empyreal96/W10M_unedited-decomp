// HviGetHypervisorVersion 
 
_DWORD *__fastcall HviGetHypervisorVersion(_DWORD *result)
{
  *result = 0;
  result[1] = 0;
  result[2] = 0;
  result[3] = 0;
  return result;
}
