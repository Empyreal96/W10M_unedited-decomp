// KiMaskInterruptInternal 
 
int __fastcall KiMaskInterruptInternal(unsigned int a1, int a2)
{
  unsigned int v3; // r4
  int *v4; // r3
  int v5; // r2
  _DWORD *v7; // r1
  _DWORD *v8; // r2
  int v9; // r3

  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (a1 & 0xF0) != 0 )
  {
    if ( a1 - 2048 >= 0x400 )
      goto LABEL_18;
    v9 = *(_DWORD *)(v3 + 1324);
    if ( !v9 )
      goto LABEL_18;
    v4 = (int *)(v9 + 4 * (a1 - 2048));
  }
  else
  {
    v4 = (int *)(v3 + 4 * ((a1 & 0xF | (a1 >> 4) & 0xF0) + 75));
  }
  if ( v4 )
  {
    v5 = *v4;
    goto LABEL_5;
  }
LABEL_18:
  v5 = 0;
LABEL_5:
  if ( !v5 )
    return sub_51FCB8();
  v7 = (_DWORD *)(v5 + 4);
  if ( *(_DWORD *)(v5 + 4) == v5 + 4 )
  {
    if ( (*(_DWORD *)(v5 + 60) & 1) != 0 )
      return off_617A60(a2, 0);
  }
  else
  {
    v8 = (_DWORD *)(v5 + 4);
    while ( (v8[14] & 1) != 0 )
    {
      v8 = (_DWORD *)*v8;
      if ( v8 == v7 )
        return off_617A60(a2, 0);
    }
  }
  return 296;
}
