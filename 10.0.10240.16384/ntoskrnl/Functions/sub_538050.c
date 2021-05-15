// sub_538050 
 
void sub_538050()
{
  _DWORD *v0; // r8
  int v1; // r10

  if ( (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 736) & v1) == 0 )
  {
    *v0 = v1;
    JUMPOUT(0x495E4A);
  }
  JUMPOUT(0x495DFA);
}
