// PopRegisterCoolingExtensionProtection 
 
int __fastcall PopRegisterCoolingExtensionProtection(int a1)
{
  int v2; // r4
  int v3; // r5
  int *v4; // r0
  unsigned __int16 *v5; // r7
  void **v6; // r8
  unsigned int v8; // [sp+10h] [bp-30h] BYREF
  void **v9; // [sp+14h] [bp-2Ch] BYREF
  int v10; // [sp+18h] [bp-28h] BYREF
  char v11[32]; // [sp+20h] [bp-20h] BYREF

  v9 = 0;
  if ( *(_DWORD *)(a1 + 28) )
    return 0;
  v3 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(a1 + 24));
  if ( IoGetDeviceProperty(v3, 11, 0, 0, &v8) == -1073741789 )
  {
    v4 = (int *)ExAllocatePoolWithTag(1, v8, 1819231056);
    v5 = (unsigned __int16 *)v4;
    if ( v4 )
    {
      v2 = IoGetDeviceProperty(v3, 11, v8, v4, &v8);
      if ( v2 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v11, v5);
        v2 = IoGetDeviceObjectPointer((int)v11, 2032127, &v9, &v10);
        v6 = v9;
        if ( v2 >= 0 )
          v2 = IoRegisterPlugPlayNotification(
                 3,
                 0,
                 v9,
                 *(_DWORD *)(v10 + 8),
                 (int)PopCoolingExtensionPnpNotification,
                 a1,
                 (unsigned __int16 *)(a1 + 28));
        if ( v6 )
          ObfDereferenceObject((int)v6);
      }
      ExFreePoolWithTag((unsigned int)v5);
    }
    else
    {
      v2 = -1073741670;
    }
  }
  else
  {
    v2 = -1073741823;
  }
  if ( v3 )
    ObfDereferenceObject(v3);
  return v2;
}
