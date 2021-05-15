// sub_96E798 
 
void sub_96E798(int a1, int a2, int a3, int a4, ...)
{
  _DWORD *v4; // r5
  int v5; // r7
  int v6; // r10
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v7 = *(_DWORD *)(v5 + 88);
  v8 = __clz(v7);
  if ( 1 != (unsigned __int8)(v8 >> 5) )
    v7 = 1 << (31 - v8);
  *(_DWORD *)(v5 + 88) = v7;
  if ( v7 )
  {
    *(_DWORD *)(v5 + 88) = v7 - 1;
    v9 = v4[6] | 0x80;
  }
  else
  {
    v9 = v4[6];
  }
  if ( MmIsVerifierEnabled((int *)va) >= 0 )
  {
    LOBYTE(v9) = v9 | 1;
    if ( KernelVerifier == 1 )
      LOBYTE(v9) = v9 | 2;
  }
  if ( v4[33] )
    v4[34] = 1;
  if ( (v9 & 1) != 0 )
  {
    MmLargePageDriverBufferLength = v6;
    v4[34] = 1;
  }
  JUMPOUT(0x9612A0);
}
