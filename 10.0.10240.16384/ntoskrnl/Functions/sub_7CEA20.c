// sub_7CEA20 
 
void __fastcall sub_7CEA20(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r8
  int v7; // r10
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r9
  int v11; // r4
  int v12; // r7
  int v13; // r5
  _DWORD *v14; // r4
  int v15; // r0
  unsigned int *v16; // r6
  unsigned int v17; // r5
  int v18; // r7
  int v19; // r2
  unsigned int v20; // r0
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3

  a6 = 0;
  a5 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  ExfAcquirePushLockExclusive((int)&ExpCovPushLock);
  v10 = 0;
  v11 = ExpCovUnloadedModuleList;
  if ( (int *)ExpCovUnloadedModuleList != &ExpCovUnloadedModuleList )
  {
    while ( 1 )
    {
      v12 = v11;
      if ( ExpCovReadFriendlyName(*(_DWORD *)(v6 + 72), v6 + 36, &a5) >= 0
        && !RtlCompareUnicodeString((unsigned __int16 *)(v11 + 16), (unsigned __int16 *)&a5, 1) )
      {
        break;
      }
      if ( a6 )
        RtlFreeAnsiString(&a5);
      v11 = *(_DWORD *)v11;
      if ( (int *)v11 == &ExpCovUnloadedModuleList )
        goto LABEL_9;
    }
    if ( a6 )
      RtlFreeAnsiString(&a5);
LABEL_9:
    if ( v12 && (int *)v11 != &ExpCovUnloadedModuleList )
    {
      v13 = *(_DWORD *)(v6 + 72);
      v14 = *(_DWORD **)(v12 + 28);
      if ( *(_DWORD *)(v13 + 4) == v14[1]
        && *(_DWORD *)(v13 + 24) == v14[6]
        && *(_DWORD *)(v13 + 28) == v14[7]
        && RtlCompareMemory((unsigned __int8 *)(v13 + 8), (int)(v14 + 2), 16) == 16 )
      {
        DbgPrintEx(126, 2, (int)"COV: Entry for same versioned %wZ found\n", v12 + 8);
        v15 = *(_DWORD *)(v13 + 32) + *(_DWORD *)(v6 + 72);
        v16 = (unsigned int *)(v14[8] + *(_DWORD *)(v12 + 28));
        if ( v7 )
        {
          memmove(v15, (int)v16, *(_DWORD *)(v13 + 28));
          ExpCovDeleteUnloadedModuleEntry(v12);
        }
        else
        {
          v17 = 0;
          if ( (v14[7] & 0xFFFFFFFC) != 0 )
          {
            v18 = v15 - (_DWORD)v16;
            do
            {
              __dmb(0xBu);
              v19 = *(unsigned int *)((char *)v16 + v18);
              do
              {
                v20 = __ldrex(v16);
                v9 = v20 | v19;
              }
              while ( __strex(v20 | v19, v16) );
              __dmb(0xBu);
              ++v17;
              ++v16;
            }
            while ( v17 < v14[7] >> 2 );
          }
        }
        goto LABEL_26;
      }
      DbgPrintEx(126, 2, (int)"COV: Entry for different versioned %wZ found\n", v12 + 8);
      ExpCovDeleteUnloadedModuleEntry(v12);
    }
  }
  if ( !v7 )
    v10 = 1;
LABEL_26:
  v21 = ExfReleasePushLock(&ExpCovPushLock, v9);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(v21);
  if ( v10 )
    ExpCovCreateUnloadedModuleEntry(v6);
  JUMPOUT(0x7740B8);
}
