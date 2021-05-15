// -NpLeafDerefInternal@NP_CONTEXT@@SAXPAUNP_CTX@1@PAPAX@Z 
 
void __fastcall NP_CONTEXT::NpLeafDerefInternal(struct NP_CONTEXT::NP_CTX *a1, void **a2, __int64 a3)
{
  unsigned int v5; // r3
  signed __int64 v6; // kr00_8
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r5
  __int64 v10; // [sp+0h] [bp-18h] BYREF

  v10 = a3;
  v5 = ((unsigned int)*a2 ^ (4 * (((unsigned int)*a2 >> 2) - 1))) & 0xFFC ^ (unsigned int)*a2;
  *a2 = (void *)v5;
  if ( (v5 & 0xFFC) == 0 )
  {
    *a2 = (void *)(v5 & 0xFFFFFFFD);
    KeQueryTickCount((int *)&v10);
    v6 = (unsigned int)(v10 >> 12) * (unsigned __int64)(unsigned int)KeMaximumIncrement;
    v7 = v6 >> 17;
    HIDWORD(v10) = SHIDWORD(v6) >> 17;
    v8 = v7 - *(_DWORD *)(*(_DWORD *)a1 + 36);
    if ( v8 > 0x3FF )
      v8 = 1023;
    *a2 = (void *)((unsigned int)*a2 ^ ((unsigned int)*a2 ^ (4 * v8)) & 0xFFC);
    if ( v8 >= 0x2FF )
    {
      v9 = v7 - 511;
      (*(void (__fastcall **)(struct NP_CONTEXT::NP_CTX *, int (__fastcall *)(void *, void *, unsigned int *), int))(*(_DWORD *)a1 + 8))(
        a1,
        NP_CONTEXT::NpiRebaseCallback,
        v7 - 511 - *(_DWORD *)(*(_DWORD *)a1 + 36));
      *(_DWORD *)(*(_DWORD *)a1 + 36) = v9;
    }
  }
}
