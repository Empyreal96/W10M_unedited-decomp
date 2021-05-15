// MiAddPageToFlushMdl 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiAddPageToFlushMdl(int a1, int a2, int a3, int a4, char a5)
{
  int v6; // r6
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r4
  int v13; // r1 OVERLAPPED
  int v14; // r2 OVERLAPPED
  int result; // r0
  unsigned int *v16; // r0
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // lr
  unsigned int v20; // r1
  int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = 0;
  if ( !*(_DWORD *)(a1 + 20) )
  {
    v6 = 2;
    v16 = (unsigned int *)(a3 + 36);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_53A048(v16);
    v17 = (unsigned __int8 *)(a3 + 39);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 0x80, v17) );
    __dmb(0xBu);
    if ( v18 >> 7 )
    {
      ExpWaitForSpinLockExclusiveAndAcquire(v16);
      v16 = (unsigned int *)(a3 + 36);
    }
    while ( 1 )
    {
      v19 = *v16;
      if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v19 & 0x40000000) == 0 )
      {
        do
          v20 = __ldrex(v16);
        while ( v20 == v19 && __strex(v19 | 0x40000000, v16) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    ++*(_DWORD *)(a3 + 40);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v16);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
    *(_DWORD *)a1 = 0;
    *(_WORD *)(a1 + 6) = 0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    *(_DWORD *)(a1 + 24) = a4;
  }
  if ( (a5 & 2) != 0 )
    v6 |= 4u;
  v10 = MiReferencePageForModifiedWrite(a2, v6);
  __dmb(0xBu);
  v11 = (unsigned int *)(a2 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  if ( !v10 )
    return 3;
  *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 20) + 28) = (a2 - MmPfnDatabase) / 24;
  *(_QWORD *)&v13 = *(_QWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 20) = v13 + 1;
  if ( v10 != 3
    || (unsigned int)(v13 + 1) < 0x10 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) != 0 )
  {
    result = *(_DWORD *)(a1 + 20) == v14;
  }
  else
  {
    result = 2;
  }
  return result;
}
