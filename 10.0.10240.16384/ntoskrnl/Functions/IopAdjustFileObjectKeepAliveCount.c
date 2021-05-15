// IopAdjustFileObjectKeepAliveCount 
 
int __fastcall IopAdjustFileObjectKeepAliveCount(_DWORD *a1, int a2, int a3, _DWORD *a4, int *a5)
{
  _DWORD *v5; // r6
  int v6; // r5
  int v9; // r4
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r3
  int v14; // r7
  unsigned int *v15; // r8
  unsigned int v16; // r2
  int *v17; // r1
  int v18; // r3
  _DWORD *v19; // r3
  bool v20; // r3
  __int64 v21; // kr00_8
  _DWORD *v22; // r2
  int v24; // [sp+8h] [bp-28h] BYREF
  int v25; // [sp+Ch] [bp-24h]
  _DWORD *v26; // [sp+10h] [bp-20h]
  int vars4; // [sp+34h] [bp+4h]

  v25 = a2;
  v26 = a4;
  v5 = 0;
  v6 = 0;
  if ( a3 )
  {
    v9 = IopGetSetSpecificExtension((int)a1, 1, 16, 1, &v24, 0);
    if ( v9 < 0 )
      return v9;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v11 = 40;
      else
        v11 = 32;
      v10 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v11);
    }
    else
    {
      v10 = ExAllocatePoolWithTag(512, 16);
    }
    v5 = (_DWORD *)v10;
    if ( v10 )
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        v13 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
        v12 = ExAllocatePoolWithTagPriority(512, 0x20u, 538996553, v13);
      }
      else
      {
        v12 = ExAllocatePoolWithTag(512, 32);
      }
      v6 = v12;
      if ( !v12 )
      {
        ExFreePoolWithTag(v5);
        v5 = 0;
      }
    }
    v14 = v24;
  }
  else
  {
    v9 = 0;
    v14 = IopGetFileObjectExtension((int)a1, 1, 0);
    if ( !v14 )
      return -1073741811;
  }
  v15 = a1 + 28;
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(a1 + 28));
  }
  else
  {
    do
      v16 = __ldrex(v15);
    while ( __strex(1u, v15) );
    __dmb(0xBu);
    if ( v16 )
      KxWaitForSpinLockAndAcquire(a1 + 28);
  }
  v17 = *(int **)(v14 + 12);
  if ( v17 )
  {
    while ( v17[1] != v25 )
    {
      v17 = (int *)*v17;
      if ( !v17 )
        goto LABEL_29;
    }
    v21 = *((_QWORD *)v17 + 1);
    v17[2] = v21;
    *a5 = HIDWORD(v21);
    *v26 = v17[2];
  }
  else
  {
LABEL_29:
    if ( a3 )
    {
      if ( v5 )
      {
        *v5 = 0;
        v5[1] = 0;
        v5[2] = 0;
        v5[3] = 0;
        memset((_BYTE *)v6, 0, 32);
        *v5 = *(_DWORD *)(v14 + 12);
        v18 = v25;
        *(_DWORD *)(v14 + 12) = v5;
        v5[1] = v18;
        v5[2] = 1;
        v5[3] = v6;
        *(_DWORD *)(v6 + 12) = v18;
        *(_DWORD *)(v6 + 20) = a1;
        if ( (a1[11] & 0x20000000) != 0 )
        {
          v19 = (_DWORD *)a1[31];
          v20 = !v19 || (*v19 & 8) == 0;
          *(_BYTE *)(v6 + 10) = v20;
        }
        else
        {
          *(_BYTE *)(v6 + 10) = 0;
        }
        v22 = v26;
        v5 = 0;
        *a5 = v6;
        v6 = 0;
        *v22 = 1;
      }
      else
      {
        v9 = -1073741670;
      }
    }
    else
    {
      v9 = -1073741811;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 28, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v15 = 0;
  }
  KfLowerIrql(v24);
  if ( v5 )
    ExFreePoolWithTag(v5);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v9;
}
