// sub_81AD18 
 
void __fastcall sub_81AD18(int a1, int a2, int a3, int a4, int a5, int a6, int a7, BOOL a8, BOOL a9, BOOL a10, int a11, int a12, BOOL *a13, int a14, int a15, int a16, BOOL *a17, int a18, int a19, int a20, int *a21, int a22, int a23, int a24, BOOL *a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40)
{
  int v40; // r5
  int *v41; // r6
  int v42; // r7
  int v43; // r0
  int v44; // r4
  int v45; // r1
  char v46; // r3
  int v47; // r0
  int v48; // r3
  int v49; // r2
  int v50; // r1

  v43 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(v40 + 24));
  v44 = v43;
  if ( v43 )
    v45 = *(_DWORD *)(*(_DWORD *)(v43 + 176) + 20);
  else
    v45 = 0;
  if ( v45 )
  {
    HIWORD(a7) = *(_WORD *)(v45 + 160) >> 1;
    a8 = *(_DWORD *)(v40 + 64) != 0;
    a10 = *(_DWORD *)(v40 + 68) != 0;
    a9 = *(_BYTE *)(v40 + 33) != 0;
    v46 = *(_BYTE *)(v40 + 34);
    a11 = v40;
    v47 = *v41;
    LOBYTE(a7) = v46;
    a13 = &a10;
    a14 = 0;
    a15 = 4;
    a16 = 0;
    a17 = &a8;
    a18 = 0;
    a19 = 4;
    a20 = 0;
    a21 = &a7;
    a22 = 0;
    a23 = 1;
    a24 = 0;
    a25 = &a9;
    a26 = 0;
    a27 = 4;
    a28 = 0;
    a29 = &a11;
    a30 = 0;
    a31 = 4;
    a32 = 0;
    a33 = (int)&a7 + 2;
    a34 = 0;
    a35 = 2;
    a36 = 0;
    v48 = *(_DWORD *)(v45 + 164);
    v49 = *(unsigned __int16 *)(v45 + 160);
    v50 = v41[1];
    a37 = v48;
    a38 = 0;
    a39 = v49;
    a40 = 0;
    EtwWrite(v47, v50, v42, 0);
  }
  if ( v44 )
    ObfDereferenceObject(v44);
  JUMPOUT(0x7B895E);
}
