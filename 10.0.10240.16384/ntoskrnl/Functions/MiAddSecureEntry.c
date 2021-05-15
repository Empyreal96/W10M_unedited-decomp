// MiAddSecureEntry 
 
int __fastcall MiAddSecureEntry(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v9; // r0
  _DWORD *v10; // r4
  int v11; // r3

  if ( (*(_DWORD *)(a1 + 28) & 0x4000) != 0 && (a5 == 1 || MiLocateExclusiveSecure(a1)) )
    return 0;
  v9 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1699966285);
  v10 = v9;
  if ( !v9 )
    return 0;
  v9[1] = 2;
  v9[2] = a2;
  v9[3] = a3;
  if ( (a4 & 1) != 0 )
  {
    v11 = a2 | 8;
  }
  else if ( (a4 & 4) != 0 )
  {
    v11 = a2 | 0xA;
  }
  else
  {
    if ( (a4 & 2) == 0 )
      goto LABEL_6;
    v11 = a2 | 9;
  }
  v9[2] = v11;
LABEL_6:
  if ( a5 == 1 )
    return sub_80308C();
  if ( a4 < 0 )
    v9[2] |= 4u;
  if ( (a4 & 0x40000000) != 0 )
    v9[2] |= 0x10u;
  MiInsertVadEvent(a1, v9, 1);
  *(_DWORD *)(a1 + 28) |= 0x4000u;
  return (int)v10;
}
