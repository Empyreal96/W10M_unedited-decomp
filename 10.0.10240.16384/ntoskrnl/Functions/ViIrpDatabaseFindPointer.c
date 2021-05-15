// ViIrpDatabaseFindPointer 
 
_DWORD *__fastcall ViIrpDatabaseFindPointer(unsigned int a1)
{
  int v2; // r5
  _DWORD **v3; // r1
  _DWORD *i; // r2

  v2 = (unsigned __int8)(-125 * (a1 >> 12));
  if ( VfUtilAddressRangeFit((unsigned int *)(ViIrpDatabaseAddressRanges + 8 * v2), a1, a1 + 112) )
  {
    v3 = (_DWORD **)(ViIrpDatabase + 8 * v2);
    for ( i = *v3; i != v3; i = (_DWORD *)*i )
    {
      if ( *(i - 6) == a1 )
        return i - 6;
    }
  }
  return 0;
}
