// DrvDbGetDeviceIdMappedProperty 
 
int __fastcall DrvDbGetDeviceIdMappedProperty(int a1, unsigned __int16 *a2, int a3, unsigned int a4, _DWORD *a5, int a6, unsigned int a7, unsigned int *a8)
{
  int v9; // r7
  int v10; // r5
  int v14; // r3
  _DWORD *v15; // r6
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r0
  int v19; // r2
  unsigned int v20; // r3
  int v21; // [sp+10h] [bp-38h] BYREF
  int v22; // [sp+14h] [bp-34h]
  int v23; // [sp+18h] [bp-30h]
  int v24; // [sp+1Ch] [bp-2Ch]
  int v25; // [sp+20h] [bp-28h]
  int v26; // [sp+24h] [bp-24h]
  _DWORD *v27; // [sp+28h] [bp-20h]

  v23 = 0;
  v24 = 0;
  v22 = 0;
  *a5 = 0;
  *a8 = 0;
  v9 = *(_DWORD *)(a4 + 16);
  v10 = 0;
  v25 = a1;
  v21 = 0;
  if ( v9 != 3 || memcmp(a4, (unsigned int)DEVPKEY_DeviceId_DriverInfMatches, 16) )
    return sub_7E2AA0();
  if ( memcmp(a4, (unsigned int)DEVPKEY_DeviceId_DriverInfMatches, 16) )
    JUMPOUT(0x7E2B20);
  v14 = *a2;
  v26 = 1;
  if ( v14 == 64 )
    JUMPOUT(0x7E2B26);
  if ( *(_DWORD *)(a1 + 24) )
    JUMPOUT(0x7E2B54);
  v15 = *(_DWORD **)(a1 + 12);
  v27 = (_DWORD *)(a1 + 12);
  if ( v15 == (_DWORD *)(a1 + 12) )
    goto LABEL_14;
  do
  {
    v16 = DrvDbOpenObjectRegKey(v25, v15, 5, a2, 1, 0, &v21, 0);
    v17 = v16;
    if ( v16 >= 0 )
    {
      v24 = 1;
      v17 = DrvDbGetDeviceIdDriverInfMatches(v16, v21);
      ZwClose();
      v10 = 0;
      v21 = 0;
      if ( v17 < 0 )
        JUMPOUT(0x7E2B3A);
      v19 = 2 * v22;
      if ( (unsigned int)(2 * v22) > 2 )
        v19 -= 2;
      v18 = a7;
      if ( a6 && v23 + v19 < a7 )
        v23 += v19;
      *a8 += v19;
    }
    else
    {
      v10 = v21;
      v18 = a7;
      if ( v17 != -1073741772 )
        break;
      v17 = 0;
    }
    v15 = (_DWORD *)*v15;
  }
  while ( v15 != v27 );
  if ( v17 < 0 && v17 != -1073741789 )
    goto LABEL_15;
  if ( v24 )
  {
    if ( *a8 )
    {
      *a5 = 8210;
      v20 = *a8 + 2;
      *a8 = v20;
      if ( a6 && v20 <= v18 )
      {
        *(_WORD *)(a6 + 2 * (v20 >> 1) - 2) = 0;
        v10 = v21;
      }
      else
      {
        v17 = -1073741789;
      }
    }
    else
    {
      v17 = -1073741275;
    }
  }
  else
  {
LABEL_14:
    v17 = -1073741772;
  }
LABEL_15:
  if ( v10 )
    ZwClose();
  return v17;
}
