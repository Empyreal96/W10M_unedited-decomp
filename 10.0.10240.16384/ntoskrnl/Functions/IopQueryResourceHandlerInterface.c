// IopQueryResourceHandlerInterface 
 
int __fastcall IopQueryResourceHandlerInterface(int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  int v8; // r7
  _BYTE *v9; // r0
  unsigned int v10; // r5
  int v11; // r4
  int *v13; // r5
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int v18[10]; // [sp+8h] [bp-58h] BYREF
  int v19; // [sp+30h] [bp-30h] BYREF
  int v20; // [sp+34h] [bp-2Ch]
  int v21; // [sp+38h] [bp-28h]
  int v22; // [sp+3Ch] [bp-24h]

  if ( *(_DWORD *)(*(_DWORD *)(a2[44] + 20) + 292) == a2[2] || (a2[7] & 0x1000) == 0 )
    return -1073741637;
  if ( a1 == 1 )
  {
    v8 = 28;
    v19 = 1813334674;
    v20 = 298887887;
    v21 = -1610601843;
    v22 = 1152517833;
  }
  else
  {
    if ( a1 == 2 )
    {
      v13 = (int *)&GUID_ARBITER_INTERFACE_STANDARD;
      v8 = 24;
    }
    else
    {
      if ( a1 != 3 )
        return -1073741811;
      v13 = (int *)&GUID_LEGACY_DEVICE_DETECTION_STANDARD;
      v8 = 20;
    }
    v14 = v13[1];
    v15 = v13[2];
    v16 = v13[3];
    v19 = *v13;
    v20 = v14;
    v21 = v15;
    v22 = v16;
  }
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, v8, 538996816);
  v10 = (unsigned int)v9;
  if ( !v9 )
    return -1073741670;
  memset(v9, 0, v8);
  *(_WORD *)v10 = v8;
  memset(v18, 0, sizeof(v18));
  LOWORD(v18[0]) = 2075;
  *(_WORD *)(v10 + 2) = 0;
  v18[2] = (int)&v19;
  v18[3] = (unsigned __int16)v8;
  v18[4] = v10;
  v18[5] = a3;
  v11 = IopSynchronousCall((int)a2, (int)v18, -1073741637, 0, 0);
  if ( v11 < 0 )
    goto LABEL_7;
  if ( a1 == 1 )
  {
    if ( !*(_DWORD *)(v10 + 16) )
    {
LABEL_25:
      v11 = -1073741823;
LABEL_17:
      if ( v11 >= 0 )
      {
        *a4 = v10;
        return v11;
      }
LABEL_7:
      ExFreePoolWithTag(v10);
      return v11;
    }
    v17 = *(_DWORD *)(v10 + 20);
LABEL_16:
    if ( v17 )
      goto LABEL_17;
    goto LABEL_25;
  }
  if ( a1 == 2 )
  {
    v17 = *(_DWORD *)(v10 + 16);
    goto LABEL_16;
  }
  return sub_80E0C4();
}
