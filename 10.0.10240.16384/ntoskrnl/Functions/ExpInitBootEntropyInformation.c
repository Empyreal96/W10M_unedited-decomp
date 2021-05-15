// ExpInitBootEntropyInformation 
 
int __fastcall ExpInitBootEntropyInformation(int a1, _BYTE **a2)
{
  _BYTE *v2; // r4
  char *v3; // r5
  _DWORD *v5; // r8
  int v6; // r10
  int v7; // r9

  v2 = *a2;
  v3 = (char *)(*((_DWORD *)KeLoaderBlock_0 + 33) + 144);
  if ( *a2 )
  {
    memset(v2, 0, 888);
    v5 = v2 + 8;
    v6 = v3 - v2;
    v7 = 8;
    do
    {
      *v5 = *(_DWORD *)((char *)v5 + v6);
      v5[2] = *(_DWORD *)((char *)v5 + v6 + 8);
      v5[3] = *(_DWORD *)((char *)v5 + v6 + 12);
      v5[4] = *(_DWORD *)((char *)v5 + v6 + 16);
      v5[5] = *(_DWORD *)((char *)v5 + v6 + 20);
      v5[6] = *(_DWORD *)((char *)v5 + v6 + 24);
      v5[7] = *(_DWORD *)((char *)v5 + v6 + 28);
      v5[8] = *(_DWORD *)((char *)v5 + v6 + 32);
      memmove((int)(v5 + 9), (int)v5 + v6 + 36, 0x40u);
      v5 += 26;
      --v7;
    }
    while ( v7 );
    *(_DWORD *)v2 = *(_DWORD *)v3;
    memmove((int)(v2 + 840), (int)(v3 + 840), 0x30u);
  }
  return sub_81A2E4();
}
