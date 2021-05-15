// DrvDbSetDeviceIdMappedProperty 
 
int __fastcall DrvDbSetDeviceIdMappedProperty(int **a1, int a2, int a3, unsigned int a4, int (*a5)[6], unsigned __int16 *a6, int a7)
{
  int v7; // r4
  int v8; // r5
  int v11; // r4
  int v12; // r10
  int v13; // r4
  int (**v14)[6]; // r9
  unsigned int v15; // r0
  int (*v16)[6]; // t1
  int v17; // r0
  unsigned __int16 *v19; // r2
  int v20; // r0
  int v21; // [sp+10h] [bp-28h] BYREF
  int v22; // [sp+14h] [bp-24h]
  int **v23; // [sp+18h] [bp-20h]

  v7 = *(_DWORD *)(a4 + 16);
  v8 = 0;
  v22 = a2;
  v23 = a1;
  v21 = 0;
  if ( v7 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceId_DriverInfNames, 16) )
    return -1073741790;
  v12 = *(_DWORD *)(a4 + 16);
  v13 = 0;
  v14 = &off_41E264;
  while ( 1 )
  {
    v16 = *v14;
    v14 += 6;
    v15 = (unsigned int)v16;
    if ( (*v16)[4] == v12 )
    {
      v17 = memcmp(v15, a4, 16);
      if ( !v17 )
        break;
    }
    if ( ++v13 )
      return -1073741802;
  }
  if ( !&(&off_41E264)[6 * v13] )
    return -1073741802;
  if ( a5 != *(&(&off_41E264)[6 * v13] + 1) && a5 )
    return -1073741811;
  if ( a3 || (v17 = DrvDbOpenObjectRegKey(v23, 0, 5, v22, 3, 0, (int)&v21, 0), v11 = v17, v8 = v21, v17 >= 0) )
  {
    if ( *(_DWORD *)(a4 + 16) != 3 || (v17 = memcmp(a4, (unsigned int)DEVPKEY_DeviceId_DriverInfMatches, 16)) != 0 )
    {
      if ( !a3 )
        a3 = v8;
      v20 = DrvDbSetRegValueMappedProperty(v17, a3);
    }
    else
    {
      if ( a5 == (int (*)[6])8210 )
      {
        v19 = a6;
        if ( !a6 || !a7 )
        {
LABEL_21:
          v11 = -1073741811;
          goto LABEL_32;
        }
      }
      else
      {
        if ( a5 )
          goto LABEL_21;
        v19 = a6;
        if ( a6 || a7 )
          goto LABEL_21;
      }
      if ( !a3 )
        a3 = v8;
      v20 = DrvDbSetDeviceIdDriverInfMatches(0, a3, v19);
    }
    v8 = v21;
    v11 = v20;
  }
LABEL_32:
  if ( v8 )
    ZwClose();
  return v11;
}
