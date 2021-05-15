// MiIssueHardFaultIo 
 
int __fastcall MiIssueHardFaultIo(int a1, int a2, int a3)
{
  unsigned int v3; // r3
  int v5; // r7
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r1
  int result; // r0
  int v12; // r5
  unsigned int *v13; // r6
  unsigned int v14; // r0
  unsigned int v15; // r2

  v3 = *(unsigned __int8 *)(a1 + 113);
  v5 = a1 + 152;
  v6 = (v3 >> 2) & 1;
  if ( v6 )
    v5 |= 1u;
  if ( (v3 & 0xFFFFFF80) != 0 )
  {
    if ( (a3 & 1) != 0 )
    {
      v15 = a3 & 0xFFFFFFFE;
      if ( *(_BYTE *)v15 == 1 && (*(_DWORD *)(v15 + 40) & 0x800) != 0 )
        v5 |= 2u;
    }
    result = SmPageRead(a1 + 56, v5, a1 + 16, a1 + 48);
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 116);
    if ( (*(_BYTE *)(a1 + 115) & 2) != 0 )
      v7 |= 1u;
    if ( v6
      || (v8 = *(_DWORD *)(a1 + 128), v8 >= dword_63389C)
      && *((_BYTE *)&MiState[2423] + ((int)(((v8 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 8
      && !a2 )
    {
      v7 |= 2u;
    }
    if ( !v6 )
    {
      v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150);
      v10 = *(_DWORD *)(v9 + 792);
      if ( v10 )
      {
        v13 = (unsigned int *)(v9 + 792);
        __dmb(0xBu);
        do
          v14 = __ldrex(v13);
        while ( v14 == v10 && __strex(v10 - 1, v13) );
        __dmb(0xBu);
        if ( v14 != v10 )
          return sub_543F90();
        v5 |= 2u;
      }
    }
    result = IoPageRead(v7, v5, a1 + 56, a1 + 16);
  }
  v12 = result;
  if ( result < 0 )
  {
    *(_DWORD *)(a1 + 48) = result;
    *(_DWORD *)(a1 + 52) = 0;
    KeSetEvent(a1 + 16, 0, 0);
    result = v12;
  }
  return result;
}
