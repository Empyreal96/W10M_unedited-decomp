// AdtpWriteToEtw 
 
int __fastcall AdtpWriteToEtw(int a1, _BYTE *a2)
{
  int v4; // r0
  int v5; // r1
  int v7; // r7
  int v8; // r4
  int v9; // r1
  unsigned int v10; // r2
  char v11; // r3
  unsigned int v12; // r5
  unsigned int v13; // r3
  unsigned int v14; // r2
  _OWORD *v15; // r3
  unsigned int v16; // r3
  unsigned __int16 v17[4]; // [sp+8h] [bp-368h] BYREF
  unsigned __int16 v18; // [sp+10h] [bp-360h] BYREF
  char v19; // [sp+12h] [bp-35Eh]
  char v20; // [sp+13h] [bp-35Dh]
  char v21; // [sp+14h] [bp-35Ch]
  char v22; // [sp+15h] [bp-35Bh]
  __int16 v23; // [sp+16h] [bp-35Ah]
  int v24; // [sp+18h] [bp-358h]
  unsigned int v25; // [sp+1Ch] [bp-354h]
  int v26; // [sp+20h] [bp-350h]
  int v27; // [sp+24h] [bp-34Ch]
  _DWORD v28[192]; // [sp+28h] [bp-348h] BYREF
  char v29; // [sp+328h] [bp-48h] BYREF
  char v30[47]; // [sp+329h] [bp-47h] BYREF

  v17[0] = 0;
  v29 = 0;
  memset(v30, 0, sizeof(v30));
  *a2 = 0;
  v4 = AdtpNormalizeAuditInfo(a1);
  if ( !*(_DWORD *)(a1 + 40) )
    return sub_815DA4(v4);
  if ( *(_WORD *)(a1 + 18) == 8 )
    v7 = 0x200000;
  else
    v7 = 0x100000;
  v8 = AdtpPackageParameters((_DWORD *)a1, v5, (int)v28, v17, (int)&v29);
  if ( v8 < 0 )
  {
    v12 = v17[0];
    goto LABEL_26;
  }
  if ( *(_WORD *)(a1 + 16) && AdtpGetCategoryAndSubCategoryId() >= 0 )
    v9 = (unsigned __int16)(v26 + (((_WORD)v27 + 48) << 8));
  else
    v9 = 65280;
  v10 = *(_DWORD *)(a1 + 4);
  if ( v10 > 0x12D0 )
  {
    if ( v10 > 0x154C )
    {
      if ( v10 == 5632 )
        goto LABEL_33;
      if ( v10 <= 0x187F )
        goto LABEL_32;
      if ( v10 <= 0x1881 )
        goto LABEL_18;
      v16 = 6275;
    }
    else
    {
      if ( v10 >= 0x154B || v10 == 5125 || v10 == 5140 )
        goto LABEL_33;
      if ( v10 <= 0x1423 )
        goto LABEL_32;
      v16 = 5157;
    }
    if ( v10 > v16 )
      goto LABEL_32;
LABEL_33:
    v11 = 1;
    goto LABEL_19;
  }
  if ( v10 == 4816 || v10 == 4616 )
    goto LABEL_33;
  if ( v10 != 4624 )
  {
    if ( v10 != 4654 && v10 != 4656 && v10 != 4661 && v10 != 4663 )
    {
      if ( v10 == 4688 )
        goto LABEL_18;
LABEL_32:
      v11 = 0;
      goto LABEL_19;
    }
    goto LABEL_33;
  }
LABEL_18:
  v11 = 2;
LABEL_19:
  v19 = v11;
  v20 = 10;
  v21 = 0;
  v22 = 0;
  v24 = 0;
  v12 = v17[0];
  v25 = v7 | 0x80000000;
  v18 = v10;
  v13 = 0;
  v14 = 0;
  v23 = v9;
  if ( !v17[0] )
  {
    v15 = 0;
LABEL_24:
    v8 = EtwWriteKMSecurityEvent(&v18, v9, v17[0], (int)v15);
    if ( v8 == -1073741058 )
      *a2 = 1;
    goto LABEL_26;
  }
  LOWORD(v9) = 0;
  do
  {
    v14 += v28[4 * v13 + 2];
    v13 = (unsigned __int16)(v9 + 1);
    v9 = v13;
  }
  while ( v13 < v17[0] );
  if ( v14 <= 0xDC00 )
  {
    v15 = v28;
    goto LABEL_24;
  }
  *a2 = 1;
  v8 = -2147483643;
LABEL_26:
  AdtpCleanupParameterAllocations((int)&v29, v28, v12);
  return v8;
}
