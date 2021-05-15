// StEtaIoComplete 
 
int __fastcall StEtaIoComplete(int result, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r1
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned __int64 v9; // [sp+0h] [bp-18h] BYREF
  int v10; // [sp+8h] [bp-10h]

  v9 = __PAIR64__(a3, a2);
  v10 = a4;
  v4 = *(_DWORD *)(result + 4 * a3 + 16);
  v5 = result;
  while ( *(_DWORD *)v4 < a2 )
    v4 += 32;
  if ( a4 == *(_DWORD *)(v4 + 24) )
  {
    KeQueryPerformanceCounter(&v9, 0);
    v6 = *(_DWORD *)(v4 + 8);
    *(_DWORD *)(v4 + 24) |= 1u;
    result = (7 * __PAIR64__(*(_DWORD *)(v4 + 12), v6) - *(_QWORD *)(v4 + 16)) >> 32;
    *(_QWORD *)(v4 + 8) = (7 * __PAIR64__(*(_DWORD *)(v4 + 12), v6) - *(_QWORD *)(v4 + 16) + v9) >> 3;
  }
  __dmb(0xBu);
  v7 = (unsigned int *)(v5 + 8);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 - 1, v7) );
  __dmb(0xBu);
  return result;
}
