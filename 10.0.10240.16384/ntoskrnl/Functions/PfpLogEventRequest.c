// PfpLogEventRequest 
 
int __fastcall PfpLogEventRequest(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r4
  _DWORD *v9; // r0
  int v10; // r3
  int v11; // r0
  unsigned int v12; // r0
  int v13; // r4
  int v14; // r5
  unsigned int v16; // [sp+0h] [bp-20h] BYREF
  unsigned int v17; // [sp+4h] [bp-1Ch]
  int v18; // [sp+8h] [bp-18h]

  v16 = a2;
  v17 = a3;
  v18 = a4;
  v5 = *a1 & 0x1F;
  if ( v5 == 2 || v5 == 3 )
  {
    v6 = dword_643B0C;
    v7 = dword_643B10;
    v8 = dword_643B14;
    v9 = (_DWORD *)a1[1];
    *v9 = dword_643B08;
    v9[1] = v6;
    v9[2] = v7;
    v9[3] = v8;
    v10 = dword_643B1C;
    v9[4] = dword_643B18;
    v9[5] = v10;
    if ( (*a1 & 0x1F) == 2 )
      v11 = (unsigned __int8)v9[6] >> 5;
    else
      v11 = MmGetDefaultPagePriority();
    PfTSetTracingPriority(v11);
  }
  if ( (*a1 & 0x1F) == 27 && (*(_DWORD *)(a1[1] + 4) & 3) == 1 )
  {
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&dword_643B6C);
    while ( __strex(v12 & 0xFFFFFFFE, (unsigned int *)&dword_643B6C) );
    __dmb(0xBu);
  }
  KeQueryTickCount((int *)&v16);
  v13 = (__int64)(((v16 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                + ((v17 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10;
  v14 = dword_63728C;
  if ( (*a1 & 0x20) != 0 )
  {
    v16 = ((*a1 >> 5) & 2) != 0;
    MmIssueMemoryListCommand((int *)&v16, 4u, 0, v16);
    PfGenerateTrace(&dword_643940, 0);
  }
  return PfLogEvent(*a1 & 0x1F, v13 + v14, a1[1], *a1 >> 7);
}
