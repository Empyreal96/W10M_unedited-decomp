// VfErrorReport9 
 
int __fastcall VfErrorReport9(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r6
  int result; // r0
  int v10; // [sp+0h] [bp-50h]
  _DWORD v11[6]; // [sp+8h] [bp-48h] BYREF
  char v12[48]; // [sp+20h] [bp-30h] BYREF

  v4 = KeGetCurrentIrql(a1);
  v8 = v4;
  if ( v4 <= 2 && ViExpandStackNeeded(v4, v5, v6, v7) )
  {
    v11[0] = 9;
    v11[1] = a1;
    v11[2] = a2;
    result = KeExpandKernelStackAndCalloutEx((int)ViErrorReportCallout, (int)v11, 3072, v8 <= 1, 0);
    if ( result < 0 )
      result = ViErrorReportDirect(a1, a2, 0, 0);
  }
  else
  {
    ViErrorDisplayDescription(a1);
    if ( RtlStringCbPrintfA((int)v12, 0x1Eu, (int)"CulpritAddress = %p.\n", a2) >= 0 )
      VfUtilDbgPrint((int)v12);
    result = ViErrorFinishReport(a1, a2, 0, 0, v10);
  }
  return result;
}
