// NtQueueApcThreadEx 
 
int __fastcall NtQueueApcThreadEx(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v9; // r7
  int v10; // r4
  int v11; // r6
  unsigned int *v12; // r0
  unsigned int v13; // r2
  unsigned int (__fastcall *v15)(unsigned int); // r3
  unsigned int (__fastcall *v16)(unsigned int); // r5
  int v17; // r4
  int v18[8]; // [sp+10h] [bp-20h] BYREF

  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v10 = ObReferenceObjectByHandle(a1, 16, PsThreadType, v9, v18);
  if ( v10 < 0 )
    return v10;
  v11 = v18[0];
  if ( (*(_DWORD *)(v18[0] + 76) & 0x400) != 0 )
  {
    v10 = -1073741816;
  }
  else if ( a2 )
  {
    v10 = ObReferenceObjectByHandle(a2, 2, PspMemoryReserveObjectTypes, v9, v18);
    if ( v10 >= 0 )
    {
      __dmb(0xBu);
      v12 = (unsigned int *)v18[0];
      do
        v13 = __ldrex(v12);
      while ( !v13 && __strex(1u, v12) );
      __dmb(0xBu);
      if ( v13 )
        return sub_7E86E8();
      v15 = (unsigned int (__fastcall *)(unsigned int))PspUserApcReserveKernelRoutine;
      v16 = (unsigned int (__fastcall *)(unsigned int))PspUserApcReserveKernelRoutine;
      v17 = (int)(v12 + 1);
      goto LABEL_11;
    }
  }
  else
  {
    v17 = ExAllocatePoolWithQuotaTag(0x208u, 0x30u, 1885434704);
    if ( v17 )
    {
      v15 = RtlpSysVolFree;
      v16 = ExFreePool;
LABEL_11:
      KeInitializeApc(v17, v11, 0, (int)v15, (int)v16, a3, 1, a4);
      if ( KeInsertQueueApc(v17, a5, a6, 0) )
      {
        v10 = 0;
      }
      else
      {
        v16(v17);
        v10 = -1073741823;
      }
      goto LABEL_13;
    }
    v10 = -1073741801;
  }
LABEL_13:
  ObfDereferenceObject(v11);
  return v10;
}
