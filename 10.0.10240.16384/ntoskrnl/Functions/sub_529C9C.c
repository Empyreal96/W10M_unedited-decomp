// sub_529C9C 
 
void __fastcall sub_529C9C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int *a11, int a12, int a13, int a14, int *a15, int a16, int a17, int a18, int *a19, int a20, int a21, int a22)
{
  int v22; // r4
  int v23; // r5
  int v24; // r6
  int v25; // r3

  if ( dword_61ED6C )
  {
    a9 = 1;
    a7 = dword_61ED84;
    v25 = dword_61ED88;
  }
  else
  {
    v25 = 0;
    a9 = 0;
    a7 = 0;
  }
  a8 = v25;
  a11 = &a9;
  a12 = 0;
  a13 = 4;
  a14 = 0;
  a15 = &a7;
  a16 = 0;
  a17 = 4;
  a18 = 0;
  a19 = &a8;
  a20 = 0;
  a21 = 4;
  a22 = 0;
  EtwWrite(v24, v23, v22, 0);
  JUMPOUT(0x46815E);
}
