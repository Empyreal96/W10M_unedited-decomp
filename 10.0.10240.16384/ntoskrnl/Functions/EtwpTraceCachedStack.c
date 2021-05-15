// EtwpTraceCachedStack 
 
int EtwpTraceCachedStack(int a1, int a2, ...)
{
  int v2; // r5
  int v4; // r7
  unsigned int v5; // r4
  int *v6; // r2
  int v7; // r1
  int varA8[43]; // [sp+8h] [bp-A8h] BYREF
  int varg_r2; // [sp+C0h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+C0h] [bp+10h]
  va_list varg_r3; // [sp+C4h] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  va_copy((va_list)varA8, varg_r2a);
  varA8[1] = 0;
  v2 = varg_r2;
  varA8[2] = 4;
  v4 = 1;
  varA8[3] = 0;
  do
  {
    v5 = *(_DWORD *)(v2 + 20);
    if ( v5 >= 0x20 )
      v5 = 32;
    v6 = &varA8[4 * v4];
    *v6 = v2 + 24;
    v6[1] = 0;
    v6[2] = 4 * v5;
    v6[3] = 0;
    v2 = *(_DWORD *)(v2 + 8);
    v4 = (unsigned __int16)(v4 + 1);
  }
  while ( v2 );
  v7 = 4194306;
  if ( a2 != 6180 )
    v7 = 4195842;
  return EtwpLogKernelEvent(varA8, a1, v4, a2, v7);
}
