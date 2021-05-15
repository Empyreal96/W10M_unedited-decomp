// sub_815194 
 
void __fastcall sub_815194(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, unsigned int a14, int a15, unsigned int a16)
{
  unsigned __int16 *v16; // r5
  int v17; // r6
  int v18; // r7
  int v19; // r9
  int v20; // r10
  int v21; // r0
  unsigned int v22; // r5

  v21 = ExpTranslateSymbolicLink(v16, &a13);
  if ( v21 >= 0 )
  {
    v22 = a14;
  }
  else
  {
    if ( v21 != -1073741788 )
      goto LABEL_7;
    v22 = a16;
    v17 = 0;
    a13 = a15;
    a14 = a16;
  }
  ExpCreateOutputARC(v20, v19, &a13, v18);
  if ( v17 == 1 )
    ExFreePoolWithTag(v22);
LABEL_7:
  JUMPOUT(0x7AA0FA);
}
