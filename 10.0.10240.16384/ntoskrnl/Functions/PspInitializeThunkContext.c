// PspInitializeThunkContext 
 
int PspInitializeThunkContext()
{
  unsigned int v0; // r5
  char v1; // r3
  _DWORD *v2; // r6
  int v3; // r9
  int v4; // r0
  unsigned int v5; // r8
  void (__fastcall *v6)(_DWORD, _DWORD, int); // r0
  int result; // r0
  int v8; // r4
  _BYTE *v9; // r8
  int v10; // r2
  __int16 v11; // r3
  int v12; // r2
  int v13; // r4
  int i; // r3
  _DWORD v15[20]; // [sp+10h] [bp-3B0h] BYREF
  _DWORD v16[104]; // [sp+60h] [bp-360h] BYREF
  _DWORD v17[112]; // [sp+200h] [bp-1C0h] BYREF

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  memset(v16, 0, sizeof(v16));
  memset(v17, 0, 416);
  v16[0] = 2097167;
  --*(_WORD *)(v0 + 310);
  v1 = PspNotifyEnableMask;
  __dmb(0xBu);
  if ( (v1 & 0x10) != 0 )
  {
    v2 = &PspCreateThreadNotifyRoutine;
    v3 = 64;
    do
    {
      v4 = ExReferenceCallBackBlock(v2);
      v5 = v4;
      if ( v4 )
      {
        if ( ExGetCallBackBlockContext(v4) )
        {
          v6 = (void (__fastcall *)(_DWORD, _DWORD, int))KeReadStateSemaphore(v5);
          v6(*(_DWORD *)(*(_DWORD *)(v0 + 336) + 176), *(_DWORD *)(v0 + 880), 1);
        }
        ExDereferenceCallBackBlock(v2, v5);
      }
      ++v2;
      --v3;
    }
    while ( v3 );
  }
  result = PspGetContextThreadInternal(v0, v16, 0, 1);
  v8 = result;
  if ( result >= 0 )
  {
    v9 = (_BYTE *)((v16[14] - 416) & 0xFFFFFFF8);
    v17[14] = v9;
    PspCreateUserContext(v17, PspLoaderInitRoutine, v9, *((_DWORD *)PspSystemDlls + 5));
    v10 = *(_DWORD *)(*(_DWORD *)(v0 + 116) + 160);
    if ( v10 )
    {
      v17[13] = v17[16];
      v17[16] = v10;
    }
    if ( (unsigned int)v9 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *v9 = *v9;
    v9[408] = v9[408];
    memmove((int)v9, (int)v16, 0x1A0u);
    result = PspSetContextThreadInternal(v0, v17, 0, 1);
    v8 = result;
  }
  v11 = *(_WORD *)(v0 + 310) + 1;
  *(_WORD *)(v0 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v0 + 100) != v0 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  if ( v8 < 0 )
  {
    v15[1] = 0;
    v15[3] = PspLoaderInitRoutine;
    v15[0] = v8;
    v15[4] = 0;
    v15[2] = 0;
    v12 = *(_DWORD *)(v0 + 32);
    v13 = v12;
    for ( i = *(_DWORD *)(v12 + 4); (i & 1) != 0; i = *(_DWORD *)(v13 + 4) )
      v13 = *(_DWORD *)(v13 + 20);
    while ( (*(_DWORD *)(v12 + 4) & 1) != 0 )
      v12 = *(_DWORD *)(v12 + 20);
    result = KiDispatchException(v15, v12 - 464, (_DWORD *)(v13 - 408), 1, 0);
  }
  return result;
}
