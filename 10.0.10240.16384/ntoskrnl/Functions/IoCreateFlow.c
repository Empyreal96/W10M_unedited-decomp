// IoCreateFlow 
 
int __fastcall IoCreateFlow(int a1)
{
  _DWORD v3[30]; // [sp+0h] [bp-78h] BYREF

  IopPreInitializeIoQosWorkItem(v3, IopCreateFlow);
  v3[10] = a1;
  IopRunIoQosWorkItem(v3);
  return v3[24];
}
