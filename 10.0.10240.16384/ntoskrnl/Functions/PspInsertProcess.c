// PspInsertProcess 
 
int __fastcall PspInsertProcess(unsigned int *a1, int a2, int a3, int a4, int a5, char a6, int a7)
{
  unsigned int v9; // r6
  int v11; // r3
  int v12; // r0
  unsigned int *v13; // r5
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r3

  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1[84] + 24) = a1[44];
  if ( SeAuditingWithTokenForSubcategory(133, 0) )
    SeAuditProcessCreation(a1, a7);
  if ( a2 )
  {
    v11 = *(_DWORD *)(a2 + 288);
    __dmb(0xBu);
    if ( v11 )
    {
      v12 = *(_DWORD *)(a2 + 288);
      __dmb(0xBu);
      if ( PspImplicitAssignProcessToJob(v12, a1, a4) < 0 )
      {
        if ( (a6 & 1) != 0 )
        {
          v13 = a1 + 42;
          __dmb(0xBu);
          do
            v14 = __ldrex(v13);
          while ( __strex(v14 - 1, v13) );
          if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
            ExfTryToWakePushLock(a1 + 42);
          v15 = KeAbPostRelease((unsigned int)(a1 + 42));
          v16 = (__int16)(*(_WORD *)(v9 + 308) + 1);
          *(_WORD *)(v9 + 308) = v16;
          if ( !v16 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
            KiCheckForKernelApcDelivery(v15);
        }
        JUMPOUT(0x715088);
      }
    }
  }
  return sub_7F483C();
}
