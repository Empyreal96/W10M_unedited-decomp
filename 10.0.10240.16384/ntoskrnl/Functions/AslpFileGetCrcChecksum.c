// AslpFileGetCrcChecksum 
 
int __fastcall AslpFileGetCrcChecksum(int *a1, _DWORD *a2)
{
  int v3; // r4
  unsigned int v4; // r2
  int v5; // r1
  int v6; // r0
  int v7; // r1

  v3 = a2[2];
  if ( *((_QWORD *)a2 + 1) >= 0x2000ui64 )
  {
    v6 = AslComputeCrc32(0, a2[4], 0x1000u);
    v5 = v3 + v7 - v4;
  }
  else
  {
    v4 = a2[5];
    v5 = a2[4];
    v6 = 0;
  }
  *a1 = AslComputeCrc32(v6, v5, v4);
  return 0;
}
