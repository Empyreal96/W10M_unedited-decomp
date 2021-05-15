// IoGetDeviceObjectPointer 
 
int __fastcall IoGetDeviceObjectPointer(int a1, int a2, _DWORD *a3, int *a4)
{
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  _DWORD *v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v14; // [sp+8h] [bp-38h]
  int v15[13]; // [sp+Ch] [bp-34h] BYREF

  v15[3] = 24;
  v15[4] = 0;
  if ( IopCaseInsensitive )
    v6 = 64;
  else
    v6 = 0;
  v15[5] = a1;
  v15[6] = v6 | 0x200;
  v15[7] = 0;
  v15[8] = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = ZwOpenFile();
  v9 = v8;
  if ( v8 >= 0 )
  {
    v9 = ObReferenceObjectByHandle(v14, 0, IoFileObjectType, 0, v15);
    if ( v9 >= 0 )
    {
      v10 = (_DWORD *)v15[0];
      *a3 = v15[0];
      *a4 = IoGetRelatedDeviceObject(v10);
    }
    v8 = ZwClose();
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v9;
}
