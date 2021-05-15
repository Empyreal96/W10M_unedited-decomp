// IopPortBacktrackAllocation 
 
int __fastcall IopPortBacktrackAllocation(int a1, int a2)
{
  __int64 v3; // r6
  int v5; // r9
  bool v6; // zf
  int v7; // r1
  _DWORD *v8; // r0
  int v10; // [sp+8h] [bp-30h]
  __int64 i; // [sp+10h] [bp-28h] BYREF

  v3 = *(_QWORD *)a2;
  for ( i = *(_QWORD *)a2; ; RtlDeleteRange(v8, *(_DWORD *)(v5 + 20), i, HIDWORD(i), *(_QWORD *)(v5 + 16) + i - 1, v10) )
  {
    v5 = *(_DWORD *)(a2 + 36);
    v6 = IopPortGetNextAlias(*(_DWORD *)(v5 + 36), a2, v3, HIDWORD(v3), &i) == 0;
    v8 = *(_DWORD **)(a1 + 24);
    v10 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16);
    if ( v6 )
      break;
    v3 = i;
  }
  return RtlDeleteRange(v8, v7, *(_DWORD *)a2, *(_DWORD *)(a2 + 4), *(_QWORD *)(a2 + 8), v10);
}
