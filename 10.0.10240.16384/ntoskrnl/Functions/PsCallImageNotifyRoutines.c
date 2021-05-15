// PsCallImageNotifyRoutines 
 
int __fastcall PsCallImageNotifyRoutines(char *a1, int a2, int a3, int a4)
{
  unsigned int v8; // r7
  char v9; // r3
  int v10; // r3
  __int64 v11; // r2
  _DWORD *v12; // r4
  int v13; // r5
  int v14; // r0
  unsigned int v15; // r6
  int result; // r0
  __int16 v17; // r3
  void (__fastcall *v18)(char *, int, int); // r0
  int v19; // [sp+0h] [bp-30h] BYREF
  char v20[40]; // [sp+8h] [bp-28h] BYREF

  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v19 = 0;
  if ( FltMgrCallbacks
    && (*(int (__fastcall **)(int, int, char *, int *))(FltMgrCallbacks + 8))(a4, 512, v20, &v19) >= 0 )
  {
    a1 = v20;
  }
  if ( (PerfGlobalGroupMask & 4) != 0 )
    PerfLogImageLoad(a1, a2, a3 + 4);
  v9 = PspNotifyEnableMask;
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
  {
    v10 = *(_DWORD *)(a3 + 4);
    if ( (v10 & 0x800) == 0 )
    {
      LODWORD(v11) = 28;
      HIDWORD(v11) = v10 | 0x400;
      v12 = &PspLoadImageNotifyRoutine;
      *(_DWORD *)(a3 + 24) = a4;
      *(_QWORD *)a3 = v11;
      v13 = 64;
      do
      {
        v14 = ExReferenceCallBackBlock(v12);
        v15 = v14;
        if ( v14 )
        {
          v18 = (void (__fastcall *)(char *, int, int))KeReadStateSemaphore(v14);
          v18(a1, a2, a3 + 4);
          ExDereferenceCallBackBlock(v12, v15);
        }
        ++v12;
        --v13;
      }
      while ( v13 );
    }
  }
  result = v19;
  if ( v19 )
    result = (*(int (**)(void))(FltMgrCallbacks + 12))();
  v17 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
