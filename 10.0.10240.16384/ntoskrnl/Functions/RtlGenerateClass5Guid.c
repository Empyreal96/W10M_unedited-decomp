// RtlGenerateClass5Guid 
 
int __fastcall RtlGenerateClass5Guid(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v10; // r5
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // [sp+10h] [bp-58h] BYREF
  int v18; // [sp+14h] [bp-54h] BYREF
  int v19; // [sp+18h] [bp-50h] BYREF
  unsigned int v20; // [sp+20h] [bp-48h] BYREF
  int v21; // [sp+24h] [bp-44h]
  int v22; // [sp+28h] [bp-40h]
  int v23; // [sp+2Ch] [bp-3Ch]
  _DWORD v24[14]; // [sp+30h] [bp-38h] BYREF

  v5 = 0;
  v17 = 0;
  v18 = 0;
  if ( !a1 )
    return sub_80C174();
  if ( !a4 )
    return -1073741582;
  if ( !a2 && a3 )
    return -1073741583;
  v10 = BCryptOpenAlgorithmProvider(&v18, L"SHA1", L"Microsoft Primitive Provider", 0);
  if ( v10 >= 0 )
  {
    v10 = BCryptGetProperty(v18, L"ObjectLength", &v19);
    if ( v10 >= 0 )
    {
      v5 = ExAllocatePoolWithTag(1, v19, 1684632903);
      if ( !v5 )
        v10 = -1073741670;
      if ( v10 >= 0 )
      {
        v10 = BCryptCreateHash(v18, &v17, v5, v19);
        if ( v10 >= 0 )
        {
          v11 = *(_DWORD *)(a1 + 4);
          v12 = *(_DWORD *)(a1 + 8);
          v13 = *(_DWORD *)(a1 + 12);
          v20 = *(_DWORD *)a1;
          v21 = v11;
          v22 = v12;
          v23 = v13;
          v20 = bswap32(*(_DWORD *)a1);
          LOWORD(v21) = __rev16(*(unsigned __int16 *)(a1 + 4));
          HIWORD(v21) = __rev16(*(unsigned __int16 *)(a1 + 6));
          v10 = BCryptHashData(v17, &v20, 16);
          if ( v10 >= 0 )
          {
            v10 = BCryptHashData(v17, a2, a3);
            if ( v10 >= 0 )
            {
              v10 = BCryptFinishHash(v17, v24);
              if ( v10 >= 0 )
              {
                v14 = v24[1];
                v15 = v24[2];
                v16 = v24[3];
                *(_DWORD *)a4 = v24[0];
                *(_DWORD *)(a4 + 4) = v14;
                *(_DWORD *)(a4 + 8) = v15;
                *(_DWORD *)(a4 + 12) = v16;
                *(_DWORD *)a4 = bswap32(*(_DWORD *)a4);
                *(_WORD *)(a4 + 4) = __rev16(*(unsigned __int16 *)(a4 + 4));
                *(_WORD *)(a4 + 6) = __rev16(*(unsigned __int16 *)(a4 + 6)) & 0xFFF | 0x5000;
                *(_BYTE *)(a4 + 8) = *(_BYTE *)(a4 + 8) & 0x3F | 0x80;
              }
            }
          }
        }
      }
    }
  }
  if ( v17 )
    BCryptDestroyHash();
  if ( v18 )
    BCryptCloseAlgorithmProvider(v18);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v10;
}
