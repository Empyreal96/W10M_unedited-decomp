// PopWriteImageHeader 
 
int __fastcall PopWriteImageHeader(_DWORD *a1, uint32x4_t *a2, int a3, int a4, __int64 a5)
{
  uint32x4_t *v5; // r4
  unsigned __int32 v6; // r1
  __int64 v9; // r0
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r8
  unsigned int v13; // lr
  unsigned int v14; // r9
  int v15; // r10
  int v16; // r1
  unsigned int v17; // r4
  unsigned __int64 v18; // kr18_8
  unsigned __int64 v19; // kr20_8
  unsigned __int64 v20; // kr28_8
  unsigned __int64 v21; // kr38_8
  bool v22; // cf
  int v23; // r3
  int result; // r0
  int (__fastcall *v25)(int); // r3
  uint32x4_t *v26; // [sp+8h] [bp-30h]
  int v27[10]; // [sp+10h] [bp-28h] BYREF

  v5 = a2;
  v6 = a2[4].n128_u32[0];
  v26 = v5;
  if ( v6 != a3 )
  {
    DbgPrint("MemImage->WakeCheck %lx doesn't make PoWakeCheck %lx\n", v6, a3);
    KeBugCheckEx(160, 265, 10, v5[4].n128_i32[0], a3);
  }
  LODWORD(v9) = ReadTimeStampCounter();
  qword_61EFB8 = v9 - a5;
  dword_61F164 = ((unsigned int)dword_61EEB4 >> 4) - 1;
  KeQueryPerformanceCounter(v27, 0);
  dword_61EFE0 = v27[0];
  dword_61EFE4 = v27[1];
  if ( a1[40] )
  {
    v10 = dword_61F134;
    v11 = dword_61F130;
    v13 = HIDWORD(qword_61EFC8);
    v12 = qword_61EFC8;
    v14 = unk_61EFC4;
    v15 = dword_61EFC0;
    v16 = 0;
    v17 = 0;
    do
    {
      v18 = __PAIR64__(v10, v11) + *(_QWORD *)(a1[41] + v16 + 40);
      v10 = HIDWORD(v18);
      v11 = v18;
      *(_QWORD *)&dword_61F130 = v18;
      v19 = __PAIR64__(v14, v15) + *(_QWORD *)(a1[41] + v16 + 24);
      v14 = HIDWORD(v19);
      v15 = v19;
      *(_QWORD *)&dword_61EFC0 = v19;
      v20 = __PAIR64__(v13, v12) + *(_QWORD *)(a1[41] + v16 + 64);
      v13 = HIDWORD(v20);
      v12 = v20;
      qword_61EFC8 = v20;
      ++v17;
      v16 += 112;
    }
    while ( v17 < a1[40] );
    v5 = v26;
  }
  qword_61F140 = qword_61F158;
  dword_61F150 = dword_61F160;
  dword_61F154 = 0;
  qword_61F158 += qword_61F138;
  dword_61F160 += dword_61F148;
  v5[4].n128_u64[1] = qword_61F128;
  if ( byte_61EED1 )
  {
    v21 = v5[4].n128_u64[1];
    v22 = __CFADD__((_DWORD)v21, dword_61F130);
    v23 = dword_61F134;
    v5[4].n128_u32[2] = v21 + dword_61F130;
    v5[4].n128_u32[3] = HIDWORD(v21) + v22 + v23;
  }
  memmove((int)&v5[6].n128_i32[2], (int)&qword_61EFA0, 0x1E0u);
  v5->n128_u32[0] = 1380075848;
  v5->n128_u32[2] = tcpxsum(0, v5, 0x310u);
  result = PopWriteHiberPages(a1, (int)v5, 1u, 0);
  v25 = *(int (__fastcall **)(int))(a1[27] + 52);
  if ( v25 )
    result = v25(result);
  return result;
}
