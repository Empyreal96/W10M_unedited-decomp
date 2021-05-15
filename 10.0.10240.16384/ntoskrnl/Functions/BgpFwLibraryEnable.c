// BgpFwLibraryEnable 
 
int __fastcall BgpFwLibraryEnable(unsigned __int8 *a1, int a2, int a3)
{
  int v4; // r4
  int v5; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int *v11; // r7
  int v12; // r2
  void *v13; // r3
  int v14; // r3

  if ( (dword_619018 & 2) == 0 )
  {
    v4 = 0;
    v5 = *a1;
    if ( (dword_619018 & 0xC00) == 3072 )
      v4 = 1;
    if ( *a1 )
    {
      v5 = a1[1];
      if ( !a1[1] )
        return sub_54D724();
    }
    if ( !v4 )
      ResFwBackgroundTransition(0, a2, a3, v5);
    v7 = *(_DWORD *)a1;
    v8 = *((_DWORD *)a1 + 1);
    v9 = *((_DWORD *)a1 + 2);
    v10 = *((_DWORD *)a1 + 3);
    v11 = (int *)(a1 + 16);
    *(_DWORD *)&BgInternal = v7;
    dword_618FC4 = v8;
    dword_618FC8 = v9;
    dword_618FCC = v10;
    v12 = v11[1];
    v13 = (void *)v11[2];
    dword_618FD0 = *v11;
    *(_DWORD *)algn_618FD4 = v12;
    off_618FD8 = v13;
    if ( dword_618FD0 == 1 )
    {
      dword_618FD0 = 5;
      v14 = dword_619018 | 8;
    }
    else
    {
      v14 = dword_619018;
    }
    dword_619018 = v14 | 2;
  }
  return 0;
}
