// MiFindDriverNonPagedSections 
 
int __fastcall MiFindDriverNonPagedSections(int a1, unsigned int *a2, unsigned int *a3, _DWORD *a4)
{
  unsigned int *v4; // r5
  int v5; // r10
  unsigned int v7; // r6
  unsigned int v10; // r0
  unsigned int v11; // r4
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = (int)a4;
  v4 = *(unsigned int **)(a1 + 136);
  v5 = *(_DWORD *)(a1 + 24);
  v7 = *a2;
  if ( *a2 == *v4 )
    return -1073741275;
  v10 = RtlFindSetBits(v4, 1u, *a2);
  v11 = v10;
  if ( v10 < v7 || v10 == -1 )
    return -1073741275;
  if ( RtlFindNextForwardRunClear((int)v4, v10, (int)v16) )
    v12 = v16[0];
  else
    v12 = *v4;
  v13 = v12 - v11;
  *a2 = v12;
  v14 = (((v5 + (v11 << 12)) >> 10) & 0x3FFFFC) - 0x40000000;
  *a3 = v14;
  *a4 = v14 + 4 * v13 - 4;
  return 0;
}
