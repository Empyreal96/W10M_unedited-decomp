// -NpLeafRemoveInternal@NP_CONTEXT@@SAPAXPAUNP_CTX@1@PAPAX@Z 
 
unsigned int __fastcall NP_CONTEXT::NpLeafRemoveInternal(struct NP_CONTEXT::NP_CTX *a1, void **a2)
{
  int v2; // r5
  unsigned int v3; // r4
  _DWORD *v4; // r6

  v2 = *(_DWORD *)a1;
  if ( ((unsigned int)*a2 & 1) != 0 )
  {
    v3 = (unsigned int)*a2 & 0xFFFFF000;
    v4 = (_DWORD *)((v3 + 7) & 0xFFFFFFFC);
    if ( *v4 && (*v4 & 2) == 0 )
    {
      (*(void (**)(void))(v2 + 20))();
      *v4 |= 2u;
      --*(_DWORD *)(v2 + 32);
    }
  }
  else
  {
    --*(_DWORD *)(v2 + 28);
    (*(void (**)(void))(v2 + 20))();
    v3 = 0;
  }
  return v3;
}
