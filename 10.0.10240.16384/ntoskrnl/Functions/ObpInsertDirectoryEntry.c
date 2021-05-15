// ObpInsertDirectoryEntry 
 
int __fastcall ObpInsertDirectoryEntry(int a1, int a2, int a3)
{
  _DWORD *v6; // r4
  _DWORD *v7; // r2

  v6 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1766089295);
  if ( !v6 )
    return 0;
  ObfReferenceObject(a2);
  v7 = (_DWORD *)(a1 + 4 * *(unsigned __int16 *)(a3 + 16));
  v6[2] = *(_DWORD *)(a3 + 12);
  *v6 = *v7;
  *v7 = v6;
  v6[1] = a2;
  *(_DWORD *)(a3 + 8) = v7;
  ObfReferenceObject(a1);
  *(_DWORD *)(a2 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(a2 - 10) & 3]) = a1;
  return 1;
}
