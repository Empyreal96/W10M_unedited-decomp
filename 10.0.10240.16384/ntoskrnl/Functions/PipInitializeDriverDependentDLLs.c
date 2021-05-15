// PipInitializeDriverDependentDLLs 
 
int __fastcall PipInitializeDriverDependentDLLs(int result, int a2)
{
  int v2; // r4
  int v3; // r8
  int v4; // r9
  _DWORD *v5; // r5
  int v6; // r7
  int i; // r2
  _DWORD *v8; // r6
  int v9; // r3
  int v10; // r3
  bool v11; // zf
  int v12; // r3
  int v13; // [sp+0h] [bp-68h] BYREF
  int v14[24]; // [sp+8h] [bp-60h] BYREF

  v2 = result;
  if ( !result )
  {
    v3 = 0;
    goto LABEL_3;
  }
  v3 = 1;
  if ( result != 1 )
  {
LABEL_3:
    v4 = 1;
    goto LABEL_4;
  }
  v4 = 0;
LABEL_4:
  v5 = *(_DWORD **)(a2 + 16);
  v6 = a2 + 16;
  if ( v5 != (_DWORD *)(a2 + 16) )
  {
    for ( i = 1; ; i = 1 )
    {
      v8 = v5;
      v9 = v5[13];
      v5 = (_DWORD *)*v5;
      if ( (v9 & 0x4000000) == 0 )
        goto LABEL_7;
      v10 = v8[34];
      if ( !v2 )
        break;
      if ( v2 == 1 )
      {
        v11 = (v8[34] & 2) == 0;
        goto LABEL_12;
      }
      if ( v2 == 2 && (v10 & 3) == 0 )
      {
LABEL_16:
        if ( v3 )
        {
          v13 = 0;
          memset(v14, 0, 64);
          v14[0] = 0;
          v14[2] = v8[9];
          v14[3] = v8[10];
          v14[1] = v8[33] & 1;
          v14[12] = v8[29];
          v14[14] = v8[31];
          v14[10] = v8[27];
          v14[13] = v8[30];
          v14[15] = v8[32];
          v12 = v8[28];
          v14[5] = (int)&dword_97E66C;
          v14[11] = v12;
          v14[4] = 0x20000;
          v14[8] = v8[25];
          v14[9] = v8[26];
          v14[6] = v8[23];
          v14[7] = v8[24];
          PnpNotifyEarlyLaunchImageLoad(v14, &v13);
          result = PnpDoPolicyCheck(v13, v4);
        }
        else
        {
          result = 1;
        }
        if ( result )
          result = MmCallDllInitialize((int)v8, v6, i, v10);
      }
LABEL_7:
      if ( v5 == (_DWORD *)v6 )
        return result;
    }
    v11 = (v8[34] & 1) == 0;
LABEL_12:
    if ( !v11 )
      goto LABEL_16;
    goto LABEL_7;
  }
  return result;
}
