// CmpRmAnalysisPhase 
 
// local variable allocation has failed, the output may be wrong!
int CmpRmAnalysisPhase(_DWORD *a1, int a2, ...)
{
  _DWORD *v2; // r6
  int v4; // r7
  _DWORD *v5; // r8
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r1
  int v9; // r0
  _DWORD *v11; // r0
  int v12; // r3
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  int *v15; // [sp+10h] [bp-50h]
  char v16[4]; // [sp+18h] [bp-48h] BYREF
  _DWORD *v17; // [sp+1Ch] [bp-44h] BYREF
  int v18; // [sp+20h] [bp-40h] BYREF
  int v19; // [sp+24h] [bp-3Ch] BYREF
  char v20[4]; // [sp+28h] [bp-38h] BYREF
  int v21; // [sp+2Ch] [bp-34h] BYREF
  char v22[8]; // [sp+30h] [bp-30h] BYREF
  char v23[8]; // [sp+38h] [bp-28h] BYREF
  char v24[32]; // [sp+40h] [bp-20h] BYREF
  va_list varg_r2; // [sp+70h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  v2 = a1 + 2;
  v19 = 0;
  v16[0] = 0;
  v17 = 0;
  if ( (_DWORD *)a1[2] == a1 + 2 )
  {
    v4 = 0;
    v5 = 0;
  }
  else
  {
    *(_DWORD *)(a1[2] + 4) = a1[3];
    *(_DWORD *)a1[3] = a1[2];
    v4 = a1[2];
    v5 = *(_DWORD **)(v4 + 4);
    *v2 = v2;
    a1[3] = a1 + 2;
  }
  v15 = &v19;
  v6 = ClfsReadLogRecord(a1[14], (int *)varg_r2, 3, &v18, v20, v16, v23, v22);
  if ( v6 >= 0 )
  {
    while ( 1 )
    {
      if ( (v16[0] & 1) != 0 )
      {
        v6 = CmpSearchAddTrans(0, (int)a1, 0, 0, v18 + 16, 1, &v17);
        if ( v6 < 0 )
          goto LABEL_16;
        v7 = (unsigned int)v17;
        if ( !v17 )
        {
          v6 = -1072103422;
          goto LABEL_16;
        }
        v8 = v18;
        if ( *(_DWORD *)(v18 + 8) == 16 )
        {
          v17[16] |= 4u;
          v7 = (unsigned int)v17;
          v8 = v18;
        }
        if ( *(_DWORD *)(v8 + 8) == 8 )
        {
          *(_DWORD *)(v7 + 64) |= 2u;
          v7 = (unsigned int)v17;
          v8 = v18;
        }
        if ( *(_DWORD *)(v8 + 8) == 4 )
          *(_DWORD *)(v7 + 64) |= 1u;
      }
      v16[0] = 1;
      v9 = ClfsReadNextLogRecord(v19, &v18, v20, v16, 0, v23, v22, v24, v15);
      v6 = v9;
      if ( v9 == -1073741807 )
        break;
      if ( v9 < 0 )
        goto LABEL_16;
    }
    v6 = 0;
LABEL_23:
    v21 = 0;
    while ( 1 )
    {
      v11 = (_DWORD *)CmListGetNextElement(v2, &v21, 0);
      v17 = v11;
      if ( !v11 )
        break;
      v12 = v11[16];
      if ( (v12 & 1) == 0 || (v12 & 6) != 0 )
      {
        *(_QWORD *)&v13 = *(_QWORD *)v11;
        if ( *(_DWORD **)(*v11 + 4) != v11 || (_DWORD *)*v14 != v11 )
          __fastfail(3u);
        *v14 = v13;
        *(_DWORD *)(v13 + 4) = v14;
        ExFreePoolWithTag((unsigned int)v17);
        goto LABEL_23;
      }
    }
  }
LABEL_16:
  if ( v19 )
    ClfsTerminateReadLog();
  if ( v4 )
  {
    *v5 = v2;
    *(_DWORD *)(v4 + 4) = a1[3];
    *(_DWORD *)a1[3] = v4;
    a1[3] = v5;
  }
  return v6;
}
