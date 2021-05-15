// NtLockProductActivationKeys 
 
int __fastcall NtLockProductActivationKeys(int *a1, _DWORD *a2)
{
  int v3; // r1
  unsigned __int16 *v4; // r0
  int v5; // r6
  __int16 v6; // t1
  int v7; // r4
  int i; // r1
  unsigned int *v9; // r0
  unsigned int v10; // r6
  unsigned int v11; // lr
  unsigned int v12; // r8
  int v13; // r10
  int *v14; // r2
  int v15; // r3
  _DWORD *v16; // r2
  int v17; // r3
  int v18; // r10
  int j; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r5
  char v25[4]; // [sp+Ch] [bp-8ACh] BYREF
  int v26; // [sp+10h] [bp-8A8h]
  int v27; // [sp+18h] [bp-8A0h]
  int v28; // [sp+1Ch] [bp-89Ch]
  _BYTE *v29; // [sp+20h] [bp-898h]
  int v30; // [sp+24h] [bp-894h]
  int v31; // [sp+28h] [bp-890h]
  int v32; // [sp+2Ch] [bp-88Ch]
  int v33; // [sp+30h] [bp-888h]
  int v34; // [sp+34h] [bp-884h]
  _BYTE *v35; // [sp+38h] [bp-880h]
  int v36; // [sp+3Ch] [bp-87Ch]
  int v37; // [sp+40h] [bp-878h]
  int v38; // [sp+44h] [bp-874h]
  _BYTE v39[8]; // [sp+48h] [bp-870h] BYREF
  _BYTE v40[8]; // [sp+50h] [bp-868h] BYREF
  unsigned __int16 v41[38]; // [sp+58h] [bp-860h] BYREF
  unsigned int v42; // [sp+A4h] [bp-814h]
  char v43[1008]; // [sp+A8h] [bp-810h] BYREF
  unsigned __int16 v44[528]; // [sp+498h] [bp-420h] BYREF

  v26 = 0;
  memmove((int)v41, (int)dword_40C3E0, 0x3Cu);
  LOWORD(v3) = -21647;
  v4 = v41;
  v5 = 30;
  do
  {
    v6 = *v4++;
    v3 = (unsigned __int16)((v3 + v6) ^ v6);
    --v5;
  }
  while ( v5 );
  if ( v3 != 47439 )
    return -1073741823;
  for ( i = 52; i >= 0; --i )
  {
    v9 = (unsigned int *)((char *)v41 + i);
    v10 = *(_DWORD *)((char *)v41 + i);
    v11 = *(_DWORD *)((char *)&v41[2] + i);
    v12 = -957401312;
    v13 = 32;
    do
    {
      --v13;
      v11 -= (abWPAStringKey[(v12 >> 11) & 3] + v12) ^ (((16 * v10) ^ (v10 >> 5)) + v10);
      v12 += 1640531527;
      v10 -= (abWPAStringKey[v12 & 3] + v12) ^ (((16 * v11) ^ (v11 >> 5)) + v11);
    }
    while ( v13 );
    *v9 = v10;
    v9[1] = v11;
  }
  RtlInitUnicodeString((unsigned int)v40, v41);
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( a1 )
    {
      v14 = a1;
      if ( (unsigned int)a1 >= MmUserProbeAddress )
        v14 = (int *)MmUserProbeAddress;
      *v14 = *v14;
      if ( (unsigned int)*a1 >= 0x2BEA )
        v15 = 26624;
      else
        v15 = 0;
      *a1 = v15;
    }
    if ( a2 )
    {
      v16 = a2;
      if ( (unsigned int)a2 >= MmUserProbeAddress )
        v16 = (_DWORD *)MmUserProbeAddress;
      *v16 = *v16;
      *a2 = InitSafeBootMode;
    }
  }
  else
  {
    if ( a1 )
    {
      if ( (unsigned int)*a1 >= 0x2BEA )
        v17 = 26624;
      else
        v17 = 0;
      *a1 = v17;
    }
    if ( a2 )
      *a2 = InitSafeBootMode;
  }
  v33 = 24;
  v34 = 0;
  v36 = 576;
  v35 = v40;
  v37 = 0;
  v38 = 0;
  v7 = ZwOpenKey();
  if ( v7 >= 0 )
  {
    v18 = 0;
    for ( j = ZwEnumerateKey(); ; j = ZwEnumerateKey() )
    {
      v22 = j;
      if ( j == -2147483622 )
        break;
      if ( j < 0 )
      {
        v7 = j;
        break;
      }
      if ( v42 + 64 <= 0x400 )
      {
        wcscpy_s((char *)v44, 512, (char *)v41);
        wcsncat_s((char *)v44, 512, v43, v42 >> 1);
        wcscat_s(v44, 512, (char *)L"\\");
        RtlInitUnicodeString((unsigned int)v39, v44);
        v27 = 24;
        v28 = 0;
        v30 = 576;
        v29 = v39;
        v31 = 0;
        v32 = 0;
        v20 = ZwOpenKey();
        if ( v20 < 0 )
        {
          v7 = v20;
        }
        else
        {
          v21 = IsRegistryKeyLocked(a2, v25);
          if ( v21 < 0 )
            goto LABEL_39;
          if ( !v25[0] )
            v21 = ZwLockRegistryKey();
          if ( v21 < 0 )
LABEL_39:
            v7 = v21;
          ZwClose();
        }
        ++v18;
      }
      else
      {
        v7 = -1073741801;
      }
    }
    ZwClose();
    if ( v22 == -2147483622 )
      v7 = 0;
  }
  return v7;
}
