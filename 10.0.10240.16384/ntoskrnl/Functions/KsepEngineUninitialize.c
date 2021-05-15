// KsepEngineUninitialize 
 
int __fastcall KsepEngineUninitialize(_DWORD *a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r1
  _WORD *v4; // r2
  int result; // r0

  if ( !a1 )
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
    *((_DWORD *)v4 + 1) = -1073740768;
    v4[1] = 2;
    *v4 = 892;
    if ( (KsepDebugFlag & 4) != 0 )
      RtlAssert((int)"Engine != NULL", (int)"minkernel\\ntos\\kshim\\ksecore.c", 892, 0);
  }
  result = a1[10];
  if ( result )
  {
    result = KsepCacheUninitialize(result);
    a1[10] = 0;
  }
  *a1 |= 3u;
  a1[2] |= 0x400u;
  return result;
}
