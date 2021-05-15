// -SmStGetDataInUseKb@-$SMKM_STORE@USM_TRAITS@@@@SAKPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStGetDataInUseKb(int a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r0
  char *v3; // r4
  int v4; // r5
  unsigned __int64 v5; // kr08_8
  int v7; // [sp+0h] [bp-610h] BYREF
  char v8[12]; // [sp+8h] [bp-608h] BYREF
  unsigned int v9; // [sp+14h] [bp-5FCh]

  v7 = 1528;
  ((void (__fastcall *)(int, _DWORD, char *, int *))SMKM_STORE<SM_TRAITS>::SmStGetStoreStats)(a1, 0, v8, &v7);
  v1 = 0;
  v2 = 0;
  v3 = v8;
  v4 = 8;
  do
  {
    v5 = __PAIR64__(v2, v1) + v9 * (unsigned __int64)*((unsigned int *)v3 + 10);
    v2 = HIDWORD(v5);
    v1 = v5;
    v3 += 8;
    --v4;
  }
  while ( v4 );
  return (__int64)(v5 + 1023) >> 10;
}
