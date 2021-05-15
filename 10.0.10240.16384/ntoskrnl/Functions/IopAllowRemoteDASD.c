// IopAllowRemoteDASD 
 
int IopAllowRemoteDASD()
{
  int v0; // r4
  int v2; // [sp+8h] [bp-20h] BYREF
  int v3; // [sp+Ch] [bp-1Ch] BYREF
  char v4[8]; // [sp+10h] [bp-18h] BYREF
  char v5[4]; // [sp+18h] [bp-10h] BYREF
  int v6; // [sp+1Ch] [bp-Ch]

  v0 = 0;
  RtlInitUnicodeString((unsigned int)v5, L"AllowRemoteDASD");
  RtlInitUnicodeString(
    (unsigned int)v4,
    L"\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices");
  if ( IopOpenRegistryKey(&v2, 0, v4, 131097, 0) >= 0 )
  {
    if ( IopGetRegistryValue(v2, v6, 0, &v3) >= 0 )
    {
      if ( *(_DWORD *)(v3 + 12) && *(_DWORD *)(*(_DWORD *)(v3 + 8) + v3) )
        v0 = 1;
      ExFreePoolWithTag(v3);
    }
    ZwClose();
  }
  return v0;
}
