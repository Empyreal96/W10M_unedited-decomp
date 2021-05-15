// MiPageTablesNeeded 
 
int __fastcall MiPageTablesNeeded(__int64 a1, unsigned int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  char *v4; // r5
  char v6[32]; // [sp+8h] [bp-20h] BYREF

  v2 = 0;
  v3 = 0;
  v4 = v6;
  do
  {
    LODWORD(a1) = (((unsigned int)a1 >> 10) & 0x3FFFFC) - 0x40000000;
    HIDWORD(a1) = ((HIDWORD(a1) >> 10) & 0x3FFFFC) - 0x40000000;
    *(_QWORD *)v4 = a1;
    if ( v3 >= a2 )
      v2 += ((HIDWORD(a1) - (int)a1) >> 2) + 1;
    ++v3;
    v4 += 8;
  }
  while ( v3 < 2 );
  return v2 - MiCountExistingPageTables(a1, HIDWORD(a1), v6, 1, a2);
}
