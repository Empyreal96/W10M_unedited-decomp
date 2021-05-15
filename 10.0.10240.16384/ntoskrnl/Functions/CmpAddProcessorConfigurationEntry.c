// CmpAddProcessorConfigurationEntry 
 
int __fastcall CmpAddProcessorConfigurationEntry(int a1, int a2, int a3)
{
  int result; // r0
  unsigned int v7; // r4
  int v8; // r3
  int v9; // [sp+10h] [bp-F0h] BYREF
  char v10[8]; // [sp+18h] [bp-E8h] BYREF
  int v11; // [sp+20h] [bp-E0h] BYREF
  unsigned __int16 v12[4]; // [sp+28h] [bp-D8h] BYREF
  _DWORD v13[14]; // [sp+30h] [bp-D0h] BYREF
  char v14[152]; // [sp+68h] [bp-98h] BYREF

  memset(v13, 0, 52);
  v13[3] = 1;
  v13[4] = 1;
  LOWORD(v13[8]) = *(unsigned __int8 *)(a1 + 1052);
  HIWORD(v13[8]) = *(unsigned __int8 *)(a1 + 1053);
  v13[11] = v14;
  v13[7] = a2;
  RtlStringCbPrintfA((int)v14, 0x80u, (int)"ARM Family 7 Model %X Revision %3X", *(unsigned __int16 *)(a1 + 960));
  v13[10] = strlen((unsigned int)v14) + 1;
  result = CmpInitializeRegistryNode(v13, a3, &v9);
  if ( result >= 0 )
  {
    v7 = a1 + 1288;
    if ( !*(_BYTE *)(a1 + 1288) )
      v7 = 0;
    if ( v7 )
    {
      RtlInitUnicodeString((unsigned int)v10, (unsigned __int16 *)&CmpVendorID);
      RtlInitAnsiString((unsigned int)v12, v7);
      if ( RtlAnsiStringToUnicodeString((unsigned __int16 *)&v11, v12, 1, v8) >= 0 )
      {
        ZwSetValueKey();
        RtlFreeAnsiString(&v11);
      }
    }
    if ( *(_DWORD *)(a1 + 1292) )
    {
      RtlInitUnicodeString((unsigned int)v10, (unsigned __int16 *)&CmpFeatureBits);
      ZwSetValueKey();
    }
    if ( *(_DWORD *)(a1 + 964) )
    {
      RtlInitUnicodeString((unsigned int)v10, L"~MHz");
      ZwSetValueKey();
    }
    CmpAddProcessorCapabilities();
    ZwClose();
    result = 0;
  }
  return result;
}
