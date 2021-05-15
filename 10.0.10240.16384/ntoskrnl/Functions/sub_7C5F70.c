// sub_7C5F70 
 
void __fastcall sub_7C5F70(int a1, int a2, _DWORD *a3, int a4, unsigned int *a5)
{
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r3
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  _DWORD **v11; // r5
  unsigned int *v12; // r0
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r4
  _DWORD *v16; // r1
  __int64 v17; // r2

  if ( *a3 == v15 )
  {
    *a3 = a2;
    *(_DWORD *)(a2 + 4) = a3;
    v5 = ExReleaseResourceLite((int)&PiPnpRtlActiveOperationsLock);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
    *(_WORD *)(v6 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v5);
    while ( !RtlIsGenericTableEmptyAvl(v15 + 12) )
    {
      v12 = *(unsigned int **)(*(_DWORD *)(v15 + 20) + 16);
      a5 = v12;
      if ( v12[3] )
      {
        ZwClose();
        a5[3] = 0;
        v12 = a5;
      }
      PiPnpRtlObjectEventDispatch((int)v12);
      RtlDeleteElementGenericTableAvl(v15 + 12, (int)&a5, v13, v14);
      PiPnpRtlObjectEventRelease(a5);
    }
    v8 = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
    v11 = (_DWORD **)(v15 + 68);
    while ( *v11 != v11 )
    {
      LODWORD(v17) = *v11;
      HIDWORD(v17) = (*v11)[1];
      v16 = (_DWORD *)**v11;
      if ( v17 != __PAIR64__((unsigned int)v11, v16[1]) )
        __fastfail(3u);
      *v11 = v16;
      v16[1] = v11;
      a5 = (unsigned int *)(v17 - 32);
      PiPnpRtlObjectEventRelease((unsigned int *)(v17 - 32));
    }
    ExFreePoolWithTag(v15);
    JUMPOUT(0x6C62A6);
  }
  JUMPOUT(0x6C62A2);
}
