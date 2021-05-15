// MiAddWorkingSetPage 
 
int __fastcall MiAddWorkingSetPage(int a1)
{
  unsigned int *v1; // r8
  unsigned int v2; // r5
  unsigned int v3; // r10
  unsigned int v4; // r2
  unsigned int *v5; // r9
  unsigned int v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r10
  unsigned int v10; // r7
  unsigned int *v11; // r1
  unsigned int v12; // lr
  unsigned int v13; // r0
  int v14; // r4

  v1 = *(unsigned int **)(a1 + 92);
  v2 = v1[9];
  v3 = v1[63];
  if ( !v2 )
    __brkdiv0();
  v4 = v1[4];
  if ( v4 > 1048574 - 0x1000 / v2 )
    return 0;
  v5 = (unsigned int *)(((((v3 + v4 * v2) >> 10) & 0xFFFFFFFC) + 4) << 10);
  if ( (unsigned int)(v5 + 1024) >= v1[13] || !MiMapNewWorkingSetPage(a1, (unsigned int)v5) )
    return 0;
  if ( !v2 )
    __brkdiv0();
  v6 = ((unsigned int)v5 - v3 + 4096) / v2;
  v7 = v1[4];
  v8 = v7 + 1;
  if ( *v1 != 0xFFFFF )
    return sub_51044C(v6);
  v10 = 0x1000 / v2 + v8;
  v1[4] = v6 - 1;
  v11 = v5;
  LOBYTE(v12) = 0;
  v13 = v7 + 1;
  if ( v8 < v10 )
  {
    v14 = (v7 + 2) << 12;
    do
    {
      v12 = v14 & 0xFFFFF000 | (2 * (((_WORD)v13 - 1) & 0x7FF)) | v12 & 1;
      *v11 = v12;
      ++v13;
      v11 = (unsigned int *)((char *)v11 + v2);
      v14 += 4096;
    }
    while ( v13 < v10 );
  }
  *(unsigned int *)((char *)v11 - v2) = *(unsigned int *)((char *)v11 - v2) & 0xFFF | 0xFFFFF000;
  *v5 |= 0xFFEu;
  *v1 = v8;
  return 1;
}
