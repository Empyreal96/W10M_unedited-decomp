// PopDiagTraceIoCoalescingOn 
 
int __fastcall PopDiagTraceIoCoalescingOn(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, char a25, char a26, char a27, char a28)
{
  int result; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r3

  result = PopPrintEx(3);
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_IO_COALESCING_ON);
    if ( result )
      result = sub_7BF0CC(
                 result,
                 v29,
                 v30,
                 v31,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 a15,
                 a16,
                 a17,
                 a18,
                 a19,
                 a20,
                 a21,
                 a22,
                 a23,
                 a24,
                 a25,
                 a26,
                 a27,
                 a28);
  }
  return result;
}
