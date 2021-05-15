// MiInitializeProbePacketVm 
 
unsigned int __fastcall MiInitializeProbePacketVm(int a1)
{
  unsigned int result; // r0
  __int64 v3; // kr00_8
  int v4; // r3
  unsigned int *v5; // r5
  char v6; // r7
  unsigned int v7; // r1
  int v8; // r3

  result = *(_DWORD *)a1;
  v3 = *(_QWORD *)&MmBadPointer;
  *(_BYTE *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 48) = v3;
  if ( result < HIDWORD(v3) )
  {
    *(_DWORD *)(a1 + 48) = *(_DWORD *)(a1 + 40) + 492;
    v4 = 1;
LABEL_3:
    *(_DWORD *)(a1 + 28) = v4;
    goto LABEL_4;
  }
  if ( result < dword_63389C )
    goto LABEL_23;
  v8 = *((unsigned __int8 *)&MiState[2423]
       + ((int)(((result >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  switch ( v8 )
  {
    case 6:
      goto LABEL_14;
    case 1:
    case 11:
      return sub_5454CC();
    case 14:
    case 7:
LABEL_14:
      *(_DWORD *)(a1 + 48) = &dword_634E80;
      v4 = 3;
      goto LABEL_3;
    case 8:
      *(_DWORD *)(a1 + 48) = &dword_634E00;
      v4 = 2;
      goto LABEL_3;
    case 5:
      v4 = 4;
      goto LABEL_3;
  }
  if ( v8 != 13 )
  {
LABEL_23:
    *(_DWORD *)(a1 + 48) = &dword_634F00;
    v4 = 5;
    goto LABEL_3;
  }
  *(_DWORD *)(a1 + 28) = 0;
LABEL_4:
  v5 = *(unsigned int **)(a1 + 48);
  if ( v5 == (unsigned int *)v3 )
  {
    *(_BYTE *)(a1 + 44) = 17;
  }
  else
  {
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v5);
    }
    else
    {
      result = *v5 & 0x7FFFFFFF;
      do
        v7 = __ldrex(v5);
      while ( v7 == result && __strex(result + 1, v5) );
      __dmb(0xBu);
      if ( v7 != result )
        result = ExpWaitForSpinLockSharedAndAcquire(v5);
    }
    *(_BYTE *)(a1 + 44) = v6;
  }
  return result;
}
