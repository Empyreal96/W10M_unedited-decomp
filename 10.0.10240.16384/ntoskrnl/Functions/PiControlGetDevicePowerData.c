// PiControlGetDevicePowerData 
 
int __fastcall PiControlGetDevicePowerData(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int result; // r0
  int v9; // r0
  int v10; // r3
  int v11; // r0
  int i; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // [sp-4h] [bp-98h] BYREF
  int v17; // [sp+0h] [bp-94h]
  int v18[2]; // [sp+Ch] [bp-88h]
  int v19; // [sp+14h] [bp-80h]
  int v20; // [sp+18h] [bp-7Ch]
  int v21; // [sp+1Ch] [bp-78h]
  int v22; // [sp+20h] [bp-74h]
  int v23; // [sp+24h] [bp-70h]
  int v24; // [sp+28h] [bp-6Ch]
  int v25; // [sp+2Ch] [bp-68h]
  int v26; // [sp+30h] [bp-64h]
  int v27; // [sp+34h] [bp-60h]
  int v28; // [sp+38h] [bp-5Ch]
  int v29; // [sp+3Ch] [bp-58h] BYREF
  int v30; // [sp+40h] [bp-54h]
  int v31; // [sp+44h] [bp-50h]
  int v32; // [sp+48h] [bp-4Ch]
  int v33; // [sp+4Ch] [bp-48h]
  int v34; // [sp+50h] [bp-44h]
  int v35; // [sp+54h] [bp-40h]
  int v36; // [sp+58h] [bp-3Ch]
  int v37; // [sp+5Ch] [bp-38h]
  int v38; // [sp+60h] [bp-34h]
  int v39; // [sp+64h] [bp-30h]
  int v40; // [sp+68h] [bp-2Ch]
  int v41; // [sp+6Ch] [bp-28h]
  int v42; // [sp+70h] [bp-24h]

  v29 = 56;
  *a5 = 0;
  if ( a3 < 4 )
  {
LABEL_2:
    result = -2147483643;
    goto LABEL_57;
  }
  if ( PpIrpQueryCapabilities(*(_DWORD *)(a1 + 16), (int)&v16) < 0 )
    return -1073741810;
  if ( PipIsDevNodeDNStarted(a1) )
  {
    v9 = PopLockGetDoDevicePowerState(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 176));
    if ( !v9 )
      v9 = 1;
    v30 = v9;
  }
  else
  {
    v30 = 4;
  }
  v10 = 9;
  v31 = 9;
  if ( (v17 & 1) != 0 )
  {
    v10 = 11;
    v31 = 11;
  }
  if ( (v17 & 2) != 0 )
  {
    v10 |= 4u;
    v31 = v10;
  }
  if ( (v17 & 0x400) != 0 )
  {
    v10 |= 0x10u;
    v31 = v10;
  }
  if ( (v17 & 0x800) != 0 )
  {
    v10 |= 0x20u;
    v31 = v10;
  }
  if ( (v17 & 0x1000) != 0 )
  {
    v10 |= 0x40u;
    v31 = v10;
  }
  if ( (v17 & 0x2000) != 0 )
  {
    v10 |= 0x80u;
    v31 = v10;
  }
  if ( (v17 & 0x10000) != 0 )
    v31 = v10 | 0x100;
  v35 = v18[0];
  v36 = v18[1];
  v37 = v19;
  v38 = v20;
  v39 = v21;
  v40 = v22;
  v41 = v23;
  v11 = 2;
  i = v24;
  v13 = v31;
  v32 = v26;
  v33 = v27;
  v34 = v28;
  v14 = v25;
  do
  {
    switch ( v14 )
    {
      case 1:
        v13 |= 0x10u;
        break;
      case 2:
        v13 |= 0x22u;
        break;
      case 3:
        v13 |= 0x44u;
        break;
      case 4:
        v13 |= 0x80u;
        break;
      default:
        goto LABEL_34;
    }
    v31 = v13;
LABEL_34:
    if ( v24 )
      v14 = v18[v24];
    else
      v14 = 0;
    --v11;
  }
  while ( v11 );
  if ( (v13 & 0x80) != 0 )
  {
    v15 = 4;
  }
  else if ( (v13 & 0x40) != 0 )
  {
    v15 = 3;
  }
  else if ( (v13 & 0x20) != 0 )
  {
    v15 = 2;
  }
  else
  {
    v15 = (v13 & 0x10) != 0;
  }
  if ( !v24 && v15 )
  {
    for ( i = 4; i >= 1; --i )
    {
      if ( v19 && v19 <= v15 )
        break;
    }
  }
  v42 = i;
  if ( a3 < 0x38 )
  {
    if ( a4 )
      memmove(a4, (int)&v29, a3);
    goto LABEL_2;
  }
  if ( a4 )
    memmove(a4, (int)&v29, 0x38u);
  result = 0;
LABEL_57:
  *a5 = 56;
  return result;
}
