// PoAllProcessorsDeepIdle 
 
int __fastcall PoAllProcessorsDeepIdle(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r7
  int v7; // r4
  int result; // r0
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // [sp+0h] [bp-20h] BYREF
  unsigned int v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h]

  v13 = a3;
  v14 = a4;
  v12 = 0;
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v5 = *(_DWORD *)(v4 + 3768);
  v6 = *(unsigned __int16 *)(v5 + 266);
  v7 = *(_DWORD *)(v5 + 260) & ~(1 << *(_DWORD *)(v4 + 1428));
  if ( (*(_DWORD *)(v5 + 128) & ~(1 << *(_BYTE *)(v4 + 2461))) != v7 )
    return 0;
  while ( v7 )
  {
    v9 = __clz(__rbit(v7));
    v7 &= ~(1 << v9);
    v10 = (int)*(&KiProcessorBlock + v9);
    v13 = v9;
    v11 = HIBYTE(*(_DWORD *)(v10 + 3000));
    if ( v11 == 8 || v11 == 6 || v11 == 7 )
      return 0;
  }
  if ( MmGetNextNode(v6, &v12) == -1 )
    result = 1;
  else
    result = sub_54FE54();
  return result;
}
