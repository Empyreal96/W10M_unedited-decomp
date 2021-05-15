// RtlpAllocateHeapInternal 
 
int __fastcall RtlpAllocateHeapInternal(int a1, unsigned int a2, int a3)
{
  int v4; // r1
  unsigned int v5; // r2
  int v8; // r9
  int v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r5
  int v13; // r0
  int v14; // r0
  int v15; // r1
  unsigned int v16; // [sp+8h] [bp-30h] BYREF
  int v17; // [sp+Ch] [bp-2Ch]
  int v18; // [sp+10h] [bp-28h]
  int v19; // [sp+14h] [bp-24h]

  v4 = *(_DWORD *)(a1 + 68) | a3;
  v5 = 0;
  v16 = 0;
  v17 = 0;
  v18 = v4;
  if ( a2 > 0x7FFFFFFF )
    return sub_528584();
  v8 = *(_DWORD *)(a1 + 88);
  v9 = -1073741823;
  if ( v8 )
  {
    if ( (v4 & 0x3C000102) != 0 )
    {
      v8 = 0;
    }
    else
    {
      if ( (_WORD)v8 == 1 )
      {
        v13 = MEMORY[0](a1, 0, 1, &v16);
        v5 = v16;
        v9 = -1073741823;
        v4 = v18;
      }
      else
      {
        v13 = -1073741823;
      }
      if ( v13 < 0 )
        JUMPOUT(0x528586);
      v16 = ((v5 + 7) & 0xFFFFFFF8) + 8;
      a2 += v16;
    }
  }
  if ( a2 )
    v10 = a2;
  else
    v10 = 1;
  v11 = RtlpAllocateHeap(a1, v4 | 2, a2, (v10 + 15) & 0xFFFFFFF8);
  v12 = v11;
  if ( !v11 )
LABEL_29:
    JUMPOUT(0x528588);
  if ( v8 )
  {
    a2 -= v16;
    v19 = v11;
    v14 = RtlpSetupExtendedBlock(a1, v18, v11);
    v12 = v14;
    if ( (_WORD)v8 == 1 )
      v9 = MEMORY[0](a1, v14, 2, v19);
    if ( v9 < 0 )
    {
      RtlFreeHeap(a1, 0, v12);
      goto LABEL_29;
    }
  }
  if ( (dword_682608 & 0x20) != 0 && v17 != 5 )
  {
    if ( !v12 )
      goto LABEL_28;
    v15 = v12 - 8;
    if ( *(_BYTE *)(v12 - 1) == 5 )
      v15 -= 8 * *(unsigned __int8 *)(v12 - 2);
    if ( ((*(unsigned __int8 *)(v15 + 2) ^ *(unsigned __int8 *)(a1 + 82) & (*(_DWORD *)(a1 + 76) >> 17)) & 8) == 0 )
LABEL_28:
      RtlpLogHeapAllocateEvent(a1, v12, a2, v17);
  }
  return v12;
}
