// IopCallArbiter 
 
int __fastcall IopCallArbiter(int a1, int a2, int *a3)
{
  int v4; // r4
  int **v6; // r2
  int v7; // r1
  int result; // r0
  int v9; // [sp+0h] [bp-28h] BYREF
  int v10; // [sp+4h] [bp-24h]
  int *v11; // [sp+8h] [bp-20h] BYREF
  int v12; // [sp+Ch] [bp-1Ch]
  int v13; // [sp+10h] [bp-18h]
  int v14; // [sp+14h] [bp-14h]

  v4 = *(_DWORD *)(a1 + 12);
  switch ( a2 )
  {
    case 0:
      v6 = &v11;
      v12 = 0;
      v13 = 0;
      v11 = a3;
      v7 = 0;
      goto LABEL_4;
    case 1:
      v12 = 0;
      v13 = 0;
      v11 = a3;
      (*(void (__fastcall **)(_DWORD, int, int **))(v4 + 16))(*(_DWORD *)(v4 + 4), 1, &v11);
      goto LABEL_8;
    case 2:
    case 5:
      v6 = 0;
      goto LABEL_3;
    case 4:
      return -1073741822;
    case 6:
      v6 = &v11;
      v7 = 6;
      v11 = (int *)*a3;
      v12 = a3[1];
      v13 = a3[2];
      v14 = a3[3];
      goto LABEL_4;
    case 7:
      v9 = a3[6];
      v10 = a3[7];
      a3[7] = (int)&v9;
      a3[6] = (int)&v9;
      v11 = &v9;
      result = (*(int (__fastcall **)(_DWORD, int, int **))(v4 + 16))(*(_DWORD *)(v4 + 4), 7, &v11);
      a3[6] = v9;
      a3[7] = v10;
      return result;
    case 9:
LABEL_8:
      v11 = a3;
      v6 = &v11;
LABEL_3:
      v7 = a2;
LABEL_4:
      result = (*(int (__fastcall **)(_DWORD, int, int **))(v4 + 16))(*(_DWORD *)(v4 + 4), v7, v6);
      break;
    default:
      result = -1073741811;
      break;
  }
  return result;
}
