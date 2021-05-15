// NtAllocateReserveObject 
 
int __fastcall NtAllocateReserveObject(_BYTE *a1, _BYTE *a2, unsigned int a3, _BYTE *a4)
{
  _DWORD *v5; // r5
  char v6; // r8
  int result; // r0
  _BYTE *v8; // r4
  int v9; // [sp+0h] [bp-48h]
  int v10; // [sp+20h] [bp-28h] BYREF
  _BYTE *_24[15]; // [sp+24h] [bp-24h] BYREF

  _24[14] = a4;
  _24[13] = (_BYTE *)a3;
  _24[12] = a2;
  v5 = a1;
  _24[11] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_BYTE *)MmUserProbeAddress;
    *(_DWORD *)a1 = *(_DWORD *)a1;
  }
  if ( a3 > 1 )
    return -1073741811;
  result = ObCreateObjectEx(
             v6,
             (_DWORD *)PspMemoryReserveObjectTypes[a3],
             (int)a2,
             v6,
             v9,
             PspMemoryReserveObjectSizes[a3],
             0,
             0,
             _24,
             0);
  if ( result >= 0 )
  {
    v8 = _24[0];
    memset(_24[0], 0, PspMemoryReserveObjectSizes[a3]);
    if ( a3 == 1 )
    {
      *((_DWORD *)v8 + 3) = 4;
      *((_DWORD *)v8 + 8) = PspIoMiniPacketCallbackRoutine;
      *((_DWORD *)v8 + 9) = v8;
      v8[40] = 0;
    }
    result = ObInsertObject((int)v8, 0, 983043, 0, 0, (int)&v10);
    _24[0] = (_BYTE *)result;
    if ( result >= 0 )
      *v5 = v10;
  }
  return result;
}
