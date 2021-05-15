// CcPerfLogScheduleReadAhead 
 
int *__fastcall CcPerfLogScheduleReadAhead(int a1, int a2, __int64 *a3, unsigned int a4, unsigned int a5, char a6, int a7)
{
  __int64 v11; // r4
  __int64 v12; // r1
  unsigned int v13; // r2
  int v15[4]; // [sp+8h] [bp-70h] BYREF
  __int64 v16[12]; // [sp+18h] [bp-60h] BYREF

  v11 = 0i64;
  memset(v16, 0, 64);
  if ( a2 )
  {
    v11 = *(_QWORD *)(a2 + 20);
    LODWORD(v11) = *(_DWORD *)(v11 + 4);
    HIDWORD(v16[0]) = *(_DWORD *)(a2 + 12);
  }
  v12 = *a3;
  LODWORD(v16[0]) = a1;
  v16[2] = __PAIR64__(a5, a4);
  v16[1] = v12;
  v13 = HIDWORD(v16[7]) & 0xFFFFFFFE | (a7 == 1);
  HIDWORD(v16[7]) = v13;
  if ( HIDWORD(v11) )
  {
    LODWORD(v16[3]) = *(_DWORD *)(HIDWORD(v11) + 52);
    v16[4] = *(_QWORD *)(HIDWORD(v11) + 56);
    v16[5] = *(_QWORD *)(HIDWORD(v11) + 64);
    HIDWORD(v16[7]) = ((unsigned __int8)v13 ^ (unsigned __int8)(*(_DWORD *)HIDWORD(v11) >> 15)) & 2 ^ v13;
    HIDWORD(v16[6]) = *(_DWORD *)(HIDWORD(v11) + 48);
  }
  if ( (_DWORD)v11 )
    LODWORD(v16[7]) = *(_DWORD *)(v11 + 96);
  LOBYTE(v16[6]) = a6;
  v15[0] = (int)v16;
  v15[1] = 0;
  v15[2] = 64;
  v15[3] = 0;
  return EtwTraceKernelEvent(v15, 1, 0x80020000, 5644, 4200706);
}
