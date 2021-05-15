// ObpDeleteDirectoryEntry 
 
int __fastcall ObpDeleteDirectoryEntry(int *a1)
{
  _DWORD **v1; // r2
  int v2; // r5
  _DWORD *v3; // r4
  int v4; // r3

  v1 = (_DWORD **)a1[2];
  v2 = *a1;
  v3 = *v1;
  *v1 = (_DWORD *)**v1;
  v4 = v3[1];
  *v3 = 0;
  *(_DWORD *)(v4 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(v4 - 10) & 3]) = 0;
  ObfDereferenceObject(v3[1]);
  ExFreePoolWithTag((unsigned int)v3);
  ObfDereferenceObject(v2);
  return 1;
}
