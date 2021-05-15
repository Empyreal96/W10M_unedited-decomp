// IoQueryFlowInformation 
 
int __fastcall IoQueryFlowInformation(int a1, int a2, int a3, int a4)
{
  _DWORD v9[26]; // [sp+0h] [bp-80h] BYREF
  char v10; // [sp+69h] [bp-17h]

  IopPreInitializeIoQosWorkItem(v9, IopQueryFlowInformation);
  v9[10] = a1;
  v9[16] = a2;
  v9[17] = a4;
  v9[19] = a3;
  v9[18] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  IopRunIoQosWorkItem(v9);
  return v9[24];
}
