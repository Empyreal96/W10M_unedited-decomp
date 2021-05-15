// FstubVerifyPartitionTableEFI 
 
int __fastcall FstubVerifyPartitionTableEFI(int *a1, int a2)
{
  int v4; // r4
  int v5; // r7
  _DWORD *v6; // r6
  int v7; // r4
  __int64 v8; // r0
  int v9; // r0
  _DWORD *v10; // r8
  unsigned int v11; // r0
  unsigned int v12; // r0
  __int64 v13; // kr10_8
  unsigned int v14; // r7
  int v15; // r1
  int v16; // r0
  int v17; // r3
  __int64 v18; // kr20_8
  __int64 v19; // r8
  _DWORD *v21; // [sp+28h] [bp-30h] BYREF
  int v22; // [sp+2Ch] [bp-2Ch]
  __int64 v23; // [sp+30h] [bp-28h]

  v21 = 0;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)ExAllocatePoolWithTag(512, 92, 1114927942);
  if ( v6 )
  {
    if ( FstubReadHeaderEFI(a1, 1i64, &v21) >= 0 && FstubReadTableEFI(a1, v21, 0) >= 0 )
    {
      v4 = 1;
      memmove((int)v6, (int)v21, 0x5Cu);
    }
    HIDWORD(v8) = a1[13];
    LODWORD(v8) = -1;
    v9 = FstubReadHeaderEFI(a1, ((unsigned int)a1[12] | 0xFFFFFFFF00000000ui64) + v8, &v21);
    v10 = v21;
    if ( v9 >= 0 && FstubReadTableEFI(a1, v21, 0) >= 0 )
    {
      v5 = 1;
      if ( v4 )
      {
LABEL_12:
        v7 = 0;
LABEL_27:
        ExFreePoolWithTag((unsigned int)v6);
        return v7;
      }
      memmove((int)v6, (int)v10, 0x5Cu);
    }
    if ( v4 )
    {
      if ( v5 )
        goto LABEL_12;
    }
    else if ( !v5 )
    {
LABEL_14:
      v7 = -1073741774;
      goto LABEL_27;
    }
    if ( a2 )
    {
      v11 = a1[1];
      if ( !v11 )
        __brkdiv0();
      v12 = (v11 + (v10[20] << 7) - 1) / v11;
      v13 = *((_QWORD *)a1 + 6);
      v14 = v12;
      if ( v4 )
      {
        v15 = 2;
        v16 = 0;
        LODWORD(v23) = v13 - v14 - 1;
        v17 = ((_DWORD)v13 != v14) + ((v13 - (unsigned __int64)v14) >> 32) - 1;
      }
      else
      {
        v18 = v13 - v12 - 1;
        v16 = HIDWORD(v18);
        v15 = v18;
        LODWORD(v23) = 2;
        v17 = 0;
      }
      v19 = 0i64;
      HIDWORD(v23) = v17;
      v21 = (_DWORD *)v15;
      v22 = v16;
      if ( v14 )
      {
        while ( 1 )
        {
          v7 = FstubReadSectors(*a1, a1[1], v19 + __PAIR64__(v16, v15), 1, a1[10]);
          if ( v7 < 0 )
            break;
          v7 = FstubWriteSector(*a1, a1[1], v19 + v23, (unsigned __int64)(v19 + v23) >> 32);
          if ( v7 < 0 )
            break;
          ++v19;
          if ( !HIDWORD(v19) )
          {
            v15 = (int)v21;
            v16 = v22;
            if ( (unsigned int)v19 < v14 )
              continue;
          }
          goto LABEL_26;
        }
      }
      else
      {
LABEL_26:
        v7 = ((int (__fastcall *)(int *, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))FstubWriteHeaderEFI)(
               a1,
               v14,
               v6[14],
               v6[15],
               v6[16],
               v6[17],
               v6[20]);
      }
      goto LABEL_27;
    }
    goto LABEL_14;
  }
  return -1073741670;
}
