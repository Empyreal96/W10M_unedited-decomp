// PiDevCfgConvertPropertyFromValue 
 
int __fastcall PiDevCfgConvertPropertyFromValue(unsigned int a1, int a2, char *a3, unsigned int a4, int *a5, char **a6)
{
  int v6; // r7
  int v7; // r6
  char *v8; // r4
  int v10; // r5
  char *v11; // r0
  int v12; // r5
  char *v13; // r0
  bool v14; // zf
  int v15; // r5
  char *v16; // r0
  int v17; // r5
  char *v18; // r0
  char v19; // r3
  int v21; // [sp+0h] [bp-18h] BYREF
  _DWORD *v22; // [sp+4h] [bp-14h]

  v21 = (int)a3;
  v22 = (_DWORD *)a4;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( a4 > 0x1003 )
  {
    if ( a4 != 8210 )
      goto LABEL_45;
    v14 = a1 == 7;
LABEL_41:
    if ( !v14 )
      goto LABEL_45;
    goto LABEL_43;
  }
  if ( a4 == 4099 )
  {
LABEL_43:
    v7 = a2;
LABEL_44:
    v8 = a3;
    goto LABEL_45;
  }
  switch ( a4 )
  {
    case 2u:
    case 3u:
      if ( a1 != 4 )
        break;
      v10 = *(_DWORD *)a3;
      if ( *(_DWORD *)a3 > 0xFFu )
        break;
      v7 = 1;
      v11 = (char *)ExAllocatePoolWithTag(1, 1, 1667526736);
      v8 = v11;
      if ( !v11 )
        return -1073741670;
      *v11 = v10;
      break;
    case 4u:
    case 5u:
      if ( a1 != 4 )
        break;
      v12 = *(_DWORD *)a3;
      if ( *(_DWORD *)a3 > 0xFFFFu )
        break;
      v7 = 2;
      v13 = (char *)ExAllocatePoolWithTag(1, 2, 1667526736);
      v8 = v13;
      if ( !v13 )
        return -1073741670;
      *(_WORD *)v13 = v12;
      break;
    case 6u:
    case 7u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
      v14 = a1 == 4;
      goto LABEL_41;
    case 8u:
    case 9u:
      if ( a1 != 4 )
      {
        v14 = a1 == 11;
        goto LABEL_41;
      }
      v15 = *(_DWORD *)a3;
      v7 = 8;
      v16 = (char *)ExAllocatePoolWithTag(1, 8, 1667526736);
      v8 = v16;
      if ( !v16 )
        return -1073741670;
      *(_DWORD *)v16 = v15;
      *((_DWORD *)v16 + 1) = 0;
      break;
    case 0xDu:
      if ( !a1 )
        break;
      if ( a1 <= 2 )
      {
        if ( a2 == 78 )
        {
          v7 = 16;
          v8 = (char *)ExAllocatePoolWithTag(1, 16, 1667526736);
          if ( !v8 )
            return -1073741670;
          v21 = 5111884;
          v22 = a3;
          if ( RtlGUIDFromString((unsigned __int16 *)&v21, v8) < 0 )
          {
            ExFreePoolWithTag((unsigned int)v8);
            v8 = 0;
          }
        }
      }
      else if ( a1 == 3 && a2 == 16 )
      {
        v7 = 16;
        goto LABEL_44;
      }
      break;
    case 0x10u:
      if ( a1 != 3 && a1 != 11 || a2 != 8 )
        break;
      v7 = 8;
      goto LABEL_44;
    case 0x11u:
      if ( a1 != 4 )
        break;
      v17 = *(_DWORD *)a3;
      v7 = 1;
      v18 = (char *)ExAllocatePoolWithTag(1, 1, 1667526736);
      v8 = v18;
      if ( !v18 )
        return -1073741670;
      v19 = -1;
      if ( !v17 )
        v19 = 0;
      *v18 = v19;
      break;
    case 0x12u:
    case 0x14u:
    case 0x19u:
      if ( a1 - 1 <= 1 )
        goto LABEL_43;
      break;
    case 0x13u:
      v14 = a1 == 3;
      goto LABEL_41;
    default:
      break;
  }
LABEL_45:
  *a5 = v7;
  *a6 = v8;
  return v6;
}
