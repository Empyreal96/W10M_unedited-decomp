// AdtpBuildObjectTypeStrings 
 
int __fastcall AdtpBuildObjectTypeStrings(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, _BYTE *a6)
{
  int v6; // r4
  int v7; // r6
  unsigned int v10; // r8
  int v11; // r10
  int v12; // r2
  int v13; // r6
  int v14; // r4
  unsigned int v15; // r2
  int v16; // r2
  int v18; // [sp+0h] [bp-50h]
  unsigned __int8 v19; // [sp+18h] [bp-38h] BYREF
  char v20[3]; // [sp+19h] [bp-37h] BYREF
  int v21; // [sp+1Ch] [bp-34h] BYREF
  int v22; // [sp+20h] [bp-30h]
  int v23; // [sp+24h] [bp-2Ch]
  int v24; // [sp+28h] [bp-28h] BYREF
  unsigned int v25; // [sp+2Ch] [bp-24h]

  v6 = a2;
  v7 = a1;
  v22 = a1;
  v23 = a2;
  v21 = 0;
  RtlInitUnicodeString(a5, (unsigned __int16 *)&dword_8CE900);
  *a6 = 0;
  if ( a4 )
  {
    qsort(a3, a4, 0x18u, (int (__fastcall *)(unsigned int, _BYTE *))CompareObjectTypes);
    v10 = 0;
    v11 = *(_DWORD *)(a3 + 20) - 1;
    do
    {
      v12 = *(_DWORD *)(a3 + 20);
      if ( v12 != v11 )
      {
        v11 = *(_DWORD *)(a3 + 20);
        if ( v12 )
        {
          v14 = AdtpBuildAccessesString(v7, v6, v12, 1, (unsigned int)&v24, 0, 0, 0, &v19);
          if ( v14 < 0 )
            return v14;
          v13 = v19;
        }
        else
        {
          RtlInitUnicodeString((unsigned int)&v24, L"---\r\n");
          v13 = 0;
          v19 = 0;
        }
        v14 = AdtpAppendString(a5, a6, &v24, &v21);
        if ( v13 )
          ExFreePoolWithTag(v25);
        if ( v14 < 0 )
          return v14;
        v7 = v22;
      }
      v15 = *(unsigned __int16 *)(a3 + 18);
      if ( v15 >= 4 )
        v15 = 3;
      v14 = AdtpAppendZString(a5, a6, (unsigned __int16 *)off_41DEC8[v15], &v21);
      if ( v14 < 0 )
        return v14;
      v20[0] = 0;
      v14 = AdtpBuildGuidString((int *)a3, (int)&v24, v16, (int)v20, v18, v20);
      if ( v14 < 0 )
        return v14;
      v14 = AdtpAppendString(a5, a6, &v24, &v21);
      ExFreePoolWithTag(v25);
      if ( v14 < 0 )
        return v14;
      v14 = AdtpAppendZString(a5, a6, L"\r\n", &v21);
      if ( v14 < 0 )
        return v14;
      ++v10;
      v6 = v23;
      a3 += 24;
    }
    while ( v10 < a4 );
  }
  return 0;
}
