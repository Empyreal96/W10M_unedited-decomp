// IopReadDumpRegistry 
 
int __fastcall IopReadDumpRegistry(int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // r0
  int v5; // [sp+8h] [bp-18h] BYREF
  int v6; // [sp+Ch] [bp-14h] BYREF
  __int16 v7[2]; // [sp+10h] [bp-10h] BYREF
  const __int16 *v8; // [sp+14h] [bp-Ch]

  v7[0] = 126;
  v7[1] = 128;
  v8 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl";
  result = IopOpenRegistryKey(&v6, 0, v7, 131097, 0);
  if ( result >= 0 )
  {
    if ( IopGetRegistryValue(v6, L"AutoReboot", 0, &v5) >= 0 )
    {
      if ( *(_DWORD *)(v5 + 12) )
        IopAutoReboot = *(_DWORD *)(*(_DWORD *)(v5 + 8) + v5);
      ExFreePoolWithTag(v5, 0);
    }
    if ( a2 && IopGetRegistryValue(v6, L"CrashDumpEnabled", 0, &v5) >= 0 )
    {
      v4 = v5;
      if ( *(_DWORD *)(v5 + 12) )
        *a2 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + v5);
      ExFreePoolWithTag(v4, 0);
    }
    result = ObCloseHandle(v6);
  }
  return result;
}
