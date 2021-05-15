// StEtaStart 
 
int __fastcall StEtaStart(int a1, int a2, _DWORD *a3)
{
  int v4; // r8
  _BYTE *v5; // r0
  int v6; // r4
  int v7; // r3
  int i; // r7
  int *v9; // r10
  int v10; // r9
  int result; // r0
  int v12; // r0
  int v13; // r8
  int v14; // r0
  int v15; // r1
  __int64 v16; // r5
  int v17; // t1
  _DWORD *v18; // r2
  int v19; // [sp+0h] [bp-48h]
  int v21; // [sp+8h] [bp-40h]
  int v22; // [sp+10h] [bp-38h] BYREF
  _DWORD *v23; // [sp+18h] [bp-30h]
  __int64 v24[5]; // [sp+20h] [bp-28h] BYREF

  v24[0] = 0i64;
  v4 = a1;
  v23 = a3;
  v5 = (_BYTE *)KeQueryPerformanceCounter(&v22, v24);
  if ( !v24[0] )
    return -1073741637;
  v6 = 0;
  v7 = a2 - v4;
  v19 = 0;
  v22 = a2 - v4;
  for ( i = v4; ; i += 4 )
  {
    v9 = *(int **)(v7 + i);
    if ( v9 )
      break;
LABEL_10:
    v19 = ++v6;
    if ( v6 >= 2 )
    {
      v18 = v23;
      result = 0;
      *(_DWORD *)(v4 + 24) = *v23;
      *(_DWORD *)(v4 + 28) = v18[1];
      return result;
    }
  }
  v10 = 1;
  if ( *v9 != -1 )
    return sub_510AE8(v5);
  v12 = ExAllocatePoolWithTag(512, 32, 1950969203);
  v21 = v12;
  if ( v12 )
  {
    v13 = v12;
    do
    {
      v14 = _rt_sdiv64(1000000i64, v24[0] * (unsigned int)v9[1]);
      HIDWORD(v16) = v15;
      LODWORD(v16) = v14;
      v17 = *v9;
      v9 += 2;
      v5 = memset((_BYTE *)v13, 0, 32);
      *(_DWORD *)v13 = v17;
      *(_QWORD *)(v13 + 8) = v16;
      v13 += 32;
      --v10;
    }
    while ( v10 );
    v6 = v19;
    v4 = a1;
    *(_DWORD *)(i + 16) = v21;
    v7 = v22;
    goto LABEL_10;
  }
  return -1073741670;
}
