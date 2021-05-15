// IopAttachDeviceToDeviceStackSafe 
 
int __fastcall IopAttachDeviceToDeviceStackSafe(unsigned int a1, int a2, int *a3)
{
  int v3; // r8
  int v7; // r9
  int v9; // r0
  int v10; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r2
  int v15; // r3

  v3 = *(_DWORD *)(a1 + 176);
  v7 = KeAcquireQueuedSpinLock(10);
  if ( (MmVerifierData & 0x10) != 0 )
    return sub_528260();
  v9 = IoGetAttachedDevice(a2);
  v10 = v9;
  if ( (*(_DWORD *)(v9 + 28) & 0x80) != 0
    || (*(_DWORD *)(*(_DWORD *)(v9 + 176) + 16) & 0xF) != 0
    || (unsigned __int16)*(char *)(v9 + 48) >= 0x7Du )
  {
    v10 = 0;
    if ( a3 )
      *a3 = 0;
  }
  else
  {
    if ( a3 )
      *a3 = v9;
    *(_BYTE *)(a1 + 48) = *(_BYTE *)(v9 + 48) + 1;
    *(_DWORD *)(a1 + 92) = *(_DWORD *)(v9 + 92);
    *(_WORD *)(a1 + 172) = *(_WORD *)(v9 + 172);
    if ( (*(_DWORD *)(*(_DWORD *)(v9 + 176) + 16) & 0x10) != 0 )
      *(_DWORD *)(*(_DWORD *)(a1 + 176) + 16) |= 0x10u;
    if ( (*(_DWORD *)(v9 + 28) & 0x8000000) != 0 )
      *(_DWORD *)(a1 + 28) |= 0x8000000u;
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 16);
    do
      v12 = __ldrex(v11);
    while ( __strex(a1, v11) );
    __dmb(0xBu);
    ++*(_WORD *)(v9 + 174);
    *(_DWORD *)(v3 + 24) = v9;
    v13 = IopGetDeviceAttachmentBase(a2);
    if ( v13 )
      v14 = *(_DWORD *)(*(_DWORD *)(v13 + 176) + 20);
    else
      v14 = 0;
    if ( v14 && *(int *)(v14 + 268) < 0 )
      PnpRequestDeviceAction(*(int **)(v14 + 16), 8, 0, 1, 0, 0);
  }
  KeReleaseQueuedSpinLock(10, v7);
  v15 = *(_DWORD *)(a2 + 44);
  if ( v15 == 8 || v15 == 3 || v15 == 20 )
  {
    if ( FltMgrCallbacks )
      (*(void (__fastcall **)(unsigned int, int))(FltMgrCallbacks + 16))(a1, a2);
  }
  return v10;
}
