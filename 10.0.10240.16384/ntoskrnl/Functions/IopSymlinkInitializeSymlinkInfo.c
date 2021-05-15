// IopSymlinkInitializeSymlinkInfo 
 
int __fastcall IopSymlinkInitializeSymlinkInfo(int a1, __int16 a2, int a3, unsigned int a4, __int16 a5, int a6, unsigned __int16 a7, __int16 a8, __int16 a9, int a10)
{
  int v12; // r0
  int result; // r0
  int v15; // r3
  _WORD *v16; // r2

  *(_WORD *)(a1 + 4) = a8;
  *(_WORD *)(a1 + 14) = a2 - 20;
  v12 = a1 + 20;
  *(_WORD *)a1 = a5;
  *(_WORD *)(a1 + 6) = 0;
  *(_WORD *)(a1 + 2) = a9;
  *(_WORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = v12;
  *(_DWORD *)(a1 + 8) = a10;
  if ( a6 )
  {
    memmove(v12, a6, a7);
    v15 = *(_DWORD *)(a1 + 16);
    *(_WORD *)(a1 + 12) = a7;
    v16 = (_WORD *)(v15 + 2 * (a7 >> 1));
    if ( *(v16 - 1) != 92 )
    {
      *v16 = 92;
      *(_WORD *)(a1 + 12) += 2;
    }
  }
  result = memmove(*(unsigned __int16 *)(a1 + 12) + *(_DWORD *)(a1 + 16), a3, a4);
  *(_WORD *)(a1 + 12) += a4;
  return result;
}
