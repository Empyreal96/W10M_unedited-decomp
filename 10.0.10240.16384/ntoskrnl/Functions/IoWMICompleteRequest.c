// IoWMICompleteRequest 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoWMICompleteRequest(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  int v5; // r1
  int v6; // r6
  int v8; // r5
  int v10; // r7
  unsigned int v11; // r9
  unsigned int v12; // r4 OVERLAPPED
  unsigned int *v13; // r2
  int v14; // r5
  unsigned int *v15; // r1
  unsigned int *v16; // r0
  unsigned int v17; // t1
  unsigned int v18; // r3
  int v19; // r3

  v5 = a3[24];
  v6 = a4;
  v8 = *(_DWORD *)(v5 + 20);
  if ( *(_BYTE *)(v5 + 1) )
    return sub_8184F8();
  v10 = *(_DWORD *)(v8 + 52);
  v11 = *(_DWORD *)(v8 + 48);
  v12 = v11 + a5;
  if ( a4 < 0 )
    goto LABEL_12;
  if ( v12 > *(_DWORD *)(v5 + 16) )
    v6 = -1073741789;
  if ( v6 < 0 )
  {
LABEL_12:
    if ( v6 == -1073741789 )
    {
      *(_DWORD *)v8 = 56;
      v19 = 32;
      *(_QWORD *)(v8 + 44) = *(_QWORD *)(&v12 - 1);
      v12 = 56;
      v6 = 0;
    }
    else
    {
      v12 = 0;
    }
  }
  else
  {
    KeQuerySystemTime((_DWORD *)(v8 + 16));
    v13 = (unsigned int *)(v8 + 60);
    *(_DWORD *)v8 = v12;
    v14 = v10;
    if ( v10 )
    {
      v15 = &v13[2 * v10];
      v16 = &v13[v10];
      do
      {
        v17 = *--v16;
        --v14;
        *(v15 - 1) = v17;
        v15 -= 2;
      }
      while ( v14 );
      do
      {
        v18 = v13[1];
        *v13 = v11;
        v13 += 2;
        v11 = (v18 + v11 + 7) & 0xFFFFFFF8;
        --v10;
      }
      while ( v10 );
    }
  }
  a3[6] = v6;
  a3[7] = v12;
  IofCompleteRequest((int)a3, 0);
  return v6;
}
