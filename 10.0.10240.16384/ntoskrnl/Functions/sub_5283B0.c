// sub_5283B0 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_5283B0(int a1, int a2, int a3, int a4, int a5, int a6, char a7)
{
  _DWORD *v7; // r4
  char *v8; // r5
  _DWORD *v9; // r6
  int v10; // r7
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  _DWORD *v13; // r2

  if ( v8 == &a7 )
  {
    *(_QWORD *)&v11 = *(_QWORD *)v7;
    if ( *(_DWORD **)(*v7 + 4) == v7 && (_DWORD *)*v12 == v7 )
    {
      *v12 = v11;
      *(_DWORD *)(v11 + 4) = v12;
      if ( v9 )
        *v9 -= v7[26];
      MiIssueHardFaultIo((int)v7, 0, 0);
      v13 = *(_DWORD **)(v10 + 4);
      *v7 = v10;
      v7[1] = v13;
      if ( *v13 == v10 )
      {
        *v13 = v7;
        *(_DWORD *)(v10 + 4) = v7;
        JUMPOUT(0x4DDA5C);
      }
      __fastfail(3u);
    }
    __fastfail(3u);
  }
  JUMPOUT(0x4DDA64);
}
