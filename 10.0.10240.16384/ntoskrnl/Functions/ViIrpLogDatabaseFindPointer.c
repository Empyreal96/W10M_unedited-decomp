// ViIrpLogDatabaseFindPointer 
 
_DWORD *__fastcall ViIrpLogDatabaseFindPointer(int a1, _DWORD *a2)
{
  int v2; // r3
  _DWORD *i; // r2

  v2 = ViIrpLogDatabase;
  *a2 = ViIrpLogDatabase;
  for ( i = *(_DWORD **)(v2 + 4); ; i = (_DWORD *)*i )
  {
    if ( i == (_DWORD *)(v2 + 4) )
      return 0;
    if ( *(i - 1) == a1 )
      break;
  }
  return i - 1;
}
