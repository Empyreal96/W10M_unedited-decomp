// IoAttachDevice 
 
int __fastcall IoAttachDevice(unsigned int a1, _DWORD *a2, int *a3)
{
  int v5; // r3
  int v6; // r4
  int v7; // r4
  int v9; // [sp+8h] [bp-38h]
  _DWORD *v10[13]; // [sp+Ch] [bp-34h] BYREF

  v10[3] = (_DWORD *)24;
  v10[4] = 0;
  if ( IopCaseInsensitive )
    v5 = 64;
  else
    v5 = 0;
  v10[5] = a2;
  v10[6] = (_DWORD *)(v5 | 0x200);
  v10[7] = 0;
  v10[8] = 0;
  v6 = ZwOpenFile();
  if ( v6 >= 0 )
  {
    v6 = ObReferenceObjectByHandle(v9, 0, (int)IoFileObjectType, 0, (int)v10, 0);
    if ( v6 < 0 )
    {
      ZwClose();
    }
    else
    {
      v7 = IoGetRelatedDeviceObject(v10[0]);
      ZwClose();
      v6 = IoAttachDeviceToDeviceStackSafe(a1, v7, a3);
      ObfDereferenceObject((int)v10[0]);
    }
  }
  return v6;
}
