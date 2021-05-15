// MmLogQueryCombineStats 
 
__int16 *__fastcall MmLogQueryCombineStats(int a1, char *a2)
{
  char *v2; // r4
  __int16 *result; // r0
  int v4; // r3
  int v5; // r2
  char v6[48]; // [sp+24h] [bp-30h] BYREF

  v2 = a2;
  if ( !a2 )
    v2 = v6;
  result = MiSystemPartition;
  *(_DWORD *)v2 = *(_DWORD *)v2 & 0xFFFFFFC0 | 1;
  *((_DWORD *)v2 + 1) = dword_6404A8;
  *((_QWORD *)v2 + 1) = qword_640490 + qword_640498;
  *((_DWORD *)v2 + 4) = dword_6404A0;
  *((_DWORD *)v2 + 5) = dword_6404A4;
  v4 = dword_6404AC;
  *((_DWORD *)v2 + 6) = dword_6404AC;
  v5 = dword_6404B0;
  *((_DWORD *)v2 + 7) = dword_6404B0;
  if ( v4 > v5 )
    *((_DWORD *)v2 + 6) = v5;
  if ( v2 == v6 )
    result = (__int16 *)sub_81C070();
  return result;
}
