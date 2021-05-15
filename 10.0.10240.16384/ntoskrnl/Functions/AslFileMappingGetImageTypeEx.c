// AslFileMappingGetImageTypeEx 
 
int __fastcall AslFileMappingGetImageTypeEx(int a1, int a2, int *a3, int *a4, int a5)
{
  _WORD *v7; // lr
  int v8; // r5
  int v9; // r8
  int v10; // r1
  int v11; // r2
  int v12; // r4
  unsigned __int16 v13; // r3
  int v14; // r0
  int v15; // r0
  unsigned __int16 *v16; // r0
  int v20; // [sp+14h] [bp-34h] BYREF
  int v21; // [sp+18h] [bp-30h]
  int v22; // [sp+1Ch] [bp-2Ch]
  int v23; // [sp+20h] [bp-28h]
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int *varg_r2; // [sp+58h] [bp+10h]
  int *varg_r3; // [sp+5Ch] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v7 = (_WORD *)a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v20 = 0;
  v8 = 0;
  LOWORD(v9) = 0;
  v10 = 0;
  v21 = 0;
  v11 = 0;
  v22 = 0;
  if ( *(_DWORD *)(a5 + 552) == 1 )
  {
    v12 = -1073741701;
    v13 = 0;
LABEL_24:
    v16 = (unsigned __int16 *)a1;
    goto LABEL_25;
  }
  v12 = AslFileMappingEnsure(a5);
  if ( v12 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslFileMappingGetImageTypeEx", 892, "AslFileMappingEnsure failed [%x]", v12);
LABEL_5:
    v11 = 0;
    v10 = 0;
    v13 = 0;
LABEL_23:
    v7 = (_WORD *)a2;
    goto LABEL_24;
  }
  if ( *(_DWORD *)(a5 + 552) != 6 )
  {
    v12 = -1073741701;
    goto LABEL_5;
  }
  v12 = AslpFileGetImageNtHeader(&v20, a5);
  if ( v12 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslFileMappingGetImageTypeEx", 912, "AslpFileGetImageNtHeader failed [%x]", v12);
    goto LABEL_5;
  }
  v14 = v20;
  v13 = *(_WORD *)(v20 + 4);
  v20 = v13;
  v9 = *(unsigned __int16 *)(v14 + 24);
  if ( !a3 && !a4 )
  {
LABEL_22:
    v11 = 0;
    v10 = 0;
    goto LABEL_23;
  }
  if ( v9 == 267 )
  {
    v8 = *(_DWORD *)(v14 + 232);
  }
  else if ( v9 == 523 )
  {
    v8 = *(_DWORD *)(v14 + 248);
  }
  if ( !v8 )
  {
    v13 = v20;
    goto LABEL_22;
  }
  v15 = AslpImageRvaToVa();
  if ( v15 )
  {
    v10 = 1;
    v21 = 1;
    v11 = *(_DWORD *)(v15 + 16);
    v22 = v11;
    v12 = 0;
    v23 = 0;
  }
  else
  {
    v11 = 0;
    v10 = 0;
  }
  v7 = (_WORD *)a2;
  v13 = v20;
  v16 = (unsigned __int16 *)a1;
LABEL_25:
  if ( v16 )
    *v16 = v13;
  if ( v7 )
    *v7 = v9;
  if ( a3 )
    *a3 = v10;
  if ( a4 )
    *a4 = v11;
  return v12;
}
