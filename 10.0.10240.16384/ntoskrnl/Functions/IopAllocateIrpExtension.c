// IopAllocateIrpExtension 
 
int __fastcall IopAllocateIrpExtension(int a1, int a2)
{
  _BYTE *v3; // r4
  char v4; // r6
  _BYTE *v6; // r0
  char v7; // r3
  _BYTE *v8; // r0

  v3 = *(_BYTE **)(a1 + 104);
  v4 = a2;
  if ( v3 )
  {
    if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 )
    {
      *((_WORD *)v3 + 1) |= 1 << a2;
      return (int)v3;
    }
    if ( a2 == 2 )
      JUMPOUT(0x552FAC);
    v8 = (_BYTE *)ExAllocatePoolWithTag(512, 40);
    v3 = v8;
    if ( !v8 )
      return (int)v3;
    memset(v8, 0, 40);
    *((_WORD *)v3 + 1) = (1 << v4) | 4;
    *((_DWORD *)v3 + 1) = *(_DWORD *)(a1 + 104);
    v7 = *(_BYTE *)(a1 + 39) & 0x3F;
LABEL_9:
    *(_BYTE *)(a1 + 39) = v7 | 0x40;
    *(_DWORD *)(a1 + 104) = v3;
    *(_WORD *)v3 |= 1u;
    return (int)v3;
  }
  if ( a2 != 2 )
  {
    v6 = (_BYTE *)ExAllocatePoolWithTag(512, 40);
    v3 = v6;
    if ( !v6 )
      return (int)v3;
    memset(v6, 0, 40);
    *((_WORD *)v3 + 1) = 1 << v4;
    v7 = *(_BYTE *)(a1 + 39);
    goto LABEL_9;
  }
  return sub_552FA0();
}
