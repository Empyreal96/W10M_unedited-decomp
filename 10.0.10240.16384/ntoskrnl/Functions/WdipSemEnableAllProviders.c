// WdipSemEnableAllProviders 
 
void WdipSemEnableAllProviders()
{
  unsigned int v0; // r3
  unsigned int v1; // r9
  unsigned int v2; // r3
  unsigned int v3; // r8
  int v4; // r5
  unsigned int *v5; // r7
  unsigned int v6; // r4
  unsigned int v7; // t1

  __dmb(0xBu);
  v0 = WdipDiagLoggerId;
  do
    v1 = __ldrex((unsigned int *)&WdipDiagLoggerId);
  while ( __strex(v0, (unsigned int *)&WdipDiagLoggerId) );
  __dmb(0xBu);
  v2 = WdipContextLoggerId;
  do
    v3 = __ldrex((unsigned int *)&WdipContextLoggerId);
  while ( __strex(v2, (unsigned int *)&WdipContextLoggerId) );
  __dmb(0xBu);
  v4 = 0;
  if ( dword_61C760 )
  {
    v5 = (unsigned int *)WdipSemProviderTable;
    while ( 1 )
    {
      v7 = *v5++;
      v6 = v7;
      if ( !memcmp(v7, (unsigned int)WDI_SEM_PROVIDER, 16) || !*(_DWORD *)(v6 + 40) || !*(_BYTE *)(v6 + 36) )
        goto LABEL_16;
      if ( WdipSemEnableDisableTrace((unsigned __int16)v1, v6, *(unsigned __int8 *)(v6 + 16)) < 0 )
        break;
      *(_BYTE *)(v6 + 37) = 1;
      if ( *(_BYTE *)(v6 + 68) )
      {
        if ( WdipSemEnableDisableTrace((unsigned __int16)v3, v6, *(unsigned __int8 *)(v6 + 48)) < 0 )
          goto LABEL_15;
        *(_BYTE *)(v6 + 69) = 1;
      }
LABEL_16:
      if ( ++v4 >= (unsigned int)dword_61C760 )
        return;
    }
    memset((_BYTE *)(v6 + 16), 0, 32);
LABEL_15:
    memset((_BYTE *)(v6 + 48), 0, 32);
    goto LABEL_16;
  }
}
