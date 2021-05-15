// ObpUnlockHandleDatabaseEntry 
 
int __fastcall ObpUnlockHandleDatabaseEntry(int a1, int a2)
{
  int **v3; // r2
  int result; // r0
  int v5; // r1
  int v6; // r2

  if ( (*(_BYTE *)(a1 + 14) & 4) != 0 )
    v3 = (int **)(a1 - ObpInfoMaskToOffset[*(_BYTE *)(a1 + 14) & 7]);
  else
    v3 = 0;
  if ( (*(_BYTE *)(a1 + 15) & 0x40) != 0 )
    return sub_7E8E54();
  v5 = 0;
  result = **v3;
  v6 = (int)(*v3 + 1);
  if ( !result )
    goto LABEL_11;
  while ( *(_DWORD *)v6 != a2 )
  {
LABEL_15:
    v6 += 8;
    if ( !--result )
      goto LABEL_9;
  }
  if ( *(unsigned __int8 *)(v6 + 7) == 255 )
  {
    v5 = v6;
    goto LABEL_15;
  }
  --*(_BYTE *)(v6 + 7);
  v5 = 0;
LABEL_9:
  if ( v5 )
  {
    v6 = v5;
    --*(_BYTE *)(v5 + 7);
  }
LABEL_11:
  if ( !*(_BYTE *)(v6 + 7) && (*(_DWORD *)(v6 + 4) & 0xFFFFFF) == 0 )
    *(_DWORD *)v6 = 0;
  return result;
}
