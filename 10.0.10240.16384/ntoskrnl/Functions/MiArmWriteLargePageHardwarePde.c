// MiArmWriteLargePageHardwarePde 
 
int __fastcall MiArmWriteLargePageHardwarePde(int result, unsigned int *a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r2
  int varg_r0; // [sp+10h] [bp+8h]
  unsigned int *varg_r1; // [sp+14h] [bp+Ch]

  varg_r0 = result;
  varg_r1 = a2;
  v4 = a3 & 0xFFF0000E | ((a3 & 0xFF0) << 6) | 2;
  if ( (a3 & 1) != 0 )
    v4 = a3 & 0xFFF0000E | ((a3 & 0xFF0) << 6) | 0x12;
  if ( (KeFeatureBits & 2) != 0 && (_DWORD)((_DWORD)a2 - result) << 18 < (unsigned int)dword_63389C )
    v4 |= 1u;
  v5 = 4;
  do
  {
    __dmb(0xBu);
    *a2++ = v4;
    v4 = v4 & 0xFFFFF ^ ((v4 & 0xFFF00000) + 0x100000);
    --v5;
  }
  while ( v5 );
  return result;
}
