// KeQueryDpcWatchdogInformation 
 
int __fastcall KeQueryDpcWatchdogInformation(int a1)
{
  unsigned int v2; // r4
  int v3; // r2
  int v4; // r2

  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( !*(_BYTE *)(v2 + 3162) )
    return -1073741823;
  memset((_BYTE *)a1, 0, 20);
  v3 = *(_DWORD *)(v2 + 3744);
  if ( v3 )
  {
    *(_DWORD *)a1 = v3;
    *(_DWORD *)(a1 + 4) = v3 - *(_DWORD *)(v2 + 3740);
  }
  v4 = *(_DWORD *)(v2 + 3260);
  if ( v4 )
  {
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)(a1 + 12) = v4 - *(_DWORD *)(v2 + 3264);
  }
  return 0;
}
