// EtwpUpdatePmcCounters 
 
int __fastcall EtwpUpdatePmcCounters(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r8
  int v6; // r6
  int v7; // r4
  int v8; // r5
  int v9; // r3
  unsigned int i; // r2
  unsigned int v11; // r9
  int j; // r6
  unsigned int k; // r6
  int v15; // [sp+0h] [bp-28h]
  int varg_r1; // [sp+34h] [bp+Ch]

  varg_r1 = a2;
  v4 = a3;
  v6 = a1;
  v15 = a1;
  if ( !a3 || a3 > 4 || *(_DWORD *)(a1 + 224) == 1 )
    return -1073741811;
  if ( *(_DWORD *)(a1 + 628) || (v7 = EtwpAllocatePmcData(a1, a2)) == 0 )
  {
    v8 = *(_DWORD *)(v6 + 628);
    v9 = *(_DWORD *)(v8 + 28);
    __dmb(0xBu);
    if ( v9 )
    {
      v7 = -1073741053;
    }
    else
    {
      for ( i = 0; i < v4; ++i )
        *(_DWORD *)(v8 + 4 * i) = *(_DWORD *)(a2 + 4 * i);
      v7 = 0;
      v11 = 0;
      for ( j = v8 + 32; v11 < KeNumberProcessors_0; j += 4 )
      {
        v7 = off_617A90(v11, v8, v4, j);
        if ( v7 )
          break;
        ++v11;
      }
      if ( v7 )
      {
        for ( k = 0; k < v11; ++k )
        {
          ((void (__cdecl *)())off_617A98)();
          *(_DWORD *)(v8 + 32) = 0;
          v8 += 4;
        }
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)(v8 + 28) = v4;
        __dmb(0xFu);
        *(_DWORD *)(v15 + 608) |= 0x800u;
      }
    }
  }
  return v7;
}
