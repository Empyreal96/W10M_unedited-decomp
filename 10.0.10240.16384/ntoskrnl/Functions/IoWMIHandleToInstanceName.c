// IoWMIHandleToInstanceName 
 
int __fastcall IoWMIHandleToInstanceName(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r2
  int v8; // r5
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a4;
  v6 = WmipGetFilePDO(a2, 0, v10);
  if ( v6 >= 0 )
  {
    v7 = a3;
    v8 = v10[0];
    v6 = IoWMIDeviceObjectToInstanceName(a1, v10[0], v7);
    if ( v6 >= 0 )
      v6 = 0;
    if ( v8 )
      ObfDereferenceObject(v8);
  }
  return v6;
}
