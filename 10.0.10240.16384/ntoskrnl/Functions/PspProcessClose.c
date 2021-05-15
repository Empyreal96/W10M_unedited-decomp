// PspProcessClose 
 
int __fastcall PspProcessClose(int result, int a2, int a3, unsigned int a4)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  if ( a4 <= 1 )
  {
    v5 = *(_DWORD *)(a2 + 404);
    __dmb(0xBu);
    if ( !v5 )
      return sub_7E76FC();
  }
  v4 = *(_DWORD *)(a2 + 316);
  __dmb(0xBu);
  if ( *(_DWORD *)(result + 176) == v4 )
  {
    v6 = *(_DWORD *)(result + 192);
    __dmb(0xBu);
    if ( (v6 & 0x40000008) != 0 )
      result = PsTerminateProcess(a2, -1073741558);
  }
  return result;
}
