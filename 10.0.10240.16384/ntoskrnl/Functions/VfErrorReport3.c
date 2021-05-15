// VfErrorReport3 
 
int __fastcall VfErrorReport3(int a1, int a2, _DWORD *a3, int a4)
{
  unsigned int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  int result; // r0
  int v14; // r4
  _DWORD v15[6]; // [sp+8h] [bp-78h] BYREF
  char v16[96]; // [sp+20h] [bp-60h] BYREF

  v8 = KeGetCurrentIrql(a1);
  v12 = v8;
  if ( v8 <= 2 && ViExpandStackNeeded(v8, v9, v10, v11) )
  {
    v15[0] = 3;
    v15[1] = a1;
    v15[2] = a2;
    v15[3] = a3;
    v15[4] = a4;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v15, 3072, v12 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(a1, a2, *a3, result);
  }
  else
  {
    v14 = *a3;
    ViErrorDisplayDescription(a1);
    if ( RtlStringCbPrintfA((int)v16, 0x47u, (int)"CulpritAddress = %p, Irp = %p, Status = 0x%x.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v16);
    result = ViErrorFinishReport(a1, a2, v14, a4, v14);
  }
  return result;
}
