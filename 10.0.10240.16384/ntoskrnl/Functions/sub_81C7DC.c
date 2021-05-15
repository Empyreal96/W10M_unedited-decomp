// sub_81C7DC 
 
void __fastcall sub_81C7DC(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, __int64 a24, __int64 a25, __int64 a26, int a27, int a28, __int64 a29, __int64 a30)
{
  int v30; // r6
  int v31; // r2

  if ( (a2 > 0 || a2 >= 0 && a3 >= 0x48) && ZwReadFile() >= 0 && a11 >= 0 && a12 == 72 && a15 == 1933995090 && a17 == 1 )
  {
    if ( (*(_DWORD *)(v30 + 12) & 0x10000000) != 0 )
      v31 = 1;
    else
      v31 = KeNumberProcessors_0;
    if ( a18 == v31
      && a23
      && a24 <= a26
      && a25 <= a26
      && a25 != a24
      && a26 >= 72
      && a26 <= *(_QWORD *)(v30 + 320)
      && a30 >= a26
      && ZwWriteFile() >= 0 )
    {
      *(_DWORD *)(v30 + 336) = a19;
      *(_DWORD *)(v30 + 340) = a20;
      *(_DWORD *)(v30 + 344) = a21;
      *(_DWORD *)(v30 + 348) = a22;
      *(_DWORD *)(v30 + 328) = a23;
      *(_QWORD *)(v30 + 296) = a24;
      *(_QWORD *)(v30 + 288) = a25;
      *(_QWORD *)(v30 + 304) = a26;
      *(_DWORD *)(v30 + 312) = a27;
      *(_DWORD *)(v30 + 316) = a28;
      JUMPOUT(0x7BCD6A);
    }
  }
  JUMPOUT(0x7BCD6C);
}
