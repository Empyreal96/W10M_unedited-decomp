// sub_7D3A24 
 
void __fastcall sub_7D3A24(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, __int16 a9, int a10, char a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, char a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28)
{
  int v28; // r6
  int v29; // r7
  int v30; // r8
  int *v31; // r10
  int v32; // lr
  int v33; // r1
  int v34; // r0
  int *v35; // r3
  int v36; // r1
  int *v37; // r2
  int v38; // r3
  int *v39; // r3
  int *v40; // r2
  int v41; // r0
  int v42; // r1

  a9 = 0;
  v33 = 0;
  if ( *(_DWORD *)(v30 + 1980) )
  {
    a25 = *(_DWORD *)(v30 + 1980);
    a26 = 0;
    a27 = *(unsigned __int16 *)(v30 + 1976);
    a28 = 0;
    v33 = 1;
  }
  v34 = *(_DWORD *)(v30 + 1988);
  v35 = &a25 + 4 * v33;
  v36 = v33 + 1;
  *(_QWORD *)v35 = (unsigned int)&a9;
  v35[2] = v29;
  v35[3] = v28;
  if ( v34 )
  {
    v37 = &a25 + 4 * v36;
    v38 = *(unsigned __int16 *)(v30 + 1984);
    *v37 = v34;
    v37[1] = v28;
    v37[2] = v38;
    v37[3] = v28;
    ++v36;
  }
  v39 = &a25 + 4 * v36;
  *(_QWORD *)v39 = (unsigned int)&a9;
  v39[2] = v29;
  v39[3] = v28;
  v40 = &a25 + 4 * v36 + 4;
  *v40 = (int)&a11;
  v40[1] = v28;
  v41 = *v31;
  v42 = v31[1];
  v40[2] = v32;
  v40[3] = v28;
  EtwWrite(v41, v42, (int)&a21, 0);
  JUMPOUT(0x6D3D78);
}
