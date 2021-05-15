// FsRtlAllocateExtraCreateParameterList 
 
int __fastcall FsRtlAllocateExtraCreateParameterList(char a1, _DWORD *a2)
{
  _DWORD *v4; // r0

  *a2 = 0;
  if ( (a1 & 1) != 0 )
    return sub_7F4784();
  ++dword_641A8C;
  v4 = (_DWORD *)RtlpInterlockedPopEntrySList(&FsRtlEcpListLookaside);
  if ( !v4 )
  {
    ++dword_641A90;
    v4 = (_DWORD *)dword_641AA8(dword_641A9C, unk_641AA4, dword_641AA0);
  }
  if ( !v4 )
    return -1073741670;
  v4[2] = v4 + 2;
  v4[3] = v4 + 2;
  v4[1] = 6;
  *v4 = 1282433861;
  *a2 = v4;
  return 0;
}
