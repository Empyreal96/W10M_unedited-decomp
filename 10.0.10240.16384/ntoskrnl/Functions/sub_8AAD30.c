// sub_8AAD30 
 
int __fastcall sub_8AAD30(int a1)
{
  int v2; // r4
  int v3; // r5
  int v5; // [sp+0h] [bp-20h] BYREF
  int v6; // [sp+4h] [bp-1Ch] BYREF
  char v7[24]; // [sp+8h] [bp-18h] BYREF

  v2 = 0;
  RtlInitUnicodeString((unsigned int)v7, L"\\DosDevices\\ACPI_ROOT_OBJECT");
  v5 = 0;
  v3 = IoGetDeviceObjectPointer((int)v7, 128, &v5, &v6);
  if ( v3 >= 0 )
    v2 = sub_8AAD14(v6);
  if ( v5 )
    ObfDereferenceObject(v5);
  if ( v3 >= 0 )
  {
    if ( !v2 )
      return -1073741632;
    v3 = PnpGetSystemPdoList(v2, a1);
  }
  if ( v2 )
    ObfDereferenceObject(v2);
  return v3;
}
