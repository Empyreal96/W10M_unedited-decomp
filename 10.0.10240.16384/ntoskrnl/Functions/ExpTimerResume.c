// ExpTimerResume 
 
void __fastcall ExpTimerResume(int result, int a2, int a3, int a4)
{
  __int64 v5; // r2
  char v6; // r1
  unsigned int v7; // r5
  int v8; // r0
  __int64 v9; // r0
  int v10; // [sp+8h] [bp-18h]

  if ( *(_BYTE *)(result + 145) )
  {
    v5 = *(_QWORD *)(result + 176);
    if ( *(_BYTE *)(result + 145) == 3 )
    {
      sub_50F864();
      return;
    }
    v6 = *(_BYTE *)(result + 144);
    v7 = *(_DWORD *)(result + 140);
    v8 = 0;
    if ( (v6 & 1) != 0 )
    {
      v8 = result + 100;
      v7 = 0;
    }
    HIDWORD(v9) = *(_DWORD *)(result + 184);
    v10 = v8;
    LODWORD(v9) = result;
    KeSetCoalescableTimer(v9, v5, v7, HIDWORD(v9), v10);
  }
  *(_BYTE *)(result + 144) &= 0xFDu;
}
