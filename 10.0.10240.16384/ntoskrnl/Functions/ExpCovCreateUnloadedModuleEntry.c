// ExpCovCreateUnloadedModuleEntry 
 
_DWORD *__fastcall ExpCovCreateUnloadedModuleEntry(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r5
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r2
  unsigned int v9; // r6
  int v10; // r3
  const char *v11; // r2
  int v12; // r1
  int *v13; // r0
  int *v14; // r5
  _BYTE *v15; // r0
  int **v16; // r1
  _DWORD *v17; // r3
  int v18; // r3
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  _DWORD *v23; // [sp+0h] [bp-20h]
  int v24; // [sp+8h] [bp-18h] BYREF
  int v25; // [sp+Ch] [bp-14h]

  v23 = a1;
  v24 = a3;
  v25 = a4;
  v5 = a1 + 9;
  v6 = a1[18];
  v25 = 0;
  v24 = 0;
  if ( ExpCovReadFriendlyName(v6, v5, &v24) < 0 )
  {
    DbgPrintEx(126, 0, (int)"COV: Allocation failure. Data for %wZ may be lost\n", (int)(a1 + 11));
    return v23;
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExfAcquirePushLockExclusive((int)&ExpCovPushLock);
  if ( ExpCovCurrentPagedPoolInUse + 32 < (unsigned int)ExpCovCurrentPagedPoolInUse
    || (v8 = ExpCovCurrentPagedPoolInUse + 32 + (unsigned __int16)v24, v8 < ExpCovCurrentPagedPoolInUse)
    || v8 == -1 )
  {
    v18 = (int)(a1 + 11);
    goto LABEL_25;
  }
  if ( (unsigned __int16)v24 + v8 < v8 || (v9 = a1[17] + (unsigned __int16)v24 + v8, v9 < v8) || v9 == -1 )
  {
    v18 = (int)v5;
LABEL_25:
    DbgPrintEx(126, 2, (int)"COV: Overflow when calculating paged pool size for %wZ\n", v18);
    goto LABEL_26;
  }
  v10 = ExCovMaxPagedPoolToUse;
  if ( v9 > ExCovMaxPagedPoolToUse )
  {
    v11 = "COV: Max paged pool size (%u) reached, coverage lost for %wZ\n";
    v23 = v5;
LABEL_11:
    DbgPrintEx(126, 2, (int)v11, v10);
    goto LABEL_26;
  }
  v13 = (int *)ExAllocatePoolWithTag(1, 32, 1920364355);
  v14 = v13;
  if ( v13 )
  {
    memset(v13, 0, 32);
    if ( RtlDuplicateUnicodeString(1, (int)&v24, (int)(v14 + 4)) >= 0 )
    {
      if ( v25 )
        RtlFreeAnsiString(&v24);
      if ( ExpCovReadFriendlyName(a1[18], a1 + 11, &v24) >= 0
        && RtlDuplicateUnicodeString(1, (int)&v24, (int)(v14 + 2)) >= 0 )
      {
        v14[6] = a1[17];
        v15 = (_BYTE *)ExAllocatePoolWithTag(1, a1[17], 1920364355);
        v14[7] = (int)v15;
        if ( v15 )
        {
          memset(v15, 0, a1[17]);
          memmove(v14[7], a1[18], a1[17]);
          v16 = (int **)dword_6198EC;
          *v14 = (int)&ExpCovUnloadedModuleList;
          v14[1] = (int)v16;
          if ( *v16 != &ExpCovUnloadedModuleList )
            __fastfail(3u);
          *v16 = v14;
          dword_6198EC = (int)v14;
          v17 = (_DWORD *)a1[12];
          v11 = "COV: Entry created for %wZ in ExpCovUnloadedModuleList\n";
          ExpCovCurrentPagedPoolInUse = v9;
          v23 = v17;
          v10 = a1[11];
          goto LABEL_11;
        }
      }
    }
  }
  DbgPrintEx(126, 0, (int)"COV: Allocation failure. Data for %wZ may be lost\n", (int)(a1 + 11));
  ExpCovFreeUnloadedModuleEntry(v14);
LABEL_26:
  v19 = ExfReleasePushLock(&ExpCovPushLock, v12);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  if ( v25 )
    RtlFreeAnsiString(&v24);
  return v23;
}
