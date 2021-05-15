// FsRtlGetSectorSizeInformation 
 
int __fastcall FsRtlGetSectorSizeInformation(int a1, int a2)
{
  int result; // r0
  int v5; // r0
  int v6; // r8
  unsigned int v7; // r4
  unsigned int v8; // r6
  int v9; // r6
  unsigned int v10; // r4
  int v11; // r2
  int v12[2]; // [sp+10h] [bp-120h] BYREF
  __int64 v13[18]; // [sp+18h] [bp-118h] BYREF
  int v14; // [sp+A8h] [bp-88h] BYREF
  int v15; // [sp+ACh] [bp-84h]
  int v16; // [sp+B0h] [bp-80h]
  unsigned int v17; // [sp+B8h] [bp-78h] BYREF
  unsigned int v18; // [sp+BCh] [bp-74h]
  int v19; // [sp+C0h] [bp-70h]
  unsigned int v20; // [sp+C8h] [bp-68h] BYREF
  unsigned int v21; // [sp+CCh] [bp-64h]
  int v22; // [sp+D0h] [bp-60h]
  int v23[8]; // [sp+D8h] [bp-58h] BYREF
  char v24[20]; // [sp+F8h] [bp-38h] BYREF
  int v25; // [sp+10Ch] [bp-24h]

  memset((_BYTE *)a2, 0, 28);
  result = FsRtlIssueDeviceIoControl(a1, 458752, 2, 0, 0, v24, 24, 0);
  if ( result >= 0 )
  {
    if ( !v25 || ((v25 - 1) & v25) != 0 )
    {
      result = -1073741621;
    }
    else
    {
      v15 = 0;
      v16 = 0;
      v14 = 6;
      memset(v23, 0, 28);
      v23[0] = 2;
      v23[1] = 1;
      v5 = FsRtlIssueDeviceIoControl(a1, 2954240, 2, &v14, 12, v23, 28, v12);
      v6 = v25;
      if ( v5 < 0
        || v12[0] < 0x1Cu
        || v23[0] < 0x1Cu
        || v23[1] < (unsigned int)v12[0]
        || !v23[4]
        || v23[4] != v25
        || (v7 = v23[5], v23[5] < (unsigned int)v23[4])
        || !v23[5]
        || ((v23[5] - 1) & v23[5]) != 0
        || v23[5] % (unsigned int)v23[4]
        || (v8 = v23[6], v23[6] % (unsigned int)v23[4]) )
      {
        result = sub_7D5984();
      }
      else
      {
        *(_DWORD *)(a2 + 16) = 3;
        *(_DWORD *)(a2 + 20) = v8;
        *(_DWORD *)a2 = v6;
        *(_DWORD *)(a2 + 4) = v7;
        *(_DWORD *)(a2 + 8) = v7;
        *(_DWORD *)(a2 + 12) = v6;
        *(_DWORD *)(a2 + 24) = -1;
        if ( v8 != -1 )
        {
          *(_DWORD *)(a2 + 20) = v8;
          if ( !v7 )
            __brkdiv0();
          v9 = v8 % v7;
          if ( v9 )
            *(_DWORD *)(a2 + 16) = 2;
          memset(v13, 0, sizeof(v13));
          if ( FsRtlIssueDeviceIoControl(a1, 458824, 2, 0, 0, v13, 144, 0) >= 0 )
          {
            v10 = v23[5];
            if ( !v23[5] )
              __brkdiv0();
            _rt_sdiv64((unsigned int)v23[5], v13[1]);
            *(_DWORD *)(a2 + 24) = v11;
            if ( !v10 )
              __brkdiv0();
            if ( (v10 - v11) % v10 != v9 )
              *(_DWORD *)(a2 + 16) &= 0xFFFFFFFD;
          }
        }
        v15 = 0;
        v16 = 0;
        v14 = 7;
        v20 = 0;
        v21 = 0;
        v22 = 0;
        if ( FsRtlIssueDeviceIoControl(a1, 2954240, 2, &v14, 12, &v20, 12, v12) >= 0
          && v12[0] >= 0xCu
          && v20 >= 0xC
          && v21 >= v12[0]
          && !(_BYTE)v22 )
        {
          *(_DWORD *)(a2 + 16) |= 4u;
        }
        v15 = 0;
        v16 = 0;
        v14 = 8;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        if ( FsRtlIssueDeviceIoControl(a1, 2954240, 2, &v14, 12, &v17, 12, v12) >= 0
          && v12[0] >= 0xCu
          && v17 >= 0xC
          && v18 >= v12[0] )
        {
          if ( (_BYTE)v19 )
            *(_DWORD *)(a2 + 16) |= 8u;
        }
        result = 0;
      }
    }
  }
  return result;
}
