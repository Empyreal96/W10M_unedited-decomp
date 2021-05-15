// WmipIoControl 
 
int __fastcall WmipIoControl(int a1, _DWORD *a2)
{
  _DWORD *v2; // r3
  unsigned int *v3; // r6
  unsigned int v5; // r5
  unsigned int v6; // r8
  unsigned int v7; // r7
  int v8; // r0
  int v9; // r4
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // [sp+18h] [bp-A8h] BYREF
  int v15; // [sp+1Ch] [bp-A4h] BYREF
  unsigned int v16; // [sp+20h] [bp-A0h] BYREF
  char v17[8]; // [sp+28h] [bp-98h] BYREF
  char v18[24]; // [sp+30h] [bp-90h] BYREF
  char v19[120]; // [sp+48h] [bp-78h] BYREF

  v2 = (_DWORD *)a2[24];
  v3 = (unsigned int *)a2[3];
  v6 = v2[3];
  v5 = v2[2];
  v7 = v2[4];
  v14 = v5;
  if ( v7 > 0x224158 )
  {
    if ( v7 <= 0x22811C )
      JUMPOUT(0x7D60F0);
    switch ( v7 )
    {
      case 0x22812Cu:
        if ( v5 >= 0x38 && v3 + 1 <= (unsigned int *)((char *)v3 + v6) )
        {
          v13 = *v3;
          if ( *v3 )
          {
            if ( v13 < 0x1000 && &v3[2 * v13 + 2] <= (unsigned int *)((char *)v3 + v6) )
            {
              v8 = WmipQueryAllDataMultiple(0, 0, a2, 1, v3, v5, v3, &v14);
              goto LABEL_10;
            }
          }
        }
        break;
      case 0x228130u:
        if ( v5 >= 0x38 && v3 + 1 <= (unsigned int *)((char *)v3 + v6) )
        {
          v12 = *v3;
          if ( *v3 )
          {
            if ( v12 < 0x1000 && &v3[6 * v12 + 2] <= (unsigned int *)((char *)v3 + v6) )
            {
              v8 = WmipQuerySingleMultiple(a2, 1, v3, v5, v3, v12, 0, 0, &v14);
LABEL_10:
              v5 = v14;
              v9 = v8;
              goto LABEL_11;
            }
          }
        }
        break;
      case 0x228144u:
        if ( v6 < 0x10 || v5 < 0x38 || *v3 > (v6 - 8) >> 3 )
        {
          v9 = -1073741808;
          goto LABEL_11;
        }
        v8 = WmipReceiveNotifications(v3, (int *)&v14, (int)a2);
        goto LABEL_10;
      default:
LABEL_57:
        JUMPOUT(0x7D619E);
    }
    v9 = -1073741811;
    goto LABEL_11;
  }
  if ( v7 == 2244952 )
    JUMPOUT(0x7D60DC);
  if ( v7 > 0x224134 )
  {
    if ( v7 == 2244920 )
      JUMPOUT(0x7D60C8);
    if ( v7 == 2244924 || v7 == 2244928 )
    {
      v9 = WmipProbeWmiOpenGuidBlock(v18, v17, v19, &v14, v3, v6, v5);
      if ( v9 >= 0 )
      {
        v9 = WmipOpenBlock(v7, 1, v18, v14, &v15);
        if ( v9 >= 0 )
        {
          v9 = ObOpenObjectByPointer(v15, 0, 0, v14, WmipGuidObjectType, 1, &v16);
          if ( v9 >= 0 )
            v3[2] = v16;
          ObfDereferenceObject(v15);
        }
      }
LABEL_11:
      if ( v9 == 259 || v9 == -1073741536 )
        return v9;
LABEL_14:
      a2[6] = v9;
      if ( v9 < 0 )
        v5 = 0;
      a2[7] = v5;
      IofCompleteRequest((int)a2, 0);
      return v9;
    }
    goto LABEL_57;
  }
  switch ( v7 )
  {
    case 0x224134u:
      JUMPOUT(0x7D6174);
    case 0x224000u:
      if ( v5 >= 0x48 )
      {
        if ( v6 < 0x30 || (v11 = v3[11], (v11 & 1) == 0) || v6 != *v3 || (v11 & 0xFFFFFF7E) != 0 )
        {
          v9 = -1073741823;
          goto LABEL_14;
        }
        v8 = WmipQueryAllData(0, a2, 1, v3, v5, &v14);
        goto LABEL_10;
      }
LABEL_40:
      v9 = -1073741789;
      goto LABEL_14;
    case 0x224004u:
      if ( v5 >= 0x38 )
      {
        v9 = WmipProbeWnodeSingleInstance(v3, v6, v5, 1);
        if ( v9 < 0 )
          goto LABEL_11;
        v14 = v6;
        v8 = WmipQuerySetExecuteSI(0, a2, 1, 1, v3, v5, &v14);
        goto LABEL_10;
      }
      goto LABEL_40;
  }
  return sub_7D60A8();
}
