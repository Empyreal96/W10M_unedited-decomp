// VfErrorReport1 
 
int __fastcall VfErrorReport1(int a1, int a2, int a3)
{
  unsigned int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  int result; // r0
  _DWORD v13[6]; // [sp+8h] [bp-60h] BYREF
  char v14[72]; // [sp+20h] [bp-48h] BYREF

  v6 = KeGetCurrentIrql(a1);
  v10 = v6;
  if ( v6 <= 2 && ViExpandStackNeeded(v6, v7, v8, v9) )
  {
    v11 = 1;
    v13[0] = 1;
    v13[1] = a1;
    if ( v10 > 1 )
      v11 = 0;
    v13[2] = a2;
    v13[3] = a3;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v13, 3072, v11, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(a1, a2, a3, 0);
  }
  else
  {
    ViErrorDisplayDescription(a1);
    if ( RtlStringCbPrintfA((int)v14, 0x30u, (int)"CulpritAddress = %p, Irp = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v14);
    result = ViErrorFinishReport(a1, a2, a3, 0, a3);
  }
  return result;
}
