// EtwpTraceImageRundown 
 
int __fastcall EtwpTraceImageRundown(int result, int a2, unsigned __int16 *a3, int a4, _DWORD *a5, char a6, char a7)
{
  int v7; // r4
  int v8; // r5
  int v9; // r3
  int v10[5]; // [sp+8h] [bp-70h] BYREF
  char v11; // [sp+1Ch] [bp-5Ch]
  char v12; // [sp+1Dh] [bp-5Bh]
  __int16 v13; // [sp+1Eh] [bp-5Ah]
  int v14; // [sp+20h] [bp-58h]
  int v15; // [sp+24h] [bp-54h]
  int v16; // [sp+28h] [bp-50h]
  int v17; // [sp+2Ch] [bp-4Ch]
  int v18; // [sp+30h] [bp-48h]
  int v19[16]; // [sp+38h] [bp-40h] BYREF

  if ( a3 )
  {
    v7 = *a3;
    if ( *a3 )
    {
      v8 = *((_DWORD *)a3 + 1);
      if ( v8 )
      {
        v10[2] = a4;
        v9 = a5[1];
        v19[4] = v8;
        v19[6] = v7;
        v10[0] = v9;
        v10[1] = a5[3];
        v10[3] = a5[5];
        v10[4] = 0;
        v11 = a6;
        v12 = a7;
        v14 = a5[2];
        v13 = 0;
        v15 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19[0] = (int)v10;
        v19[1] = 0;
        v19[2] = 44;
        v19[3] = 0;
        v19[5] = 0;
        v19[7] = 0;
        v19[8] = (int)&EtwpNull;
        v19[9] = 0;
        v19[10] = 2;
        v19[11] = 0;
        result = EtwpLogKernelEvent(v19, result, 3, a2, 4200451);
      }
    }
  }
  return result;
}
