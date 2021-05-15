// ArbQueryConflict 
 
int __fastcall ArbQueryConflict(int a1, int a2)
{
  int v4; // r7
  int v5; // r6
  unsigned int v6; // r9
  unsigned int v7; // r10
  __int64 v8; // kr08_8
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r10
  unsigned int v12; // r9
  int v13; // r0
  _DWORD *v14; // r2
  _DWORD *v16; // r3
  _DWORD *v17; // [sp+8h] [bp-E0h] BYREF
  unsigned __int64 v18; // [sp+Ch] [bp-DCh]
  int v19; // [sp+14h] [bp-D4h]
  int v20[14]; // [sp+18h] [bp-D0h] BYREF
  unsigned int v21; // [sp+50h] [bp-98h] BYREF
  unsigned int v22; // [sp+54h] [bp-94h]
  int v23[14]; // [sp+58h] [bp-90h] BYREF
  int v24; // [sp+90h] [bp-58h] BYREF
  int v25; // [sp+94h] [bp-54h]
  int v26; // [sp+98h] [bp-50h]
  int v27; // [sp+9Ch] [bp-4Ch]

  v19 = 10;
  v4 = 0;
  v5 = 0;
  memset(v20, 0, sizeof(v20));
  v6 = *(_DWORD *)(a1 + 164);
  v7 = *(_DWORD *)(a1 + 160);
  v8 = *(_QWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 164) = ArbpQueryConflictCallback;
  *(_DWORD *)(a1 + 160) = &v17;
  v18 = __PAIR64__(v6, v7);
  v9 = RtlCopyRangeList((_DWORD *)HIDWORD(v8), (_DWORD *)v8);
  if ( v9 >= 0 )
  {
    v9 = ArbpBuildAlternative(a1, *(_DWORD *)(a2 + 4), (int)&v24);
    if ( v9 >= 0 )
    {
      memset(v20, 0, sizeof(v20));
      v20[2] = v26;
      v20[3] = v27;
      v20[6] = v26;
      v20[7] = v27;
      v20[9] = (int)&v24;
      v20[10] = 1;
      v20[11] = (int)&v24;
      LOWORD(v20[12]) = 4;
      v20[0] = v24;
      v20[1] = v25;
      v20[4] = v24;
      v20[5] = v25;
      v20[8] = (int)v23;
      memset(v23, 0, sizeof(v23));
      v23[4] = *(_DWORD *)a2;
      v23[5] = 4;
      if ( IoGetDeviceProperty(v23[4], 13, 4u, &v23[8], &v21) < 0 )
        v23[8] = 1;
      if ( IoGetDeviceProperty(*(_DWORD *)a2, 14, 4u, &v23[10], &v21) < 0 )
        v23[10] = 0;
      v5 = ExAllocatePoolWithTag(1, 240, 1130525249);
      if ( v5 )
      {
        v9 = (*(int (__fastcall **)(int, int *))(a1 + 112))(a1, v20);
        if ( v9 >= 0 )
        {
          RtlDeleteOwnersRanges(*(int ***)(a1 + 24), *(_DWORD *)(v20[8] + 16));
          v10 = 0;
          v11 = 240;
          while ( 1 )
          {
            v17 = 0;
            v20[4] = v20[0];
            v20[5] = v20[1];
            v20[6] = v20[2];
            v20[7] = v20[3];
            if ( (*(int (__fastcall **)(int, int *))(a1 + 124))(a1, v20) )
              break;
            if ( v4 == v19 )
            {
              v11 += 120;
              v12 = v5;
              v19 += 5;
              v13 = ExAllocatePoolWithTag(1, v11, 1130525249);
              v5 = v13;
              if ( !v13 )
              {
                v9 = -1073741670;
                v5 = v12;
LABEL_19:
                v6 = HIDWORD(v18);
                v7 = v18;
                goto LABEL_20;
              }
              memmove(v13, v12, v10);
              ExFreePoolWithTag(v12);
            }
            if ( !v17 )
            {
              v16 = (_DWORD *)(v5 + 24 * v4);
              *v16 = 0;
              v16[2] = 0;
              v16[3] = 0;
              v16[4] = -1;
              v16[5] = -1;
              ++v4;
              break;
            }
            v14 = (_DWORD *)(v10 + v5);
            ++v4;
            *(_DWORD *)(v10 + v5) = v17[5];
            v22 = v10 + 24;
            v14[2] = *v17;
            v14[3] = v17[1];
            v14[4] = v17[2];
            v14[5] = v17[3];
            v9 = RtlDeleteOwnersRanges(*(int ***)(a1 + 24), v17[5]);
            if ( v9 < 0 )
              goto LABEL_19;
            v10 = v22;
          }
          RtlFreeRangeList(*(_DWORD **)(a1 + 24));
          v6 = HIDWORD(v18);
          v7 = v18;
          v9 = 0;
          *(_DWORD *)(a1 + 160) = v18;
          *(_DWORD *)(a1 + 164) = v6;
          **(_DWORD **)(a2 + 12) = v5;
          **(_DWORD **)(a2 + 8) = v4;
        }
      }
      else
      {
        v9 = -1073741670;
      }
    }
  }
LABEL_20:
  if ( (v20[12] & 0x10) != 0 )
  {
    ExFreePoolWithTag(v20[13]);
    LOWORD(v20[12]) &= 0xFFEFu;
  }
  if ( v9 < 0 )
  {
    if ( v5 )
      ExFreePoolWithTag(v5);
    RtlFreeRangeList(*(_DWORD **)(a1 + 24));
    *(_DWORD *)(a1 + 160) = v7;
    *(_DWORD *)(a1 + 164) = v6;
    **(_DWORD **)(a2 + 12) = 0;
  }
  return v9;
}
