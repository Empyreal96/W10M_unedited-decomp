// WdipSemDeleteValueFromRegistry 
 
int __fastcall WdipSemDeleteValueFromRegistry(int a1, int a2, int a3, int a4)
{
  _DWORD v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[1] = a3;
  v5[2] = a4;
  if ( !a1 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v5, L"SEMUpdate");
  return ZwDeleteValueKey();
}
