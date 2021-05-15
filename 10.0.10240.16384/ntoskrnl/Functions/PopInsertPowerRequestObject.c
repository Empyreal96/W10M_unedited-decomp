// PopInsertPowerRequestObject 
 
_DWORD *__fastcall PopInsertPowerRequestObject(_DWORD *result, int a2)
{
  int **v2; // r1
  int *v3; // r2
  void **v4; // r1

  if ( a2 )
  {
    v4 = (void **)dword_61F8FC;
    *result = &PopSpecialPowerRequestObjectList;
    result[1] = v4;
    if ( *v4 != &PopSpecialPowerRequestObjectList )
      __fastfail(3u);
    *v4 = result;
    dword_61F8FC = (int)result;
    v3 = &PopSpecialPowerRequestObjectCount;
  }
  else
  {
    v2 = (int **)dword_61F904;
    *result = &PopPowerRequestObjectList;
    result[1] = v2;
    if ( *v2 != &PopPowerRequestObjectList )
      sub_7F30C4();
    *v2 = result;
    dword_61F904 = (int)result;
    v3 = &PopPowerRequestObjectCount;
  }
  ++*v3;
  return result;
}
