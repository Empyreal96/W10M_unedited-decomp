// MiLockPageTableRange 
 
int __fastcall MiLockPageTableRange(unsigned int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r10
  unsigned int v6; // r7
  int v7; // r0
  int v8; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  int v14; // [sp+8h] [bp-38h]
  unsigned int v15; // [sp+Ch] [bp-34h]
  unsigned int v16; // [sp+10h] [bp-30h]
  _DWORD *v17; // [sp+18h] [bp-28h] BYREF
  unsigned int v18; // [sp+1Ch] [bp-24h]

  v16 = a1;
  v2 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v3 = ((a1 >> 20) & 0xFFC) - 1070596096;
  v4 = ((a2 >> 20) & 0xFFC) - 1070596096;
  v5 = a1;
  v15 = v4;
  v6 = 0;
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v9 = (unsigned __int8 *)v2 + 3;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v11 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v12 = __ldrex(v2);
        while ( v12 == v11 && __strex(v11 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v3 > v4 )
  {
LABEL_20:
    v6 = 0;
    v8 = 0;
    goto LABEL_21;
  }
  while ( 1 )
  {
    v18 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
    v17 = (_DWORD *)(((v18 >> 10) & 0x3FFFFC) - 0x40000000);
    v7 = MiResolvePageTablePage(0, v5, (int *)&v17, 0, v14, 0);
    v8 = v7;
    if ( v7 != -1073741802 )
    {
      if ( v7 != -1073740748 )
        goto LABEL_21;
      goto LABEL_19;
    }
    if ( !MiLockPageTablePage(MmPfnDatabase + 24 * (*v17 >> 12), 0) )
      break;
    v3 += 4;
    v6 = v5;
    v5 = v3 << 20;
LABEL_19:
    if ( v3 > v15 )
      goto LABEL_20;
  }
  v8 = -1073741670;
LABEL_21:
  MiUnlockWorkingSetExclusive((int)v2, v14);
  if ( v6 )
    MiUnlockPageTableRange(v16, v6);
  return v8;
}
