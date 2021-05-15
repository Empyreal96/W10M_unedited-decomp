// VfErrorReport5 
 
int __fastcall VfErrorReport5(int a1, int a2, _DWORD *a3)
{
  unsigned int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r7
  int result; // r0
  int v11; // r6
  int v12[6]; // [sp+8h] [bp-60h] BYREF
  char v13[72]; // [sp+20h] [bp-48h] BYREF

  v5 = KeGetCurrentIrql(a1);
  v9 = v5;
  if ( v5 <= 2 && ViExpandStackNeeded(v5, v6, v7, v8) )
  {
    v12[0] = 5;
    v12[1] = 550;
    v12[2] = a2;
    v12[3] = (int)a3;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v12, 3072, v9 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(550, a2, *a3, 0);
  }
  else
  {
    v11 = *a3;
    ViErrorDisplayDescription(550);
    if ( RtlStringCbPrintfA((int)v13, 0x30u, (int)"CulpritAddress = %p, Irp = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v13);
    result = ViErrorFinishReport(550, a2, v11, 0, v11);
  }
  return result;
}
