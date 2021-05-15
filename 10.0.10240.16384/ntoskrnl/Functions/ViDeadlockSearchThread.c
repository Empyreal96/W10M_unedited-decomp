// ViDeadlockSearchThread 
 
_DWORD *__fastcall ViDeadlockSearchThread(unsigned int a1)
{
  unsigned int v2; // r1
  _DWORD **v3; // r6
  _DWORD *v4; // r4
  bool i; // zf

  v2 = (a1 >> 12)
     - 1023
     * ((unsigned int)((((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                     + ((unsigned int)((a1 >> 12) - (((a1 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  v3 = (_DWORD **)(*(_DWORD *)(ViDeadlockGlobals + 8208) + 8 * v2);
  v4 = *v3;
  if ( *v3 != v3 )
  {
    for ( i = !VfUtilAddressRangeFit((unsigned int *)(ViDeadlockGlobals + 8 * (v2 + 1027)), a1, a1 + 1); !i; i = v4 == v3 )
    {
      if ( *(v4 - 3) == a1 )
        return v4 - 3;
      v4 = (_DWORD *)*v4;
    }
  }
  return 0;
}
