// NtResetWriteWatch 
 
int __fastcall NtResetWriteWatch(int a1, unsigned int a2, unsigned int a3)
{
  int v7; // r3
  int v8; // r5
  int v9; // r10
  unsigned int v10; // r6
  char v11; // r7
  _DWORD *v12; // r0
  int v13; // r5
  int *i; // r6
  unsigned int *v15; // r7
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  int v19; // r9
  int v20; // r4
  unsigned int v21; // r1
  int v22; // [sp+10h] [bp-50h] BYREF
  int v23; // [sp+14h] [bp-4Ch] BYREF
  unsigned int v24; // [sp+18h] [bp-48h]
  int v25; // [sp+1Ch] [bp-44h]
  int v26; // [sp+20h] [bp-40h]
  char v27[56]; // [sp+28h] [bp-38h] BYREF

  if ( a2 > MmHighestUserAddress - 0x10000 )
    return sub_5272B4();
  if ( MmHighestUserAddress - a2 - 0xFFFF < a3 )
    return -1073741583;
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = *(_DWORD *)((v7 & 0xFFFFFFC0) + 0x74);
  if ( a1 == -1 )
  {
    v9 = *(_DWORD *)((v7 & 0xFFFFFFC0) + 0x74);
  }
  else
  {
    if ( ObReferenceObjectByHandleWithTag(
           a1,
           8,
           PsProcessType,
           *(char *)((v7 & 0xFFFFFFC0) + 0x15A),
           2002218317,
           &v22,
           0) < 0 )
      JUMPOUT(0x5272B6);
    v9 = v22;
  }
  v10 = a3 + a2 - 1;
  v11 = 0;
  v22 = 0;
  if ( a2 > v10 )
  {
    v20 = -1073741583;
  }
  else
  {
    if ( v8 != v9 )
    {
      KiStackAttachProcess(v9, 0, (int)v27);
      v11 = 1;
      v22 = 1;
    }
    v25 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
    v24 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
    v12 = (_DWORD *)MiObtainReferencedVad(a2, &v23);
    v13 = (int)v12;
    if ( v12 )
    {
      if ( (v12[7] & 7) == 4 && v10 <= ((v12[4] << 12) | 0xFFFu) )
      {
        for ( i = (int *)v12[9]; i; i = (int *)*i )
        {
          if ( i[1] == 4 )
            break;
        }
        v15 = (unsigned int *)(v9 + 492);
        v26 = v12[3];
        v23 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 492);
        }
        else
        {
          v16 = (unsigned __int8 *)(v9 + 495);
          do
            v17 = __ldrex(v16);
          while ( __strex(v17 | 0x80, v16) );
          __dmb(0xBu);
          if ( v17 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v9 + 492));
          while ( 1 )
          {
            v18 = *v15;
            if ( (*v15 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v18 & 0x40000000) == 0 )
            {
              do
                v21 = __ldrex(v15);
              while ( v21 == v18 && __strex(v18 | 0x40000000, v15) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v19 = v25;
        RtlClearBits((_BYTE *)i + 8, (a2 >> 12) - v26, ((int)(v24 - v25) >> 2) + 1);
        MiMoveDirtyBitsToPfns(v19, v24);
        MiUnlockWorkingSetExclusive(v9 + 492, v23);
        v11 = v22;
        v20 = 0;
      }
      else
      {
        v20 = -1073741585;
      }
      MiUnlockAndDereferenceVad(v13);
    }
    else
    {
      v20 = -1073741585;
    }
  }
  if ( (v11 & 1) != 0 )
    KiUnstackDetachProcess((unsigned int)v27, 0);
  if ( a1 != -1 )
    ObfDereferenceObjectWithTag(v9);
  return v20;
}
