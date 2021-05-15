// SepSetProcessUniqueAttribute 
 
int __fastcall SepSetProcessUniqueAttribute(int a1)
{
  int result; // r0
  int v3; // r0
  int v4; // [sp+0h] [bp-48h] BYREF
  __int16 v5; // [sp+8h] [bp-40h] BYREF
  __int16 v6; // [sp+Ah] [bp-3Eh]
  int v7; // [sp+Ch] [bp-3Ch]
  __int16 *v8; // [sp+10h] [bp-38h]
  char v9[8]; // [sp+18h] [bp-30h] BYREF
  int v10[2]; // [sp+20h] [bp-28h] BYREF
  __int16 v11; // [sp+28h] [bp-20h] BYREF
  __int16 v12[11]; // [sp+2Ah] [bp-1Eh] BYREF

  v11 = 0;
  memset(v12, 0, sizeof(v12));
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  ExAllocateLocallyUniqueId(v10);
  result = SepAddLuidToIndexEntry(v10, v9);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)&v11, L"TSA://ProcUnique");
    v12[4] = 0;
    v12[3] = 2;
    *(_DWORD *)&v12[5] = 65;
    *(_DWORD *)&v12[7] = 2;
    *(_DWORD *)&v12[9] = v9;
    v4 = 4;
    v5 = 1;
    v6 = 0;
    v3 = *(_DWORD *)(a1 + 476);
    v7 = 1;
    v8 = &v11;
    result = AuthzBasepSetSecurityAttributesToken(v3, &v4, (int)&v5);
  }
  return result;
}
