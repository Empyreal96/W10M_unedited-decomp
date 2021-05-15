// IopGetPhysicalMemoryBlock 
 
int __fastcall IopGetPhysicalMemoryBlock(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int *v4; // r4
  int v5; // r0
  __int64 *v6; // r5
  int v7; // r1
  unsigned int v8; // r2
  __int64 v9; // kr00_8
  unsigned int v10; // r6
  unsigned int v11; // r8
  __int64 v13; // kr08_8
  int v14; // r7
  unsigned int *v15; // r0
  unsigned int *v16; // r0
  __int64 *v17; // r1
  __int64 v18; // r2
  unsigned int v19[6]; // [sp+0h] [bp-18h] BYREF

  v19[0] = a4;
  v4 = 0;
  v5 = MmGetPhysicalMemoryRanges();
  v6 = (__int64 *)v5;
  if ( v5 )
  {
    v9 = *(_QWORD *)(v5 + 8);
    v7 = HIDWORD(v9);
    v8 = v9;
    v10 = 0;
    v11 = 0;
    if ( !v9 )
      return sub_54E9E8();
    do
    {
      ++v10;
      v11 += (v7 << 20) | (v8 >> 12);
      v13 = *(_QWORD *)(v5 + 16 * v10 + 8);
      v7 = HIDWORD(v13);
      v8 = v13;
    }
    while ( v13 );
    if ( !v10 )
      return sub_54E9E8();
    if ( RtlULongLongToULong(8 * v10, (unsigned __int64)v10 >> 29, v19) < 0 )
      return sub_54E9E8();
    v14 = v19[0] + 16;
    if ( v19[0] + 16 < v19[0] )
      return sub_54E9E8();
    v15 = (unsigned int *)ExAllocatePoolWithTag(512, v19[0] + 16);
    v4 = v15;
    if ( !v15 )
      return sub_54E9E8();
    memset(v15, 0, v14);
    *v4 = v10;
    v4[1] = v11;
    v16 = v4;
    v17 = v6;
    do
    {
      v16[2] = *v17 >> 12;
      v16 += 2;
      v18 = v17[1];
      v17 += 2;
      v16[1] = v18 >> 12;
      --v10;
    }
    while ( v10 );
    ExFreePoolWithTag(v6, 0);
  }
  return (int)v4;
}
