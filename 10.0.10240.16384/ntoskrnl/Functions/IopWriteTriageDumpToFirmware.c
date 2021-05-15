// IopWriteTriageDumpToFirmware 
 
int __fastcall IopWriteTriageDumpToFirmware(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  _DWORD *v6; // r4
  unsigned int v7; // r6
  int v8; // r9
  int *v9; // r4
  unsigned int v10; // r5
  int v11; // r3
  int v12; // r2
  int v13; // r3
  unsigned int v14; // kr00_4
  int v15[2]; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+8h] [bp-20h] BYREF
  int v17; // [sp+Ch] [bp-1Ch]

  v15[0] = a1;
  v15[1] = a2;
  v16 = a3;
  v17 = a4;
  v4 = a1;
  if ( !a1 )
    return -1073741661;
  v15[0] = a1 + 4096;
  *(_DWORD *)(a1 + 4112) = 28;
  v6 = (_DWORD *)v15[0];
  *(_DWORD *)v15[0] = 236792178;
  v6[1] = 1254188463;
  v6[2] = -187784257;
  v6[3] = -29881173;
  *(_DWORD *)(v15[0] + 20) = 458752;
  v7 = 131100;
  *(_DWORD *)(v15[0] + 24) = 131100;
  v8 = v15[0];
  if ( (((v15[0] & 0xFFFu) + 135167) >> 12) + 1 > 0x100 )
    return -1073741670;
  v9 = (int *)a1;
  v10 = 0;
  do
  {
    if ( v7 < 0x1000 )
    {
      v11 = v7;
      goto LABEL_9;
    }
    do
    {
      v11 = 4096;
LABEL_9:
      *v9 = v11;
      v9[1] = 0;
      MmGetPhysicalAddress((int)&v16, v8, 0, v11);
      v12 = v9[1];
      v9[2] = v16;
      v9[3] = v17;
      v13 = *v9;
      v14 = v7 - *v9;
      v10 = (__PAIR64__(v10, v7) - __PAIR64__(v12, *v9)) >> 32;
      v7 = v14;
      v9 += 4;
      v8 += v13;
    }
    while ( v10 );
  }
  while ( v14 );
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  MmGetPhysicalAddress((int)&v16, v4, v12, 0);
  return off_617ACC(v15, 1, v16, v17);
}
