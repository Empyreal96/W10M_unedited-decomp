// AslpFileGetSizeAttribute 
 
int __fastcall AslpFileGetSizeAttribute(int a1)
{
  int v2; // r4
  int v4[6]; // [sp+10h] [bp-28h] BYREF

  memset(v4, 0, sizeof(v4));
  memset((_BYTE *)a1, 0, 24);
  v2 = ZwQueryInformationFile();
  if ( v2 >= 0 )
  {
    *(_DWORD *)a1 = 2;
    *(_DWORD *)(a1 + 4) = 4;
    *(_DWORD *)(a1 + 8) = v4[2];
    *(_DWORD *)(a1 + 12) = 0;
    v2 = 0;
    *(_DWORD *)(a1 + 16) |= 1u;
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileGetSizeAttribute", 1032, "NtQueryFullAttributesFile failed [%x]", v2);
  }
  return v2;
}
