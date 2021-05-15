// VmDeleteMemoryRange 
 
int __fastcall VmDeleteMemoryRange(unsigned int a1, int a2, unsigned int a3, int a4, int a5)
{
  int v9; // r4
  int result; // r0
  _DWORD *v11; // r4
  unsigned int v12[16]; // [sp+8h] [bp-40h] BYREF

  v9 = __mrc(15, 0, 13, 0, 3);
  if ( VmValidateMemoryRangeParameters(a1) )
    return -1073741811;
  v11 = *(_DWORD **)(*(_DWORD *)((v9 & 0xFFFFFFC0) + 0x74) + 800);
  if ( !v11 )
    return -1073741688;
  memset(v12, 0, 40);
  v12[6] = (a2 << 20) | (a1 >> 12);
  v12[7] = v12[6] + a4 - 1;
  v12[8] = a3 >> 12;
  v12[9] = (a3 >> 12) + a4 - 1;
  result = VmpRemoveMemoryRange(v11, v12, a5);
  if ( result >= 0 )
    result = 0;
  return result;
}
