// RtlpInitializeHeapSegment 
 
int __fastcall RtlpInitializeHeapSegment(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8)
{
  int v10; // lr
  unsigned int v11; // r1
  int v12; // r6
  signed int v13; // r9
  int v14; // r10
  __int16 v15; // r3
  int v16; // r0
  char v17; // r3
  _DWORD *v18; // r1
  _DWORD *v19; // r3
  int v21; // r7
  int v22; // [sp+8h] [bp-28h]
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  if ( a8 - a6 > 0xFFFFF000 )
    goto LABEL_23;
  v10 = (int)(a8 - a6) / 4096;
  v11 = a7;
  v12 = ((a3 + 7) & 0xFFFFFFF8) + a2;
  v13 = (a3 + 7) & 0xFFFFFFF8;
  if ( v12 + 40 < a7 )
    goto LABEL_3;
  if ( v12 + 40 >= a8 )
LABEL_23:
    JUMPOUT(0x553F06);
  v22 = v12 - a7 + 8;
  if ( ZwAllocateVirtualMemory() < 0 )
    return sub_553EFC();
  if ( (dword_682608 & 0x20) != 0 )
    RtlpLogHeapCommit(a1, a7, v22, 3, 4096, 4);
  v10 = (int)(a8 - a6) / 4096;
  v11 = v12 + 8;
  a7 = v12 + 8;
LABEL_3:
  v14 = (int)(a8 - v11) / 4096;
  *(_WORD *)a2 = v13 >> 3;
  *(_BYTE *)(a2 + 2) = 1;
  *(_BYTE *)(a2 + 7) = 1;
  *(_BYTE *)(a2 + 3) = 0;
  v15 = *(_WORD *)(a1 + 84);
  *(_DWORD *)(a2 + 24) = a1;
  *(_DWORD *)(a2 + 28) = a6;
  *(_DWORD *)(a2 + 32) = v10;
  *(_DWORD *)(a2 + 36) = v12;
  *(_WORD *)(a2 + 4) = v15;
  *(_DWORD *)(a2 + 8) = -1114130;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 12) = a5;
  *(_DWORD *)(a2 + 40) = a6 + (v10 << 12);
  *(_DWORD *)(a1 + 484) += v10 << 12;
  *(_DWORD *)(a1 + 480) += v10 << 12;
  *(_DWORD *)(a2 + 56) = a2 + 56;
  *(_DWORD *)(a2 + 60) = a2 + 56;
  *(_BYTE *)(a2 + 6) = *(_DWORD *)(a2 + 24) != a2;
  *(_WORD *)(v12 + 4) = *(_WORD *)(a1 + 84) ^ *(_WORD *)a2;
  v16 = *(_DWORD *)(a2 + 24);
  if ( v16 == a2 )
  {
    v17 = 0;
  }
  else
  {
    v21 = HIWORD(v13) + 1;
    if ( v21 <= 0 || v21 >= 254 )
    {
      RtlpLogHeapFailure(3, v16);
      v11 = a7;
    }
    v17 = BYTE2(v13) + 1;
  }
  *(_BYTE *)(v12 + 6) = v17;
  RtlpCreateUCREntry(a1, a2, v11 - 24, v14 << 12);
  if ( *(_DWORD *)(a1 + 76) )
  {
    *(_BYTE *)(a2 + 3) = *(_BYTE *)a2 ^ *(_BYTE *)(a2 + 2) ^ *(_BYTE *)(a2 + 1);
    *(_DWORD *)a2 ^= *(_DWORD *)(a1 + 80);
  }
  if ( v22 )
    RtlpInsertFreeBlock(a1, v12, v22);
  v18 = *(_DWORD **)(a1 + 168);
  v19 = (_DWORD *)(a2 + 16);
  if ( *v18 == a1 + 164 )
  {
    *v19 = a1 + 164;
    *(_DWORD *)(a2 + 20) = v18;
    *v18 = v19;
    *(_DWORD *)(a1 + 168) = v19;
  }
  else
  {
    RtlpLogHeapFailure(12, 0);
  }
  ++*(_DWORD *)(a1 + 496);
  return 1;
}
