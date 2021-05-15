// PopGenerateUnHibernatedMdl 
 
_DWORD *__fastcall PopGenerateUnHibernatedMdl(int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  int v3; // r0
  unsigned int v4; // r5
  unsigned int v5; // r1
  unsigned int v6; // r8
  int v7; // r9
  char **v8; // r6
  char *v9; // t1
  __int64 v10; // r0

  v2 = PopGenerateScratchMdl(a1, a2);
  if ( v2 )
  {
    v3 = ReadTimeStampCounter();
    v4 = 0;
    v6 = v5;
    v7 = v3;
    if ( (v2[5] & 0xFFFFF000) != 0 )
    {
      v8 = (char **)(v2 + 7);
      do
      {
        v9 = *v8++;
        PopDiscardRange(dword_61EC98, v9, 1u, 1752457543);
        ++v4;
      }
      while ( v4 < v2[5] >> 12 );
    }
    LODWORD(v10) = ReadTimeStampCounter();
    qword_61EFB0 += v10 - __PAIR64__(v6, v7);
  }
  return v2;
}
