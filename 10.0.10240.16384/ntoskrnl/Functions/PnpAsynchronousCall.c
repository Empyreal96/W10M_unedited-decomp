// PnpAsynchronousCall 
 
int __fastcall PnpAsynchronousCall(int a1, int a2, int a3, int a4)
{
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r3
  int v13; // r3
  int v14; // r4

  v8 = IoGetAttachedDeviceReference(a1);
  v9 = IoAllocateIrp(*(_BYTE *)(v8 + 48), 0);
  if ( v9 )
  {
    IovUtilWatermarkIrp();
    if ( a1 )
      v10 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    else
      v10 = 0;
    if ( v10 )
      *(_DWORD *)(v10 + 36) = v9;
    *(_DWORD *)(v9 + 24) = -1073741637;
    *(_DWORD *)(v9 + 28) = 0;
    v11 = *(_DWORD *)(v9 + 96) - 40;
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_BYTE *)(v9 + 32) = 0;
    *(_DWORD *)(v9 + 40) = 0;
    *(_DWORD *)(v9 + 44) = 0;
    *(_DWORD *)(v9 + 80) = v12;
    memmove(v11, a2, 0x28u);
    v13 = *(_DWORD *)(v9 + 96);
    *(_DWORD *)(v13 - 8) = a3;
    *(_DWORD *)(v13 - 4) = a4;
    *(_BYTE *)(v13 - 37) = -32;
    v14 = IofCallDriver(v8, v9);
  }
  else
  {
    v14 = -1073741670;
  }
  ObfDereferenceObject(v8);
  return v14;
}
