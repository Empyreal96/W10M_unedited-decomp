// ObpInsertHandleCount 
 
char *__fastcall ObpInsertHandleCount(int a1)
{
  int **v2; // r4
  int *v3; // r9
  unsigned int v4; // r8
  int v5; // r6
  int v6; // r10
  int v7; // r0
  int *v8; // r7
  int v10; // r6
  int v11; // r3
  int v12[12]; // [sp+0h] [bp-30h] BYREF

  if ( (*(_BYTE *)(a1 + 14) & 4) != 0 )
    v2 = (int **)(a1 - ObpInfoMaskToOffset[*(_BYTE *)(a1 + 14) & 7]);
  else
    v2 = 0;
  if ( !v2 )
    return 0;
  if ( (*(_BYTE *)(a1 + 15) & 0x40) != 0 )
  {
    v12[0] = 1;
    v3 = v12;
    v4 = 12;
    v12[1] = (int)*v2;
    v5 = 2;
    v6 = 20;
    v12[2] = (int)v2[1];
  }
  else
  {
    v3 = *v2;
    v10 = **v2;
    v11 = 8 * (v10 - 1);
    v5 = v10 + 4;
    v4 = v11 + 12;
    v6 = 8 * (v5 - 1) + 12;
  }
  v7 = ExAllocatePoolWithTag(1, v6, 1682465359);
  v8 = (int *)v7;
  if ( !v7 )
    return 0;
  memmove(v7, (int)v3, v4);
  if ( (*(_BYTE *)(a1 + 15) & 0x40) != 0 )
    *(_BYTE *)(a1 + 15) &= 0xBFu;
  else
    ExFreePoolWithTag((unsigned int)v3);
  memset((_BYTE *)v8 + v4, 0, v6 - v4);
  *v8 = v5;
  *v2 = v8;
  return (char *)v8 + v4;
}
