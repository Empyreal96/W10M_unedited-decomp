// SepCaptureHandles 
 
int __fastcall SepCaptureHandles(unsigned int a1, int a2, int *a3, int a4)
{
  int *v4; // r6
  unsigned int v7; // r4
  int v9; // r0
  unsigned int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v4 = a3;
  v7 = 0;
  *a3 = 0;
  if ( a1 > 0xA )
    return -1073741585;
  if ( !a1 )
    return 0;
  v9 = ExAllocatePoolWithTag(1, 4 * a1, 1850238291);
  if ( !v9 )
    return -1073741670;
  while ( v7 < a1 )
  {
    *(_DWORD *)(v9 + 4 * v7) = *(_DWORD *)(a2 + 4 * v7);
    ++v7;
  }
  *v4 = v9;
  return 0;
}
