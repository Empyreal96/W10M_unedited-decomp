// IopGetNumaNodeInformation 
 
int __fastcall IopGetNumaNodeInformation(int a1, _WORD *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r6
  int v7; // r4
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  v5 = IopGetDevicePDO(*(_DWORD *)(a1 + 4));
  v6 = v5;
  if ( !v5 )
    return -1073741810;
  v7 = IoGetDeviceNumaNode(v5, v9);
  ObfDereferenceObject(v6);
  if ( v7 >= 0 )
    *a2 = v9[0];
  return v7;
}
