// MiArmWriteSimpleHardwarePde 
 
int __fastcall MiArmWriteSimpleHardwarePde(int a1, unsigned int *a2, int a3)
{
  unsigned int v3; // r2
  int result; // r0

  v3 = a3 & 0xFFFFF000 | 1;
  if ( (KeFeatureBits & 2) != 0 && (_DWORD)((_DWORD)a2 - a1) << 18 < (unsigned int)dword_63389C )
    v3 |= 4u;
  result = 4;
  do
  {
    __dmb(0xBu);
    *a2++ = v3;
    v3 = v3 & 0x3FF ^ ((v3 & 0xFFFFFC00) + 1024);
    --result;
  }
  while ( result );
  return result;
}
