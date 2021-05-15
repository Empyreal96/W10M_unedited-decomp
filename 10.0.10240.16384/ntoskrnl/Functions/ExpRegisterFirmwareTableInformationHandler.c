// ExpRegisterFirmwareTableInformationHandler 
 
int __fastcall ExpRegisterFirmwareTableInformationHandler(int a1, unsigned int a2, char a3)
{
  int v3; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r0
  _DWORD *v8; // r6
  _DWORD *v10; // r0
  int v11; // r3
  int *v12; // r5
  int **v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v3 = 0;
  if ( a3 )
    return -1073741727;
  if ( !a1 || a2 < 0x10 )
    return -1073741820;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  v7 = ExAcquireResourceExclusiveLite((int)&ExpFirmwareTableResource, 1, v5, v6);
  v8 = (_DWORD *)(ExpFirmwareTableProviderListHead - 16);
  if ( &ExpFirmwareTableProviderListHead == (int *)ExpFirmwareTableProviderListHead )
  {
LABEL_8:
    if ( *(_BYTE *)(a1 + 4) )
    {
      v10 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1413894721);
      if ( v10 )
      {
        *v10 = *(_DWORD *)a1;
        v10[2] = *(_DWORD *)(a1 + 8);
        v11 = *(_DWORD *)(a1 + 12);
        v12 = v10 + 4;
        v10[3] = v11;
        v10[4] = v10 + 4;
        v10[5] = v10 + 4;
        ObfReferenceObject(v10[3]);
        v13 = (int **)dword_61A1BC;
        *v12 = (int)&ExpFirmwareTableProviderListHead;
        v12[1] = (int)v13;
        if ( *v13 != &ExpFirmwareTableProviderListHead )
          __fastfail(3u);
        *v13 = v12;
        dword_61A1BC = (int)v12;
      }
      else
      {
        v3 = -1073741670;
      }
    }
    else
    {
      v3 = -1073741811;
    }
    v14 = ExReleaseResourceLite((int)&ExpFirmwareTableResource);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
    return v3;
  }
  while ( *v8 != *(_DWORD *)a1 )
  {
    v8 = (_DWORD *)(v8[4] - 16);
    if ( &ExpFirmwareTableProviderListHead == v8 + 4 )
      goto LABEL_8;
  }
  return sub_81AE74(v7);
}
