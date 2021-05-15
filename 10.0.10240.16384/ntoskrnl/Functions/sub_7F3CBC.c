// sub_7F3CBC 
 
void __fastcall sub_7F3CBC(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, int a9, int a10, char a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, __int16 *a19, int a20, int a21, int a22, char *a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, char a36)
{
  __int64 *v36; // r4
  int v37; // r7
  __int64 v38; // r0

  a10 = 0;
  a9 = 0;
  if ( CmpQueryNameString(v37, (unsigned __int16 *)&a9) >= 0 )
  {
    v38 = *v36;
    a15 = a10;
    a16 = 0;
    a17 = (unsigned __int16)a9;
    a18 = 0;
    a7 = 0;
    a19 = &a7;
    a20 = 0;
    a21 = 2;
    a22 = 0;
    a23 = &a36;
    a24 = 0;
    a25 = 4;
    a26 = 0;
    EtwWrite(v38, SHIDWORD(v38), (int)&a11, 0);
    RtlFreeAnsiString(&a9);
  }
  JUMPOUT(0x70EEA4);
}
