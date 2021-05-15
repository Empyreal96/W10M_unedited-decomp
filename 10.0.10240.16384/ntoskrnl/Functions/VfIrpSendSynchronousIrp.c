// VfIrpSendSynchronousIrp 
 
int __fastcall VfIrpSendSynchronousIrp(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int *a7)
{
  int v10; // r7
  _DWORD *v11; // r4
  int result; // r0
  int v13; // r2
  int v14; // r8
  char v15[48]; // [sp+8h] [bp-30h] BYREF

  if ( a6 )
    *a6 = 0;
  if ( a7 )
    *a7 = 0;
  v10 = IoGetAttachedDeviceReference(a1);
  v11 = (_DWORD *)IoAllocateIrpEx(v10, *(_BYTE *)(v10 + 48), 0);
  if ( v11 )
  {
    if ( a3 )
      IovUtilWatermarkIrp();
    v11[6] = a4;
    v11[7] = a5;
    KeInitializeEvent((int)v15, 1, 0);
    memmove(v11[24] - 40, a2, 0x28u);
    v13 = v11[24];
    *(_DWORD *)(v13 - 8) = ViIrpSynchronousCompletionRoutine;
    *(_DWORD *)(v13 - 4) = v15;
    *(_BYTE *)(v13 - 37) = -32;
    v14 = IofCallDriver(v10, (int)v11);
    ObfDereferenceObject(v10);
    if ( v14 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
      v14 = v11[6];
    }
    if ( a7 )
      *a7 = v14;
    if ( a6 )
      *a6 = v11[7];
    IoFreeIrp((int)v11);
    result = 1;
  }
  else
  {
    ObfDereferenceObject(v10);
    result = 0;
  }
  return result;
}
