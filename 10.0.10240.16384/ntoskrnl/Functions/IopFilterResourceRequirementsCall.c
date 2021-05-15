// IopFilterResourceRequirementsCall 
 
int __fastcall IopFilterResourceRequirementsCall(int a1, int a2, _DWORD *a3)
{
  int v5; // r6
  _DWORD *v6; // r4
  int v7; // r3
  int v8; // r4
  int v10; // [sp+8h] [bp-30h] BYREF
  int v11; // [sp+Ch] [bp-2Ch]
  char v12[40]; // [sp+10h] [bp-28h] BYREF

  v5 = IoGetAttachedDeviceReference(a1);
  v6 = (_DWORD *)IoAllocateIrp(*(_BYTE *)(v5 + 48), 0);
  if ( v6 )
  {
    IovUtilWatermarkIrp();
    if ( a2 )
    {
      v10 = 0;
      v6[6] = 0;
      v11 = a2;
      v6[7] = a2;
    }
    else
    {
      v10 = -1073741637;
      v6[6] = -1073741637;
    }
    KeInitializeEvent((int)v12, 1, 0);
    v6[10] = &v10;
    v6[11] = v12;
    v6[20] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    IopQueueThreadIrp((int)v6);
    v7 = v6[24];
    *(_BYTE *)(v7 - 39) = 13;
    *(_BYTE *)(v7 - 40) = 27;
    *(_DWORD *)(v7 - 32) = a2;
    v8 = IofCallDriver(v5, (int)v6);
    if ( v8 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
      v8 = v10;
    }
    *a3 = v11;
  }
  else
  {
    v8 = -1073741670;
  }
  ObfDereferenceObject(v5);
  return v8;
}
