// EtwEventEnabled 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwEventEnabled(int a1, int a2, int a3)
{
  int v3; // r1
  unsigned int v4; // r5 OVERLAPPED
  unsigned int v5; // r6 OVERLAPPED
  int v7; // r1

  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 16);
    *(_QWORD *)&v4 = *(_QWORD *)(a3 + 8);
    if ( *(_DWORD *)(v3 + 56)
      && (*(unsigned __int8 *)(a3 + 4) <= (unsigned int)*(unsigned __int8 *)(v3 + 60) || !*(_BYTE *)(v3 + 60))
      && ((*(_DWORD *)(v3 + 64) & 0x40) != 0 && !(v4 | v5)
       || *(_DWORD *)(v3 + 76) & v5 | *(_DWORD *)(v3 + 72) & v4
       && __PAIR64__(*(_DWORD *)(v3 + 84) & v5, *(_DWORD *)(v3 + 80) & v4) == *(_QWORD *)(v3 + 80)) )
    {
      return 1;
    }
    if ( *(_BYTE *)(a1 + 52) )
    {
      v7 = *(_DWORD *)(a1 + 20);
      if ( *(_DWORD *)(v7 + 56) )
      {
        if ( *(unsigned __int8 *)(a3 + 4) <= (unsigned int)*(unsigned __int8 *)(v7 + 60) || !*(_BYTE *)(v7 + 60) )
        {
          if ( (*(_DWORD *)(v7 + 64) & 0x40) != 0 )
            return sub_50E2F8();
          if ( *(_DWORD *)(v7 + 76) & v5 | *(_DWORD *)(v7 + 72) & v4
            && __PAIR64__(*(_DWORD *)(v7 + 84) & v5, *(_DWORD *)(v7 + 80) & v4) == *(_QWORD *)(v7 + 80) )
          {
            return 1;
          }
        }
      }
    }
    return 0;
  }
  return 0;
}
