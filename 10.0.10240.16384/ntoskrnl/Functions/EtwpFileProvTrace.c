// EtwpFileProvTrace 
 
int __fastcall EtwpFileProvTrace(int result, int a2, int a3, int a4)
{
  int v4; // r5
  int v7; // r10
  int *v8; // r4
  __int64 v9; // kr00_8

  v4 = 0;
  v7 = result;
  switch ( a3 )
  {
    case 1088:
      v8 = KFileEvt_Create;
      goto LABEL_21;
    case 1089:
      v8 = KFileEvt_Cleanup;
      goto LABEL_21;
    case 1090:
      v8 = KFileEvt_Close;
      goto LABEL_21;
    case 1091:
      v8 = KFileEvt_Read;
      v4 = 1;
      goto LABEL_21;
    case 1092:
      v8 = KFileEvt_Write;
      v4 = 1;
      goto LABEL_21;
    case 1093:
      v8 = KFileEvt_SetInformation;
      goto LABEL_21;
    case 1094:
      v8 = KFileEvt_Delete;
      goto LABEL_21;
    case 1095:
      v8 = KFileEvt_Rename;
      goto LABEL_21;
    case 1096:
      v8 = KFileEvt_DirEnum;
      goto LABEL_21;
    case 1097:
      v8 = KFileEvt_Flush;
      goto LABEL_21;
    case 1098:
      v8 = KFileEvt_QueryInformation;
      goto LABEL_21;
    case 1099:
      v8 = KFileEvt_FSCTL;
      goto LABEL_21;
    case 1100:
      v8 = KFileEvt_OperationEnd;
      v4 = 1;
      goto LABEL_21;
    case 1101:
      v8 = KFileEvt_DirNotify;
      goto LABEL_21;
    case 1102:
      v8 = KFileEvt_CreateNewFile;
      goto LABEL_21;
    case 1103:
      v8 = KFileEvt_DeletePath;
      goto LABEL_21;
    case 1104:
      v8 = KFileEvt_RenamePath;
      goto LABEL_21;
    case 1105:
      v8 = KFileEvt_SetLinkPath;
      goto LABEL_21;
    case 1106:
      v8 = KFileEvt_SetLink;
LABEL_21:
      v9 = *(_QWORD *)&EtwpFileProvRegHandle;
      result = EtwEventEnabled(EtwpFileProvRegHandle, unk_61A92C, (int)v8);
      if ( result )
        result = EtwWriteEx(v9, SHIDWORD(v9), (int)v8, 0, 0, 0, v4, a4, 0, a2, v7);
      break;
    default:
      return result;
  }
  return result;
}
