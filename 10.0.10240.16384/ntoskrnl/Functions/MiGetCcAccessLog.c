// MiGetCcAccessLog 
 
_DWORD *__fastcall MiGetCcAccessLog(int a1, int a2)
{
  _DWORD *v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r6
  int v8; // r3
  __int64 v9; // kr08_8
  int v10; // r5
  _DWORD *v11; // r2

  if ( !dword_634480 )
    goto LABEL_8;
  do
    v4 = (_DWORD *)__ldrex((unsigned int *)&dword_634480);
  while ( __strex(0, (unsigned int *)&dword_634480) );
  if ( !v4 )
    goto LABEL_8;
  v5 = v4[9];
  v6 = v4[8] + 8 * a2;
  if ( v6 > v5 || (v6 = (v4[10] - v5) & 0xFFFFFFFC, v6 >= 2048) )
  {
    MiQueuePageAccessLog(v4, 0, v5, v6);
    v4 = 0;
  }
  if ( !v4 )
  {
LABEL_8:
    v7 = (8 * a2 + 4159) & 0xFFFFF000;
    v4 = (_DWORD *)ExAllocatePoolWithTag(512, v7, 1665232205);
    if ( !v4 )
      return 0;
    MiInitializePageAccessLogging((int)dword_634E00, v4, v7, v8);
    v4[1] = 1;
  }
  v9 = *(_QWORD *)(v4 + 9);
  v10 = *(_DWORD *)(a1 + 12);
  v11 = (_DWORD *)(v9 + 4);
  if ( (unsigned int)(v9 + 4) >= HIDWORD(v9) )
    goto LABEL_15;
  do
  {
    if ( *v11 == v10 )
      break;
    ++v11;
  }
  while ( (unsigned int)v11 < HIDWORD(v9) );
  if ( (unsigned int)v11 >= HIDWORD(v9) )
  {
LABEL_15:
    v4[9] = v9 - 4;
    *(_DWORD *)v9 = v10;
    v11 = (_DWORD *)v9;
  }
  v4[2] = (HIDWORD(v9) - (int)v11) >> 2;
  v4[6] = v4[8];
  return v4;
}
