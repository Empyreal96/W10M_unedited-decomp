// EtwpQueryProcessCommandLine 
 
int __fastcall EtwpQueryProcessCommandLine(int a1, int a2)
{
  int v2; // r6
  _WORD *v3; // r8
  int v4; // r3
  _DWORD *v5; // r2
  unsigned int v6; // r9
  unsigned int v7; // r4
  int v8; // r0
  unsigned int i; // r2

  v2 = a2;
  *(_WORD *)a2 = 0;
  v3 = *(_WORD **)(a2 + 4);
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 320) + 16);
  if ( v4 )
  {
    v5 = (_DWORD *)(v4 + 64);
    if ( v4 + 64 >= (unsigned int)MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    v6 = v5[1];
    v7 = *v5 & 0xFFFE;
    if ( v7 )
    {
      if ( v6 )
      {
        if ( (v6 & 1) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        if ( v7 + v6 > MmUserProbeAddress || v7 + v6 < v6 )
          *(_BYTE *)MmUserProbeAddress = 0;
        if ( v7 > 0x400 )
          v7 = 1024;
      }
      else
      {
        v7 = 0;
      }
    }
  }
  else
  {
    v6 = 0;
    v7 = 0;
  }
  if ( !v7 )
    return 0;
  if ( *(_WORD *)(a2 + 2) )
  {
    if ( v7 >= *(unsigned __int16 *)(a2 + 2) )
      LOWORD(v7) = *(_WORD *)(a2 + 2);
    v7 = (unsigned __int16)v7;
    goto LABEL_23;
  }
  v8 = ExAllocatePoolWithTag(1, v7, 1350005829);
  v3 = (_WORD *)v8;
  if ( v8 )
  {
    *(_DWORD *)(v2 + 4) = v8;
    *(_WORD *)(v2 + 2) = v7;
LABEL_23:
    memmove((int)v3, v6, v7);
    for ( i = v7 >> 1; i; --i )
    {
      if ( !*v3 )
        *v3 = 32;
      ++v3;
    }
    *(_WORD *)v2 = v7;
    return 0;
  }
  return -1073741670;
}
