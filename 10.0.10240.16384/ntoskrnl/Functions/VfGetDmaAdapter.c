// VfGetDmaAdapter 
 
int __fastcall VfGetDmaAdapter(int a1, int a2, _DWORD *a3)
{
  int v3; // r6
  unsigned int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r4
  int v11; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  if ( !ViVerifyDma || ViDMADisabledNoRebootNeeded == 1 || VfIsPCIBus() )
    return IoGetDmaAdapter(a1, a2, (int)a3);
  if ( (MmVerifierData & 0x20000) == 0 )
    VF_ASSERT_IRQL(0);
  if ( a1 )
  {
    while ( VF_FIND_INACTIVE_ADAPTER_AND_REMOVE(a1) )
      ViReleaseDmaAdapter();
  }
  if ( ViDoubleBufferDma && *a3 > 0x20u )
    *a3 = 32;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = off_617B30(v7);
  if ( v8 >= 0 )
    v3 = 0;
  if ( v8 < 0 )
    v3 = 1;
  v9 = ((int (__fastcall *)(int, int, int))pXdvIoGetDmaAdapter)(a1, a2, (int)a3);
  v10 = v9;
  if ( v9 )
  {
    v11 = ViHookDmaAdapter(v9, a2, *a3, v3);
    if ( v11 )
    {
      *(_DWORD *)(v11 + 12) = a1;
      *(_DWORD *)(v11 + 24) = vars4;
      return v10;
    }
    (*(void (__fastcall **)(int))(*(_DWORD *)(v10 + 4) + 4))(v10);
  }
  return 0;
}
