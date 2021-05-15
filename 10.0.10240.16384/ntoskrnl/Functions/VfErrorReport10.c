// VfErrorReport10 
 
int __fastcall VfErrorReport10(int a1, int a2, int a3, int a4)
{
  unsigned int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  int result; // r0
  _DWORD v14[6]; // [sp+8h] [bp-80h] BYREF
  char v15[104]; // [sp+20h] [bp-68h] BYREF

  v8 = KeGetCurrentIrql(a1);
  v12 = v8;
  if ( v8 <= 2 && ViExpandStackNeeded(v8, v9, v10, v11) )
  {
    v14[0] = 10;
    v14[1] = a1;
    v14[2] = a2;
    v14[3] = a3;
    v14[4] = a4;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v14, 3072, v12 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(a1, a2, a3, a4);
  }
  else
  {
    ViErrorDisplayDescription(a1);
    if ( RtlStringCbPrintfA((int)v15, 0x4Bu, (int)"CulpritAddress = %p, Irp = %p, DeviceObject = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v15);
    result = ViErrorFinishReport(a1, a2, a3, a4, a3);
  }
  return result;
}
