// HvpMapEntryGetBlockAddress 
 
int __fastcall HvpMapEntryGetBlockAddress(int a1, int *a2, char *a3, _DWORD *a4)
{
  _DWORD *v4; // r6
  char v7; // r0
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r3
  unsigned int v12; // r0
  unsigned int v13; // r1

  v4 = a2 + 3;
  if ( (a2[3] & 1) != 0 )
  {
    v7 = 0;
    v8 = a2[1];
LABEL_3:
    v9 = v8 & 0xFFFFFFF0;
    v10 = *a2;
    *a3 = v7;
    return v10 + v9;
  }
  __pld(v4);
  v12 = *v4 & 0xFFFFFFFE;
  do
    v13 = __ldrex(v4);
  while ( v13 == v12 && __strex(v12 + 2, v4) );
  __dmb(0xBu);
  if ( v13 == v12 )
  {
    v7 = 1;
    *a4 = -1;
    v8 = a2[2];
    goto LABEL_3;
  }
  return sub_50C47C();
}
