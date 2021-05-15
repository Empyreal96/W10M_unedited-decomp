// CmpParseInfBuffer 
 
int __fastcall CmpParseInfBuffer(int a1, int a2, int *a3)
{
  int v3; // r5
  int v4; // r9
  _DWORD *v5; // r0
  unsigned int v6; // r7
  int result; // r0
  unsigned int v8; // r10
  int v9; // r4
  int v10; // r6
  int v11; // r8
  int v12; // r5
  unsigned int v13; // [sp+0h] [bp-40h]
  int v14; // [sp+4h] [bp-3Ch]
  int v16; // [sp+Ch] [bp-34h] BYREF
  int *v17; // [sp+10h] [bp-30h]
  int v18; // [sp+14h] [bp-2Ch]
  int v19; // [sp+18h] [bp-28h] BYREF
  __int16 *v20; // [sp+1Ch] [bp-24h]
  unsigned __int8 v21; // [sp+20h] [bp-20h]

  v17 = a3;
  v3 = a1;
  v18 = a1;
  v4 = 0;
  v5 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1768967491);
  v6 = (unsigned int)v5;
  if ( !v5 )
    return sub_96BEC4();
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v13 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v14 = 1;
  v11 = 1;
  v16 = v3;
  while ( 2 )
  {
    CmpGetToken(&v16, v3 + a2, &v19);
    v12 = v19;
    switch ( v11 )
    {
      case 1:
        switch ( v19 )
        {
          case 1:
            goto LABEL_12;
          case 2:
            goto LABEL_38;
          case 0:
            goto LABEL_44;
        }
        goto LABEL_46;
      case 2:
        if ( v19 == 3 )
        {
          v20 = &EmptyValue;
          v21 = 0;
          v4 = 0;
LABEL_43:
          v11 = 4;
        }
        else
        {
          if ( v19 != 4 )
            goto LABEL_46;
          v4 = v21;
          v11 = 3;
          v13 = (unsigned int)v20;
        }
        goto LABEL_12;
      case 3:
        if ( v19 == 3 )
          goto LABEL_43;
        goto LABEL_46;
      case 4:
        if ( v19 )
        {
          if ( v19 == 1 && CmpAppendSection(v6, v13, v4) )
          {
            v13 = 0;
            goto LABEL_28;
          }
          goto LABEL_46;
        }
        if ( !CmpAppendSection(v6, v13, v4) )
          goto LABEL_46;
        v13 = 0;
        goto LABEL_44;
      case 5:
        switch ( v19 )
        {
          case 1:
            goto LABEL_12;
          case 2:
LABEL_38:
            v11 = 2;
            goto LABEL_12;
          case 0:
            goto LABEL_44;
          case 4:
            v8 = (unsigned int)v20;
            v4 = v21;
            v11 = 6;
            goto LABEL_12;
        }
        goto LABEL_46;
      case 6:
        if ( v19 == 5 )
        {
          if ( !CmpAppendLine(v6, v8, v4) )
            goto LABEL_46;
          v8 = 0;
          v11 = 8;
        }
        else if ( v19 )
        {
          if ( v19 == 1 )
          {
            if ( !CmpAppendLine(v6, 0, 0) || !CmpAppendValue(v6, v8) )
              goto LABEL_45;
            v8 = 0;
LABEL_28:
            v11 = 5;
          }
          else
          {
            if ( v19 != 6 )
            {
LABEL_46:
              v9 = 1;
              v10 = 1;
              goto LABEL_69;
            }
            if ( !CmpAppendLine(v6, 0, 0) || !CmpAppendValue(v6, v8) )
              goto LABEL_45;
            v8 = 0;
LABEL_8:
            v11 = 7;
          }
        }
        else
        {
          if ( !CmpAppendLine(v6, 0, 0) || !CmpAppendValue(v6, v8) )
          {
LABEL_45:
            v9 = 1;
            v10 = 1;
            goto LABEL_12;
          }
          v8 = 0;
LABEL_44:
          v9 = 1;
        }
LABEL_12:
        if ( !v10 )
        {
          if ( v12 == 1 )
            ++v14;
          goto LABEL_15;
        }
LABEL_69:
        *v17 = v14;
        if ( v13 && v4 )
          ExFreePoolWithTag(v13);
        if ( v8 && v4 )
          ExFreePoolWithTag(v8);
        ExFreePoolWithTag(v6);
        v6 = 0;
LABEL_15:
        v3 = v18;
        if ( !v9 )
          continue;
        if ( v6 )
          *(_DWORD *)(v6 + 4) = 0;
        result = v6;
        break;
      case 7:
        if ( v19 == 4 )
          goto LABEL_10;
        if ( v19 != 6 )
          goto LABEL_46;
        v20 = &EmptyValue;
        v21 = 0;
        v4 = 0;
        if ( !CmpAppendValue(v6, &EmptyValue) )
          goto LABEL_45;
        goto LABEL_12;
      case 8:
        if ( !v19 )
        {
          v20 = &EmptyValue;
          v21 = 0;
          v4 = 0;
          if ( !CmpAppendValue(v6, &EmptyValue) )
            v10 = 1;
          goto LABEL_44;
        }
        if ( v19 != 1 )
        {
          if ( v19 != 4 )
            goto LABEL_46;
LABEL_10:
          if ( !CmpAppendValue(v6, v20) )
            goto LABEL_46;
          v11 = 9;
          goto LABEL_12;
        }
        v20 = &EmptyValue;
        v21 = 0;
        v4 = 0;
        if ( CmpAppendValue(v6, &EmptyValue) )
          goto LABEL_28;
        v10 = 1;
        v9 = 1;
        goto LABEL_69;
      case 9:
      case 10:
        switch ( v19 )
        {
          case 1:
            goto LABEL_28;
          case 0:
            goto LABEL_44;
          case 6:
            goto LABEL_8;
        }
        goto LABEL_46;
      default:
        goto LABEL_45;
    }
    return result;
  }
}
