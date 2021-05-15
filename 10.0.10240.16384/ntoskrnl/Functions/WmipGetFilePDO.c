// WmipGetFilePDO 
 
int __fastcall WmipGetFilePDO(int a1, char a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r4
  _DWORD *v6; // r6
  int v7; // r0
  int v8; // r7
  int v9; // r0
  int v10; // r5
  int v11; // r3
  unsigned int v12; // r0
  _DWORD *v14; // [sp+8h] [bp-18h] BYREF

  v14 = a4;
  v5 = ObReferenceObjectByHandle(a1, 0, (int)IoFileObjectType, a2, (int)&v14, 0);
  if ( v5 >= 0 )
  {
    v6 = v14;
    v7 = IoGetRelatedDeviceObject(v14);
    v8 = IoGetAttachedDeviceReference(v7);
    v9 = IoAllocateIrp(*(_BYTE *)(v8 + 48), 0);
    v10 = v9;
    if ( v9 )
    {
      v11 = *(_DWORD *)(v9 + 96);
      *(_BYTE *)(v11 - 40) = 27;
      *(_BYTE *)(v11 - 39) = 7;
      *(_DWORD *)(v11 - 32) = 4;
      *(_DWORD *)(v11 - 12) = v6;
      *(_DWORD *)(v9 + 24) = -1073741637;
      v5 = IoSynchronousCallDriver(v8, v9);
      if ( v5 >= 0 )
      {
        v12 = *(_DWORD *)(v10 + 28);
        *a3 = *(_DWORD *)(v12 + 4);
        ExFreePoolWithTag(v12);
        v5 = 0;
      }
      IoFreeIrp(v10);
    }
    else
    {
      v5 = -1073741670;
    }
    ObfDereferenceObject(v8);
    if ( v6 )
      ObfDereferenceObject((int)v6);
  }
  return v5;
}
