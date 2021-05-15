// MiLogKernelStackEvent 
 
int *__fastcall MiLogKernelStackEvent(int a1, int a2, int a3)
{
  int v3; // r3
  int v5[4]; // [sp+8h] [bp-30h] BYREF
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  if ( a3 == 1 )
    v3 = 632;
  else
    v3 = 633;
  v5[0] = 11;
  v5[1] = 0;
  v5[2] = a1;
  v5[3] = a2;
  v6[0] = (int)v5;
  v6[1] = 0;
  v6[2] = 16;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, 0x20000001u, v3, 289413890);
}
