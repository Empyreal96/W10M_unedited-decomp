// KsepShimDbMapToMemory 
 
int KsepShimDbMapToMemory()
{
  unsigned int v0; // r5
  int v1; // r6
  int v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r1
  _WORD *v6; // r3
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r1
  _WORD *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r1
  _WORD *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r1
  _WORD *v16; // r3
  unsigned int v17; // [sp+18h] [bp-48h] BYREF
  int v18; // [sp+1Ch] [bp-44h] BYREF
  char v19[8]; // [sp+20h] [bp-40h] BYREF
  int v20; // [sp+30h] [bp-30h]
  int v21; // [sp+34h] [bp-2Ch]
  char *v22; // [sp+38h] [bp-28h]
  int v23; // [sp+3Ch] [bp-24h]
  int v24; // [sp+40h] [bp-20h]
  int v25; // [sp+44h] [bp-1Ch]

  v0 = 0;
  v17 = 0;
  v1 = 0;
  RtlInitUnicodeString((unsigned int)v19, L"\\SystemRoot\\AppPatch\\drvmain.sdb");
  v20 = 24;
  v21 = 0;
  v22 = v19;
  v24 = 0;
  v25 = 0;
  v23 = 576;
  if ( ZwOpenFile() < 0 )
    return sub_7CE214();
  v20 = 24;
  v21 = 0;
  v22 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 576;
  v3 = ZwCreateSection();
  if ( v3 >= 0 )
  {
    v3 = ObReferenceObjectByHandle(0, 983071, MmSectionObjectType, 0, (int)&v18, 0);
    v1 = v18;
    if ( v3 < 0 )
    {
      __dmb(0xBu);
      do
      {
        v8 = __ldrex(&KsepHistoryErrorsIndex);
        v9 = v8 + 1;
      }
      while ( __strex(v9, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v10 = &KsepHistoryErrors[4 * (v9 & 0x3F)];
      *((_DWORD *)v10 + 1) = v3;
      v10[1] = 9;
      *v10 = 530;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(0, (int)"KSE: ObRefByHandle(section) failed!\n");
      KsepLogError(0, (int)"KSE: ObRefByHandle(section) failed!\n");
    }
    else
    {
      v7 = v18;
      v18 = 0;
      v3 = MmMapViewInSystemSpace(v7, (int)&v17, (int)&v18);
      if ( v3 < 0 )
      {
        __dmb(0xBu);
        do
        {
          v11 = __ldrex(&KsepHistoryErrorsIndex);
          v12 = v11 + 1;
        }
        while ( __strex(v12, &KsepHistoryErrorsIndex) );
        __dmb(0xBu);
        v13 = &KsepHistoryErrors[4 * (v12 & 0x3F)];
        *((_DWORD *)v13 + 1) = v3;
        v13[1] = 9;
        *v13 = 543;
        if ( (KsepDebugFlag & 2) != 0 )
          KsepDebugPrint(0, (int)"KSE: Unable to map view of section!\n");
        KsepLogError(0, (int)"KSE: Unable to map view of section!\n");
        v0 = v17;
      }
      else
      {
        v0 = v17;
        KsepShimDbHandle = SdbInitDatabaseInMemory(v17, v18);
        if ( !KsepShimDbHandle )
        {
          v3 = -1073741823;
          __dmb(0xBu);
          do
          {
            v14 = __ldrex(&KsepHistoryErrorsIndex);
            v15 = v14 + 1;
          }
          while ( __strex(v15, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v16 = &KsepHistoryErrors[4 * (v15 & 0x3F)];
          *((_DWORD *)v16 + 1) = -1073741823;
          v16[1] = 9;
          *v16 = 552;
          if ( (KsepDebugFlag & 2) != 0 )
            KsepDebugPrint(0, (int)"KSE: SdbInitDatabaseInMemory Failed!\n");
          KsepLogError(0, (int)"KSE: SdbInitDatabaseInMemory Failed!\n");
          goto LABEL_31;
        }
        v3 = 0;
      }
    }
  }
  else
  {
    __dmb(0xBu);
    do
    {
      v4 = __ldrex(&KsepHistoryErrorsIndex);
      v5 = v4 + 1;
    }
    while ( __strex(v5, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v6 = &KsepHistoryErrors[4 * (v5 & 0x3F)];
    *((_DWORD *)v6 + 1) = v3;
    v6[1] = 9;
    *v6 = 516;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(0, (int)"KSE: ZwCreateSection Failed!\n");
    KsepLogError(0, (int)"KSE: ZwCreateSection Failed!\n");
  }
  if ( v3 < 0 )
  {
LABEL_31:
    if ( v0 )
      MmUnmapViewInSystemSpace(v0);
    if ( v1 )
      ObfDereferenceObject(v1);
    return v3;
  }
  KsepShimDbFileHandle = 0;
  KsepShimDbSectionHandle = 0;
  KsepShimDbSectionPointer = v1;
  KsepShimDbAddress = v0;
  return v3;
}
