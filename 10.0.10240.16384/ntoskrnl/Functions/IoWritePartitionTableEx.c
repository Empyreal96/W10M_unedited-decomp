// IoWritePartitionTableEx 
 
int __fastcall IoWritePartitionTableEx(int a1, _DWORD *a2)
{
  int v3; // r4
  unsigned int v4; // r5
  int *v5; // r7
  unsigned int v6; // r8
  unsigned int v7; // r0
  int v8; // r0
  __int64 v9; // kr00_8
  int v10; // r0
  unsigned int v12[8]; // [sp+28h] [bp-20h] BYREF

  v12[0] = 0;
  v3 = FstubAllocateDiskInformation(a1, v12);
  if ( v3 < 0 )
    return v3;
  v4 = v12[0];
  if ( !*a2 )
  {
    v10 = FstubWritePartitionTableMBR(v12[0], a2);
LABEL_14:
    v3 = v10;
    goto LABEL_15;
  }
  if ( *a2 != 1 )
  {
    v3 = -1073741637;
    goto LABEL_15;
  }
  v12[0] = 0;
  if ( FstubReadHeaderEFI((int *)v4, 1i64, v12) >= 0
    || (v3 = FstubReadHeaderEFI((int *)v4, *(_QWORD *)(v4 + 48) - 1i64, v12), v3 >= 0) )
  {
    v5 = (int *)v12[0];
    v6 = *(_DWORD *)(v12[0] + 80);
    if ( a2[1] > v6 )
    {
      v3 = -1073741811;
      goto LABEL_15;
    }
    v7 = *(_DWORD *)(v4 + 4);
    if ( !v7 )
      __brkdiv0();
    v8 = (v6 << 7) / v7;
    *(_QWORD *)(v12[0] + 40) = (unsigned int)v8 + 2i64;
    v9 = *(_QWORD *)(v4 + 48) - (unsigned int)v8 - 2i64;
    *((_QWORD *)v5 + 6) = v9;
    v3 = FstubWritePartitionTableEFI(
           (_DWORD *)v4,
           a2[2],
           a2[3],
           a2[4],
           a2[5],
           v6,
           v5[10],
           v5[11],
           v5[12],
           SHIDWORD(v9),
           0,
           a2[1],
           (int)(a2 + 12));
    if ( v3 < 0 )
      goto LABEL_15;
    v10 = FstubWritePartitionTableEFI(
            (_DWORD *)v4,
            a2[2],
            a2[3],
            a2[4],
            a2[5],
            v6,
            v5[10],
            v5[11],
            v5[12],
            v5[13],
            1,
            a2[1],
            (int)(a2 + 12));
    goto LABEL_14;
  }
LABEL_15:
  if ( v4 )
    FstubFreeDiskInformation(v4);
  return v3;
}
