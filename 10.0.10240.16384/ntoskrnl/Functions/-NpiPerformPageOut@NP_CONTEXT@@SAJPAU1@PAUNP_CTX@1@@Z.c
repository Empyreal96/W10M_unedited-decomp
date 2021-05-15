// -NpiPerformPageOut@NP_CONTEXT@@SAJPAU1@PAUNP_CTX@1@@Z 
 
int __fastcall NP_CONTEXT::NpiPerformPageOut(struct NP_CONTEXT *a1, struct NP_CONTEXT::NP_CTX *a2)
{
  int *v4; // r6
  int v5; // r0
  void *v6; // r7
  int result; // r0

  while ( 1 )
  {
    *((_DWORD *)a1 + 10) = 0;
    (*((void (__fastcall **)(struct NP_CONTEXT::NP_CTX *, int (__fastcall *)(void *, void *, unsigned int *), struct NP_CONTEXT *))a1
     + 2))(
      a2,
      NP_CONTEXT::NpiTreeWalkCallback,
      a1);
    v4 = (int *)*((_DWORD *)a1 + 10);
    v5 = *(_DWORD *)(((*v4 & 0xFFFFF000) + 7) & 0xFFFFFFFC);
    v6 = (void *)(*v4 & 0xFFFFF000);
    if ( !v5 || (v5 & 2) != 0 )
      break;
    --*((_DWORD *)a1 + 8);
LABEL_6:
    ++*((_DWORD *)a1 + 7);
    *v4 = v5;
    NP_CONTEXT::NpNodeFree(a2, v6, 1u);
    if ( *((_DWORD *)a1 + 6) <= *(_DWORD *)a1 )
      return 0;
  }
  v5 = (*((int (__fastcall **)(struct NP_CONTEXT::NP_CTX *))a1 + 3))(a2);
  if ( v5 )
  {
    ++*((_DWORD *)a1 + 13);
    goto LABEL_6;
  }
  result = -1073741435;
  ++*((_DWORD *)a1 + 15);
  return result;
}
