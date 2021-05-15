// ViSwap 
 
int __fastcall ViSwap(int *a1, int *a2, char **a3, int a4)
{
  _DWORD *v7; // r5
  int result; // r0
  char *v9; // r0
  __int16 v10; // r4
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a4;
  v7 = ViGetMapRegisterFile(*a1);
  if ( !v7 )
    return 0;
  v9 = ViGetMdlBufferSa(*a2, *a3);
  v10 = (__int16)v9;
  if ( !v9 || !ViFindMappedRegisterInFile((int)v7, (int)v9, v11) )
    return 0;
  *a2 = v7[8];
  *a3 = (char *)(*(_DWORD *)(v7[8] + 16) + (v10 & 0xFFF) + (v11[0] << 12) + *(_DWORD *)(v7[8] + 24));
  result = 1;
  *a1 = v7[7];
  return result;
}
