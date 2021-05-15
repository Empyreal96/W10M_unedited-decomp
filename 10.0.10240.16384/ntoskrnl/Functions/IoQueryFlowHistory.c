// IoQueryFlowHistory 
 
int __fastcall IoQueryFlowHistory(int a1, int a2, int a3, int a4)
{
  _DWORD v9[32]; // [sp+0h] [bp-80h] BYREF

  IopPreInitializeIoQosWorkItem(v9, IopQueryFlowHistory);
  v9[10] = a1;
  v9[12] = a2;
  v9[13] = a3;
  v9[14] = a4;
  IopRunIoQosWorkItem(v9);
  return v9[24];
}
