// KdpSetCommonState 
 
int __fastcall KdpSetCommonState(int a1, int a2, int a3)
{
  unsigned __int16 v5; // r0
  unsigned int v6; // r3
  int v7; // r4
  int v8; // r6
  int result; // r0
  int v10[6]; // [sp+10h] [bp-18h] BYREF

  *(_DWORD *)a3 = a1;
  *(_WORD *)(a3 + 4) = KeProcessorLevel;
  v5 = KeGetCurrentProcessorNumberEx(0);
  *(_WORD *)(a3 + 6) = v5;
  v6 = KeNumberProcessors_0;
  *(_DWORD *)(a3 + 8) = KeNumberProcessors_0;
  if ( v6 <= v5 )
    *(_DWORD *)(a3 + 8) = v5 + 1;
  *(_QWORD *)(a3 + 16) = (int)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v7 = *(_DWORD *)(a2 + 64);
  *(_QWORD *)(a3 + 24) = v7;
  memset((_BYTE *)(a3 + 192), 0, 48);
  KdpCopyMemoryChunks(v7, 0, a3 + 200, 16, 0, 4, v10);
  v8 = v10[0];
  *(_DWORD *)(a3 + 196) = LOWORD(v10[0]);
  result = KdpDeleteBreakpointRange(v7, v8 + v7 - 1);
  if ( result )
    result = sub_528008();
  return result;
}
