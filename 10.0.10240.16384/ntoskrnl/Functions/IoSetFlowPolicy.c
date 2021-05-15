// IoSetFlowPolicy 
 
int __fastcall IoSetFlowPolicy(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD v13[32]; // [sp+0h] [bp-80h] BYREF

  IopPreInitializeIoQosWorkItem(v13, IopSetFlowPolicy);
  v13[10] = a1;
  v13[5] = a4;
  v13[6] = a5;
  v13[4] = a3;
  v13[15] = a2;
  v13[7] = a6;
  v13[8] = a7;
  v13[9] = a8;
  IopRunIoQosWorkItem(v13);
  return v13[24];
}
