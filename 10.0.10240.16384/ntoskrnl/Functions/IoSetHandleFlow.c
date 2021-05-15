// IoSetHandleFlow 
 
int __fastcall IoSetHandleFlow(int a1, int a2, int a3, int a4)
{
  _DWORD v8[26]; // [sp+0h] [bp-80h] BYREF
  char v9; // [sp+68h] [bp-18h]

  IopPreInitializeIoQosWorkItem(v8, IopSetHandleFlow);
  v9 = 0;
  v8[10] = a2;
  v8[11] = a1;
  v8[25] = a4;
  IopRunIoQosWorkItem(v8);
  return v8[24];
}
