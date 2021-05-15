// sub_7E0A00 
 
void sub_7E0A00(int a1, int a2, int a3, int a4, ...)
{
  unsigned __int16 *v4; // r4
  int *v5; // r5
  int *v6; // r7
  int v7; // r8
  int v8; // r0
  unsigned __int16 *v9; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  int v11; // [sp+4h] [bp+4h]
  va_list va1; // [sp+8h] [bp+8h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  while ( 1 )
  {
    v9 = va_arg(va1, unsigned __int16 *);
    v11 = va_arg(va1, _DWORD);
    if ( *((_BYTE *)v5 + 20) )
    {
      v8 = PnpAllocatePWSTR((unsigned __int16 *)v5[2], 0x7FFFFFFFu, 1466986064, (int *)va);
      v4 = v9;
      if ( v8 < 0
        || CmSetDeviceInterfacePathFormat(v8, (int)v9, 1) < 0
        || (RtlInitUnicodeString((unsigned int)va1, v4), IoSetDeviceInterfaceState((int)va1, v7) < 0) )
      {
LABEL_7:
        if ( v4 )
          ExFreePoolWithTag((unsigned int)v4);
        JUMPOUT(0x7774BE);
      }
      ExFreePoolWithTag((unsigned int)v4);
      v4 = 0;
      v9 = 0;
    }
    v5 = (int *)*v5;
    if ( v5 == v6 )
      goto LABEL_7;
  }
}
