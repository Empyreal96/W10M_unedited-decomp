// EtwpTraceIo 
 
int __fastcall EtwpTraceIo(int a1, int a2, _DWORD *a3)
{
  _DWORD *v4; // r4
  int v5; // r7
  int v6; // r3
  int v7; // r8
  int v8; // r6
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int result; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  _DWORD *v19; // r3
  _DWORD v20[4]; // [sp+8h] [bp-80h] BYREF
  _DWORD v21[12]; // [sp+18h] [bp-70h] BYREF
  _DWORD v22[6]; // [sp+48h] [bp-40h] BYREF
  _DWORD *v23; // [sp+60h] [bp-28h] BYREF
  int v24; // [sp+64h] [bp-24h]
  int v25; // [sp+68h] [bp-20h]
  int v26; // [sp+6Ch] [bp-1Ch]

  v4 = (_DWORD *)a3[24];
  v5 = a3[20];
  v6 = *(unsigned __int8 *)v4;
  if ( v6 != 9 )
  {
    if ( v6 == 3 )
      v7 = 266;
    else
      v7 = 267;
    v8 = a3[2];
    v9 = a3[7];
    v21[0] = a2;
    v21[1] = v8;
    v21[7] = a3;
    v21[2] = v9;
    v21[4] = v4[4];
    v21[5] = v4[5];
    v21[8] = v4[2];
    v10 = v4[3];
    v21[3] = 0;
    v21[9] = v10;
    if ( v5 )
      v11 = *(_DWORD *)(v5 + 880);
    else
      v11 = -1;
    v21[10] = v11;
    if ( (a1 & 0xFFFF0000) == 1448280064 )
      return sub_546F44();
    if ( (a1 & 0xFFFFFF) == 5467492 || (a1 & 0xFFFFFF) == 5460546 )
      JUMPOUT(0x546F46);
    if ( (v8 & 8) != 0 )
    {
      v16 = a3[3];
      if ( !v16 )
        goto LABEL_17;
      v13 = *(_DWORD *)(v16 + 100);
    }
    else
    {
      v13 = a3[25];
    }
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 12);
LABEL_14:
      v21[6] = v14;
      v23 = v21;
      v24 = 0;
      v15 = 44;
      goto LABEL_15;
    }
LABEL_17:
    v14 = 0;
    goto LABEL_14;
  }
  v17 = a3[2];
  v22[0] = a2;
  v22[1] = v17;
  v7 = 270;
  v22[2] = v4[2];
  v22[3] = v4[3];
  v22[4] = a3;
  if ( v5 )
    v18 = *(_DWORD *)(v5 + 880);
  else
    v18 = -1;
  v22[5] = v18;
  v23 = v22;
  v24 = 0;
  v15 = 24;
LABEL_15:
  v25 = v15;
  v26 = 0;
  result = EtwTraceKernelEvent(&v23, 1, 256, v7, 4200451);
  if ( (dword_61AD40 & 0x100) != 0 )
  {
    v20[0] = 0;
    v20[1] = 0;
    v20[2] = 0;
    v20[3] = 0;
    if ( IoGetActivityIdIrp((int)a3, v20) )
      v19 = 0;
    else
      v19 = v20;
    result = EtwpDiskProvTraceDisk(v7, &v23, v5, v19);
  }
  return result;
}
