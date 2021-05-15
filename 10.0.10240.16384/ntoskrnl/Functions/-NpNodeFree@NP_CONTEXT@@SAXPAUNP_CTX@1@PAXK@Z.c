// -NpNodeFree@NP_CONTEXT@@SAXPAUNP_CTX@1@PAXK@Z 
 
void __fastcall NP_CONTEXT::NpNodeFree(struct NP_CONTEXT::NP_CTX *a1, void *a2, unsigned int a3)
{
  int v4; // r1

  v4 = *(_DWORD *)a1;
  if ( a3 && (--*(_DWORD *)(v4 + 24), **(_DWORD **)(v4 + 48) < *(_DWORD *)(v4 + 4)) )
  {
    *(_DWORD *)a2 = **(_DWORD **)(v4 + 48) + 1;
    **(_DWORD **)(v4 + 48) = a2;
    *(_DWORD *)(v4 + 48) = a2;
  }
  else
  {
    ExFreePoolWithTag(a2);
  }
}
