// IoFillDumpHeader 
 
_BYTE *__fastcall IoFillDumpHeader(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v12; // r0
  _BYTE *result; // r0
  int v14; // r0
  unsigned int v15; // r2
  int v16; // r4
  int v17; // r1
  int v18; // r5
  int v19; // r5
  __int64 *v20; // r4
  __int64 v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r3

  v12 = RtlFillMemoryUlong((_DWORD *)a1, 0x1000u, 1162297680);
  *(_DWORD *)(a1 + 44) = a4;
  *(_DWORD *)(a1 + 48) = a5;
  *(_DWORD *)(a1 + 4) = 1347245380;
  *(_DWORD *)(a1 + 52) = a6;
  *(_DWORD *)(a1 + 40) = a3;
  *(_DWORD *)(a1 + 56) = a7;
  if ( a8 )
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(*(_DWORD *)(a8 + 116) + 24);
  else
    *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 32) = 452;
  *(_DWORD *)(a1 + 3976) = a2;
  *(_DWORD *)(a1 + 20) = MmPfnDatabase;
  *(_DWORD *)(a1 + 24) = &PsLoadedModuleList;
  *(_DWORD *)(a1 + 28) = &PsActiveProcessHead;
  *(_DWORD *)(a1 + 96) = &KdDebuggerDataBlock;
  *(_DWORD *)(a1 + 36) = KeNumberProcessors_0;
  *(_DWORD *)(a1 + 8) = 15;
  *(_DWORD *)(a1 + 12) = 10240;
  if ( a2 == 6 || a2 == 5 || !MmPhysicalMemoryBlock )
    goto LABEL_20;
  if ( (unsigned int)KeGetCurrentIrql(v12) > 1 )
    return (_BYTE *)sub_54E9F8();
  v14 = MmGetPhysicalMemoryRanges();
  if ( !v14 )
  {
LABEL_20:
    memset((_BYTE *)(a1 + 100), 0, 700);
  }
  else
  {
    v16 = *(_DWORD *)(v14 + 12);
    v15 = *(_DWORD *)(v14 + 8);
    v17 = 0;
    v18 = 0;
    while ( v15 | v16 )
    {
      v18 += (v16 << 20) | (v15 >> 12);
      ++v17;
      v16 = *(_DWORD *)(v14 + 16 * v17 + 12);
      v15 = *(_DWORD *)(v14 + 16 * v17 + 8);
    }
    if ( (unsigned int)(8 * (v17 + 1)) > 0x2BC )
      v17 = 86;
    *(_DWORD *)(a1 + 100) = v17;
    *(_DWORD *)(a1 + 104) = v18;
    if ( v17 )
    {
      v19 = a1;
      v20 = (__int64 *)v14;
      do
      {
        *(_DWORD *)(v19 + 108) = *v20 >> 12;
        v21 = v20[1];
        v20 += 2;
        *(_DWORD *)(v19 + 112) = v21 >> 12;
        v19 += 8;
        --v17;
      }
      while ( v17 );
    }
    ExFreePoolWithTag(v14, 0);
  }
  result = memset((_BYTE *)(a1 + 800), 0, 1200);
  *(_DWORD *)(a1 + 2000) = -2147483645;
  *(_DWORD *)(a1 + 2004) = 1;
  *(_DWORD *)(a1 + 2008) = 0;
  *(_DWORD *)(a1 + 2016) = 0;
  *(_DWORD *)(a1 + 2012) = 0;
  v22 = MEMORY[0xFFFF9014];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4032) = v22;
  v23 = MEMORY[0xFFFF9018];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4036) = v23;
  v24 = MEMORY[0xFFFF9008];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4024) = v24;
  v25 = MEMORY[0xFFFF900C];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4028) = v25;
  *(_DWORD *)(a1 + 3988) = MEMORY[0xFFFF9264];
  *(_DWORD *)(a1 + 3992) = MEMORY[0xFFFF92D0];
  v26 = MEMORY[0xFFFF92C4];
  *(_DWORD *)(a1 + 2208) = 0;
  *(_DWORD *)(a1 + 2212) = v26;
  return result;
}
