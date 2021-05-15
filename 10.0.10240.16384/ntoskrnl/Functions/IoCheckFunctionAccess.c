// IoCheckFunctionAccess 
 
int __fastcall IoCheckFunctionAccess(int a1, int a2, int a3, int a4, int *a5, int *a6)
{
  int v6; // r4
  bool v8; // zf
  bool v9; // zf
  int v10; // r2
  int *v11; // r3
  int v12; // r3
  int v13; // r2
  int *v14; // r3
  int v15; // r3
  int v17[4]; // [sp+0h] [bp-10h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v6 = 0;
  switch ( a2 )
  {
    case 0:
    case 2:
      return v6;
    case 3:
    case 12:
      v8 = (a1 & 1) != 0;
      goto LABEL_3;
    case 4:
      v9 = (a1 & 6) == 0;
      goto LABEL_6;
    case 5:
      v10 = *a5;
      v11 = IopQueryOperationAccess;
      goto LABEL_10;
    case 6:
      v10 = *a5;
      v11 = IopSetOperationAccess;
LABEL_10:
      v12 = v11[v10];
      if ( v12 )
        goto LABEL_11;
      return v6;
    case 7:
      v8 = (~a1 & 8) == 0;
      goto LABEL_3;
    case 8:
      v8 = (~a1 & 0x10) == 0;
      goto LABEL_3;
    case 9:
      v8 = (~a1 & 2) == 0;
      goto LABEL_3;
    case 10:
      v13 = *a6;
      v14 = IopQueryFsOperationAccess;
      goto LABEL_17;
    case 11:
      v13 = *a6;
      v14 = IopSetFsOperationAccess;
LABEL_17:
      v12 = v14[v13];
      goto LABEL_11;
    case 13:
    case 14:
    case 15:
      v15 = (unsigned __int16)a4 >> 14;
      if ( !v15 )
        return v6;
      v9 = (v15 & a1) == 0;
LABEL_6:
      if ( !v9 )
        return v6;
      goto LABEL_4;
    case 17:
      v9 = (a1 & 3) == 0;
      goto LABEL_6;
    case 20:
      SeQuerySecurityAccessMask(*a5, v17);
      goto LABEL_23;
    case 21:
      SeSetSecurityAccessMask(*a5, v17);
LABEL_23:
      v12 = v17[0];
LABEL_11:
      v8 = (v12 & ~a1) == 0;
LABEL_3:
      if ( !v8 )
LABEL_4:
        v6 = -1073741790;
      break;
    default:
      v6 = -1073741808;
      break;
  }
  return v6;
}
