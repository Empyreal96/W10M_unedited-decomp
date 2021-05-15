// AlpcpCreateRegion 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AlpcpCreateRegion(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r7 OVERLAPPED
  int v8; // r10
  unsigned int v9; // r8 OVERLAPPED
  _DWORD *v10; // r2
  _DWORD *v11; // r1
  _DWORD *v12; // r5
  unsigned int v13; // r4
  int v14; // r0
  _BYTE *v15; // r0
  _BYTE *v16; // r4
  int v17; // r3
  int v18; // r7
  bool v19; // zf
  unsigned int *v20; // lr
  int v21; // r0
  int v22; // r1
  int v23; // r3
  _DWORD *v24; // r3
  int v25; // lr
  int v26; // r3

  *a4 = 0;
  v5 = a2;
  if ( a1[4] != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    return sub_7F63B4();
  v8 = (AlpcpViewGranularity + a3 - 1) & ~(AlpcpViewGranularity - 1);
  v9 = (AlpcpRegionGranularity + a3 - 1) & ~(AlpcpRegionGranularity - 1);
  if ( a2 )
  {
    v5 = (AlpcpRegionGranularity + a2 - 1) & ~(AlpcpRegionGranularity - 1);
    v12 = a1 + 8;
  }
  else
  {
    v10 = (_DWORD *)a1[8];
    v11 = a1 + 8;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    if ( v10 == a1 + 8 )
    {
LABEL_5:
      if ( a1[1] - v5 < v9 )
        return -1073741670;
      v12 = a1 + 8;
    }
    else
    {
      do
      {
        v25 = v10[3];
        if ( v25 - v5 == v9 )
        {
          v12 = v10;
          goto LABEL_7;
        }
        if ( v25 - v5 > v9 && (!v12 || v13 > v25 - v5) )
        {
          v12 = v10;
          v14 = v5;
          v13 = v25 - v5;
        }
        v26 = v10[4];
        v10 = (_DWORD *)*v10;
        v5 = v25 + v26;
      }
      while ( v10 != v11 );
      if ( !v12 )
        goto LABEL_5;
      v5 = v14;
    }
  }
LABEL_7:
  v15 = (_BYTE *)AlpcpAllocateBlob(AlpcRegionType, 48, 0);
  v16 = v15;
  if ( !v15 )
    return -1073741670;
  memset(v15, 0, 48);
  *((_DWORD *)v16 + 8) = v16 + 32;
  *((_DWORD *)v16 + 9) = v16 + 32;
  v17 = *((_DWORD *)v16 + 6);
  *(_QWORD *)(v16 + 12) = *(_QWORD *)&v5;
  *((_DWORD *)v16 + 5) = v8;
  *((_DWORD *)v16 + 6) = v17 & 0xFFFFFFFE;
  v18 = *(a1 - 3);
  v19 = v18 == 0;
  if ( v18 <= 0 )
  {
LABEL_28:
    if ( !v19 )
      KeBugCheckEx(24, 0, (int)a1, 32, v18);
  }
  else
  {
    v20 = a1 - 3;
    while ( 1 )
    {
      v21 = v18;
      __dmb(0xBu);
      do
        v22 = __ldrex(v20);
      while ( v22 == v18 && __strex(v18 + 1, v20) );
      v18 = v22;
      __dmb(0xBu);
      if ( v22 == v21 )
        break;
      if ( v22 <= 0 )
      {
        v19 = v22 == 0;
        goto LABEL_28;
      }
    }
  }
  *((_DWORD *)v16 + 2) = a1;
  v23 = v12[1];
  *(_DWORD *)v16 = v12;
  *((_DWORD *)v16 + 1) = v23;
  v24 = (_DWORD *)v12[1];
  *a4 = v16;
  *v24 = v16;
  v12[1] = v16;
  ++a1[7];
  return 0;
}
