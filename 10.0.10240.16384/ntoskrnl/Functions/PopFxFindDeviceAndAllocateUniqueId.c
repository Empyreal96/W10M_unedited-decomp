// PopFxFindDeviceAndAllocateUniqueId 
 
int __fastcall PopFxFindDeviceAndAllocateUniqueId(_DWORD *a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v8; // r0
  int v9[2]; // [sp+0h] [bp-20h] BYREF
  int v10; // [sp+8h] [bp-18h] BYREF
  int v11; // [sp+Ch] [bp-14h]

  v9[1] = (int)a2;
  v10 = a3;
  v11 = a4;
  v5 = 0;
  v9[0] = 0;
  if ( PopFxQueryBiosDeviceName((int)a1, (int)&v10) < 0 )
  {
    a1[40] = a1[5];
    a1[41] = a1[6];
LABEL_3:
    *a2 = v5;
    return 0;
  }
  v8 = PopFxFindAcpiDeviceByUniqueId((int)&v10, v9);
  v5 = v9[0];
  if ( v8 < 0 )
  {
    if ( v8 == -1073741738 )
      JUMPOUT(0x7E0DEE);
    a1[40] = v10;
    a1[41] = v11;
    goto LABEL_3;
  }
  return sub_7E0DD4();
}
