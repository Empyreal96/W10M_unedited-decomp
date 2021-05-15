// IopIsBitlockerOn 
 
int IopIsBitlockerOn()
{
  int v0; // r4
  int result; // r0
  int v2; // [sp+8h] [bp-18h] BYREF
  int v3; // [sp+Ch] [bp-14h] BYREF
  char v4[16]; // [sp+10h] [bp-10h] BYREF

  v0 = 1;
  RtlInitUnicodeString((unsigned int)v4, L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\BitlockerStatus");
  if ( IopOpenRegistryKey(&v2, 0, v4, 131097, 0) < 0 )
    goto LABEL_9;
  if ( IopGetRegistryValue(v2, L"BootStatus", 0, &v3) >= 0 )
  {
    if ( *(_DWORD *)(v3 + 12) )
      v0 = *(_DWORD *)(*(_DWORD *)(v3 + 8) + v3);
    ExFreePoolWithTag(v3, 0);
  }
  ObCloseHandle(v2);
  if ( v0 == 1 )
LABEL_9:
    result = 1;
  else
    result = 0;
  return result;
}
