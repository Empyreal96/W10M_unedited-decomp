// HvpMapEntryGetBinAddress 
 
unsigned int __fastcall HvpMapEntryGetBinAddress(int a1, _DWORD *a2, char *a3, _DWORD *a4)
{
  _DWORD *v4; // r6
  char v6; // r0
  int v7; // r3
  unsigned int v9; // r0
  unsigned int v10; // r1

  v4 = a2 + 3;
  if ( (a2[3] & 1) != 0 )
  {
    v6 = 0;
    v7 = a2[1];
LABEL_3:
    *a3 = v6;
    return v7 & 0xFFFFFFF0;
  }
  __pld(v4);
  v9 = *v4 & 0xFFFFFFFE;
  do
    v10 = __ldrex(v4);
  while ( v10 == v9 && __strex(v9 + 2, v4) );
  __dmb(0xBu);
  if ( v10 == v9 )
  {
    v6 = 1;
    *a4 = -1;
    v7 = a2[2];
    goto LABEL_3;
  }
  return sub_52E4F0();
}
