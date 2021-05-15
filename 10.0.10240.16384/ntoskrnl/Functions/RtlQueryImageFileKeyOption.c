// RtlQueryImageFileKeyOption 
 
int __fastcall RtlQueryImageFileKeyOption(int a1, unsigned __int16 *a2, int a3, int *a4, unsigned int a5, unsigned int *a6)
{
  int v8; // r4
  char *v9; // r6
  int v10; // r0
  unsigned int v12; // r4
  int v13; // r10
  int v14; // r3
  unsigned int v15; // r5
  unsigned int v16; // r2
  int v17; // [sp+8h] [bp-50h]
  unsigned __int16 v18[2]; // [sp+10h] [bp-48h] BYREF
  char *v19; // [sp+14h] [bp-44h]
  unsigned int *v20; // [sp+18h] [bp-40h]
  int v21; // [sp+1Ch] [bp-3Ch]
  char v22; // [sp+20h] [bp-38h] BYREF

  v20 = a6;
  v21 = a1;
  v8 = RtlInitUnicodeStringEx((int)v18, a2);
  if ( v8 < 0 )
    return v8;
  if ( a5 >= 8 )
  {
    v12 = a5 + 12;
  }
  else
  {
    v9 = &v22;
    v10 = ZwQueryValueKey();
    v8 = v10;
    if ( v10 >= 0 )
    {
      v13 = 0;
      goto LABEL_10;
    }
    if ( v10 != -2147483643 )
      return v8;
    v12 = v17;
  }
  v13 = ExAllocatePoolWithQuotaTag(0x208u, v12, 1799976018);
  if ( !v13 )
    return -1073741801;
  v9 = (char *)v13;
  v8 = ZwQueryValueKey();
  if ( v8 >= 0 )
  {
LABEL_10:
    v14 = *((_DWORD *)v9 + 1);
    switch ( v14 )
    {
      case 3:
      case 7:
        if ( a3 == v14 )
        {
          v15 = *((_DWORD *)v9 + 2);
          if ( !a4 )
            goto LABEL_26;
          v16 = *((_DWORD *)v9 + 2);
          if ( v16 > a5 )
            goto LABEL_26;
          goto LABEL_47;
        }
        break;
      case 4:
        if ( a3 == 4 )
        {
          if ( a5 == 4 && *((_DWORD *)v9 + 2) == 4 )
          {
            v15 = 4;
            if ( a4 )
            {
              *a4 = *((_DWORD *)v9 + 3);
              goto LABEL_19;
            }
            goto LABEL_26;
          }
          goto LABEL_24;
        }
        break;
      case 11:
        if ( a3 == 11 )
        {
          if ( a5 == 8 && *((_DWORD *)v9 + 2) == 8 )
          {
            v15 = 8;
            if ( a4 )
            {
              *a4 = *((_DWORD *)v9 + 3);
              a4[1] = *((_DWORD *)v9 + 4);
LABEL_19:
              if ( v20 && (v8 >= 0 || v8 == -2147483643) )
                *v20 = v15;
              goto LABEL_20;
            }
LABEL_26:
            v8 = -2147483643;
            goto LABEL_19;
          }
          goto LABEL_24;
        }
        break;
      case 1:
        if ( a3 == 4 )
        {
          if ( a5 == 4 )
          {
            if ( ((unsigned __int8)a4 & 3) != 0 )
            {
              v8 = -2147483646;
LABEL_20:
              if ( v13 )
                ExFreePoolWithTag(v13);
              return v8;
            }
            v15 = 4;
            v17 = 4;
            if ( !a4 )
              goto LABEL_26;
            v19 = v9 + 12;
            v18[0] = *((_DWORD *)v9 + 2);
            v18[1] = *((_DWORD *)v9 + 2);
            v8 = RtlUnicodeStringToInteger(v18, 0, a4);
LABEL_35:
            v15 = v17;
            goto LABEL_19;
          }
LABEL_24:
          v8 = -1073741820;
          goto LABEL_20;
        }
        v15 = *((_DWORD *)v9 + 2);
        if ( v15 > a5 )
          goto LABEL_26;
        v16 = *((_DWORD *)v9 + 2);
LABEL_47:
        memmove((int)a4, (int)(v9 + 12), v16);
        goto LABEL_19;
      default:
        v8 = -1073741788;
        goto LABEL_35;
    }
    v8 = -1073741788;
    goto LABEL_20;
  }
  return sub_7EAB40();
}
