// IopSynchronousCall 
 
int __fastcall IopSynchronousCall(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v8; // r0
  int v9; // r5
  _DWORD *v10; // r4
  int v11; // r4
  int v13; // r4
  int v14; // [sp+8h] [bp-30h] BYREF
  int v15; // [sp+Ch] [bp-2Ch]
  char v16[40]; // [sp+10h] [bp-28h] BYREF

  v8 = IoGetAttachedDeviceReference(a1);
  v9 = v8;
  if ( (*(_DWORD *)(v8 + 28) & 0x80) != 0 )
  {
    v13 = IoGetLowerDeviceObject(v8);
    if ( !v13 )
    {
      v11 = -1073741436;
      goto LABEL_7;
    }
    ObfDereferenceObject(v9);
    v9 = v13;
  }
  v10 = (_DWORD *)IoAllocateIrp(*(_BYTE *)(v9 + 48), 0);
  if ( v10 )
  {
    IovUtilWatermarkIrp();
    v14 = a3;
    v10[6] = a3;
    v15 = a4;
    v10[7] = a4;
    KeInitializeEvent((int)v16, 1, 0);
    v10[10] = &v14;
    v10[11] = v16;
    v10[20] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    IopQueueThreadIrp((int)v10);
    memmove(v10[24] - 40, a2, 0x28u);
    v11 = IofCallDriver(v9, (int)v10);
    if ( v11 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v16, 0, 0, 0, 0);
      v11 = v14;
    }
    if ( a5 )
      *a5 = v15;
  }
  else
  {
    v11 = -1073741670;
  }
LABEL_7:
  ObfDereferenceObject(v9);
  return v11;
}
