// IopDeleteFileObjectExtension 
 
int __fastcall IopDeleteFileObjectExtension(int result)
{
  int *v1; // r7
  int v2; // r5
  int *v3; // r6
  int v4; // r1
  _DWORD *v5; // r4
  _DWORD *v6; // r8
  _DWORD *v7; // r8
  int v8; // r0
  _DWORD *v9; // r0
  int v10; // r3
  unsigned int v11; // r0
  _BYTE *v12; // r9
  _DWORD *v13; // r10
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r4
  int v17; // [sp+0h] [bp-38h]
  int v18; // [sp+4h] [bp-34h]
  int v19; // [sp+8h] [bp-30h]
  int v20; // [sp+Ch] [bp-2Ch]
  int *v21; // [sp+10h] [bp-28h]

  v1 = *(int **)(result + 124);
  v18 = result;
  v21 = v1;
  if ( v1 == IopRevocationExtension )
    return result;
  v2 = 0;
  v17 = 0;
  do
  {
    v3 = &v1[v2];
    v4 = v3[1];
    if ( !v4 )
      goto LABEL_4;
    switch ( v2 )
    {
      case 4:
        return sub_54B354();
      case 0:
        v10 = v1[1];
        if ( v10 )
        {
          v11 = *(_DWORD *)(v10 + 4);
          if ( v11 )
            ObDereferenceObjectDeferDeleteWithTag(v11);
        }
        goto LABEL_18;
      case 5:
        FsRtlFreeExtraCreateParameter(v1[6]);
        goto LABEL_4;
      case 1:
        v5 = (_DWORD *)v1[2];
        v6 = (_DWORD *)v5[2];
        while ( v6 )
        {
          v9 = v6;
          v6 = (_DWORD *)*v6;
          ExFreePoolWithTag(v9, 0);
        }
        v7 = (_DWORD *)v5[3];
        if ( v7 )
        {
          do
          {
            v12 = (_BYTE *)v7[3];
            v13 = v7;
            v7 = (_DWORD *)*v7;
            v19 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(dword_631A78);
            }
            else
            {
              do
                v14 = __ldrex(dword_631A78);
              while ( __strex(1u, dword_631A78) );
              __dmb(0xBu);
              if ( v14 )
                KxWaitForSpinLockAndAcquire(dword_631A78);
            }
            v20 = (unsigned __int8)v12[10];
            if ( v12[8] == 1 )
              v12[9] = 1;
            else
              ExFreePoolWithTag(v12, 0);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(dword_631A78);
            }
            else
            {
              __dmb(0xBu);
              dword_631A78[0] = 0;
            }
            KfLowerIrql(v19);
            if ( v13[2] )
            {
              PspAdjustKeepAliveCountProcess(v13[1], -1, v18, v20);
              ObfDereferenceObjectWithTag(v13[1]);
            }
            ExFreePoolWithTag(v13, 0);
          }
          while ( v7 );
          v2 = v17;
          v1 = v21;
          v3 = &v21[v17];
        }
        v8 = v5[1];
        if ( v8 )
          ObfDereferenceObjectWithTag(v8);
LABEL_18:
        ExFreePoolWithTag(v3[1], 0);
        goto LABEL_4;
    }
    if ( v2 != 6 )
    {
      if ( v2 == 2 )
      {
        v15 = *(_DWORD *)(v4 + 20);
        if ( v15 )
        {
          do
          {
            v16 = *(_DWORD *)(v15 + 20);
            ExFreePoolWithTag(v15, 0);
            v15 = v16;
          }
          while ( v16 );
        }
      }
      goto LABEL_18;
    }
    ExFreeToNPagedLookasideList(&IopOplockFoExtLookasideList, v4);
LABEL_4:
    v17 = ++v2;
  }
  while ( v2 < 7 );
  if ( (*v1 & 2) != 0 )
    IopCleanupNotifications(*(_DWORD *)(*(_DWORD *)(v18 + 4) + 8), v18);
  return ExFreePoolWithTag(v1, 0);
}
