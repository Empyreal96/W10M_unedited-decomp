// sub_8138C4 
 
void __fastcall sub_8138C4(int a1, int a2, int a3, int a4, char a5, int a6, int a7, int a8, char a9, char **a10, char a11, char **a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28)
{
  int v28; // r9
  char *v29; // r0
  char *v30; // r8
  int v31; // r2
  int v32; // r3
  int v33; // r4
  int v34; // r2
  char **v35; // r1
  char **v36; // r1

  v29 = (char *)ExAllocatePoolWithTag(1, 36, 1262764866);
  v30 = v29;
  if ( v29 )
  {
    memset(v29, 0, 36);
    v31 = a26;
    v32 = a27;
    v33 = a28;
    *((_DWORD *)v30 + 2) = a25;
    *((_DWORD *)v30 + 3) = v31;
    *((_DWORD *)v30 + 4) = v32;
    *((_DWORD *)v30 + 5) = v33;
    v34 = *((_DWORD *)v30 + 8) | 4;
    *((_DWORD *)v30 + 8) = v34;
    if ( v28 == 0xFFFFF )
    {
      *((_DWORD *)v30 + 8) = v34 | 8;
      v35 = a12;
      *(_DWORD *)v30 = &a11;
      *((_DWORD *)v30 + 1) = v35;
      if ( *v35 != &a11 )
        __fastfail(3u);
      *v35 = v30;
      a12 = (char **)v30;
    }
    else
    {
      v36 = a10;
      *(_DWORD *)v30 = &a9;
      *((_DWORD *)v30 + 1) = v36;
      if ( *v36 != &a9 )
        __fastfail(3u);
      *v36 = v30;
      a10 = (char **)v30;
    }
    JUMPOUT(0x7A5F26);
  }
  BcdCloseObject(a5);
  JUMPOUT(0x7A5FBC);
}
