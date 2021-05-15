// MmHardFaultBytesRequired 
 
int __fastcall MmHardFaultBytesRequired(int a1, int a2, unsigned __int64 a3, int a4)
{
  unsigned int v4; // r4
  _DWORD **v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r2
  int *v8; // r1
  unsigned int v9; // r2
  __int16 v11; // r3
  int v12; // t1
  int var10[8]; // [sp+8h] [bp-10h] BYREF
  unsigned __int64 varg_r2; // [sp+28h] [bp+10h]

  var10[6] = a1;
  var10[7] = a2;
  varg_r2 = a3;
  v4 = (a4 + (a3 & 0xFFF) + 4095) >> 12;
  v5 = *(_DWORD ***)(a1 + 20);
  varg_r2 = a3;
  v6 = MiOffsetToProtos(*v5, a3, (int)var10);
  v7 = v6[1];
  v8 = (int *)(v7 + 4 * var10[0]);
  v9 = v7 + 4 * v6[7];
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    if ( (unsigned int)v8 >= v9 )
      return sub_80654C();
    v12 = *v8++;
    v11 = v12;
    if ( (v12 & 2) == 0 && ((v11 & 0x400) != 0 || (v11 & 0x800) == 0 && (v11 & 0x10) != 0) )
      break;
    if ( !--v4 )
      return 0;
  }
  return 1;
}
