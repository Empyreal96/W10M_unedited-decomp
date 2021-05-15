// PopWriteChecksumPages 
 
char *__fastcall PopWriteChecksumPages(char *result)
{
  char *v1; // r8
  unsigned int v2; // r9
  unsigned int v3; // r10
  int v4; // r0
  int v5; // r5
  int v6; // r1
  int v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // r0
  bool v10; // cf
  unsigned int v11; // r2
  int v12; // r1

  v1 = result;
  v2 = (unsigned int)(2 * *((_DWORD *)result + 70) + 4095) >> 12;
  if ( v2 )
  {
    v3 = (unsigned int)(*((_DWORD *)result + 62) + 4095) >> 12;
    result = (char *)((v3 + v2) << 12);
    if ( (unsigned __int64)(v3 + v2) << 12 <= qword_61EEA8 )
    {
      v4 = ReadTimeStampCounter();
      v5 = *((_DWORD *)v1 + 32);
      v7 = v6;
      v8 = v4;
      *(_DWORD *)(v5 + 96) = *((_DWORD *)v1 + 70);
      *(_DWORD *)(v5 + 100) = *((_DWORD *)v1 + 71);
      *(_DWORD *)(*((_DWORD *)v1 + 32) + 88) = v3;
      PopWriteHiberPages(v1, *((_DWORD *)v1 + 74), v2, v3);
      v9 = ReadTimeStampCounter();
      v10 = v9 >= v8;
      v11 = v9 - v8;
      result = &PopSleepStats;
      qword_61EFD8 += __PAIR64__(v12 - (v7 + (unsigned int)!v10), v11);
    }
  }
  return result;
}
