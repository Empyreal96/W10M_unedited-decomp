// ObpGetTraceIndex 
 
int __fastcall ObpGetTraceIndex(unsigned __int16 *a1)
{
  unsigned int v1; // r4
  int v2; // r5
  int v3; // r7
  unsigned __int16 *v4; // r1
  int v5; // r2
  int v6; // t1
  unsigned int v7; // r10
  unsigned int v8; // r6
  unsigned int v9; // r9
  unsigned __int16 *v10; // r5
  int v11; // r0
  int v12; // r3
  int v13; // r4
  int v14; // r0

  v1 = 0;
  v2 = 16;
  v3 = (int)a1;
  v4 = a1;
  do
  {
    v5 = v4[1];
    v6 = *v4;
    v4 += 2;
    v1 += v6 ^ v5;
    --v2;
  }
  while ( v2 );
  v7 = v1 % 0x3FFD;
  v8 = v7;
  v9 = v7;
  v10 = (unsigned __int16 *)ObpStackTable;
  v11 = ObpStackTable + 4;
  v12 = ObpStackTable + 2 * v7;
  while ( 1 )
  {
    v13 = *(unsigned __int16 *)(v12 + 68);
    if ( v13 == 0xFFFF
      || RtlCompareMemory(
           (unsigned __int8 *)(*(_DWORD *)(v11 + 4 * ((unsigned int)v13 >> 10)) + ((v13 - (v13 >> 10 << 10)) << 6)),
           v3,
           64) == 64 )
    {
      break;
    }
    v8 = (unsigned __int16)((int)(v9 + 1) % 16381);
    if ( v8 == v7 )
      return 16381;
    v9 = (unsigned __int16)((int)(v9 + 1) % 16381);
    v12 = (int)&v10[v8];
    v11 = (int)(v10 + 2);
  }
  if ( v13 != 0xFFFF )
    return v13;
  if ( *v10 != v10[1] )
  {
LABEL_12:
    v13 = *v10;
    v10[v8 + 34] = v13;
    memmove(*(_DWORD *)&v10[2 * ((unsigned int)v13 >> 10) + 2] + ((v13 - (v13 >> 10 << 10)) << 6), v3, 0x40u);
    ++*v10;
    return v13;
  }
  v14 = ExAllocatePoolWithTag(512, 0x10000, 1951556175);
  if ( v14 )
  {
    v10 = (unsigned __int16 *)ObpStackTable;
    *(_DWORD *)(ObpStackTable + 4 * (*(unsigned __int16 *)(ObpStackTable + 2) >> 10) + 4) = v14;
    v10[1] += 1024;
    goto LABEL_12;
  }
  return 16381;
}
