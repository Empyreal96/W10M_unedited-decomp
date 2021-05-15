// MmAreMdlPagesCached 
 
int __fastcall MmAreMdlPagesCached(_DWORD *a1)
{
  unsigned int *v1; // r5
  unsigned int v2; // r6
  int v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // t1

  v1 = a1 + 7;
  v2 = (unsigned int)&a1[((a1[5] + (((unsigned __int16)a1[6] + (unsigned __int16)a1[4]) & 0xFFFu) + 4095) >> 12) + 7];
  v3 = MmPfnDatabase;
  while ( 1 )
  {
    v5 = *v1++;
    v4 = v5;
    if ( !MI_IS_PFN(v5) || (*(_BYTE *)(v3 + 24 * v4 + 18) & 0xC0) != 64 )
      break;
    if ( (unsigned int)v1 >= v2 )
      return 1;
  }
  return 0;
}
