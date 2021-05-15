// RtlCreateSystemVolumeInformationFolder 
 
int __fastcall RtlCreateSystemVolumeInformationFolder(unsigned __int16 *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r6
  unsigned int v4; // r1
  int v5; // r5
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  unsigned int v9; // r0
  unsigned int v10; // r5
  int v12; // [sp+20h] [bp-58h] BYREF
  unsigned int v13; // [sp+24h] [bp-54h] BYREF
  int v14[2]; // [sp+28h] [bp-50h] BYREF
  __int16 v15[2]; // [sp+30h] [bp-48h] BYREF
  int v16; // [sp+34h] [bp-44h]
  char v17[8]; // [sp+38h] [bp-40h] BYREF
  int v18[14]; // [sp+40h] [bp-38h] BYREF

  RtlInitUnicodeString((unsigned int)v14, L"System Volume Information");
  v2 = *a1;
  v3 = LOWORD(v14[0]);
  v4 = (unsigned __int16)(LOWORD(v14[0]) + v2);
  v15[0] = LOWORD(v14[0]) + v2;
  if ( v4 < v2 || v4 < LOWORD(v14[0]) )
    return -1073741811;
  if ( *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (v2 >> 1) - 2) == 92 )
  {
    v5 = 0;
  }
  else
  {
    LOWORD(v4) = v4 + 2;
    v15[0] = v4;
    v5 = 1;
  }
  v15[1] = v4 + 2;
  v6 = RtlpSysVolAllocate();
  v16 = v6;
  if ( !v6 )
    return -1073741670;
  memmove(v6, *((_DWORD *)a1 + 1), *a1);
  v8 = *a1;
  v15[0] = *a1;
  if ( v5 )
  {
    *(_WORD *)(v16 + 2 * (v8 >> 1)) = 92;
    v8 = (unsigned __int16)(v15[0] + 2);
    v15[0] += 2;
  }
  memmove(v8 + v16, v14[1], v3);
  v15[0] += v3;
  *(_WORD *)(v16 + 2 * ((unsigned __int16)v15[0] >> 1)) = 0;
  v7 = RtlpSysVolCreateSecurityDescriptor(v14, &v13);
  if ( v7 >= 0 )
  {
    v18[0] = 24;
    v18[1] = 0;
    v18[3] = 576;
    v18[2] = (int)v15;
    v18[5] = 0;
    v10 = v14[0];
    v18[4] = v14[0];
    if ( NtCreateFile((int)&v12, 0x10000, (int)v18, (int)v17, 0, 0, 7, 1, 4192, 0, 0) >= 0 )
      NtClose();
    v7 = NtCreateFile((int)&v12, 1966080, (int)v18, (int)v17, 0, 6, 7, 3, 33, 0, 0);
    if ( v7 < 0 )
    {
      RtlpSysVolTakeOwnership(v15);
      v7 = NtCreateFile((int)&v12, 1966080, (int)v18, (int)v17, 0, 6, 7, 3, 33, 0, 0);
    }
    RtlpSysVolFree(v16);
    if ( v7 >= 0 )
    {
      RtlpSysVolFree(v10);
      v7 = RtlpSysVolCheckOwnerAndSecurity(v12, v13);
      NtClose();
      v9 = v13;
    }
    else
    {
      RtlpSysVolFree(v13);
      v9 = v10;
    }
  }
  else
  {
    v9 = v16;
  }
  RtlpSysVolFree(v9);
  return v7;
}
