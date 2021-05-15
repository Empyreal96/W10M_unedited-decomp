// CMFGetLargePageSectionSize 
 
int __fastcall CMFGetLargePageSectionSize(int a1, _DWORD *a2)
{
  unsigned int v4; // r7
  __int64 v6; // kr08_8
  unsigned __int64 v7; // kr18_8
  __int64 v8; // r2

  v4 = MEMORY[0xFFFF9244] >> 12;
  if ( !(MEMORY[0xFFFF9244] >> 12) )
    return -1073741637;
  v6 = ((*(_QWORD *)a1 & 0xFFF) != 0) + (*(_QWORD *)a1 >> 12);
  if ( !v4 )
    __brkdiv0();
  if ( !((unsigned int)v6 % v4) )
  {
    *a2 = *(_DWORD *)a1;
    a2[1] = *(_DWORD *)(a1 + 4);
    return 0;
  }
  v7 = __PAIR64__(
         ((v6 << 12) + __PAIR64__((v4 - (unsigned int)v6 % v4) >> 20, (v4 - (unsigned int)v6 % v4) << 12)) >> 32,
         -4095)
     + ((((_DWORD)v6 << 12) + ((v4 - (unsigned int)v6 % v4) << 12)) | 0xFFFFFFFF00000000ui64);
  *(_QWORD *)a2 = v7;
  _rt_sdiv64(v4, ((v7 & 0xFFF) != 0) + __PAIR64__(HIDWORD(v7) >> 12, (HIDWORD(v7) << 20) | (v4 >> 12)));
  if ( !v8 && !a2[1] && *a2 >= *(_DWORD *)a1 )
    return 0;
  return -1073741823;
}
