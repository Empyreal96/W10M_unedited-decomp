// ViDeadlockSearchResource 
 
_DWORD *__fastcall ViDeadlockSearchResource(unsigned int a1, int a2)
{
  unsigned int v4; // r1
  _DWORD **v5; // r4
  _DWORD *i; // r2

  v4 = (a1 >> 12)
     - 1023
     * ((unsigned int)((((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                     + ((unsigned int)((a1 >> 12) - (((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  v5 = (_DWORD **)(*(_DWORD *)(ViDeadlockGlobals + 16) + 8 * v4);
  if ( *v5 != v5 && VfUtilAddressRangeFit((unsigned int *)(ViDeadlockGlobals + 8 * (v4 + 3)), a1, a1 + 1) )
  {
    ViDeadlockTrimResources(v5, a2);
    for ( i = *v5; i != v5; i = (_DWORD *)*i )
    {
      if ( *(i - 4) == a1 )
        return i - 6;
    }
  }
  return 0;
}
