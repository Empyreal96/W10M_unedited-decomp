// sub_7C4F48 
 
void __fastcall sub_7C4F48(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // r5
  int v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r2
  unsigned int v16; // lr
  int v17; // r1
  int v18; // t1
  int v19; // r3
  int v20; // r2

  v13 = *(_DWORD *)(v11 + a4);
  v14 = v11 + a4;
  if ( (a8 & v13) == a8 )
  {
    a1 = 0;
    v15 = 0;
    v16 = **(_DWORD **)(v14 + 4);
    if ( v16 )
    {
      v17 = *(_DWORD *)(*(_DWORD *)(a2 + 344) + v11 + 4);
      while ( 1 )
      {
        v18 = *(_DWORD *)(v17 + 4);
        v17 += 4;
        if ( v18 == *(_DWORD *)(*(_DWORD *)(v12 + 40) + 176) )
          break;
        if ( ++v15 >= v16 )
          goto LABEL_8;
      }
      a1 = 1;
LABEL_8:
      a2 = a5;
    }
    if ( !a1 )
LABEL_20:
      JUMPOUT(0x6BF6CC);
    a3 = a7;
  }
  if ( (v13 & a3) == a3 )
  {
    a1 = EtwpApplyExeFilter(v12, *(_DWORD *)(v14 + 8));
    a2 = a5;
  }
  if ( a1 )
  {
    v19 = *(_DWORD *)(a2 + 344);
    v20 = *(_DWORD *)(v19 + v11);
    if ( (v20 & a10) == a10 || (v20 & a11) == a11 )
      a1 = EtwpApplyPackageIdFilter(v12, *(_DWORD *)(v19 + v11 + 12), *(_DWORD *)(v19 + v11 + 16));
    if ( a1 )
      JUMPOUT(0x6BF6BC);
  }
  goto LABEL_20;
}
