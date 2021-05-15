// PopCopyWakeSource 
 
int __fastcall PopCopyWakeSource(int a1, int a2, int a3)
{
  __int64 v4; // r0
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r3

  v4 = PopWakeSourceSize(a3, a3);
  *(_DWORD *)(a1 + 4) = v4;
  v5 = *(_DWORD *)(HIDWORD(v4) + 8);
  if ( !v5 )
  {
    *(_DWORD *)a1 = 0;
    LODWORD(v4) = a1 + 10;
    *(_WORD *)(a1 + 8) = *(_WORD *)(HIDWORD(v4) + 12);
    v7 = *(unsigned __int16 *)(HIDWORD(v4) + 12);
    HIDWORD(v4) = *(_DWORD *)(HIDWORD(v4) + 16);
    goto LABEL_17;
  }
  if ( v5 == 1 )
  {
    *(_DWORD *)a1 = 1;
    v9 = *(_DWORD *)(HIDWORD(v4) + 12);
    switch ( v9 )
    {
      case 1:
LABEL_9:
        v8 = 0;
LABEL_10:
        *(_DWORD *)(a1 + 8) = v8;
        return v4;
      case 2:
        *(_DWORD *)(a1 + 8) = 1;
        return v4;
      case 4:
        v8 = 3;
        goto LABEL_10;
    }
  }
  else if ( (unsigned int)(v5 - 2) <= 1 )
  {
    if ( v5 == 2 )
      v6 = 2;
    else
      v6 = 3;
    *(_DWORD *)a1 = v6;
    HIDWORD(v4) = *(_DWORD *)(HIDWORD(v4) + 12);
    if ( HIDWORD(v4) )
    {
      v7 = *(_DWORD *)HIDWORD(v4);
      LODWORD(v4) = a1 + 8;
LABEL_17:
      LODWORD(v4) = memmove(v4, SHIDWORD(v4), v7);
      return v4;
    }
    goto LABEL_9;
  }
  return v4;
}
