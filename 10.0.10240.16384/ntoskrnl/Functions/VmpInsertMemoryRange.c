// VmpInsertMemoryRange 
 
int __fastcall VmpInsertMemoryRange(unsigned int *a1, _DWORD *a2, unsigned int a3)
{
  int v6; // r8
  unsigned int v7; // r3
  _DWORD *v8; // r5
  int v9; // r0
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r5
  _DWORD *v15; // r5
  int v16; // r0
  _DWORD *v17; // r5
  int v18; // r2
  _DWORD *v19; // r3
  _DWORD *v20; // r5
  int v21; // r2
  _DWORD *v22; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v6 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
  }
  else
  {
    v10 = (unsigned __int8 *)a1 + 3;
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1);
    while ( 1 )
    {
      v12 = *a1;
      if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(a1);
        while ( v13 == v12 && __strex(v12 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = a1[6];
  if ( v7 == -1 )
  {
    a1[6] = a3;
  }
  else if ( v7 != a3 )
  {
    v14 = -1073740007;
    goto LABEL_47;
  }
  v8 = (_DWORD *)a1[1];
  if ( v8 )
  {
    do
    {
      v9 = VmpProcessMemoryRangeCompareGpnRange(a2, v8);
      if ( v9 >= 0 )
      {
        if ( v9 <= 0 )
          break;
        v8 = (_DWORD *)v8[1];
      }
      else
      {
        v8 = (_DWORD *)*v8;
      }
    }
    while ( v8 );
    if ( v8 )
      goto LABEL_24;
  }
  v15 = (_DWORD *)a1[3];
  if ( v15 )
  {
    do
    {
      v16 = VmpProcessMemoryRangeCompareVpnRange(a2, v15);
      if ( v16 >= 0 )
      {
        if ( v16 <= 0 )
          break;
        v15 = (_DWORD *)v15[1];
      }
      else
      {
        v15 = (_DWORD *)*v15;
      }
    }
    while ( v15 );
    if ( v15 )
    {
LABEL_24:
      v14 = -1073741800;
      goto LABEL_47;
    }
  }
  v17 = (_DWORD *)a1[1];
  v18 = 0;
  if ( v17 )
  {
    while ( 1 )
    {
      if ( VmpProcessMemoryRangeCompareGpn(a2 + 6, v17, v18) < 0 )
      {
        v19 = (_DWORD *)*v17;
        if ( !*v17 )
        {
          v18 = 0;
          break;
        }
      }
      else
      {
        v19 = (_DWORD *)v17[1];
        if ( !v19 )
        {
          v18 = 1;
          break;
        }
      }
      v17 = v19;
    }
  }
  RtlRbInsertNodeEx((unsigned int)(a1 + 1), (unsigned int)v17, v18, a2 + 3);
  v20 = (_DWORD *)a1[3];
  v21 = 0;
  if ( !v20 )
    goto LABEL_46;
  while ( VmpProcessMemoryRangeCompareVpn(a2 + 8, v20) >= 0 )
  {
    v22 = (_DWORD *)v20[1];
    if ( !v22 )
    {
      v21 = 1;
      goto LABEL_46;
    }
LABEL_44:
    v20 = v22;
  }
  v22 = (_DWORD *)*v20;
  if ( *v20 )
    goto LABEL_44;
  v21 = 0;
LABEL_46:
  RtlRbInsertNodeEx((unsigned int)(a1 + 3), (unsigned int)v20, v21, a2);
  v14 = 0;
LABEL_47:
  if ( v6 != -1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1, vars4);
    }
    else
    {
      __dmb(0xBu);
      *a1 = 0;
    }
    KfLowerIrql((unsigned __int8)v6);
  }
  return v14;
}
