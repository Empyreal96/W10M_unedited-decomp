// PiDqIrpComplete 
 
int __fastcall PiDqIrpComplete(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r8
  _DWORD *v7; // r6
  int v8; // r3
  int v9; // r4
  int v10; // r5
  _DWORD *v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int varg_r1; // [sp+2Ch] [bp+Ch]
  _DWORD *varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v5 = a3;
  if ( a2 < 0 )
  {
    a1[7] = 0;
  }
  else
  {
    if ( *(_DWORD *)(a1[24] + 16) == 4653063 )
    {
      v7 = (_DWORD *)a1[15];
      v8 = a4[1];
      v9 = a4[2];
      v10 = a4[3];
      *v7 = *a4;
      v7[1] = v8;
      v7[2] = v9;
      v7[3] = v10;
    }
    else
    {
      v11 = (_DWORD *)a1[3];
      v12 = a4[1];
      v13 = a4[2];
      v14 = a4[3];
      *v11 = *a4;
      v11[1] = v12;
      v11[2] = v13;
      v11[3] = v14;
    }
    a1[7] = v5;
  }
  a1[6] = a2;
  return IofCompleteRequest((int)a1, 0);
}
