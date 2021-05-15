// SeSetAuditParameter 
 
int __fastcall SeSetAuditParameter(int a1, int a2, int a3, unsigned __int16 *a4)
{
  int result; // r0
  int v6; // r4
  _DWORD *v8; // r2
  int v9; // r4
  _DWORD *v10; // r2
  int v11; // r3

  result = 0;
  v6 = 0;
  if ( !a1 )
    return -1073741811;
  switch ( a2 )
  {
    case 0:
    case 6:
      v8 = (_DWORD *)(a1 + 20 * a3);
      v8[7] = 0;
      goto LABEL_4;
    case 1:
    case 2:
    case 34:
      v9 = *a4 + 8;
      v10 = (_DWORD *)(a1 + 20 * a3);
      v10[10] = a4;
      v10[6] = a2;
      v10[7] = v9;
      return result;
    case 3:
    case 10:
    case 21:
    case 27:
      v8 = (_DWORD *)(a1 + 20 * a3);
      v6 = 4;
      v8[8] = *(_DWORD *)a4;
      goto LABEL_4;
    case 4:
      v6 = 4 * (*((unsigned __int8 *)a4 + 1) + 2);
      v8 = (_DWORD *)(a1 + 20 * a3);
      v8[10] = a4;
      goto LABEL_4;
    case 5:
    case 12:
    case 14:
    case 15:
    case 18:
    case 22:
    case 26:
    case 35:
      v8 = (_DWORD *)(a1 + 20 * a3);
      v6 = 8;
      v8[8] = *(_DWORD *)a4;
      v8[9] = *((_DWORD *)a4 + 1);
      goto LABEL_4;
    case 7:
    case 9:
    case 16:
    case 17:
    case 19:
    case 20:
      return -1073741822;
    case 8:
      if ( a4 )
        JUMPOUT(0x520634);
      return sub_520630(0);
    case 11:
      v8 = (_DWORD *)(a1 + 20 * a3);
      v8[8] = a4;
      v6 = 4;
      goto LABEL_4;
    case 13:
      goto LABEL_14;
    case 23:
    case 28:
      v11 = *a4;
      if ( v11 == 23 )
      {
        v6 = 28;
      }
      else if ( v11 == 2 || v11 != 33 )
      {
LABEL_14:
        v6 = 16;
      }
      else
      {
        v6 = 14;
      }
      v8 = (_DWORD *)(a1 + 20 * a3);
      v8[10] = a4;
LABEL_4:
      v8[6] = a2;
      v8[7] = v6;
      break;
    default:
      return -1073741811;
  }
  return result;
}
