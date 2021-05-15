// KiTraceSetTimer2 
 
int *__fastcall KiTraceSetTimer2(int a1, int a2, int a3)
{
  __int64 v6; // r8
  char v7; // r10
  int v8; // r1
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r8
  char v12; // r0
  int v14[4]; // [sp+8h] [bp-58h] BYREF
  __int64 v15; // [sp+18h] [bp-48h]
  int v16; // [sp+20h] [bp-40h]
  int v17; // [sp+24h] [bp-3Ch]
  int v18; // [sp+28h] [bp-38h]
  char v19; // [sp+2Ch] [bp-34h]
  int var30[14]; // [sp+30h] [bp-30h] BYREF

  v14[0] = *(_DWORD *)(a1 + 40);
  v6 = *(_QWORD *)(a1 + 64);
  v7 = *(_BYTE *)(a1 + 81);
  v14[1] = *(_DWORD *)(a1 + 44);
  v14[2] = *(_DWORD *)(a1 + 48);
  v14[3] = *(_DWORD *)(a1 + 52);
  v15 = *(_QWORD *)(a1 + 56);
  KiUpdateTimer2Flags((unsigned int *)a1, a3, 0);
  if ( a3 == 1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock, var30[13]);
    }
    else
    {
      __dmb(0xBu);
      KiTimer2CollectionLock = 0;
    }
  }
  v8 = KiWaitNever;
  v9 = KiWaitAlways;
  v10 = bswap32(__ROR4__(KiWaitNever ^ v6, -(char)KiWaitNever) ^ a1) ^ KiWaitAlways;
  v11 = bswap32(__ROR4__(KiWaitNever ^ HIDWORD(v6), -(char)KiWaitNever) ^ a1) ^ KiWaitAlways;
  if ( a2 )
  {
    KiTraceCancelTimer2(a1, v10);
    v8 = KiWaitNever;
    v9 = KiWaitAlways;
  }
  v16 = -927066983 * (__ROR4__(bswap32(v9 ^ a1) ^ v10, v8) ^ v8);
  v17 = v10;
  v18 = -927066983 * (__ROR4__(bswap32(v9 ^ v11) ^ a1, v8) ^ v8);
  v12 = KiTimer2TypeFlagsToEtwFlags(v7);
  v19 = v12;
  if ( v10 )
  {
    v12 |= 1u;
    v19 = v12;
  }
  if ( v15 )
    v19 = v12 | 2;
  var30[0] = (int)v14;
  var30[1] = 0;
  var30[2] = 40;
  var30[3] = 0;
  return EtwTraceKernelEvent(var30, 1, 0x40020000u, 3944, 8395522);
}
