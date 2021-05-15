// DbgkpTriageDumpSaveState 
 
_DWORD *__fastcall DbgkpTriageDumpSaveState(_DWORD *result)
{
  _DWORD *v1; // r2

  result[2] = result[5];
  v1 = (_DWORD *)(*result + 4192);
  result[3] = *v1;
  result[4] = v1[1];
  return result;
}
