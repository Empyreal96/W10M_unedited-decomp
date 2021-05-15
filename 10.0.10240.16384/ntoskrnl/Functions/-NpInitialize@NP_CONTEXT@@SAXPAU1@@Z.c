// -NpInitialize@NP_CONTEXT@@SAXPAU1@@Z 
 
void __fastcall NP_CONTEXT::NpInitialize(struct NP_CONTEXT *a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v5; // r2
  __int64 v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+8h] [bp-8h]

  v6 = __PAIR64__(a3, a2);
  v7 = a4;
  memset(a1, 0, 68);
  HIDWORD(v5) = (char *)a1 + 44;
  LODWORD(v5) = 0;
  *(_QWORD *)HIDWORD(v5) = v5;
  KeQueryTickCount(&v6);
  *((_DWORD *)a1 + 9) = (__int64)((unsigned int)(v6 >> 12) * (unsigned __int64)(unsigned int)KeMaximumIncrement) >> 17;
}
