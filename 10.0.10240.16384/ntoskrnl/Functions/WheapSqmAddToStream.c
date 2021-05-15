// WheapSqmAddToStream 
 
_BYTE *__fastcall WheapSqmAddToStream(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  unsigned int v5; // r6
  _BYTE *result; // r0
  int *v7; // r4
  int v8; // r7
  int *v9; // r3
  unsigned __int16 *v10; // r0
  unsigned int v11; // r0
  const __int16 *v12; // r3
  int v13; // [sp+8h] [bp-218h] BYREF
  int *v14; // [sp+10h] [bp-210h]
  int v15; // [sp+14h] [bp-20Ch]
  int var208[131]; // [sp+18h] [bp-208h] BYREF
  int varg_r0; // [sp+228h] [bp+8h] BYREF
  int varg_r1[3]; // [sp+22Ch] [bp+Ch] BYREF

  varg_r0 = a1;
  varg_r1[1] = a3;
  varg_r1[2] = a4;
  v4 = (int *)a3;
  v5 = a2;
  varg_r1[0] = a2;
  v14 = 0;
  v15 = 0;
  result = memset(var208, 0, 488);
  v13 = 11;
  if ( v4 && v5 < 9 )
  {
    v14 = &v13;
    v15 = 0;
    var208[0] = 4;
    var208[1] = 0;
    var208[2] = (int)dword_41D4AC;
    var208[3] = 0;
    var208[4] = 16;
    var208[5] = 0;
    var208[6] = (int)&varg_r0;
    var208[7] = 0;
    var208[8] = 4;
    var208[9] = 0;
    var208[10] = (int)varg_r1;
    var208[11] = 0;
    var208[12] = 4;
    var208[13] = 0;
    if ( v5 )
    {
      v7 = &var208[14];
      do
      {
        v8 = *v4;
        *v7 = (int)v4;
        v7[1] = 0;
        v7[2] = 4;
        v7[3] = 0;
        if ( v8 == 1 )
          v9 = v4 + 1;
        else
          v9 = &dword_41D4A8;
        v7[4] = (int)v9;
        v7[5] = 0;
        v7[6] = 4;
        v7[7] = 0;
        if ( v8 == 2 )
          v10 = (unsigned __int16 *)v4[1];
        else
          v10 = L"0";
        v11 = wcslen(v10);
        if ( v8 == 2 )
          v12 = (const __int16 *)v4[1];
        else
          v12 = L"0";
        v7[8] = (int)v12;
        v7[9] = 0;
        v7[10] = 2 * (v11 + 1);
        v7[11] = 0;
        v7 += 12;
        v4 += 2;
        --v5;
      }
      while ( v5 );
    }
    result = (_BYTE *)EtwWrite(WheapEtwHandle, unk_6197CC, (int)WHEA_SQM_EVENT_ADDTOSTREAM, 0);
  }
  return result;
}
