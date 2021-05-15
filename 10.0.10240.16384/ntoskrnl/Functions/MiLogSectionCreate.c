// MiLogSectionCreate 
 
int *__fastcall MiLogSectionCreate(int *a1, int a2)
{
  int v2; // r5
  int v3; // r4
  int v4; // r6
  int *result; // r0
  int v6; // r0
  int v7[2]; // [sp+8h] [bp-30h] BYREF
  int v8; // [sp+10h] [bp-28h]
  int *v9; // [sp+18h] [bp-20h] BYREF
  int v10; // [sp+1Ch] [bp-1Ch]
  int v11; // [sp+20h] [bp-18h]
  int v12; // [sp+24h] [bp-14h]

  v2 = *a1;
  v3 = *(_DWORD *)(*a1 + 40);
  v4 = *(_DWORD *)(*a1 + 4);
  v7[0] = v3;
  v7[1] = v3 + 4 * v4;
  if ( a2 == 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v2 + 32) + 176);
    v9 = v7;
    v10 = 0;
    v11 = 12;
    v12 = 0;
    result = EtwTraceKernelEvent((int *)&v9, 1, 0x20400001u, 585, 4200706);
    if ( (*(_WORD *)(v2 + 8) & 0x1000) != 0 && (dword_682604 & 1) != 0 )
    {
      v6 = MiInitPerfMemoryFlags(1, 2);
      result = MiLogPerfMemoryRangeEvent(v3, 0, v6, v4);
    }
  }
  else
  {
    v8 = -1;
    v9 = v7;
    v10 = 0;
    v11 = 12;
    v12 = 0;
    result = EtwTraceKernelEvent((int *)&v9, 1, 0x20400001u, 591, 20977922);
  }
  return result;
}
