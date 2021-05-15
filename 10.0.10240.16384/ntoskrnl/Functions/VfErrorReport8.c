// VfErrorReport8 
 
int __fastcall VfErrorReport8(int a1, int a2, int a3)
{
  unsigned int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r7
  int result; // r0
  _DWORD v12[6]; // [sp+8h] [bp-68h] BYREF
  char v13[80]; // [sp+20h] [bp-50h] BYREF

  v6 = KeGetCurrentIrql(a1);
  v10 = v6;
  if ( v6 <= 2 && ViExpandStackNeeded(v6, v7, v8, v9) )
  {
    v12[0] = 8;
    v12[1] = a1;
    v12[2] = a2;
    v12[3] = a3;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v12, 3072, v10 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(a1, a2, a3, 0);
  }
  else
  {
    ViErrorDisplayDescription(a1);
    if ( RtlStringCbPrintfA((int)v13, 0x39u, (int)"CulpritAddress = %p, DeviceObject = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v13);
    result = ViErrorFinishReport(a1, a2, a3, 0, a3);
  }
  return result;
}
