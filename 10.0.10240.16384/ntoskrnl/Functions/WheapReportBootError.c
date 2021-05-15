// WheapReportBootError 
 
int __fastcall WheapReportBootError(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r4
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r7
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1388);
  v6 = WheapGetErrorSource(*(_DWORD *)(v5 + 4), *(_DWORD *)(a1 + 24));
  v7 = v6;
  if ( !v6 )
    return 0;
  __dmb(0xBu);
  v9 = (unsigned int *)(v6 + 16);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  v13[0] = 0;
  v11 = WheapAllocErrorRecord(v6, v13);
  v12 = v11;
  if ( !v11 )
    return 0;
  WheapFillOutErrorRecord(v13[0] - 28, a1, v7, v11 + 28);
  WheapWorkQueueAddItem(*(_DWORD *)(v5 + 8), v12);
  return 1;
}
