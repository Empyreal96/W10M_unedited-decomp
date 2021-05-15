// VfErrorReport7 
 
int __fastcall VfErrorReport7(int a1, int a2, int a3, int a4)
{
  unsigned int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r8
  int result; // r0
  int v13[6]; // [sp+8h] [bp-88h] BYREF
  char v14[112]; // [sp+20h] [bp-70h] BYREF

  v7 = KeGetCurrentIrql(KeGetCurrentIrql);
  v11 = v7;
  if ( v7 <= 2 && ViExpandStackNeeded(v7, v8, v9, v10) )
  {
    v13[0] = 7;
    v13[1] = 585;
    v13[2] = a2;
    v13[3] = a3;
    v13[4] = a4;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v13, 3072, v11 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(585, a2, a3, a4);
  }
  else
  {
    ViErrorDisplayDescription(585);
    if ( RtlStringCbPrintfA((int)v14, 0x56u, (int)"CulpritAddress = %p, DeviceObject1 = %p, DeviceObject2 = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v14);
    result = ViErrorFinishReport(585, a2, a3, a4, a3);
  }
  return result;
}
