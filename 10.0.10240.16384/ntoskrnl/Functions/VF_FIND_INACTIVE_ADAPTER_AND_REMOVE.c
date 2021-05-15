// VF_FIND_INACTIVE_ADAPTER_AND_REMOVE 
 
int *__fastcall VF_FIND_INACTIVE_ADAPTER_AND_REMOVE(int a1)
{
  int *v2; // r5
  int v3; // r8
  unsigned int v4; // r1
  int *i; // r2
  __int64 v6; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = 0;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_908C58);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&dword_908C58);
    while ( __strex(1u, (unsigned int *)&dword_908C58) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C58);
  }
  for ( i = (int *)ViAdapterList; &ViAdapterList != i; i = (int *)*i )
  {
    if ( i[3] == a1 && (i[5] <= 0 || *((_BYTE *)i + 16) == 1) )
    {
      v6 = *(_QWORD *)i;
      v2 = i;
      if ( *(int **)(*i + 4) != i || *(int **)HIDWORD(v6) != i )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v6) = v6;
      *(_DWORD *)(v6 + 4) = HIDWORD(v6);
      break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_908C58, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_908C58 = 0;
  }
  KfLowerIrql(v3);
  return v2;
}
