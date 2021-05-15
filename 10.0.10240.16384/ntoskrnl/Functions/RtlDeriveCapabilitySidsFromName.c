// RtlDeriveCapabilitySidsFromName 
 
int __fastcall RtlDeriveCapabilitySidsFromName(int a1, int a2, int a3)
{
  int result; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  _DWORD *v10; // r5
  int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r4
  int *v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  unsigned __int16 v22; // [sp+0h] [bp-40h] BYREF
  int v23; // [sp+4h] [bp-3Ch]
  int v24; // [sp+8h] [bp-38h] BYREF
  int v25; // [sp+Ch] [bp-34h]
  int v26; // [sp+10h] [bp-30h]
  int v27; // [sp+14h] [bp-2Ch]
  int v28; // [sp+18h] [bp-28h]
  int v29; // [sp+1Ch] [bp-24h]
  int v30; // [sp+20h] [bp-20h]
  int v31; // [sp+24h] [bp-1Ch]

  if ( !a1 || !a2 || !a3 )
    __fastfail(5u);
  memset((_BYTE *)a3, 0, 48);
  memset((_BYTE *)a2, 0, 44);
  result = RtlUpcaseUnicodeString(&v22, a1, 1);
  if ( result >= 0 )
  {
    SymCryptSha256(v23, v22, &v24);
    RtlInitializeSid(a2, &RtlpNtAuthority, 9);
    *(_DWORD *)(a2 + 8) = 32;
    v7 = v25;
    v8 = v26;
    v9 = v27;
    *(_DWORD *)(a2 + 12) = v24;
    *(_DWORD *)(a2 + 16) = v7;
    *(_DWORD *)(a2 + 20) = v8;
    *(_DWORD *)(a2 + 24) = v9;
    v10 = (_DWORD *)(a2 + 28);
    v11 = v29;
    v12 = v30;
    v13 = v31;
    v14 = 0;
    *v10 = v28;
    v10[1] = v11;
    v10[2] = v12;
    v10[3] = v13;
    v15 = &RtlpLegacyApplicationCapabilityNames;
    do
    {
      if ( RtlEqualUnicodeString(&v22, v15, 0) )
        return sub_50B350();
      ++v14;
      v15 += 2;
    }
    while ( v14 < 0xC );
    RtlFreeAnsiString(&v22);
    if ( v14 == 12 )
    {
      RtlInitializeSid(a3, &RtlpAppPackageAuthority, 10);
      *(_DWORD *)(a3 + 8) = 3;
      *(_DWORD *)(a3 + 12) = 1024;
      v16 = v25;
      v17 = v26;
      v18 = v27;
      *(_DWORD *)(a3 + 16) = v24;
      *(_DWORD *)(a3 + 20) = v16;
      *(_DWORD *)(a3 + 24) = v17;
      *(_DWORD *)(a3 + 28) = v18;
      v19 = v29;
      v20 = v30;
      v21 = v31;
      *(_DWORD *)(a3 + 32) = v28;
      *(_DWORD *)(a3 + 36) = v19;
      *(_DWORD *)(a3 + 40) = v20;
      *(_DWORD *)(a3 + 44) = v21;
    }
    result = 0;
  }
  return result;
}
