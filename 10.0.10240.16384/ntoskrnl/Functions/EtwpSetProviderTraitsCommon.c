// EtwpSetProviderTraitsCommon 
 
int __fastcall EtwpSetProviderTraitsCommon(int a1, _DWORD *a2, unsigned int a3, int *a4)
{
  _DWORD *v5; // r6
  unsigned int v7; // r9
  int v8; // r8
  int v9; // r0
  unsigned int v10; // r5
  _DWORD *v12; // r4
  int v13; // r5
  int v14; // r2
  _DWORD *v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r4
  int v19; // r5
  unsigned int v20; // r1
  int v21; // r0

  v5 = a2;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 1;
  v7 = 0;
  v8 = KeAbPreAcquire(a3, 0, 0);
  v9 = KfRaiseIrql(1);
  do
    v10 = __ldrex((unsigned __int8 *)a3);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)a3) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    return sub_808180();
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(a3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a3 + 28) = v9;
  v12 = (_DWORD *)*a4;
  if ( *a4 )
  {
    v13 = 0;
    while ( 1 )
    {
      v21 = TraitsCompare((int)v5, (int)v12);
      if ( v21 <= 0 )
      {
        if ( v21 >= 0 )
        {
          v13 = 1;
          v7 = (unsigned int)v5;
          ++v12[3];
          v5 = v12;
          goto LABEL_13;
        }
        v15 = (_DWORD *)*v12;
        if ( !*v12 )
        {
          v14 = 0;
          goto LABEL_12;
        }
      }
      else
      {
        v15 = (_DWORD *)v12[1];
        if ( !v15 )
        {
          v14 = 1;
          goto LABEL_12;
        }
      }
      v12 = v15;
    }
  }
  v12 = 0;
  v14 = 0;
  v13 = 0;
LABEL_12:
  RtlRbInsertNodeEx((unsigned int)a4, (unsigned int)v12, v14, v5);
LABEL_13:
  __dmb(0xBu);
  v16 = (unsigned int *)(a1 + 56);
  do
    v17 = __ldrex(v16);
  while ( !v17 && __strex((unsigned int)v5, v16) );
  __dmb(0xBu);
  if ( v17 )
  {
    if ( v13 )
    {
      --v5[3];
    }
    else
    {
      RtlRbRemoveNode(a4, v5);
      v7 = (unsigned int)v5;
    }
    v18 = -1073741823;
  }
  else
  {
    v18 = 0;
  }
  v19 = *(_DWORD *)(a3 + 28);
  *(_DWORD *)(a3 + 4) = 0;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)a3);
  while ( !v20 && __strex(1u, (unsigned int *)a3) );
  if ( v20 )
    ExpReleaseFastMutexContended((unsigned int *)a3, v20);
  KfLowerIrql((unsigned __int8)v19);
  KeAbPostRelease(a3);
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v18;
}
