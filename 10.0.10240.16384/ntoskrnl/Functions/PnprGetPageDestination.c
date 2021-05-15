// PnprGetPageDestination 
 
int __fastcall PnprGetPageDestination(unsigned __int64 a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r4
  unsigned int v5; // r8
  __int64 v6; // r6
  __int64 v7; // t1
  bool v8; // cc

  v3 = 0;
  v4 = *(_DWORD *)(PnprContext + 20);
  v5 = *(_DWORD *)(v4 + 4);
  if ( !v5 )
    return -1073741275;
  while ( 1 )
  {
    v7 = *(_QWORD *)(v4 + 16);
    v4 += 16;
    v6 = v7;
    v8 = HIDWORD(a1) > HIDWORD(v7);
    if ( HIDWORD(a1) >= HIDWORD(v7)
      && (v8 || (unsigned int)a1 >= (unsigned int)v6)
      && a1 <= *(_QWORD *)(v4 + 8) + v6 - 1 )
    {
      break;
    }
    if ( ++v3 >= v5 )
      return -1073741275;
  }
  return (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(PnprContext + 600))(
           *(_DWORD *)(PnprContext + 552),
           HIDWORD(a1),
           a1,
           HIDWORD(a1));
}
