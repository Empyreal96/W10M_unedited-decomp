// IoCreateFileSpecifyDeviceObjectHint 
 
int __fastcall IoCreateFileSpecifyDeviceObjectHint(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  int v16[6]; // [sp+30h] [bp-18h] BYREF

  v16[1] = 0;
  v16[3] = 0;
  v16[2] = a15;
  v16[0] = 16;
  return IoCreateFileEx(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, v16);
}
