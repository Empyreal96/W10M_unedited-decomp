// sub_52A634 
 
void __fastcall sub_52A634(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char *a11, int a12, int a13, int a14, int *a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int *a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, char a46)
{
  int v46; // r4
  int v47; // r5
  int v48; // r6
  int v49; // r2
  int v50; // r3
  int v51; // r1
  int v52; // r0
  int v53; // r2
  int v54; // r4
  int *v55; // r4

  v49 = *(_DWORD *)(v46 + 40 * *(char *)(v46 + 34) + 108);
  BYTE1(a7) = *(_BYTE *)(v49 + 112);
  a9 = *(_DWORD *)(v49 + 116);
  LOBYTE(a7) = *(_DWORD *)(v49 + 120) - 1;
  v50 = *(_DWORD *)(v49 + 12);
  if ( v50 )
    v51 = *(_DWORD *)(*(_DWORD *)(v50 + 176) + 20);
  else
    v51 = 0;
  a8 = v51;
  v52 = 5;
  v53 = *(unsigned __int16 *)(v51 + 20) >> 1;
  a11 = &a46;
  a12 = 0;
  a13 = 4;
  a14 = 0;
  a15 = &a9;
  a16 = 0;
  a17 = 4;
  a18 = 0;
  a19 = (int)&a7 + 1;
  a20 = 0;
  a21 = 1;
  a22 = 0;
  a23 = &a8;
  a24 = 0;
  a25 = 4;
  a26 = 0;
  a27 = (int)&a7 + 2;
  a28 = 0;
  a29 = 2;
  a30 = 0;
  HIWORD(a7) = v53;
  if ( v53 )
  {
    v54 = *(unsigned __int16 *)(v51 + 20);
    a31 = *(_DWORD *)(v51 + 24);
    a32 = 0;
    a33 = v54;
    a34 = 0;
    v52 = 6;
  }
  v55 = (int *)&(&a11)[4 * v52];
  *v55 = (int)&a7;
  v55[2] = 1;
  v55[1] = 0;
  v55[3] = 0;
  EtwWrite(v48, v47, (int)POP_ETW_EVENT_IRPSTART, 0);
  JUMPOUT(0x469EF4);
}
