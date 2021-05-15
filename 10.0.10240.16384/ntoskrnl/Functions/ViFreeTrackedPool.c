// ViFreeTrackedPool 
 
unsigned int __fastcall ViFreeTrackedPool(int a1, int a2, int a3, int a4)
{
  char v4; // r9
  int v5; // r7
  int v7; // r3
  unsigned int *v8; // r6
  unsigned int v9; // r5
  int v10; // r2
  int v11; // r3
  int v12; // r6
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int result; // r0
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1

  v4 = a3;
  v5 = a2;
  if ( a4 == 1 )
  {
    v7 = a1 & 0xFFFFF000;
    if ( (a1 & 0xFFF) != 0 )
      v8 = (unsigned int *)(v7 + 8);
    else
      v8 = (unsigned int *)(v7 + 4084);
  }
  else if ( (a1 & 0xFFF) != 0 && (a3 = a1 - 8, v5 = a2 - 8, (*(_WORD *)(a1 - 6) & 0x1000) != 0) )
  {
    v7 = a3 + 8 * (*(_WORD *)(a1 - 6) & 0x1FF);
    v8 = (unsigned int *)(v7 - 8);
  }
  else
  {
    v7 = a1 + v5;
    v8 = (unsigned int *)(a1 + v5 - 4);
  }
  v9 = *v8;
  if ( (*v8 & 3) != 0 || !MiIsAddressValid(*v8, 1, (unsigned __int8)a3, v7) )
    VerifierBugCheckIfAppropriate(196, 314, a1);
  v10 = *(_DWORD *)((v9 & 0xFFFFF000) + 8);
  v11 = 556929861;
  if ( v10 != 556929861 )
    VerifierBugCheckIfAppropriate(196, 315, a1);
  v12 = *(_DWORD *)((v9 & 0xFFFFF000) + 4);
  if ( (v12 & 3) != 0 || !MiIsAddressValid(v12 + 20, 1, (unsigned __int8)v10, v11) )
    VerifierBugCheckIfAppropriate(196, 316, a1);
  if ( *(_DWORD *)(v12 + 20) != -1737090752 )
    VerifierBugCheckIfAppropriate(196, 317, a1);
  if ( *(_DWORD *)v9 != a1 )
    VerifierBugCheckIfAppropriate(196, 318, a1);
  if ( *(_DWORD *)(v9 + 8) != v5 )
    VerifierBugCheckIfAppropriate(196, 319, a1);
  *(_DWORD *)(v9 + 8) |= 1u;
  RtlpInterlockedPushEntrySList((unsigned __int64 *)(v12 + 32), (_DWORD *)v9);
  if ( (v4 & 1) != 0 )
  {
    v13 = (unsigned int *)(v12 + 56);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 - v5, v13) );
    v15 = (unsigned int *)(v12 + 40);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 - 1, v15) );
    do
      result = __ldrex(&dword_620DD0);
    while ( __strex(result - v5, &dword_620DD0) );
    do
      v18 = __ldrex(&dword_620DC0);
    while ( __strex(v18 - 1, &dword_620DC0) );
  }
  else
  {
    v19 = (unsigned int *)(v12 + 60);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 - v5, v19) );
    v21 = (unsigned int *)(v12 + 44);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 - 1, v21) );
    do
      result = __ldrex(&dword_620DD4);
    while ( __strex(result - v5, &dword_620DD4) );
    do
      v23 = __ldrex(&dword_620DC4);
    while ( __strex(v23 - 1, &dword_620DC4) );
  }
  return result;
}
