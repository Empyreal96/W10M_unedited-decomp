// KseDriverScopeInitialize 
 
int KseDriverScopeInitialize()
{
  int result; // r0
  unsigned int v1; // r1
  unsigned int v2; // r1
  char *v3; // r3

  result = KseRegisterShim((int)&KseDsShim, 0, 0);
  if ( result >= 0 )
  {
    __dmb(0xBu);
    do
    {
      v1 = __ldrex(KsepHistoryMessagesIndex);
      v2 = v1 + 1;
    }
    while ( __strex(v2, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v3 = (char *)&KsepHistoryMessages + 8 * (v2 & 0x3F);
    *((_DWORD *)v3 + 1) = 0;
    *((_WORD *)v3 + 1) = 11;
    *(_WORD *)v3 = 144;
    if ( (KsepDebugFlag & 1) != 0 )
      result = sub_965870();
    else
      result = KsepLogInfo(11, (int)"KSE-DS: driver scope shim registered.\n");
  }
  return result;
}
