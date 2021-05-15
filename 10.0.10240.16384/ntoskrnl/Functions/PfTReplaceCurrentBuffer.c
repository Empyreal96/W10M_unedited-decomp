// PfTReplaceCurrentBuffer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfTReplaceCurrentBuffer(int a1)
{
  _DWORD *v2; // r0
  unsigned int v3; // r1
  int v4; // r2
  _DWORD *v5; // r2 OVERLAPPED
  int v6; // r1 OVERLAPPED

  v2 = PfTGetFreeBuffer(a1);
  if ( !v2 )
    return -1073741823;
  if ( (*(_DWORD *)a1 & 0xF) == 1 )
  {
    v3 = v2[6];
    v4 = (unsigned __int16)(*(_WORD *)(*(_DWORD *)(a1 + 16) + 28) + v3);
    *((_WORD *)v2 + 14) = v4;
    if ( 0xFFFF - v4 < v3 )
      *(_DWORD *)((((unsigned int)v2 + 35) & 0xFFFFFFFC) + 20 * (0xFFFF - v4)) = -1;
  }
  v5 = (_DWORD *)(a1 + 16);
  v6 = *(_DWORD *)(a1 + 16);
  *(_QWORD *)v2 = *(_QWORD *)&v6;
  if ( *(_DWORD *)(v6 + 4) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)(v6 + 4) = v2;
  *v5 = v2;
  if ( *(unsigned __int16 *)(a1 + 10) <= (unsigned int)*(unsigned __int16 *)(a1 + 8) )
    KeSetEvent((int)&unk_643944, 0, 0);
  return 0;
}
