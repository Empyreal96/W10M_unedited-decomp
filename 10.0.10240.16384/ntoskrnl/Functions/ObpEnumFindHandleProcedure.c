// ObpEnumFindHandleProcedure 
 
int __fastcall ObpEnumFindHandleProcedure(int a1, unsigned int *a2, int a3, int *a4)
{
  unsigned int v6; // r7
  int v7; // r3
  unsigned int v9; // lr
  int v10; // r4
  int v11; // r0
  _DWORD *v12; // r1
  unsigned int v13; // r2
  char v14; // r3
  unsigned int v15; // r1

  v6 = *a2;
  v7 = *a4;
  v9 = *a2 & 0xFFFFFFF8;
  if ( v7 && v7 != v9 )
    goto LABEL_3;
  v11 = a4[1];
  if ( v11 )
  {
    if ( v11 != ObTypeIndexTable[*(unsigned __int8 *)(v9 + 12) ^ BYTE1(v9) ^ (unsigned __int8)ObHeaderCookie] )
      goto LABEL_3;
  }
  v12 = (_DWORD *)a4[2];
  if ( !v12 )
    goto LABEL_13;
  v13 = a2[1];
  v14 = v6 & 6;
  if ( (v13 & 0x4000000) != 0 )
    v14 |= 8u;
  if ( (v13 & 0x2000000) != 0 )
    v14 |= 1u;
  if ( *v12 == (v14 & 7) && v12[1] == (v13 & 0x1FFFFFF) )
LABEL_13:
    v10 = 1;
  else
LABEL_3:
    v10 = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex(a2);
  while ( __strex(v15 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  return v10;
}
