// PerfLogImageLoad 
 
int *__fastcall PerfLogImageLoad(int *result, int a2, int *a3)
{
  int *v3; // r4
  int v4; // r2
  _DWORD *v5; // r0
  int v6[3]; // [sp+10h] [bp-70h] BYREF
  int v7; // [sp+1Ch] [bp-64h]
  int v8; // [sp+20h] [bp-60h]
  char v9; // [sp+24h] [bp-5Ch]
  char v10[3]; // [sp+25h] [bp-5Bh]
  int v11; // [sp+28h] [bp-58h]
  int v12; // [sp+2Ch] [bp-54h]
  int v13; // [sp+30h] [bp-50h]
  int v14; // [sp+34h] [bp-4Ch]
  int v15; // [sp+38h] [bp-48h]
  int v16[16]; // [sp+40h] [bp-40h] BYREF

  v3 = result;
  if ( result && *(_WORD *)result && result[1] )
  {
    v6[0] = a3[1];
    v6[1] = a3[3];
    v6[2] = a2;
    *(_WORD *)&v10[1] = 0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v7 = 0;
    v8 = 0;
    v11 = 0;
    v4 = *a3;
    v9 = (unsigned __int16)v4 >> 12;
    *(_WORD *)v10 = BYTE2(v4) & 7;
    v5 = (_DWORD *)RtlImageNtHeader(v6[0]);
    if ( v5 )
    {
      v7 = v5[22];
      v8 = v5[2];
      v11 = v5[13];
    }
    if ( (dword_61AD40 & 4) != 0 )
      EtwpPsProvTraceImage(v3, v6, 5121, 0);
    v16[0] = (int)v6;
    v16[1] = 0;
    v16[2] = 44;
    v16[3] = 0;
    v16[4] = v3[1];
    v16[5] = 0;
    v16[6] = *(unsigned __int16 *)v3;
    v16[7] = 0;
    v16[8] = (int)&EtwpNull;
    v16[9] = 0;
    v16[10] = 2;
    v16[11] = 0;
    result = EtwTraceKernelEvent(v16, 3, 4u, 778, 5249283);
  }
  return result;
}
