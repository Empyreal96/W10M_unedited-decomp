// CcMapData 
 
int __fastcall CcMapData(int a1, int a2, int a3, char a4, _DWORD *a5, int *a6)
{
  unsigned int *v9; // r5
  unsigned int v10; // r6
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int *v13; // r5
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int *v16; // r4
  unsigned int *v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  int *v21; // [sp+18h] [bp-30h] BYREF
  int v22; // [sp+1Ch] [bp-2Ch] BYREF
  int v23[10]; // [sp+20h] [bp-28h] BYREF

  v22 = a4 & 1;
  if ( (a4 & 1) != 0 )
  {
    v9 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4240);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
  }
  else
  {
    v11 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4236);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
  }
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  if ( v22 )
  {
    v13 = a6;
    *a6 = CcGetVirtualAddress(
            *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4),
            *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4),
            *(_DWORD *)a2,
            *(_DWORD *)(a2 + 4),
            &v21,
            &v22,
            (a4 & 0x40) != 0,
            0);
  }
  else
  {
    v13 = a6;
    if ( !CcPinFileData(a1, (_DWORD *)a2, a3, 1, 0, a4, &v21, a6, v23) )
    {
      v14 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4300);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 + 1, v14) );
      LOBYTE(v21) = 0;
      return (unsigned __int8)v21;
    }
  }
  v16 = v21;
  if ( (a4 & 0x10) == 0 )
  {
    CcMapAndRead(a3, 0, 1, *v13);
    v16 = v21;
  }
  v17 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4304);
  v18 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
  do
    v19 = __ldrex(v17);
  while ( __strex(v19 + v18, v17) );
  *a5 = (char *)v16 + 1;
  LOBYTE(v21) = 1;
  return (unsigned __int8)v21;
}
