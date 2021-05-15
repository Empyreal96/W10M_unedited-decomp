// _CmGetDeviceSiblings 
 
int __fastcall CmGetDeviceSiblings(int a1, unsigned __int16 *a2, _WORD *a3, int *a4)
{
  int v4; // r6
  int v8; // r3
  int v9; // r4
  unsigned __int16 *v10; // r5
  int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r3
  unsigned int v15; // [sp+0h] [bp-1B8h] BYREF
  int v16; // [sp+4h] [bp-1B4h]
  unsigned __int16 v17[216]; // [sp+8h] [bp-1B0h] BYREF

  v4 = (int)a3;
  if ( a3 )
  {
    if ( *a4 )
      *a3 = 0;
    else
      v4 = 0;
  }
  else
  {
    *a4 = 0;
  }
  v8 = *a4;
  *a4 = 0;
  v16 = v8;
  v15 = 200;
  v9 = CmGetDeviceParent(a1, a2, v17, &v15);
  if ( v9 >= 0 )
  {
    v10 = 0;
    v15 = 0;
    while ( 1 )
    {
      v11 = CmGetDeviceChildren(a1, v17, v10, &v15);
      v9 = v11;
      if ( !v11 )
        break;
      if ( v11 != -1073741789 )
        goto LABEL_14;
      if ( v10 )
        ExFreePoolWithTag((unsigned int)v10);
      v10 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v15, 1380994640);
      if ( !v10 )
      {
        v9 = -1073741801;
LABEL_14:
        if ( v9 < 0 )
          goto LABEL_24;
        break;
      }
    }
    if ( !v10 )
      return -1073741275;
    if ( PnpMultiSzDeleteString(v10, a2) )
    {
      v12 = PnpMultiSzGetLen(v10);
      if ( v12 > 1 )
      {
        v13 = v16;
        *a4 = v12;
        if ( v13 >= v12 )
          memmove(v4, (int)v10, 2 * v12);
        else
          v9 = -1073741789;
      }
      else
      {
        v9 = -1073741275;
      }
    }
    else
    {
      v9 = -1073741595;
    }
LABEL_24:
    if ( v10 )
      ExFreePoolWithTag((unsigned int)v10);
  }
  return v9;
}
