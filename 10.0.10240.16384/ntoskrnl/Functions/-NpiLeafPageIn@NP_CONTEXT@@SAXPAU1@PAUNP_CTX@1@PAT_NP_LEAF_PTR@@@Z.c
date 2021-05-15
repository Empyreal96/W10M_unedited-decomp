// -NpiLeafPageIn@NP_CONTEXT@@SAXPAU1@PAUNP_CTX@1@PAT_NP_LEAF_PTR@@@Z 
 
void __fastcall NP_CONTEXT::NpiLeafPageIn(struct NP_CONTEXT *a1, struct NP_CONTEXT::NP_CTX *a2, union _NP_LEAF_PTR *a3)
{
  void *v6; // r0
  unsigned int v7; // r5

  v6 = NP_CONTEXT::NpNodeAllocate(a2, (unsigned int)a2, 3u);
  v7 = (unsigned int)v6;
  if ( v6 )
  {
    if ( (*((int (__fastcall **)(struct NP_CONTEXT::NP_CTX *, void *, _DWORD))a1 + 4))(a2, v6, *(_DWORD *)a3) >= 0 )
    {
      ++*((_DWORD *)a1 + 14);
      --*((_DWORD *)a1 + 7);
      ++*((_DWORD *)a1 + 8);
      *(_DWORD *)((v7 + 7) & 0xFFFFFFFC) = *(_DWORD *)a3;
      *(_DWORD *)a3 = v7 | 1;
      v7 = 0;
    }
    else
    {
      ++*((_DWORD *)a1 + 16);
    }
    if ( v7 )
      NP_CONTEXT::NpNodeFree(a2, (void *)v7, 1u);
  }
  else
  {
    ++*((_DWORD *)a1 + 16);
  }
}
