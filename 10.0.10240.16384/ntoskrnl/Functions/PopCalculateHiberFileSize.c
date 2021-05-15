// PopCalculateHiberFileSize 
 
int __fastcall PopCalculateHiberFileSize(_QWORD *a1, _BYTE *a2)
{
  int v3; // r8
  unsigned int v4; // r0
  _DWORD *v5; // r7
  unsigned int v6; // r6
  unsigned int v7; // lr
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r3
  __int64 v12; // r0
  unsigned __int64 v15; // [sp+10h] [bp-38h] BYREF
  int v16; // [sp+18h] [bp-30h]
  int v17; // [sp+1Ch] [bp-2Ch]
  int v18; // [sp+20h] [bp-28h]
  int v19; // [sp+24h] [bp-24h]

  v3 = 2;
  v4 = MmGetNumberOfPhysicalPages(0);
  v5 = &PopHiberFileBucket;
  v6 = 100;
  if ( (unsigned int)PopHiberFileSizePercent >= 0x28 )
    v6 = PopHiberFileSizePercent;
  if ( (unsigned int)PopHiberFileSizePercent < 0x28 )
  {
    if ( (unsigned int)(PopHiberFileType - 1) <= 1 )
      v3 = (unsigned __int8)PopHiberFileType;
    v7 = 0;
    while ( 1 )
    {
      v8 = v5[1];
      v9 = v5[2];
      v10 = v5[3];
      LODWORD(v15) = *v5;
      HIDWORD(v15) = v8;
      v16 = v9;
      v17 = v10;
      v11 = v5[5];
      v18 = v5[4];
      v19 = v11;
      if ( __PAIR64__(v4 >> 20, v4 << 12) <= v15 )
        break;
      ++v7;
      v5 += 6;
      if ( v7 >= 7 )
        goto LABEL_12;
    }
    v6 = *((_DWORD *)&v15 + v3 + 2);
    if ( v6 >= 0x64 )
      v6 = 100;
  }
LABEL_12:
  LODWORD(v12) = _rt_udiv64(100i64, v6 * (unsigned __int64)v4);
  *a1 = v12 << 12;
  if ( a2 )
    *a2 = v3;
  return v12;
}
