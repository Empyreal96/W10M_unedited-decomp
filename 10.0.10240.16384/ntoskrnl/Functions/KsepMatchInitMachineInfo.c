// KsepMatchInitMachineInfo 
 
int KsepMatchInitMachineInfo()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r2
  _WORD *v3; // r3
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  unsigned int v7; // r2
  _WORD *v8; // r3

  if ( KsepMatchInitAcpiOemInfo() < 0 )
    return sub_965798();
  __dmb(0xBu);
  do
  {
    v1 = __ldrex(&KsepHistoryErrorsIndex);
    v2 = v1 + 1;
  }
  while ( __strex(v2, &KsepHistoryErrorsIndex) );
  __dmb(0xBu);
  v3 = &KsepHistoryErrors[4 * (v2 & 0x3F)];
  v3[1] = 10;
  *((_DWORD *)v3 + 1) = -1073741822;
  *v3 = 162;
  if ( (KsepDebugFlag & 2) != 0 )
    KsepDebugPrint(0, (int)"KSE: KsepMatchInitCpuInfo failed\n [0x%08x]\n");
  KsepLogError(0, (int)"KSE: KsepMatchInitCpuInfo failed\n [0x%08x]\n", -1073741822);
  v4 = KsepMatchInitBiosInfo();
  v5 = v4;
  if ( v4 < 0 )
  {
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(&KsepHistoryErrorsIndex);
      v7 = v6 + 1;
    }
    while ( __strex(v7, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v8 = &KsepHistoryErrors[4 * (v7 & 0x3F)];
    *((_DWORD *)v8 + 1) = v4;
    v8[1] = 10;
    *v8 = 168;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(0, (int)"KSE: KsepMatchInitBiosInfo failed [0x%08x]\n");
    KsepLogError(0, (int)"KSE: KsepMatchInitBiosInfo failed [0x%08x]\n", v5);
  }
  result = 0;
  KsepMatchMachineInfo = (int)&dword_647518;
  dword_6217B4 = (int)&dword_6474F4;
  dword_6217B8 = (int)dword_6474D0;
  dword_6217BC = (int)&unk_64747C;
  return result;
}
