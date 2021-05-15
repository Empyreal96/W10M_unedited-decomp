// IoWMIOpenBlock 
 
int __fastcall IoWMIOpenBlock(int *a1, int a2, _DWORD *a3)
{
  int v6; // r0
  int result; // r0
  int v8; // [sp+28h] [bp-98h] BYREF
  char v9[8]; // [sp+30h] [bp-90h] BYREF
  int v10[6]; // [sp+38h] [bp-88h] BYREF
  unsigned __int16 v11[9]; // [sp+50h] [bp-70h] BYREF
  __int16 v12[47]; // [sp+62h] [bp-5Eh] BYREF

  RtlStringCchCopyW(v11, 0x2Eu, (int)L"\\WmiGuid\\");
  RtlStringCchPrintfW(v12, 0x25u, (int)L"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x", *a1);
  RtlInitUnicodeString((unsigned int)v9, v11);
  memset(v10, 0, sizeof(v10));
  v10[0] = 24;
  v10[2] = (int)v9;
  v10[3] = 512;
  if ( (a2 & 4) != 0 )
  {
    v6 = 2244928;
  }
  else if ( (a2 & 0x40000) != 0 )
  {
    v6 = 2244872;
  }
  else
  {
    v6 = 2244924;
  }
  result = WmipOpenBlock(v6, 0, v10, a2, &v8);
  if ( result >= 0 )
  {
    result = 0;
    *a3 = v8;
  }
  return result;
}
