// KseVersionLieInitialize 
 
int KseVersionLieInitialize()
{
  int result; // r0
  int v1; // r0
  unsigned int v2; // r2
  unsigned int v3; // r2
  _WORD *v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r2
  _WORD *v7; // r3

  if ( KseRegisterShim((int)&Win7VersionLieShim, 0, 0) < 0 )
    return sub_965880();
  v1 = KseRegisterShim((int)&Win8VersionLieShim, 0, 0);
  if ( v1 < 0 )
  {
    __dmb(0xBu);
    do
    {
      v2 = __ldrex(&KsepHistoryErrorsIndex);
      v3 = v2 + 1;
    }
    while ( __strex(v3, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v4 = &KsepHistoryErrors[4 * (v3 & 0x3F)];
    *((_DWORD *)v4 + 1) = v1;
    v4[1] = 12;
    *v4 = 249;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(12, (int)"Built-in Win8 version lie shims: failed to register.\n");
    KsepLogError(12, (int)"Built-in Win8 version lie shims: failed to register.\n");
  }
  result = KseRegisterShim((int)&Win81VersionLieShim, 0, 0);
  if ( result < 0 )
  {
    __dmb(0xBu);
    do
    {
      v5 = __ldrex(&KsepHistoryErrorsIndex);
      v6 = v5 + 1;
    }
    while ( __strex(v6, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v7 = &KsepHistoryErrors[4 * (v6 & 0x3F)];
    *((_DWORD *)v7 + 1) = result;
    v7[1] = 12;
    *v7 = 257;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(12, (int)"Built-in Win8.1 version lie shims: failed to register.\n");
    result = KsepLogError(12, (int)"Built-in Win8.1 version lie shims: failed to register.\n");
  }
  return result;
}
