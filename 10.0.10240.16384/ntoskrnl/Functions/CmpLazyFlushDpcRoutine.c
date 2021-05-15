// CmpLazyFlushDpcRoutine 
 
int __fastcall CmpLazyFlushDpcRoutine(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r8
  char v5; // r6
  int v6; // lr
  unsigned int *v7; // r4
  unsigned int v8; // r2
  int v9; // r3
  int result; // r0
  unsigned int v11; // [sp+E2h] [bp-5Ah]
  unsigned int v12; // [sp+E6h] [bp-56h]
  unsigned __int64 v13; // [sp+EAh] [bp-52h]
  char v14; // [sp+112h] [bp-2Ah]

  v4 = (unsigned int *)a2;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)a1 = 0;
    *(_DWORD *)(a1 + 16) = (unsigned __int64)a4 >> 8;
    v14 = a3;
    v5 = 64 - (a3 & 0x3F);
    LODWORD(v13) = (a2 << (a3 & 0x3F)) | ((unsigned int)a2 >> v5) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v13) = (a2 << ((a3 & 0x3F) - 32)) | (a2 >> 31 << (a3 & 0x3F)) | ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v5);
    v11 = ((unsigned __int64)a1 >> (a3 & 0x3F)) | (a1 << v5);
    v12 = ((unsigned int)(a1 >> 31) >> (a3 & 0x3F)) | (a1 >> 31 << v5) | ((unsigned int)a1 >> ((a3 & 0x3F) - 32)) | (a1 << (32 - (a3 & 0x3F)));
    *(_DWORD *)(a1 + 20) ^= a4;
    *(_DWORD *)(a1 + 24) ^= a3;
    KiCustomAccessRoutine5((unsigned int *)a2);
    v6 = (v11 >> (64 - (v14 & 0x3F))) | (v12 << ((v14 & 0x3F) - 32)) | (v12 >> (32 - (v14 & 0x3F))) | (v11 << (v14 & 0x3F));
    v4 = (unsigned int *)(((_DWORD)v13 << (64 - (v14 & 0x3F))) | (v13 >> (v14 & 0x3F)));
    *(_DWORD *)(v6 + 16) = v4;
    *(_BYTE *)v6 = 19;
  }
  v7 = v4 + 24;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v4 + 24);
  }
  else
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire(v4 + 24);
  }
  v9 = CmpHoldLazyFlush;
  __dmb(0xBu);
  if ( v9 )
  {
    result = 0;
    v4[26] = 0;
    v4[27] = 0;
  }
  else
  {
    KeSetEvent(v4 + 20, 0, 0);
    result = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(v4 + 24);
  __dmb(0xBu);
  *v7 = 0;
  return result;
}
