// sub_552038 
 
void __fastcall sub_552038(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11, char a12, char a13, int a14, int a15, int a16, int a17, int a18, char *a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, char *a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, char a43)
{
  int v43; // r5
  int v44; // r6
  unsigned int v45; // r8
  unsigned int *v46; // r7
  char *v47; // r0
  int v48; // lr

  a19 = &a11;
  a20 = 0;
  a21 = 2;
  a22 = 0;
  v46 = &STACK[0x188];
  v47 = &a43;
  a23 = *(_DWORD *)(v44 + 164);
  a24 = 0;
  v48 = 10;
  a25 = 2 * a15;
  a26 = 0;
  a27 = &a12;
  a28 = 0;
  a29 = 4;
  a30 = 0;
  a31 = v43 + 4;
  a32 = 0;
  a33 = 4;
  a34 = 0;
  a35 = v43 + 8;
  a36 = 0;
  a37 = 4;
  a38 = 0;
  a39 = v43 + 12;
  a40 = 0;
  a41 = 4;
  a42 = 0;
  do
  {
    *v46 = (unsigned int)((*(unsigned int *)((char *)v46 + v43 - (_DWORD)&STACK[0x188] + 36) * (unsigned __int64)v45) >> 32) >> 3;
    *((_DWORD *)v47 + 1) = 0;
    *((_DWORD *)v47 + 2) = 4;
    *(_DWORD *)v47 = v46;
    *((_DWORD *)v47 + 3) = 0;
    v47 += 16;
    ++v46;
    --v48;
  }
  while ( v48 );
  STACK[0x138] = (unsigned int)&a13;
  STACK[0x13C] = 0;
  STACK[0x140] = 4;
  STACK[0x144] = 0;
  STACK[0x148] = (unsigned int)&a14;
  STACK[0x14C] = 0;
  STACK[0x150] = 4;
  STACK[0x154] = 0;
  STACK[0x158] = v43 + 80;
  STACK[0x15C] = 0;
  STACK[0x160] = 4;
  STACK[0x164] = 0;
  STACK[0x168] = v43 + 24;
  STACK[0x16C] = 0;
  STACK[0x170] = 4;
  STACK[0x174] = 0;
  STACK[0x178] = v43 + 84;
  STACK[0x17C] = 0;
  STACK[0x180] = 4;
  STACK[0x184] = 0;
  EtwWrite(a18, a17, (int)POP_ETW_EVENT_THERMAL_ZONE_ENUMERATED, 0);
  JUMPOUT(0x4F09AA);
}
