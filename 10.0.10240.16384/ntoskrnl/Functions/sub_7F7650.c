// sub_7F7650 
 
int __fastcall sub_7F7650(int a1, int a2, int a3, char a4, int a5)
{
  int v5; // r9
  unsigned int v6; // r4
  int *v7; // r7
  __int16 v8; // r3
  int v10; // r4
  int v11; // r8
  unsigned int v12; // r6
  int v13; // r0
  int v14; // r1
  int v15; // r3
  int v16; // r5
  int v17[10]; // [sp+0h] [bp-28h] BYREF

  if ( (a4 & 1) != 0 )
    v12 = v10 | 0x6000000;
  else
    v12 = (v10 | 0x4000000) & 0xFDFFFFFF;
  v5 = a2 | 1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v17[0] = 0;
  v13 = ExpAllocateHandleTableEntry(v11, v17);
  v7 = (int *)v13;
  v16 = v17[0];
  if ( v13 )
  {
    if ( a5 && (v13 = ExpSetHandleExtraInfo(v11, v17[0])) != 0 )
    {
      v13 = ExpFreeHandleTableEntry(v11, v16, (int)v7, v15);
      v16 = 0;
    }
    else
    {
      if ( *(_DWORD *)(v11 + 60) )
        v13 = ExpUpdateDebugInfo(v11, v6, v16, 1);
      v7[1] = v12;
      __dmb(0xBu);
      *v7 = v5;
    }
  }
  v8 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return ((int (__fastcall *)(int, int, int, int))v17[9])(v16, v14, v17[0], v17[1]);
}
