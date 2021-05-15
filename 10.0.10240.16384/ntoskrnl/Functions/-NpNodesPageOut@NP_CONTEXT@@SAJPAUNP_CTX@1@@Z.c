// -NpNodesPageOut@NP_CONTEXT@@SAJPAUNP_CTX@1@@Z 
 
int __fastcall NP_CONTEXT::NpNodesPageOut(struct NP_CONTEXT::NP_CTX *a1)
{
  int v2; // r0
  int result; // r0

  v2 = *(_DWORD *)a1;
  if ( *(_DWORD *)(v2 + 24) <= *(_DWORD *)v2 )
    result = 0;
  else
    result = NP_CONTEXT::NpiPerformPageOut((struct NP_CONTEXT *)v2, a1);
  return result;
}
