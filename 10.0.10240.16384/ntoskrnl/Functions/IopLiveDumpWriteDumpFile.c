// IopLiveDumpWriteDumpFile 
 
int __fastcall IopLiveDumpWriteDumpFile(_DWORD *a1)
{
  int v1; // r10
  int v2; // r9
  unsigned int v4; // r8
  unsigned int v5; // r6
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r5
  int v9; // r6
  __int64 v11; // [sp+0h] [bp-30h] BYREF
  char v12[40]; // [sp+8h] [bp-28h] BYREF

  v1 = a1[57];
  v2 = a1[10];
  v11 = *(_QWORD *)(v1 + 4128);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = 0;
  if ( a1[74] )
  {
    while ( 1 )
    {
      v6 = a1[11];
      if ( v6 && *(_DWORD *)(v6 + 4) )
      {
        v8 = -1073741536;
        goto LABEL_12;
      }
      if ( (*(_DWORD *)(v4 + 960) & 1) != 0 )
        break;
      if ( v5 >= a1[74] - 1 )
        v7 = a1[72] << 12;
      else
        v7 = 0x40000;
      v8 = IopLiveDumpWriteBuffer(v2, *(_DWORD *)(a1[76] + 4 * v5), v7, &v11);
      if ( v8 < 0 )
        goto LABEL_12;
      ExFreePoolWithTag(*(_DWORD *)(a1[76] + 4 * v5));
      *(_DWORD *)(a1[76] + 4 * v5++) = 0;
      if ( v5 >= a1[74] )
        goto LABEL_10;
    }
    v8 = -1073741749;
  }
  else
  {
LABEL_10:
    v9 = RtlNumberOfSetBits(a1 + 55);
    v8 = IopLiveDumpWriteSecondaryData(v2, a1 + 7, &v11, v12);
    if ( v8 >= 0 )
    {
      *(_QWORD *)(v1 + 4000) = v11;
      *(_DWORD *)(v1 + 2208) |= 0x10u;
      *(_DWORD *)(v1 + 4136) = v9;
      *(_DWORD *)(v1 + 4096) = 1347241043;
      *(_DWORD *)(v1 + 4100) = 1347245380;
      *(_DWORD *)(v1 + 4140) = 0;
      v11 = 0i64;
      v8 = IopLiveDumpWriteBuffer(v2, v1, *(_DWORD *)(v1 + 4128), &v11);
    }
  }
LABEL_12:
  IopLiveDumpFreeDumpBuffers((unsigned int)(a1 + 68));
  return v8;
}
