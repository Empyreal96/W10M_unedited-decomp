// sub_7DB6C4 
 
void __fastcall sub_7DB6C4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32)
{
  char v32; // r4
  int v33; // r5
  int v34; // r6
  int v35; // r7
  int v36; // r8
  int v37; // r0
  int *v38; // r2

  v37 = PsGetProcessId(v34);
  a9 = &a7;
  a10 = 0;
  a11 = 4;
  a12 = 0;
  a7 = v37;
  if ( (v32 & 2) != 0 )
  {
    if ( (v32 & 1) != 0 )
      v38 = KERNEL_MEM_EVENT_WS_INSWAP_START;
    else
      v38 = KERNEL_MEM_EVENT_WS_OUTSWAP_START;
    a13 = v33;
    a14 = 0;
    a15 = 4;
    a16 = 0;
  }
  else
  {
    a13 = v33 + 16;
    a14 = 0;
    a15 = 4;
    a16 = 0;
    if ( (v32 & 1) != 0 )
    {
      v38 = KERNEL_MEM_EVENT_WS_INSWAP_STOP;
    }
    else
    {
      a17 = v33;
      a18 = 0;
      a19 = 4;
      a20 = 0;
      a21 = v33 + 4;
      a22 = 0;
      a23 = 4;
      a24 = 0;
      a25 = v33 + 8;
      a26 = 0;
      a27 = 4;
      a28 = 0;
      a29 = v33 + 12;
      a30 = 0;
      a31 = 4;
      v38 = KERNEL_MEM_EVENT_WS_OUTSWAP_STOP;
      a32 = 0;
    }
  }
  EtwWrite(v36, v35, (int)v38, 0);
  JUMPOUT(0x6E3F8E);
}
