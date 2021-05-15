// MiUpdateSessionPdeMaster 
 
void __fastcall MiUpdateSessionPdeMaster(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5
  int v11; // r2
  int v12; // r3
  int *v13; // r1

  v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v11 = (unsigned int)(a1 - dword_63389C) >> 22;
  v12 = *(_DWORD *)(v10 + 0x2000);
  v13 = (int *)(v12 + 4 * v11);
  if ( (unsigned int)v13 < 0xC0000000 )
    *v13 = a2;
  else
    sub_510220(a1, (unsigned int)v13, v11, v12, a5, a6, a7, a8, a9, a10);
}
