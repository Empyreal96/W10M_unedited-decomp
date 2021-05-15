// ExpTimerDpcRoutine 
 
int __fastcall ExpTimerDpcRoutine(int result, int a2, int a3, int a4)
{
  int v4; // r8
  int v5; // r9
  char v6; // r6
  int v7; // r4
  unsigned int *v8; // r6
  unsigned int v9; // r2
  int v10; // r2
  int v11; // r1
  __int64 v12; // r0
  unsigned __int64 v13; // [sp+E9h] [bp-7Fh]
  unsigned int v14; // [sp+131h] [bp-37h]
  unsigned int v15; // [sp+135h] [bp-33h]
  char v16; // [sp+139h] [bp-2Fh]

  v4 = a2;
  v5 = result;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)result = 0;
    *(_DWORD *)(result + 16) = (unsigned __int64)a4 >> 8;
    v16 = a3;
    v6 = 64 - (a3 & 0x3F);
    LODWORD(v13) = (a2 << (a3 & 0x3F)) | ((unsigned int)a2 >> v6) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v13) = (a2 << ((a3 & 0x3F) - 32)) | (a2 >> 31 << (a3 & 0x3F)) | ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v6);
    v14 = ((unsigned __int64)result >> (a3 & 0x3F)) | (result << v6);
    v15 = ((unsigned int)(result >> 31) >> (a3 & 0x3F)) | (result >> 31 << v6) | ((unsigned int)result >> ((a3 & 0x3F) - 32)) | (result << (32 - (a3 & 0x3F)));
    *(_DWORD *)(result + 20) ^= a4;
    *(_DWORD *)(result + 24) ^= a3;
    KiCustomAccessRoutine0((unsigned int *)a2);
    v5 = (v14 >> (64 - (v16 & 0x3F))) | (v15 << ((v16 & 0x3F) - 32)) | (v15 >> (32 - (v16 & 0x3F))) | (v14 << (v16 & 0x3F));
    result = (HIDWORD(v13) << (64 - (v16 & 0x3F))) | ((unsigned int)v13 >> ((v16 & 0x3F) - 32)) | ((_DWORD)v13 << (32 - (v16 & 0x3F)));
    v4 = ((_DWORD)v13 << (64 - (v16 & 0x3F))) | (v13 >> (v16 & 0x3F));
    *(_DWORD *)(v5 + 16) = v4;
    *(_BYTE *)v5 = 19;
  }
  v7 = 0;
  v8 = (unsigned int *)(v4 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = KiAcquireSpinLockInstrumented(v4 + 48);
  }
  else
  {
    do
      v9 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( v9 )
      result = KxWaitForSpinLockAndAcquire((unsigned int *)(v4 + 48));
  }
  if ( (*(_BYTE *)(v4 + 144) & 1) != 0 )
  {
    v10 = MEMORY[0xFFFF9018];
    __dmb(0xBu);
    v11 = MEMORY[0xFFFF9014];
    __dmb(0xBu);
    while ( v10 != MEMORY[0xFFFF901C] )
    {
      __dmb(0xAu);
      __yield();
      v10 = MEMORY[0xFFFF9018];
      __dmb(0xBu);
      v11 = MEMORY[0xFFFF9014];
      __dmb(0xBu);
    }
    result = KeInsertQueueApc(v4 + 52, v11, v10, 0);
    if ( !result )
      v7 = 1;
    if ( *(_DWORD *)(v4 + 140) )
    {
      if ( --v7 < 0 )
      {
        result = ObfReferenceObjectWithTag(v4);
        v7 = 0;
      }
      if ( (*(_BYTE *)(v4 + 144) & 2) == 0 )
      {
        HIDWORD(v12) = *(_DWORD *)(v4 + 184);
        LODWORD(v12) = v4;
        result = KeSetCoalescableTimer(v12, -10000i64 * *(int *)(v4 + 140), 0, HIDWORD(v12), v5);
        if ( result )
          ++v7;
      }
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(v4 + 48);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  if ( v7 )
    result = ObfDereferenceObjectWithTag(v4);
  return result;
}
