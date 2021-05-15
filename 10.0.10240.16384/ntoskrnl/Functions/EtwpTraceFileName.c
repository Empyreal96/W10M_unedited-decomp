// EtwpTraceFileName 
 
int __fastcall EtwpTraceFileName(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v5; // r3
  int v6; // r1
  __int16 v8; // [sp+8h] [bp-50h] BYREF
  int v9; // [sp+10h] [bp-48h] BYREF
  int v10[16]; // [sp+18h] [bp-40h] BYREF

  v8 = 0;
  v5 = *a2;
  if ( v5 > 0x2000 )
    v5 = 0x2000;
  v10[6] = v5;
  v10[7] = 0;
  v10[8] = (int)&v8;
  v10[9] = 0;
  v10[10] = 2;
  v10[11] = 0;
  v10[1] = 0;
  v6 = *((_DWORD *)a2 + 1);
  v9 = a1;
  v10[2] = 4;
  v10[0] = (int)&v9;
  v10[3] = 0;
  v10[4] = v6;
  v10[5] = 0;
  if ( (dword_61AD40 & 0x200) != 0 )
    return sub_546F08();
  if ( a4 == 1060 )
    return EtwpLogKernelEvent(v10, a3, 3, 1060, 4200450);
  return EtwTraceKernelEvent(v10, 3, 512, a4, 4200450);
}
