// AslRegistryBuildMachinePath 
 
int __fastcall AslRegistryBuildMachinePath(int a1, unsigned __int16 *a2)
{
  int v4; // r0
  unsigned __int16 v5; // r3
  _BYTE *v6; // r0
  int v7; // r4
  int v8; // r2
  int v9; // r3
  _DWORD v11[4]; // [sp+8h] [bp-10h] BYREF

  v11[0] = 0;
  v11[1] = 0;
  RtlInitUnicodeString((unsigned int)v11, L"\\Registry\\Machine");
  *(_WORD *)a1 = 0;
  v4 = wcslen(a2);
  v5 = LOWORD(v11[0]) + 2 * (v4 + 1);
  *(_WORD *)(a1 + 2) = v5;
  v6 = AslAlloc(v4, v5);
  *(_DWORD *)(a1 + 4) = v6;
  if ( v6 )
  {
    RtlAppendUnicodeStringToString((unsigned __int16 *)a1, (unsigned __int16 *)v11);
    RtlAppendUnicodeToString((unsigned __int16 *)a1, (int)a2, v8, v9);
    v7 = 0;
  }
  else
  {
    v7 = -1073741801;
    AslLogCallPrintf(
      1,
      (int)"AslRegistryBuildMachinePath",
      1193,
      "Failed to allocate %d bytes for user key buffer",
      *(unsigned __int16 *)(a1 + 2));
  }
  return v7;
}
