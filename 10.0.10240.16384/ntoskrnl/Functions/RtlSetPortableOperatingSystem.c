// RtlSetPortableOperatingSystem 
 
int __fastcall RtlSetPortableOperatingSystem(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+8h] [bp-8h] BYREF

  v5[1] = a4;
  v5[0] = a1 != 0;
  return ((int (__fastcall *)(int, _DWORD, const __int16 *, int, int *, int))RtlWriteRegistryValue)(
           2,
           0,
           L"PortableOperatingSystem",
           4,
           v5,
           4);
}
