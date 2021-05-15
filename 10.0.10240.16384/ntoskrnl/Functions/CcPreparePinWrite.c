// CcPreparePinWrite 
 
int __fastcall CcPreparePinWrite(int a1, _DWORD *a2, int a3, int a4, char a5, _DWORD *a6, int *a7)
{
  int v8; // r5
  int v11; // lr
  int *v12; // r2
  int **v13; // r4
  unsigned int v14; // r0
  unsigned int v15; // r1
  char v16; // r3
  char v17; // r4
  int *v19; // [sp+1Ch] [bp-44h] BYREF
  int v20; // [sp+20h] [bp-40h] BYREF
  int *v21; // [sp+24h] [bp-3Ch]
  int v22; // [sp+28h] [bp-38h]
  unsigned __int64 v23; // [sp+30h] [bp-30h] BYREF
  __int64 v24; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  _DWORD *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = a3;
  v20 = 0;
  v11 = *a2;
  v23 = *(_QWORD *)a2;
  v12 = 0;
  v19 = 0;
  v13 = &v19;
  v22 = v8;
  if ( (a5 & 0x20) != 0 )
  {
    CcMapDataForOverwrite(a1, a2, v8, a6, a7);
    LOBYTE(v20) = 1;
  }
  else
  {
    v14 = HIDWORD(v24);
    v15 = v24;
    while ( 1 )
    {
      if ( v12 )
      {
        if ( v13 == &v19 )
        {
          v19 = (int *)CcAllocateObcb(a2, v8);
          v13 = (int **)(v19 + 4);
          v21 = v19 + 4;
          *a7 = v20;
          v11 = v23;
          v14 = HIDWORD(v24);
          v15 = v24;
        }
        v8 += v11 - v15;
        varg_r2 = v8;
        v23 = __PAIR64__(v14, v15);
        v21 = (int *)++v13;
      }
      if ( !CcPinFileData(a1, &v23, v8, 0, 1, a5, v13, &v20, &v24) )
      {
        v16 = 0;
        goto LABEL_17;
      }
      v15 = v24;
      v11 = v23;
      v14 = HIDWORD(v24);
      if ( (__int64)(v24 - v23) >= (unsigned int)v8 )
        break;
      v12 = v19;
    }
    if ( v13 == &v19 )
      *a7 = v20;
    if ( a4 )
      memset((_BYTE *)*a7, 0, v22);
    CcSetDirtyPinnedData(v19, 0);
    *a6 = v19;
    v16 = 1;
LABEL_17:
    v17 = v16;
    if ( !v16 && v19 )
      CcUnpinData();
    LOBYTE(v20) = v17;
  }
  return (unsigned __int8)v20;
}
