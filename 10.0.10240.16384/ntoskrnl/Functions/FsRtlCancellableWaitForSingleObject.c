// FsRtlCancellableWaitForSingleObject 
 
int __fastcall FsRtlCancellableWaitForSingleObject(int a1, int a2, int a3, int a4)
{
  int varg_r0[4]; // [sp+10h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  return FsRtlCancellableWaitForMultipleObjects(1, varg_r0);
}
