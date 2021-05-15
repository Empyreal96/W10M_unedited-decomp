// CmpGetNodeName 
 
int __fastcall CmpGetNodeName(int a1, int a2, _WORD *a3)
{
  int v5; // r3
  unsigned int v7; // r7
  _WORD *v8; // r0
  _WORD *v9; // r4

  if ( a3 )
    *a3 = 0;
  v5 = *(unsigned __int16 *)(a2 + 72);
  if ( (*(_WORD *)(a2 + 2) & 0x20) == 0 )
    return sub_968344(a1, a2, 540167491, v5);
  v7 = (unsigned __int16)(2 * (v5 + 1));
  v8 = (_WORD *)(*(int (__fastcall **)(unsigned int, _DWORD, int))(a1 + 12))(v7, 0, 540167491);
  v9 = v8;
  if ( !v8 )
    return 0;
  CmpCopyCompressedName(v8, v7, a2 + 76, *(unsigned __int16 *)(a2 + 72));
  v9[(v7 >> 1) - 1] = 0;
  if ( a3 )
    *a3 = v7;
  return (int)v9;
}
