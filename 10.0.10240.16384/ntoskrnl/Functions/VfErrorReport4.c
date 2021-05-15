// VfErrorReport4 
 
int __fastcall VfErrorReport4(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  unsigned int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r9
  int v13; // r3
  int result; // r0
  int v15; // [sp+0h] [bp-B0h]
  int v16[6]; // [sp+10h] [bp-A0h] BYREF
  char v17[136]; // [sp+28h] [bp-88h] BYREF

  v8 = KeGetCurrentIrql(KeGetCurrentIrql);
  v12 = v8;
  if ( v8 <= 2 && ViExpandStackNeeded(v8, v9, v10, v11) )
  {
    v13 = 4;
    v16[0] = 4;
    if ( v12 <= 1 )
      v13 = 1;
    if ( v12 > 1 )
      v13 = 0;
    v16[1] = 548;
    v16[2] = a2;
    v16[3] = (int)a3;
    v16[4] = a4;
    v16[5] = a5;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v16, 3072, v13, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(548, a2, *a3, a4);
  }
  else
  {
    ViErrorDisplayDescription(548);
    v15 = *a3;
    if ( RtlStringCbPrintfA(
           (int)v17,
           0x6Cu,
           (int)"CulpritAddress = %p, Irp = %p, ExpectedStatus = 0x%x, ActualStatus = 0x%x.\n",
           a2) >= 0 )
      VfUtilDbgPrint((int)v17);
    result = ViErrorFinishReport(548, a2, *a3, a4, v15);
  }
  return result;
}
