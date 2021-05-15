// sub_54D66C 
 
void __fastcall sub_54D66C(int a1, int a2, __int16 a3, int a4, char *a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, char a23)
{
  int *v23; // r4
  int v24; // r6
  int v25; // r10
  int v26; // r3
  char *v27; // r5
  char v28; // r3
  int v29; // r3

  v26 = *v23;
  v27 = 0;
  a5 = 0;
  a13 = v26;
  a14 = v23[1];
  if ( (a3 & 8) != 0 )
  {
    if ( (a3 & 0xC00) != 0 )
    {
      a5 = &a23;
      v28 = 1;
    }
    else
    {
      v28 = 0;
    }
    if ( BgpGxConvertRectangle(v23, 4u, (int)&a5, v28) < 0 )
      JUMPOUT(0x4E1DAC);
    v27 = a5;
    a16 = *((_DWORD *)a5 + 3);
    a17 = *((_DWORD *)a5 + 5);
    v29 = 1;
  }
  else
  {
    a16 = v23[3];
    a17 = v23[5];
    v29 = *(_DWORD *)(v24 + 16);
  }
  a15 = v29;
  (*(void (__fastcall **)(int *, int, _DWORD))(v24 + 24))(&a13, v25, 0);
  if ( v27 )
  {
    if ( v27 != &a23 )
      BgpGxRectangleDestroy(v27);
  }
  JUMPOUT(0x4E1DA8);
}
