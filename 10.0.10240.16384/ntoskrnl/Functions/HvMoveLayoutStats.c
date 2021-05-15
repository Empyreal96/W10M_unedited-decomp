// HvMoveLayoutStats 
 
_DWORD *__fastcall HvMoveLayoutStats(_DWORD *result)
{
  int v1; // r2

  v1 = result[3];
  *result += result[2];
  result[1] += v1;
  result[2] = 0;
  result[3] = 0;
  return result;
}
