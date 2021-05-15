// ViDeadlockTrimResources 
 
_DWORD **__fastcall ViDeadlockTrimResources(_DWORD **result, int *a2)
{
  _DWORD *v3; // r5
  int v4; // r3
  _DWORD *v5; // r4
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r1

  v3 = result;
  v4 = *(_DWORD *)(ViDeadlockGlobals + 16464) + 1;
  *(_DWORD *)(ViDeadlockGlobals + 16464) = v4;
  if ( (v4 & 0xF) == 0 )
  {
    v5 = *result;
    if ( *result != result )
    {
      do
      {
        v6 = (int)(v5 - 6);
        v5 = (_DWORD *)*v5;
        v7 = ViDeadlockAgeWindow;
        __dmb(0xBu);
        v8 = ViDeadlockTrimThreshold;
        __dmb(0xBu);
        result = (_DWORD **)ViDeadlockForgetResourceHistory(v6, v8, v7, a2);
      }
      while ( v5 != v3 );
    }
  }
  return result;
}
