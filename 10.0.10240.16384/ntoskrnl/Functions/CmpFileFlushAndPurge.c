// CmpFileFlushAndPurge 
 
int __fastcall CmpFileFlushAndPurge(int a1, int a2)
{
  int v3; // r0
  _DWORD *v4; // r5
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r6
  _DWORD *v11; // [sp+8h] [bp-28h] BYREF
  char v12[32]; // [sp+10h] [bp-20h] BYREF

  if ( (*(_BYTE *)(a1 + 72) & 4) != 0 && !a2 )
    return CmpFileFlush();
  v3 = *(_DWORD *)(a1 + 4 * a2 + 1776);
  if ( v3 && !CmpNoWrite )
  {
    if ( ObReferenceObjectByHandle(v3, 2, *(_DWORD *)CmIoFileObjectType, 0, &v11) < 0 )
      goto LABEL_14;
    KeInitializeEvent((int)v12, 1, 0);
    v4 = v11;
    v5 = IoGetRelatedDeviceObject(v11);
    v6 = IoAllocateIrp(*(_BYTE *)(v5 + 48), 0);
    v7 = v6;
    if ( !v6 )
      return sub_7F3E44();
    *(_DWORD *)(v6 + 100) = v4;
    *(_DWORD *)(v6 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v6 + 84) = 0;
    v8 = *(_DWORD *)(v6 + 96);
    *(_BYTE *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 48) = 0;
    *(_BYTE *)(v6 + 33) = 0;
    *(_BYTE *)(v6 + 36) = 0;
    *(_DWORD *)(v6 + 56) = 0;
    *(_BYTE *)(v8 - 40) = 9;
    *(_BYTE *)(v8 - 39) = 1;
    *(_DWORD *)(v8 - 16) = v5;
    *(_DWORD *)(v8 - 12) = v4;
    v9 = *(_DWORD *)(v6 + 96);
    *(_DWORD *)(v9 - 8) = SmKmGenericCompletion;
    *(_DWORD *)(v9 - 4) = v12;
    *(_BYTE *)(v9 - 37) = -32;
    v10 = IofCallDriver(v5, v6);
    if ( v10 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
      v10 = *(_DWORD *)(v7 + 24);
    }
    ObfDereferenceObject((int)v4);
    IoFreeIrp(v7);
    if ( v10 < 0 )
LABEL_14:
      JUMPOUT(0x7F3E4A);
  }
  return 1;
}
