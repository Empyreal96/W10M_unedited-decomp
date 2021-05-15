// MiAllocateMemoryListLocks 
 
_BYTE *MiAllocateMemoryListLocks()
{
  int v0; // r3
  int v1; // r5
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v0 = (unsigned __int16)KeNumberNodes + 2 * dword_633818 + 27;
  v1 = 3 * v0;
  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 12 * v0, 1632398669);
  v3 = v2;
  if ( v2 )
    memset(v2, 0, 4 * v1);
  return v3;
}
